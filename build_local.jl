libclangex_jll = Base.UUID("82994860-12e5-56b1-9971-c34819be692e")

using Pkg, Scratch, Preferences, Libdl

source_dir = @__DIR__

# 1. Get a scratch directory
scratch_dir = get_scratch!(libclangex_jll, "build")
isdir(scratch_dir) && rm(scratch_dir; recursive=true)

# 2. Ensure that an appropriate LLVM_full_jll is installed
Pkg.activate(; temp=true)
llvm_assertions = try
    cglobal((:_ZN4llvm24DisableABIBreakingChecksE, Base.libllvm_path()), Cvoid)
    false
catch
    true
end
LLVM = if llvm_assertions
    Pkg.add(name="LLVM_full_assert_jll", version=Base.libllvm_version)
    using LLVM_full_assert_jll
    LLVM_full_assert_jll
else
    Pkg.add(name="LLVM_full_jll", version=Base.libllvm_version)
    using LLVM_full_jll
    LLVM_full_jll
end
LLVM_DIR = joinpath(LLVM.artifact_dir)

Clang = if VERSION < v"1.8-" && llvm_assertions
    Pkg.add(name="Clang_assert_jll", version=Base.libllvm_version)
    using Clang_assert_jll
    Clang_assert_jll
else
    Pkg.add(name="Clang_jll", version=Base.libllvm_version)
    using Clang_jll
    Clang_jll
end
CLANG_DIR = joinpath(Clang.artifact_dir)

@info "Building" scratch_dir source_dir LLVM_DIR CLANG_DIR

run(`cmake -DLLVM_DIR=$(LLVM_DIR) -DCLANG_DIR=$(CLANG_DIR) -DLLVM_ASSERT_BUILD=$(llvm_assertions) -DLLVM_VERSION_MAJOR=$(Base.libllvm_version.major) -B$(scratch_dir) -S$(source_dir)`)
run(`cmake --build $(scratch_dir) --parallel $(Sys.CPU_THREADS)`)

# Discover built libraries
built_libs = filter(readdir(scratch_dir)) do file
    endswith(file, ".$(Libdl.dlext)") && startswith(file, "lib")
end

lib_path = joinpath(scratch_dir, only(built_libs))
isfile(lib_path) || error("Could not find library $lib_path in build directory")

# Tell libclangex_jll to load our libraries
set_preferences!(
    joinpath(@__DIR__, "LocalPreferences.toml"),
    "libclangex_jll",
    "libclangex_path" => lib_path,
    force=true,
)

