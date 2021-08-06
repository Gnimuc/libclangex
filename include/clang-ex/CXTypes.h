#ifndef LIBCLANGEX_CXTYPES_H
#define LIBCLANGEX_CXTYPES_H

#include "clang-c/Platform.h"
#include <stdbool.h>
#include <time.h>

#ifdef __cplusplus
extern "C" {
#endif

// CompilerInstance
typedef void *CXCompilerInstance;

// Options
typedef void *CXTargetOptions;
typedef void *CXTargetInfo_;
typedef void *CXCodeGenOptions;
typedef void *CXHeaderSearchOptions;
typedef void *CXPreprocessorOptions;
typedef void *CXFrontendOptions;
typedef void *CXLangOptions;

// Diagnostic
typedef void *CXDiagnosticIDs;
typedef void *CXDiagnosticOptions;
typedef void *CXDiagnosticConsumer;
typedef void *CXDiagnosticsEngine;

// CompilerInvocation
typedef void *CXCompilerInvocation;

// FileManager
typedef void *CXDirectoryEntry;
typedef void *CXFileID;
typedef void *CXFileEntry;
typedef void *CXFileEntryRef; // FIXME: make it a stack value instead of opaque pointer
typedef void *CXFileManager;

// SourceManager
typedef void *CXSourceManager;
typedef void *CXSourceLocation_;

// Preprocessor
typedef void *CXPreprocessor;
typedef void *CXHeaderSearch;
typedef void *CXLexer;
typedef void *CXToken_;
typedef void *CXAnnotationValue;

typedef enum CXTranslationUnitKind {
  CXTranslationUnitKind_TU_Complete,
  CXTranslationUnitKind_TU_Prefix,
  CXTranslationUnitKind_TU_Module
} CXTranslationUnitKind;

// AST
typedef void *CXASTContext;
typedef void *CXASTConsumer;
typedef void *CXType_;
typedef void *CXQualType;
typedef void *CXTranslationUnitDecl;
typedef void *CXDeclGroupRef;
typedef void *CXDecl;
typedef void *CXNamedDecl;
typedef void *CXTypeDecl;
typedef void *CXTagDecl;
typedef void *CXTemplateParameterList;
typedef void *CXRecordDecl;
typedef void *CXCXXRecordDecl;
typedef void *CXNestedNameSpecifier;
typedef void *CXCXXScopeSpec;
typedef void *CXIdentifierTable;
typedef void *CXIdentifierInfo;
typedef void *CXDeclarationName;

// CodeGen
typedef void *CXCodeGenerator;
typedef void *CXCodeGenModule;

// Sema
typedef void *CXSema;
typedef void *CXScope;
typedef void *CXLookupResult;

typedef enum CXDeclaratorContext {
  CXDeclaratorContext_File,
  CXDeclaratorContext_Prototype,
  CXDeclaratorContext_ObjCResult,
  CXDeclaratorContext_ObjCParameter,
  CXDeclaratorContext_KNRTypeList,
  CXDeclaratorContext_TypeName,
  CXDeclaratorContext_FunctionalCast,
  CXDeclaratorContext_Member,
  CXDeclaratorContext_Block,
  CXDeclaratorContext_ForInit,
  CXDeclaratorContext_SelectionInit,
  CXDeclaratorContext_Condition,
  CXDeclaratorContext_TemplateParam,
  CXDeclaratorContext_CXXNew,
  CXDeclaratorContext_CXXCatch,
  CXDeclaratorContext_ObjCCatch,
  CXDeclaratorContext_BlockLiteral,
  CXDeclaratorContext_LambdaExpr,
  CXDeclaratorContext_LambdaExprParameter,
  CXDeclaratorContext_ConversionId,
  CXDeclaratorContext_TrailingReturn,
  CXDeclaratorContext_TrailingReturnVar,
  CXDeclaratorContext_TemplateArg,
  CXDeclaratorContext_TemplateTypeArg,
  CXDeclaratorContext_AliasDecl,
  CXDeclaratorContext_AliasTemplate,
  CXDeclaratorContext_RequiresExpr
} CXDeclaratorContext;

typedef enum CXDeclSpecContext {
  CXDeclSpecContext_DSC_normal,
  CXDeclSpecContext_DSC_class,
  CXDeclSpecContext_DSC_type_specifier,
  CXDeclSpecContext_DSC_trailing,
  CXDeclSpecContext_DSC_alias_declaration,
  CXDeclSpecContext_DSC_top_level,
  CXDeclSpecContext_DSC_template_param,
  CXDeclSpecContext_DSC_template_type_arg,
  CXDeclSpecContext_DSC_objc_method_result,
  CXDeclSpecContext_DSC_condition
} CXDeclSpecContext;

// Parser
typedef void *CXParser;

// Action
typedef void *CXFrontendAction;
typedef void *CXCodeGenAction;

// Lookup
typedef enum CXLookupNameKind {
  CXLookupNameKind_LookupOrdinaryName = 0,
  CXLookupNameKind_LookupTagName,
  CXLookupNameKind_LookupLabel,
  CXLookupNameKind_LookupMemberName,
  CXLookupNameKind_LookupOperatorName,
  CXLookupNameKind_LookupDestructorName,
  CXLookupNameKind_LookupNestedNameSpecifierName,
  CXLookupNameKind_LookupNamespaceName,
  CXLookupNameKind_LookupUsingDeclName,
  CXLookupNameKind_LookupRedeclarationWithLinkage,
  CXLookupNameKind_LookupLocalFriendName,
  CXLookupNameKind_LookupObjCProtocolName,
  CXLookupNameKind_LookupObjCImplicitSelfParam,
  CXLookupNameKind_LookupOMPReductionName,
  CXLookupNameKind_LookupOMPMapperName,
  CXLookupNameKind_LookupAnyName
} CXLookupNameKind;

#ifdef __cplusplus
}
#endif
#endif