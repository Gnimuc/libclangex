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

typedef enum CXTagTypeKind {
  CXTagTypeKind_TTK_Struct,
  CXTagTypeKind_TTK_Interface,
  CXTagTypeKind_TTK_Union,
  CXTagTypeKind_TTK_Class,
  CXTagTypeKind_TTK_Enum
} CXTagTypeKind;

typedef enum CXTemplateName_NameKind {
  CXTemplateName_NameKind_Template,
  CXTemplateName_NameKind_OverloadedTemplate,
  CXTemplateName_NameKind_AssumedTemplate,
  CXTemplateName_NameKind_QualifiedTemplate,
  CXTemplateName_NameKind_DependentTemplate,
  CXTemplateName_NameKind_SubstTemplateTemplateParm,
  CXTemplateName_NameKind_SubstTemplateTemplateParmPack
} CXTemplateName_NameKind;

typedef enum CXTemplateArgument_ArgKind {
  CXTemplateArgument_ArgKind_Null = 0,
  CXTemplateArgument_ArgKind_Type,
  CXTemplateArgument_ArgKind_Declaration,
  CXTemplateArgument_ArgKind_NullPtr,
  CXTemplateArgument_ArgKind_Integral,
  CXTemplateArgument_ArgKind_Template,
  CXTemplateArgument_ArgKind_TemplateExpansion,
  CXTemplateArgument_ArgKind_Expression,
  CXTemplateArgument_ArgKind_Pack
} CXTemplateArgument_ArgKind;

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