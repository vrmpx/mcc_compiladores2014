/* File: ast.cc
 * ------------
 */

#include "ast.h"
#include "ast_type.h"
#include "ast_decl.h"
#include <string.h> // strdup
#include <stdio.h>  // printf
#include "errors.h"
#include "scope.h"

Node::Node(yyltype loc) {
    location = new yyltype(loc);
    parent = NULL;
    nodeScope = NULL;
}

Node::Node() {
    location = NULL;
    parent = NULL;
    nodeScope = NULL;
}

Decl *Node::FindDecl(Identifier *idToFind, lookup l) {
    Decl *mine;
    if (!nodeScope) PrepareScope();
    if (nodeScope && (mine = nodeScope->Lookup(idToFind)))
        return mine;
    if (l == kDeep && parent)
        return parent->FindDecl(idToFind, l);
    return NULL;
}

FnDecl *Node::GetEnclosFunc(Node *node) {
    Node *parent = node->GetParent();
    FnDecl *fndecl = NULL;

    while(parent != NULL){
        if ((fndecl = dynamic_cast<FnDecl*>(parent)))
            break;
        parent = parent->GetParent();
    }
    return fndecl;
}

ClassDecl *Node::GetEnclosClass(Node *node) {
    Node *parent = node->GetParent();
    ClassDecl *classDecl = NULL;

    while(parent != NULL){
        if ((classDecl = dynamic_cast<ClassDecl*>(parent)))
            break;
        parent = parent->GetParent();
    }
    return classDecl;
}

 
Identifier::Identifier(yyltype loc, const char *n) : Node(loc) {
    name = strdup(n);
    cached = NULL;

    this->memLoc = NULL; 
} 

Identifier::Identifier(const char *n) : Node() {
    name = strdup(n);
    cached = NULL;


    this->memLoc = NULL;
}

