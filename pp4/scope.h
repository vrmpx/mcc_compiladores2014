/* File: scope.h
 * -------------
 * The Scope class will be used to manage scopes, sort of
 * table used to map identifier names to Declaration objects.
 */

#ifndef _H_scope
#define _H_scope

#include "hashtable.h"

class Decl;
class Identifier;
class ClassDecl; 
class LoopStmt;

class Scope { 
  protected:
    Hashtable<Decl*> *table;
    LoopStmt *loopStmt;
    ClassDecl *classDecl;

  public:
    Scope();

    Decl *Lookup(Identifier *id);
    bool Declare(Decl *dec);
    void CopyFromScope(Scope *other, ClassDecl *cd);
    Hashtable<Decl*>* GetTable() { return table; }

    LoopStmt* GetLoopStmt() { return loopStmt; }
    void SetLoopStmt(LoopStmt* l) { loopStmt = l; }

    ClassDecl* GetClassDecl() { return classDecl; }
    void SetClassDecl(ClassDecl* c) { classDecl = c; }

};


#endif
