#include "clang-ex/AST/CXDeclarationName.h"
#include "clang/AST/DeclarationName.h"

CXDeclarationName clang_DeclarationName_create(void) {
  return clang::DeclarationName().getAsOpaquePtr();
}

CXDeclarationName clang_DeclarationName_createFromIdentifierInfo(CXIdentifierInfo IDInfo) {
  return clang::DeclarationName(static_cast<clang::IdentifierInfo *>(IDInfo))
      .getAsOpaquePtr();
}

void clang_DeclarationName_dump(CXDeclarationName DN) {
  clang::DeclarationName::getFromOpaquePtr(DN).dump();
}

bool clang_DeclarationName_isEmpty(CXDeclarationName DN) {
  return clang::DeclarationName::getFromOpaquePtr(DN).isEmpty();
}

char *clang_DeclarationName_getAsString(CXDeclarationName DN) {
  auto str = clang::DeclarationName::getFromOpaquePtr(DN).getAsString();
  std::unique_ptr<char[]> ptr = std::make_unique<char[]>(str.size() + 1);
  ptr[str.size() + 1] = '\0';
  std::copy(str.begin(), str.end(), ptr.get());
  return ptr.release();
}

void clang_DeclarationName_disposeString(char *Str) { delete[] Str; }
