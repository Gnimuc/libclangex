#ifndef LIBCLANGEX_H
#define LIBCLANGEX_H

#include "clang-ex/CXTypes.h"
#include "clang-c/Platform.h"

#include "CXError.h"
#include "CXTypes.h"
#include "AST/CXASTConsumer.h"
#include "AST/CXASTContext.h"
#include "AST/CXDecl.h"
#include "AST/CXDeclBase.h"
#include "AST/CXDeclCXX.h"
#include "AST/CXDeclGroup.h"
#include "AST/CXDeclTemplate.h"
#include "AST/CXDeclarationName.h"
#include "AST/CXExpr.h"
#include "AST/CXMangle.h"
#include "AST/CXNestedNameSpecifier.h"
#include "AST/CXOperationKinds.h"
#include "AST/CXTemplateBase.h"
#include "AST/CXTemplateName.h"
#include "AST/CXType.h"
#include "Basic/CXCodeGenOptions.h"
#include "Basic/CXDiagnostic.h"
#include "Basic/CXDiagnosticIDs.h"
#include "Basic/CXDiagnosticOptions.h"
#include "Basic/CXExceptionSpecificationType.h"
#include "Basic/CXFileEntry.h"
#include "Basic/CXFileManager.h"
#include "Basic/CXIdentifierTable.h"
#include "Basic/CXLambda.h"
#include "Basic/CXLangOptions.h"
#include "Basic/CXLinkage.h"
#include "Basic/CXModule.h"
#include "Basic/CXPragmaKinds.h"
#include "Basic/CXSourceLocation.h"
#include "Basic/CXSourceManager.h"
#include "Basic/CXSpecifiers.h"
#include "Basic/CXTargetInfo.h"
#include "Basic/CXTargetOptions.h"
#include "Basic/CXVisibility.h"
#include "CodeGen/CXCodeGenABITypes.h"
#include "CodeGen/CXCodeGenAction.h"
#include "CodeGen/CXModuleBuilder.h"
#include "Driver/CXDriver.h"
#include "Frontend/CXCompilerInstance.h"
#include "Frontend/CXCompilerInvocation.h"
#include "Frontend/CXFrontendOptions.h"
#include "Frontend/CXTextDiagnosticPrinter.h"
#include "Lex/CXHeaderSearch.h"
#include "Lex/CXHeaderSearchOptions.h"
#include "Lex/CXLexer.h"
#include "Lex/CXPreprocessor.h"
#include "Lex/CXPreprocessorOptions.h"
#include "Lex/CXToken.h"
#include "Parse/CXParseAST.h"
#include "Parse/CXParser.h"
#include "Sema/CXDeclSpec.h"
#include "Sema/CXLookup.h"
#include "Sema/CXScope.h"
#include "Sema/CXSema.h"

#ifdef __cplusplus
extern "C" {
#endif

CINDEX_LINKAGE void clang_Stmt_EnableStatistics(void);
CINDEX_LINKAGE void clang_Stmt_PrintStats(void);

#ifdef __cplusplus
}
#endif
#endif
