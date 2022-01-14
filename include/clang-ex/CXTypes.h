#ifndef LIBCLANGEX_CXTYPES_H
#define LIBCLANGEX_CXTYPES_H

#include "clang-c/Platform.h"
#include <stdbool.h>
#include <stdint.h>
#include <time.h>

#ifdef __cplusplus
extern "C" {
#endif

// AST
// ASTConsumer
typedef void *CXASTConsumer;

// ASTContext
typedef void *CXASTContext;

// Decl
typedef void *CXTranslationUnitDecl;
typedef void *CXPragmaCommentDecl;
typedef void *CXPragmaDetectMismatchDecl;
typedef void *CXExternCContextDecl;
typedef void *CXNamedDecl;
typedef void *CXLabelDecl;
typedef void *CXNamespaceDecl;
typedef void *CXValueDecl;
typedef void *CXDeclaratorDecl;
typedef void *CXVarDecl;
typedef void *CXImplicitParamDecl;
typedef void *CXParmVarDecl;
typedef void *CXFunctionDecl;
typedef void *CXFieldDecl;
typedef void *CXEnumConstantDecl;
typedef void *CXIndirectFieldDecl;
typedef void *CXTypeDecl;
typedef void *CXTypedefNameDecl;
typedef void *CXTypedefDecl;
typedef void *CXTypeAliasDecl;
typedef void *CXTagDecl;
typedef void *CXEnumDecl;
typedef void *CXRecordDecl;
typedef void *CXFileScopeAsmDecl;
typedef void *CXBlockDecl;
typedef void *CXCapturedDecl;
typedef void *CXImportDecl;
typedef void *CXExportDecl;

// DeclarationName
typedef void *CXDeclarationName;

// DeclBase
typedef void *CXDecl;
typedef void *CXDeclContext;

// DeclCXX
typedef void *CXAccessSpecDecl;
typedef void *CXCXXBaseSpecifier;
typedef void *CXCXXRecordDecl;
typedef void *CXExplicitSpecifier;
typedef void *CXCXXDeductionGuideDecl;
typedef void *CXRequiresExprBodyDecl;
typedef void *CXCXXMethodDecl;
typedef void *CXCXXCtorInitializer;
typedef void *CXCXXConstructorDecl;
typedef void *CXCXXDestructorDecl;
typedef void *CXCXXConversionDecl;
typedef void *CXLinkageSpecDecl;
typedef void *CXUsingDirectiveDecl;
typedef void *CXNamespaceAliasDecl;
typedef void *CXLifetimeExtendedTemporaryDecl;
typedef void *CXUsingShadowDecl;
typedef void *CXConstructorUsingShadowDecl;
typedef void *CXUsingPackDecl;
typedef void *CXUnresolvedUsingValueDecl;
typedef void *CXUnresolvedUsingTypenameDecl;
typedef void *CXStaticAssertDecl;
typedef void *CXBindingDecl;
typedef void *CXDecompositionDecl;
typedef void *CXMSPropertyDecl;
typedef void *CXMSGuidDecl;

// DeclGroup
typedef void *CXDeclGroupRef;

// DeclTemplate
typedef void *CXTemplateDecl;
typedef void *CXRedeclarableTemplateDecl;
typedef void *CXFunctionTemplateDecl;
typedef void *CXTemplateTypeParmDecl;
typedef void *CXNonTypeTemplateParmDecl;
typedef void *CXTemplateTemplateParmDecl;
typedef void *CXBuiltinTemplateDecl;
typedef void *CXClassTemplateSpecializationDecl;
typedef void *CXClassTemplatePartialSpecializationDecl;
typedef void *CXClassTemplateDecl;
typedef void *CXFriendTemplateDecl;
typedef void *CXTypeAliasTemplateDecl;
typedef void *CXClassScopeFunctionSpecializationDecl;
typedef void *CXVarTemplateSpecializationDecl;
typedef void *CXVarTemplatePartialSpecializationDecl;
typedef void *CXVarTemplateDecl;
typedef void *CXConceptDecl;
typedef void *CXTemplateParamObjectDecl;

typedef void *CXTemplateParameterList;
typedef void *CXTemplateArgumentList;

// NestedNameSpacifier
typedef void *CXNestedNameSpecifier;

// Types
typedef void *CXType_;
typedef void *CXQualType;
typedef void *CXComplexType;
typedef void *CXPointerType;
typedef void *CXReferenceType;
typedef void *CXLValueReferenceType;
typedef void *CXRValueReferenceType;
typedef void *CXMemberPointerType;
typedef void *CXArrayType;
typedef void *CXConstantArrayType;
typedef void *CXIncompleteArrayType;
typedef void *CXVariableArrayType;
typedef void *CXDependentSizedArrayType;
typedef void *CXFunctionType;
typedef void *CXFunctionNoProtoType;
typedef void *CXFunctionProtoType;
typedef void *CXTypedefType;
typedef void *CXTagType;
typedef void *CXRecordType;
typedef void *CXEnumType;
typedef void *CXTemplateTypeParmType;
typedef void *CXSubstTemplateTypeParmType;
typedef void *CXSubstTemplateTypeParmPackType;
typedef void *CXTemplateSpecializationType;
typedef void *CXTypeWithKeyword;
typedef void *CXElaboratedType;
typedef void *CXDependentNameType;
typedef void *CXDependentTemplateSpecializationType;
typedef void *CXDeducedType;

// TemplateBase
typedef void *CXTemplateName;

// TemplateName
typedef void *CXTemplateArgument;

// Basic
// CodeGenOptions
typedef void *CXCodeGenOptions;

// Diagnostic
typedef void *CXDiagnosticConsumer;
typedef void *CXDiagnosticsEngine;

// DiagnosticIDs
typedef void *CXDiagnosticIDs;

// DiagnosticOptions
typedef void *CXDiagnosticOptions;

// FileEntry
typedef void *CXFileEntry;

// FileManager
typedef void *CXDirectoryEntry;
typedef void *CXFileEntryRef; // FIXME: make it a stack value instead of opaque pointer
typedef void *CXFileManager;

// IdentifierTable
typedef void *CXIdentifierInfo;
typedef void *CXIdentifierTable;

// LangOptions
typedef void *CXLangOptions;

// SourceLocation
typedef void *CXSourceLocation_;

// SourceManager
typedef void *CXFileID;
typedef void *CXSourceManager;

// TargetInfo
typedef void *CXTargetInfo_;

// TargetOptions
typedef void *CXTargetOptions;

// CodeGen
// CodeGenAction
typedef void *CXCodeGenAction;

// ModuleBuilder
typedef void *CXCodeGenerator;
typedef void *CXCodeGenModule;

// Frontend
// CompilerInstance
typedef void *CXCompilerInstance;

// CompilerInvocation
typedef void *CXCompilerInvocation;

// FrontendOptions
typedef void *CXFrontendOptions;

// Lex
// HeaderSearch
typedef void *CXHeaderSearch;

// HeaderSearchOptions
typedef void *CXHeaderSearchOptions;

// Lexer
typedef void *CXLexer;

// Preprocessor
typedef void *CXPreprocessor;

// PreprocessorOptions
typedef void *CXPreprocessorOptions;

// Token
typedef void *CXToken_;

typedef void *CXAnnotationValue;

// Parse
// Parser
typedef void *CXParser;

// Sema
typedef void *CXSema;

// DeclSpec
typedef void *CXCXXScopeSpec;

// Lookup
typedef void *CXLookupResult;

// Scope
typedef void *CXScope;

// Others
typedef enum CXTranslationUnitKind {
  CXTranslationUnitKind_TU_Complete,
  CXTranslationUnitKind_TU_Prefix,
  CXTranslationUnitKind_TU_Module
} CXTranslationUnitKind;

typedef void *CXFrontendAction;

#ifdef __cplusplus
}
#endif
#endif