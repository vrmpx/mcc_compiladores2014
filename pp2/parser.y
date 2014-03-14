/* File: parser.y
 * --------------
 * Bison input file to generate the parser for the compiler.
 *
 * pp2: your job is to write a parser that will construct the parse tree
 *      and if no parse errors were found, print it.  The parser should 
 *      accept the language as described in specification, and as augmented 
 *      in the pp2 handout.
 */

%{

/* Just like lex, the text within this first region delimited by %{ and %}
 * is assumed to be C/C++ code and will be copied verbatim to the y.tab.c
 * file ahead of the definitions of the yyparse() function. Add other header
 * file inclusions or C++ variable declarations/prototypes that are needed
 * by your code here.
 */
#include "scanner.h" // for yylex
#include "parser.h"
#include "errors.h"

void yyerror(const char *msg); // standard error-handling routine

%}

/* The section before the first %% is the Definitions section of the yacc
 * input file. Here is where you declare tokens and types, add precedence
 * and associativity options, and so on.
 */
 
/* yylval 
 * ------
 * Here we define the type of the yylval global variable that is used by
 * the scanner to store attibute information about the token just scanned
 * and thus communicate that information to the parser. 
 *
 * pp2: You will need to add new fields to this union as you add different 
 *      attributes to your non-terminal symbols.
 */
%union {
    int integerConstant;
    bool boolConstant;
    char *stringConstant;
    double doubleConstant;
    char identifier[MaxIdentLen+1]; // +1 for terminating null
    Decl *decl;
    List<Decl*> *declList;
    VarDecl *varDecl;
    FnDecl *fnDecl;
    ClassDecl *classDecl;
    InterfaceDecl *interfaceDecl;
    VarDecl *var;
    List<VarDecl *> *varList;
    Type *type;
    StmtBlock *stmtBlock;
    List<Identifier *> *identifierList;
    NamedType *namedType;
    List<NamedType *> *namedTypeList;
    List<Stmt *> *stmtList;
    Stmt *stmt;
    Expr *expr;
    List<Expr *> *exprList;
    IfStmt *ifStmt;
    WhileStmt *whileStmt;
    ForStmt *forStmt;
    ReturnStmt *returnStmt;
    BreakStmt *breakStmt;
    PrintStmt *printStmt;
    LValue *lvalue;
}


/* Tokens
 * ------
 * Here we tell yacc about all the token types that we are using.
 * Bison will assign unique numbers to these and export the #define
 * in the generated y.tab.h header file.
 */
%token   T_Void T_Bool T_Int T_Double T_String T_Class 
%token   T_LessEqual T_GreaterEqual T_Equal T_NotEqual T_Dims
%token   T_And T_Or T_Null T_Extends T_This T_Interface T_Implements
%token   T_While T_For T_If T_Else T_Return T_Break
%token   T_New T_NewArray T_Print T_ReadInteger T_ReadLine

%token   <identifier> T_Identifier
%token   <stringConstant> T_StringConstant 
%token   <integerConstant> T_IntConstant
%token   <doubleConstant> T_DoubleConstant
%token   <boolConstant> T_BoolConstant


/* Non-terminal types
 * ------------------
 * In order for yacc to assign/access the correct field of $$, $1, we
 * must to declare which field is appropriate for the non-terminal.
 * As an example, this first type declaration establishes that the DeclList
 * non-terminal uses the field named "declList" in the yylval union. This
 * means that when we are setting $$ for a reduction for DeclList ore reading
 * $n which corresponds to a DeclList nonterminal we are accessing the field
 * of the union named "declList" which is of type List<Decl*>.
 * pp2: You'll need to add many of these of your own.
 */
%type <declList>  DeclP 
%type <decl>      Decl
%type <var>      VariableDecl
%type <varList>  VariableDeclA
%type <var>      Variable
%type <varList>      VarPC
%type <type>      Type
%type <fnDecl>      FunctionDecl
%type <varList>      Formals
%type <identifierList>      IndentifierPC
%type <classDecl>      ClassDecl
%type <namedType>      Extends01
%type <namedTypeList>      Implements01
%type <decl>      Field
%type <declList>      FieldA
%type <interfaceDecl>      InterfaceDecl
%type <decl>      Prototype
%type <declList>      PrototypeA
%type <stmtBlock>      StmtBlock
%type <stmt>      Stmt
%type <stmtList>      StmtA
%type <ifStmt>      IfStmt
%type <stmt>      Else01
%type <whileStmt>      WhileStmt
%type <forStmt>      ForStmt
%type <returnStmt>      ReturnStmt
%type <breakStmt>      BreakStmt
%type <printStmt>      PrintStmt
%type <expr>      Expr
%type <expr>      Expr01
%type <exprList>      ExprPC
%type <lvalue>      LValue
%type <expr>      Call
%type <exprList>      Actuals
%type <expr>      Constant
%%
/* Rules
 * -----
 * All productions and actions should be placed between the start and stop
 * %% markers which delimit the Rules section.
   
 */
Program   :    DeclP            { 
                                      @1; 
                                      /* pp2: The @1 is needed to convince 
                                       * yacc to set up yylloc. You can remove 
                                       * it once you have other uses of @n*/
                                      Program *program = new Program($1);
                                      // if no errors, advance to next phase
                                      if (ReportError::NumErrors() == 0) 
                                          program->Print(0);
                                    }
          ;

DeclP  :    DeclP Decl        { ($$=$1)->Append($2); }
       |    Decl              { ($$ = new List<Decl*>)->Append($1); }
       ;

Decl      :    VariableDecl               { $$ = $1; } 
          |    FunctionDecl               { $$ = $1; }
          |    ClassDecl                  { $$ = $1; }
          |    InterfaceDecl              { $$ = $1; }
          ;

VariableDecl : Variable ';'               { $$ = $1; }
             ;

VariableDeclA : VariableDeclA VariableDecl       {($$ = $1)->Append($2);}
              |                                  {$$ = new List<VarDecl*>;}
              ;

Variable     : Type T_Identifier         {
                                            Identifier *id = new Identifier(@2, $2);
                                            $$ = new VarDecl(id, $1);
                                         }
             ;

VarPC        : VarPC ',' Variable    {($$ = $1)->Append($3);}
             | Variable                   {($$ = new List<VarDecl *>)->Append($1);} 
             ;

Type     :   T_Int                       { $$ = new Type(*Type::intType); }
         |   T_Double                    { $$ = new Type(*Type::doubleType); }
         |   T_Bool                      { $$ = new Type(*Type::boolType); }
         |   T_String                    { $$ = new Type(*Type::stringType); }
         |   T_Identifier                { Identifier *id = new Identifier(@1, $1); $$ = new NamedType(id); }
         |   Type T_Dims                 { $$ = new ArrayType(@1, $1); }
         ;

FunctionDecl : Type T_Identifier '(' Formals ')' StmtBlock            {
                                                                        Identifier *id = new Identifier(@2, $2);
                                                                        $$ = new FnDecl(id, $1, $4);
                                                                        $$ -> SetFunctionBody($6);
                                                                      }
             | T_Void T_Identifier '(' Formals ')' StmtBlock          {
                                                                        Identifier *id = new Identifier(@2, $2);
                                                                        Type *tvoid = new Type(*Type::voidType);
                                                                        $$ = new FnDecl(id, tvoid, $4);
                                                                        $$ -> SetFunctionBody($6);
                                                                      }
             ;

Formals  :  VarPC                       { $$ = $1; }
         |                              { $$ = new List<VarDecl *>; }
         ;

IndentifierPC : IndentifierPC ',' T_Identifier                         {
                                                                         Identifier *id = new Identifier(@3, $3);
                                                                         ($$ = $1) -> Append(id);
                                                                       }
              | T_Identifier                                           {
                                                                         Identifier *id = new Identifier(@1, $1);
                                                                         ($$ = new List<Identifier *>)->Append(id);
                                                                       }
              ;

ClassDecl : T_Class T_Identifier Extends01 Implements01 '{' FieldA '}'      {
                                                                              Identifier *id = new Identifier(@2, $2);
                                                                              $$ = new ClassDecl(id, $3, $4, $6);
                                                                            }
          ;

Extends01 : T_Extends T_Identifier                                     {
                                                                          Identifier *id = new Identifier(@2, $2);
                                                                          $$ = new NamedType(id);
                                                                       }
          |                                                            { $$ = NULL; }
          ;

Implements01 : T_Implements IndentifierPC                               {
                                                                          $$ = new List<NamedType*>;
                                                                          for (int i = 0; i < $2 -> NumElements(); i++){
                                                                            $$->Append(new NamedType($2 -> Nth(i)));
                                                                          }
                                                                       }
             |                                                         { $$ = new List<NamedType *>; }
             ;

Field     : VariableDecl              { $$ = $1; }
          | FunctionDecl              { $$ = $1; }
          ;

FieldA    : FieldA Field              { ($$ = $1) -> Append($2); }
          |                           { $$ = new List<Decl*>; }
          ;

InterfaceDecl : T_Interface T_Identifier '{' PrototypeA '}'            {
                                                                          Identifier *id = new Identifier(@2, $2);
                                                                          $$ = new InterfaceDecl(id, $4);
                                                                       }
              ;

Prototype     :  Type T_Identifier '(' Formals ')' ';'                 {
                                                                          Identifier *id = new Identifier(@2, $2);
                                                                          $$ = new FnDecl(id, $1, $4);
                                                                       }
              |  T_Void T_Identifier '(' Formals ')' ';'               {
                                                                          Identifier *id = new Identifier(@2, $2);
                                                                          Type *tvoid = new Type(*Type::voidType);
                                                                          $$ = new FnDecl(id, tvoid, $4);
                                                                       }
              ;

PrototypeA    : PrototypeA Prototype                                   { ($$ = $1) -> Append($2); }
              |                                                        { $$ = new List<Decl*>; }
              ;

StmtBlock     : '{' VariableDeclA StmtA '}'                            { $$ = new StmtBlock($2, $3); }
              ;

Stmt          :    Expr01 ';'                                          { $$ = $1; }
              |    IfStmt                                              { $$ = $1; }
              |    WhileStmt                                           { $$ = $1; }
              |    ForStmt                                             { $$ = $1; }
              |    BreakStmt                                           { $$ = $1; }
              |    ReturnStmt                                          { $$ = $1; }
              |    PrintStmt                                           { $$ = $1; }
              |    StmtBlock                                           { $$ = $1; }
              ;

StmtA         :    StmtA Stmt                                          { ($$ = $1)->Append($2); }
              |                                                        { $$ = new List<Stmt*>; }
              ;

IfStmt        :    T_If '(' Expr ')' Stmt Else01                       {$$ = new IfStmt($3, $5, $6); }
              ;

Else01        :    T_Else Stmt                                         { $$ = $2; }
              |                                                        { $$ = NULL; }
              ;

WhileStmt     : T_While '(' Expr ')' Stmt                              { $$ = new WhileStmt($3, $5); }
              ;

ForStmt       : T_For '(' Expr01 ';' Expr ';' Expr01 ')' Stmt          { $$ = new ForStmt($3, $5, $7, $9); }
              ;

ReturnStmt    : T_Return Expr01 ';'                                    { $$ = new ReturnStmt(@1, $2); }
              ;

BreakStmt     : T_Break ';'                                            { $$ = new BreakStmt(@1); }
              ;

PrintStmt     : T_Print '(' ExprPC ')' ';'                             { $$ = new PrintStmt($3); }
              ;

Expr          : LValue '=' Expr                                        { 
                                                                          Operator *op = new Operator(@2, "="); 
                                                                          $$ = new AssignExpr($1, op, $3);
                                                                       }
              | Constant                                               { $$ = $1; }
              | LValue                                                 { $$ = $1; }
              | T_This                                                 { $$ = new This(@1); }
              | Call                                                   { $$ = $1; }
              | '(' Expr ')'                                           { $$ = $2; }
              | Expr '+' Expr                                          { 
                                                                          Operator *op = new Operator(@2, "+"); 
                                                                          $$ = new ArithmeticExpr($1, op, $3);
                                                                       }
              | Expr '-' Expr                                          { 
                                                                          Operator *op = new Operator(@2, "-"); 
                                                                          $$ = new ArithmeticExpr($1, op, $3);
                                                                       }
              | Expr '*' Expr                                          { 
                                                                          Operator *op = new Operator(@2, "*"); 
                                                                          $$ = new ArithmeticExpr($1, op, $3);
                                                                       }
              | Expr '/' Expr                                          { 
                                                                          Operator *op = new Operator(@2, "/"); 
                                                                          $$ = new ArithmeticExpr($1, op, $3);
                                                                       }
              | Expr '%' Expr                                          { 
                                                                          Operator *op = new Operator(@2, "%"); 
                                                                          $$ = new ArithmeticExpr($1, op, $3);
                                                                       }
              | '-' Expr                                               { 
                                                                          Operator *op = new Operator(@1, "-"); 
                                                                          $$ = new ArithmeticExpr(op, $2);
                                                                       }
              | Expr '<' Expr                                          { 
                                                                          Operator *op = new Operator(@2, "<"); 
                                                                          $$ = new RelationalExpr($1, op, $3);
                                                                       }
              | Expr T_LessEqual Expr                                  { 
                                                                          Operator *op = new Operator(@2, "<="); 
                                                                          $$ = new RelationalExpr($1, op, $3);
                                                                       }
              | Expr '>' Expr                                          { 
                                                                          Operator *op = new Operator(@2, ">"); 
                                                                          $$ = new RelationalExpr($1, op, $3);
                                                                       }
              | Expr T_GreaterEqual Expr                               { 
                                                                          Operator *op = new Operator(@2, ">="); 
                                                                          $$ = new RelationalExpr($1, op, $3);
                                                                       }
              | Expr T_Equal Expr                                      { 
                                                                          Operator *op = new Operator(@2, "=="); 
                                                                          $$ = new EqualityExpr($1, op, $3);
                                                                       }
              | Expr T_NotEqual Expr                                   { 
                                                                          Operator *op = new Operator(@2, "!="); 
                                                                          $$ = new EqualityExpr($1, op, $3);
                                                                       }
              | Expr T_And Expr                                        { 
                                                                          Operator *op = new Operator(@2, "&&"); 
                                                                          $$ = new LogicalExpr($1, op, $3);
                                                                       }
              | Expr T_Or Expr                                         { 
                                                                          Operator *op = new Operator(@2, "||"); 
                                                                          $$ = new LogicalExpr($1, op, $3);
                                                                       }
              | '!' Expr                                               { 
                                                                          Operator *op = new Operator(@1, "!"); 
                                                                          $$ = new LogicalExpr(op, $2);
                                                                       }
              | T_ReadInteger '(' ')'                                  { $$ = new ReadIntegerExpr(@1); }
              | T_ReadLine '(' ')'                                     { $$ = new ReadLineExpr(@1); }
              | T_New T_Identifier                                     { 
                                                                          Identifier *id = new Identifier(@2, $2); 
                                                                          NamedType *type = new NamedType(id);
                                                                          $$ = new NewExpr(@1, type);
                                                                       }
              | T_NewArray '(' Expr ',' Type ')'                       { $$ = new NewArrayExpr(@1, $3, $5); }
              ;

Expr01        :   Expr                                                 { $$ = $1; }
              |                                                        { $$ = new EmptyExpr; }
              ;

ExprPC        :   ExprPC ',' Expr                                      { ($$ = $1) -> Append($3); }
              |   Expr                                                 { ($$ = new List<Expr*>) -> Append($1); }
              ;

LValue        :  T_Identifier                                          {
                                                                          Identifier *id = new Identifier(@1, $1);
                                                                          $$ = new FieldAccess(NULL, id);
                                                                       }
              |  Expr '.' T_Identifier                                 {
                                                                          Identifier *id = new Identifier(@3, $3);
                                                                          $$ = new FieldAccess($1, id);
                                                                       }
              |  Expr '[' Expr ']'                                     {
                                                                          $$ = new ArrayAccess(@1, $1, $3);
                                                                       }
              ;

Call          : T_Identifier '(' Actuals ')'                           {
                                                                          Identifier *id = new Identifier(@1, $1);
                                                                          $$ = new Call(@1, NULL, id, $3);
                                                                       }
              | Expr '.' T_Identifier '(' Actuals ')'                  {
                                                                          Identifier *id = new Identifier(@3, $3);
                                                                          $$ = new Call(@2, $1, id, $5);
                                                                       }
              ;

Actuals       : ExprPC                                                 { $$ = $1; }
              |                                                        { $$ = new List<Expr*>; }
              ;

Constant      : T_IntConstant                                        { $$ = new IntConstant(@1, $1); }
              | T_DoubleConstant                                         { $$ = new DoubleConstant(@1, $1); }
              | T_BoolConstant                                           { $$ = new BoolConstant(@1, $1); }
              | T_StringConstant                                         { $$ = new StringConstant(@1, $1); }
              | T_Null                                                 { $$ = new NullConstant(@1); }
              ;

%%

/* The closing %% above marks the end of the Rules section and the beginning
 * of the User Subroutines section. All text from here to the end of the
 * file is copied verbatim to the end of the generated y.tab.c file.
 * This section is where you put definitions of helper functions.
 */

/* Function: InitParser
 * --------------------
 * This function will be called before any calls to yyparse().  It is designed
 * to give you an opportunity to do anything that must be done to initialize
 * the parser (set global variables, configure starting state, etc.). One
 * thing it already does for you is assign the value of the global variable
 * yydebug that controls whether yacc prints debugging information about
 * parser actions (shift/reduce) and contents of state stack during parser.
 * If set to false, no information is printed. Setting it to true will give
 * you a running trail that might be helpful when debugging your parser.
 * Please be sure the variable is set to false when submitting your final
 * version.
 */
void InitParser()
{
   PrintDebug("parser", "Initializing parser");
   yydebug = false;
}