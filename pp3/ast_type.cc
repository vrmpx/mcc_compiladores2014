/* File: ast_type.cc
 * -----------------
 * Implementation of type node classes.
 */
#include "ast_type.h"
#include "ast_decl.h"
#include <string.h>

 
/* Class constants
 * ---------------
 * These are public constants for the built-in base types (int, double, etc.)
 * They can be accessed with the syntax Type::intType. This allows you to
 * directly access them and share the built-in types where needed rather that
 * creates lots of copies.
 */

Type *Type::intType    = new Type("int");
Type *Type::doubleType = new Type("double");
Type *Type::voidType   = new Type("void");
Type *Type::boolType   = new Type("bool");
Type *Type::nullType   = new Type("null");
Type *Type::stringType = new Type("string");
Type *Type::errorType  = new Type("error"); 

Type::Type(const char *n) {
    Assert(n);
    typeName = strdup(n);
}



	
NamedType::NamedType(Identifier *i) : Type(*i->GetLocation()) {
    Assert(i != NULL);
    (id=i)->SetParent(this);
} 

void NamedType::ReportNotDeclaredIdentifier(reasonT reason){
	ReportError::IdentifierNotDeclared(id, reason);
}

bool NamedType::IsEquivalentTo(Type *other) {
    NamedType* nOther = dynamic_cast<NamedType*>(other);

    if(other == NULL)
    	return false;

    return strcmp(id->Name(), nOther->id->Name()) == 0;
}

ArrayType::ArrayType(yyltype loc, Type *et) : Type(loc) {
    Assert(et != NULL);
    (elemType=et)->SetParent(this);
}

void ArrayType::ReportNotDeclaredIdentifier(reasonT reason){
	elemType->ReportNotDeclaredIdentifier(reason);
}

bool ArrayType::IsEquivalentTo(Type *other) {
    ArrayType *arrayOther = dynamic_cast<ArrayType*>(other);

    if (arrayOther == NULL)
        return false;

    return elemType->IsEquivalentTo(arrayOther->elemType);
}
