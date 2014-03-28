/* File: ast_stmt.h
 * ----------------
 * The Stmt class and its subclasses are used to represent
 * statements in the parse tree.  For each statment in the
 * language (for, if, return, etc.) there is a corresponding
 * node class for that construct. 
 *
 * pp3: You will need to extend the Stmt classes to implement
 * semantic analysis for rules pertaining to statements.
 */


#ifndef _H_ast_stmt
#define _H_ast_stmt

#include "list.h"
#include "ast.h"
#include "hashtable.h"
#include "ast_decl.h"

class Decl;
class VarDecl;
class Expr;
class FnDecl;
class ClassDecl;

class Scope 
{
  private:
    Scope *parent;

  public:
    Hashtable<Decl*> *table;
    FnDecl *fnDecl;
    ClassDecl *clDecl;

  public:
    Scope(): table(new Hashtable<Decl*>), fnDecl(NULL) {}

    void SetParent(Scope *p){ parent = p; }
    Scope* GetParent() { return parent; }

    void SetFunctionDecl(FnDecl *f){ fnDecl = f; }
    FnDecl* GetFunctionDecl() { return fnDecl; }

    void SetClassDecl(ClassDecl *c){ clDecl = c; }
    ClassDecl* GetClassDecl() { return clDecl; }

    int AddDecl(Decl *decl);

};
  
class Program : public Node
{
  public:
    static Scope *pScope;

  protected:
     List<Decl*> *decls;
     
  public:
     Program(List<Decl*> *declList);
     void Check();

  private:
    void BuildScope();
};

class Stmt : public Node
{
  protected:
      Scope *scope;

  public:
     Stmt() : Node(), scope(new Scope)  {}
     Stmt(yyltype loc) : Node(loc), scope(new Scope) {}

     virtual void BuildScope(Scope *parent);
     virtual void Check() = 0;
};

class StmtBlock : public Stmt 
{
  protected:
    List<VarDecl*> *decls;
    List<Stmt*> *stmts;
    
  public:
    StmtBlock(List<VarDecl*> *variableDeclarations, List<Stmt*> *statements);

    void BuildScope(Scope *parent);
    void Check();
};

  
class ConditionalStmt : public Stmt
{
  protected:
    Expr *test;
    Stmt *body;
  
  public:
    ConditionalStmt(Expr *testExpr, Stmt *body);

    virtual void BuildScope(Scope *parent);
    virtual void Check();
};

class LoopStmt : public ConditionalStmt 
{
  public:
    LoopStmt(Expr *testExpr, Stmt *body)
            : ConditionalStmt(testExpr, body) {}

    virtual void BuildScope(Scope *parent);
};

class ForStmt : public LoopStmt 
{
  protected:
    Expr *init, *step;
  
  public:
    ForStmt(Expr *init, Expr *test, Expr *step, Stmt *body);
};

class WhileStmt : public LoopStmt 
{
  public:
    WhileStmt(Expr *test, Stmt *body) : LoopStmt(test, body) {}
};

class IfStmt : public ConditionalStmt 
{
  protected:
    Stmt *elseBody;
  
  public:
    IfStmt(Expr *test, Stmt *thenBody, Stmt *elseBody);

    void BuildScope(Scope *parent);
    void Check();
};

class BreakStmt : public Stmt 
{
  public:
    BreakStmt(yyltype loc) : Stmt(loc) {}

   void Check();
};

class ReturnStmt : public Stmt  
{
  protected:
    Expr *expr;
  
  public:
    ReturnStmt(yyltype loc, Expr *expr);

    void BuildScope(Scope *parent);
    void Check();
};

class PrintStmt : public Stmt
{
  protected:
    List<Expr*> *args;
    
  public:
    PrintStmt(List<Expr*> *arguments);

    void BuildScope(Scope *parent);
    void Check();
};


#endif
