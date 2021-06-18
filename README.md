# libclangex

## Build 
```
LLVM_MAJOR_VER=`julia -e "print(Base.libllvm_version.major)"`
julia -e "using Pkg; pkg\"add LLVM_full_jll@${LLVM_MAJOR_VER}\""
LLVM_DIR=`julia -e "using LLVM_full_jll; print(LLVM_full_jll.artifact_dir)"`
echo "LLVM_DIR=$LLVM_DIR"
julia -e "using Pkg; pkg\"add Clang_jll@${LLVM_MAJOR_VER}\""
CLANG_DIR=`julia -e "using Clang_jll; print(Clang_jll.artifact_dir)"`
echo "CLANG_DIR=$CLANG_DIR"

mkdir build && cd build
cmake .. -DLLVM_DIR=${LLVM_DIR} -DCLANG_DIR=${CLANG_DIR}
make
```