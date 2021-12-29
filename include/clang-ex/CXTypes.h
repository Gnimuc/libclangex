#ifndef LIBCLANGEX_CXTYPES_H
#define LIBCLANGEX_CXTYPES_H

#include "clang-c/Platform.h"
#include <stdbool.h>
#include <stdint.h>
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
typedef void *CXTranslationUnitDecl;
typedef void *CXDeclGroupRef;
typedef void *CXDecl;
typedef void *CXDeclContext;
typedef void *CXTranslationUnitDecl;
typedef void *CXNamedDecl;
typedef void *CXValueDecl;
typedef void *CXTypeDecl;
typedef void *CXTypedefNameDecl;
typedef void *CXTagDecl;
typedef void *CXEnumDecl;
typedef void *CXTemplateDecl;
typedef void *CXRedeclarableTemplateDecl;
typedef void *CXClassTemplateDecl;
typedef void *CXTemplateParameterList;
typedef void *CXTemplateArgumentList;
typedef void *CXRecordDecl;
typedef void *CXCXXRecordDecl;
typedef void *CXClassTemplateSpecializationDecl;
typedef void *CXNestedNameSpecifier;
typedef void *CXCXXScopeSpec;
typedef void *CXIdentifierTable;
typedef void *CXIdentifierInfo;
typedef void *CXDeclarationName;
typedef void *CXTemplateName;
typedef void *CXTemplateArgument;

// Type
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

// CodeGen
typedef void *CXCodeGenerator;
typedef void *CXCodeGenModule;

// Sema
typedef void *CXSema;
typedef void *CXScope;
typedef void *CXLookupResult;

// Parser
typedef void *CXParser;

// Action
typedef void *CXFrontendAction;
typedef void *CXCodeGenAction;

#ifdef __cplusplus
}
#endif
#endif