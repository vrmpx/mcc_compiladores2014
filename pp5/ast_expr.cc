/* File: ast_expr.cc
 * -----------------
 * Implementation of expression node classes.
 *
 * VM:
 * La mayor parte de la logica de esta clase se basa en el codigo de  
 * ManuZhang <OwenZhang1990@gmail.com> https://github.com/manuzhang
 * Codigo utilizado con previa autorizacion.
 */
#include "ast_expr.h"
#include "ast_type.h"
#include "ast_decl.h"
#include <string.h>
#include "codegen.h"
#include "errors.h"
#include "tac.h"

#include <stdio.h>
 using namespace std;

bool Expr::HasBase() {
  if(this->GetBase()){
      return true;
  } else {
    Decl *decl = this->FindDecl(this->GetField());
    if (decl) {
      if (decl->GetEnclosFunc(decl) == NULL && decl->GetEnclosClass(decl) != NULL)
            return true;
    }
  }
  return false;
}


ClassDecl* GetClassFromScope(Node* node){
    ClassDecl* c;
    while(node != NULL){
        if((c = dynamic_cast<ClassDecl*>(node)) != NULL)
            return c;
        node = node->GetParent();
    }
    return NULL;
}

Decl* FindDeclInClass(ClassDecl* classDecl, Identifier* field){
    Scope *s = classDecl->GetScope();

    if(s == NULL)
        return NULL;
    
    //Buscamos la definicion de la funcion en su clase
    return s->Lookup(field);
}

bool Expr::IsBool() {
    return GetType()->IsEquivalentTo(Type::boolType);
}

IntConstant::IntConstant(yyltype loc, int val) : Expr(loc) {
    value = val;
}

Location *IntConstant::Emit() {
  FnDecl *fndecl = this->GetEnclosFunc(this);
  if (fndecl) {
      int localOffset = fndecl->UpdateFrame();
      return Program::cg->GenLoadConstant(this->value, localOffset);
  }

  return NULL;
}

Type* IntConstant::GetType() {
    return Type::intType;
}

DoubleConstant::DoubleConstant(yyltype loc, double val) : Expr(loc) {
    value = val;
}

Type* DoubleConstant::GetType() {
    return Type::doubleType;
}

BoolConstant::BoolConstant(yyltype loc, bool val) : Expr(loc) {
    value = val;
}

Type* BoolConstant::GetType() {
    return Type::boolType;
}

Location *BoolConstant::Emit() {
  FnDecl *fndecl = this->GetEnclosFunc(this);
  if (fndecl)
    {
      int localOffset = fndecl->UpdateFrame();
      return Program::cg->GenLoadConstant(static_cast<int>(this->value), localOffset);
    }

  return NULL;

}

StringConstant::StringConstant(yyltype loc, const char *val) : Expr(loc) {
    Assert(val != NULL);
    value = strdup(val);
}

Type* StringConstant::GetType() {
    return Type::stringType;
}

Location *StringConstant::Emit() {
  FnDecl *fndecl = this->GetEnclosFunc(this);
  if (fndecl)
    {
      int localOffset = fndecl->UpdateFrame();
      return Program::cg->GenLoadConstant(this->value, localOffset);
    }

  return NULL;
}

Type* NullConstant::GetType() {
    return Type::nullType;
}

Location *NullConstant::Emit() {
  FnDecl *fndecl = this->GetEnclosFunc(this);
  int localOffset = 0;
  if (fndecl)
    {
      localOffset = fndecl->UpdateFrame();
      return Program::cg->GenLoadConstant(0, localOffset);
    }
  return NULL;
}

Operator::Operator(yyltype loc, const char *tok) : Node(loc) {
    Assert(tok != NULL);
    strncpy(tokenString, tok, sizeof(tokenString));
}

void Operator::SetToken(const char *tok) {
  Assert(tok != NULL);
  strncpy(this->tokenString, tok, sizeof(this->tokenString));
}

CompoundExpr::CompoundExpr(Expr *l, Operator *o, Expr *r) 
  : Expr(Join(l->GetLocation(), r->GetLocation())) {
    Assert(l != NULL && o != NULL && r != NULL);
    (op=o)->SetParent(this);
    (left=l)->SetParent(this); 
    (right=r)->SetParent(this);
}

CompoundExpr::CompoundExpr(Operator *o, Expr *r) 
  : Expr(Join(o->GetLocation(), r->GetLocation())) {
    Assert(o != NULL && r != NULL);
    left = NULL; 
    (op=o)->SetParent(this);
    (right=r)->SetParent(this);
}

void CompoundExpr::Check() {
    if(left!=NULL)
        left->Check();
    right->Check();
}

Location *ArithmeticExpr::Emit() {
  if (right) {

      FnDecl *fndecl = this->GetEnclosFunc(this);
      if (fndecl) {
        const char *token = op->GetToken();
        if (left) {
            int localOffset = fndecl->UpdateFrame();
            return Program::cg->GenBinaryOp(token, this->left->Emit(), this->right->Emit(), localOffset);
        } else {
            int localOffset = fndecl->UpdateFrame();
            Location *zero = Program::cg->GenLoadConstant(0, localOffset);
            localOffset = fndecl->UpdateFrame();
            return Program::cg->GenBinaryOp(token, zero, this->right->Emit(), localOffset);
        }
      }
    }

  return NULL;
}

Location *RelationalExpr::Emit() {
  if (left && right) {
      FnDecl *fndecl = this->GetEnclosFunc(this);
      if (fndecl)  {
          const char *token = op->GetToken();
          Location *left_loc = left->Emit();
          Location *right_loc = this->right->Emit();
          if (!strcmp(token, "<")) {
              int localOffset = fndecl->UpdateFrame();
              return Program::cg->GenBinaryOp(token, left_loc, right_loc, localOffset);
          } else if (!strcmp(token, ">")) {
            int localOffset = fndecl->UpdateFrame();
            return Program::cg->GenBinaryOp("<", right_loc, left_loc, localOffset);
          }
          else if (!strcmp(token, "<=")) {
              int localOffset = fndecl->UpdateFrame();
              Location *new_left = Program::cg->GenBinaryOp("<", left_loc, right_loc, localOffset);
              localOffset = fndecl->UpdateFrame();
              Location *new_right = Program::cg->GenBinaryOp("==", left_loc, right_loc, localOffset);
              localOffset = fndecl->UpdateFrame();
              return Program::cg->GenBinaryOp("||", new_left, new_right, localOffset);
          } else if (!strcmp(token, ">=")) {
              int localOffset = fndecl->UpdateFrame();
              Location *new_left = Program::cg->GenBinaryOp("<", right_loc, left_loc, localOffset);
              localOffset = fndecl->UpdateFrame();
              Location *new_right = Program::cg->GenBinaryOp("==", left_loc, right_loc, localOffset);
              localOffset = fndecl->UpdateFrame();
              return Program::cg->GenBinaryOp("||", new_left, new_right, localOffset);
          }
        }
    }

  return NULL;
}

Location *EqualityExpr::Emit() {
  if (this->left && this->right)
    {
      int localOffset = 0;
      FnDecl *fndecl = this->GetEnclosFunc(this);
      if (fndecl) // local variable
        {
      if (this->left->GetType() == Type::stringType && this->right->GetType() == Type::stringType)
        {
          localOffset = fndecl->UpdateFrame();
          return Program::cg->GenBuiltInCall(StringEqual, this->left->Emit(), this->right->Emit(), localOffset);
        }
      else
        {
          const char *token = op->GetToken();

              Location *left_loc = this->left->Emit();
              Location *right_loc = this->right->Emit();

          if (!strcmp(token, "!="))
            {
              int localOffset = fndecl->UpdateFrame();
              Location *less = Program::cg->GenBinaryOp("<", left_loc, right_loc, localOffset);

              localOffset = fndecl->UpdateFrame();
              Location *greater = Program::cg->GenBinaryOp("<", right_loc, left_loc, localOffset);

              localOffset = fndecl->UpdateFrame();
              return Program::cg->GenBinaryOp("||", less, greater, localOffset);
            }
          else
            {
              int localOffset = fndecl->UpdateFrame();
              return Program::cg->GenBinaryOp(token, left_loc, right_loc, localOffset);
            }
        }
        }
    }

  return NULL;

}

Location *LogicalExpr::Emit() {
  if (this->right) {
      FnDecl *fndecl = this->GetEnclosFunc(this);

      if (fndecl) {
          if (this->left) {
              int localOffset = fndecl->UpdateFrame();
              return Program::cg->GenBinaryOp(op->GetToken(), this->left->Emit(), this->right->Emit(), localOffset);
          } else {
              int localOffset = fndecl->UpdateFrame();
              Location *one = Program::cg->GenLoadConstant(1, localOffset);
              localOffset = fndecl->UpdateFrame();
              return Program::cg->GenBinaryOp("-", one, this->right->Emit(), localOffset);
          }
       }
    }

  return NULL;
}

Location *AssignExpr::Emit() {
  int localOffset = 0;
  if (this->left && this->right)
    {
      if (typeid(*this->right) == typeid(ReadLineExpr)) // make a copy; otherwise could be changed by following call
        {

        }

      Location *right_loc = this->right->Emit();
      if (this->left->HasBase())
        {
          Location *left_loc = this->left->StoreEmit();
          Program::cg->GenStore(left_loc, right_loc);
          return left_loc;
        }
      else
        {
          Location *left_loc = this->left->Emit();
          Program::cg->GenAssign(left_loc, right_loc);
          return left_loc;
        }
    }

  return NULL;
}


Type* This::GetType() {
    ClassDecl* c = GetClassFromScope(this);
    if(c != NULL)
        return c->GetType();
    return Type::errorType;
}

Location *This::Emit() {
  FnDecl *fndecl = this->GetEnclosFunc(this);
  if (fndecl)
    return fndecl->GetFormals()->Nth(0)->GetID()->GetMemLoc();
  return NULL;
}

ArrayAccess::ArrayAccess(yyltype loc, Expr *b, Expr *s) : LValue(loc) {
    (base=b)->SetParent(this); 
    (subscript=s)->SetParent(this);
}

void ArrayAccess::Check() {
    base->Check();
    subscript->Check();
}

Type* ArrayAccess::GetType() {
   ArrayType* arrType = dynamic_cast<ArrayType*>(base->GetType()); 
   if(arrType)
        return arrType->GetElemType();
   return base->GetType();
}

const char* ArrayAccess::GetTypeName() {
  return "";
}

Location *ArrayAccess::Emit() {
  Location *address = this->StoreEmit();
  int localOffset;
  FnDecl *fndecl = this->GetEnclosFunc(this);
  if (fndecl)
    {
      localOffset = fndecl->UpdateFrame();
      return Program::cg->GenLoad(address, localOffset);
    }
  return NULL;
}

Location *ArrayAccess::StoreEmit() {
  if (this->base && this->subscript) {
      int localOffset = 0;
      FnDecl *fndecl = this->GetEnclosFunc(this);
      if (fndecl) {
          // access array size
          Location *base_loc = this->base->Emit();
      
          localOffset = fndecl->UpdateFrame();
          Location *size = Program::cg->GenLoad(base_loc, localOffset);

          // whether out of bounds
          localOffset = fndecl->UpdateFrame();

          Location *subs = this->subscript->Emit();
          Location *test_max = Program::cg->GenBinaryOp("<", subs, size, localOffset);
          localOffset = fndecl->UpdateFrame();
          Location *minus = Program::cg->GenLoadConstant(-1, localOffset);

          localOffset = fndecl->UpdateFrame();
          Location *test_min = Program::cg->GenBinaryOp("<", minus, subs, localOffset);

          char *label_0 = Program::cg->NewLabel();
          char *label_1 = Program::cg->NewLabel();

          localOffset = fndecl->UpdateFrame();
          Location *test = Program::cg->GenBinaryOp("&&", test_min, test_max, localOffset);

          Program::cg->GenIfZ(test, label_0);

          // access the element
          localOffset = fndecl->UpdateFrame();
          Location *varsize_loc = Program::cg->GenLoadConstant(CodeGenerator::VarSize, localOffset);
          localOffset = fndecl->UpdateFrame();
          Location *tmp = Program::cg->GenBinaryOp("*", subs, varsize_loc, localOffset);
          localOffset = fndecl->UpdateFrame();
          Location *offset_loc = Program::cg->GenBinaryOp("+", tmp, varsize_loc, localOffset);
          Location *address = Program::cg->GenBinaryOp("+", base_loc, offset_loc, localOffset);

          Program::cg->GenGoto(label_1);

          // report error
          // Program::cg->GenLabel(label_0);
          // const char *error_msg = "Decaf runtime error: Array script out of bounds";
          // Program::PrintError(error_msg, fndecl);

          Program::cg->GenLabel(label_1);

          return address;
        }
    }

  return NULL;
}

FieldAccess::FieldAccess(Expr *b, Identifier *f) 
  : LValue(b? Join(b->GetLocation(), f->GetLocation()) : *f->GetLocation()) {
    Assert(f != NULL); // b can be be NULL (just means no explicit base)
    base = b; 
    if (base) base->SetParent(this); 
    (field=f)->SetParent(this);
}

void FieldAccess::Check() {
    if(base!=NULL)
        base->Check();
    field->Check();

    type = this->GetType();
}

Type* FieldAccess::GetType() {
    if ( base != NULL) {
        //Obtenemos la clase de base
        NamedType* ntype = dynamic_cast<NamedType*>(base->GetType());
        if (ntype != NULL){

            // cout << "FieldAccess::"<<field->GetName() << "::Check With Base " << ntype->GetId() << endl;

            ClassDecl* d = dynamic_cast<ClassDecl*>(this->FindDecl(ntype->GetId()));
            if ( d != NULL ){
                //Buscamos la declaracion del campo en la clase
                Decl* lookup = FindDeclInClass(d, field);
                if ( lookup != NULL ){
                    return lookup->GetType();
                }
            }
        }
        return Type::errorType;
    } else {
        Decl* d = this->FindDecl(field);
        if(d == NULL || dynamic_cast<VarDecl*>(d) == NULL)
            return Type::errorType;

        return d->GetType();
    }
}

Location *FieldAccess::Emit() {
  FnDecl *fndecl = this->GetEnclosFunc(this);
  int localOffset = 0;

  if (fndecl){
      if (this->base) {
         Location *base_loc = this->base->Emit();

          ClassDecl *classdecl = NULL;
          
          if (typeid(*this->base) == typeid(This))
            classdecl = this->GetEnclosClass(this);
          else {
              NamedType *ntype = dynamic_cast<NamedType*>(base->GetType());
              Decl *decl = this->FindDecl(ntype->GetId());
              if (decl)
                classdecl = dynamic_cast<ClassDecl*>(decl);
          }

          if (classdecl)
            return this->LoadField(base_loc, classdecl, fndecl);
      
      } else {
          Decl *decl = this->FindDecl(field->GetID());
          if (decl) {
              ClassDecl *classdecl = decl->GetEnclosClass(decl);
              if ((decl->GetEnclosFunc(decl) != NULL) || classdecl == NULL) 
                  return decl->GetID()->GetMemLoc();
              else {
                  Location *base_loc = fndecl->GetFormals()->Nth(0)->GetID()->GetMemLoc();
                  return this->LoadField(base_loc, classdecl, fndecl);
              }
          }
        }
    }
  return NULL;
}


Location *FieldAccess::StoreEmit() {
  FnDecl *fndecl = this->GetEnclosFunc(this);
  int localOffset = 0;

  if (fndecl) {
      if (this->base) {
          Location *base_loc = this->base->Emit();

          ClassDecl *classdecl = NULL;
          if (typeid(*this->base) == typeid(This)){
            classdecl = this->GetEnclosClass(this);
         } else {
              NamedType *ntype = dynamic_cast<NamedType*>(base->GetType());
              Decl *decl = this->FindDecl(ntype->GetID());
              if (decl)
                classdecl = dynamic_cast<ClassDecl*>(decl);

         }
          if (classdecl)
            return this->StoreField(base_loc, classdecl, fndecl);
        } else {
          Decl *decl = this->FindDecl(field->GetID());
          if (decl) {
              ClassDecl *classdecl = decl->GetEnclosClass(decl);
              if (decl->GetEnclosFunc(decl) != NULL
                  || classdecl == NULL) {
                return decl->GetID()->GetMemLoc();
              } else {
                Location *base_loc = fndecl->GetFormals()->Nth(0)->GetID()->GetMemLoc();
                return this->StoreField(base_loc, classdecl, fndecl);
              }
          }
      }
    }
  return NULL;
}

Location *FieldAccess::LoadField(Location *base_loc, ClassDecl *classdecl, FnDecl *fndecl) {
  if (classdecl) {
      int localOffset = 0;
      List<const char *> *fieldlabels = classdecl->GetFieldLabels();
      for (int i = 0; i < fieldlabels->NumElements(); i++) {
          if (!strcmp(fieldlabels->Nth(i), this->field->GetName())) {
              localOffset = fndecl->UpdateFrame();
              return Program::cg->GenLoad(base_loc, localOffset, (i + 1) * CodeGenerator::VarSize);
            }
        }
    }
  return NULL;
}

Location *FieldAccess::StoreField(Location *base_loc, ClassDecl *classdecl, FnDecl *fndecl) {
  if (classdecl) {
      int localOffset = 0;
      List<const char *> *fieldlabels = classdecl->GetFieldLabels();
      for (int i = 0; i < fieldlabels->NumElements(); i++) {
          if (!strcmp(fieldlabels->Nth(i), this->field->GetName())) {
              localOffset = fndecl->UpdateFrame();
              Location *offset_loc = Program::cg->GenLoadConstant((i + 1) * CodeGenerator::VarSize, localOffset);
              localOffset = fndecl->UpdateFrame();
              return Program::cg->GenBinaryOp("+", base_loc, offset_loc, localOffset);
          }
      }
  }
  return NULL;
}



Call::Call(yyltype loc, Expr *b, Identifier *f, List<Expr*> *a) : Expr(loc)  {
    Assert(f != NULL && a != NULL); // b can be be NULL (just means no explicit base)
    base = b;
    if (base) base->SetParent(this);
    (field=f)->SetParent(this);
    (actuals=a)->SetParentAll(this);
}

void Call::Check() {
    if(base!= NULL)
        base->Check();

    field->Check();
    actuals->CheckAll();

    type = this->GetType();

}

Type* Call::GetType() {

    if (base != NULL){
         //Obtenemos la clase de base
        NamedType* ntype = dynamic_cast<NamedType*>(base->GetType());
        if (ntype != NULL){

            // cout << "FieldAccess::"<<field->GetName() << "::Check With Base " << ntype->GetId() << endl;

            ClassDecl* d = dynamic_cast<ClassDecl*>(this->FindDecl(ntype->GetId()));
            if ( d != NULL ){
                //Buscamos la declaracion del campo en la clase
                Decl* lookup = FindDeclInClass(d, field);
                if ( lookup != NULL ){
                    return lookup->GetType();
                }
            }
        }
    } else { 
        Decl* d = FindDecl(field);
        FnDecl* fn = dynamic_cast<FnDecl*>(d);
        if(fn != NULL) {
            return fn->GetType();
        }
    }

    return Type::errorType;

}

Location *Call::Emit() {
  Location *rtvalue = NULL;
  int localOffset = 0;

  FnDecl *fndecl = this->GetEnclosFunc(this);
  if (fndecl) {
      if (this->base)  {
      // arr.length()
      if (typeid(*this->base->GetType()) == typeid(ArrayType) && !strcmp(this->field->GetName(), "length"))  {
          localOffset = fndecl->UpdateFrame();
          return Program::cg->GenLoad(this->base->Emit(), localOffset);
        }

      Location *base_loc = this->base->Emit();

      Decl *decl = NULL;

      const char *classname = this->base->GetTypeName();
      if ((decl = Program::sym_table->Lookup(classname)) != NULL)
        rtvalue = RuntimeCall(base_loc, dynamic_cast<ClassDecl*>(decl), fndecl);

     
      return rtvalue;
    } else {
      Decl *decl = this->FindDecl(field->GetID());
      if (decl && typeid(*decl) == typeid(FnDecl)) {
          ClassDecl *classdecl = decl->GetEnclosClass(decl); // could be base class
          if (classdecl) {
              Location *base_loc = fndecl->GetFormals()->Nth(0)->GetID()->GetMemLoc();
              rtvalue = RuntimeCall(base_loc, this->GetEnclosClass(this), fndecl);
        } else {
          int args_num = PushArguments(this->actuals);
          FnDecl *call = dynamic_cast<FnDecl*>(decl);
          if (decl->GetType() == Type::voidType) {
              rtvalue = Program::cg->GenLCall(call->GetLabel(), false);
            } else  {
              localOffset = fndecl->UpdateFrame();
              rtvalue = Program::cg->GenLCall(call->GetLabel(), true, localOffset);
            }
          Program::cg->GenPopParams(args_num * CodeGenerator::VarSize);
        }
          return rtvalue;
        }
    }
    }
  return NULL;
}

int Call::PushArguments(List<Expr*> *args) {
  int args_num = 0;
  if (args) {
      args_num = args->NumElements();
      //for (int i = 0; i < args_num; i++)
      for (int i = args_num - 1; i >= 0; i--) {
        Expr *arg = args->Nth(i);
        Program::cg->GenPushParam(arg->Emit());
      }
  }
  return args_num;
}

Location *Call::RuntimeCall(Location *base_loc, ClassDecl *classdecl, FnDecl *fndecl) {
  Location *func = NULL, *rtvalue = NULL;

  int localOffset;

  localOffset = fndecl->UpdateFrame();
  Location *vtable = Program::cg->GenLoad(base_loc, localOffset);

  List<const char *> *methodlabels = classdecl->GetMethodLabels();
  for (int i = 0; i < methodlabels->NumElements(); i++) {
      const char *methodname = strchr(methodlabels->Nth(i), '.') + 1;
      if (!strcmp(methodname, this->field->GetName())) {
        localOffset = fndecl->UpdateFrame();
        func = Program::cg->GenLoad(vtable, localOffset, i * CodeGenerator::VarSize);
        break;
      }
  }

  // push arguments and the default "this"
  int args_num = PushArguments(this->actuals);
  Program::cg->GenPushParam(base_loc);

  if (func){
      if (this->GetType() == Type::voidType) {
        rtvalue = Program::cg->GenACall(func, false);
      } else {
        localOffset = fndecl->UpdateFrame();
        rtvalue = Program::cg->GenACall(func, true, localOffset);
      }
  }
  Program::cg->GenPopParams((args_num + 1) * CodeGenerator::VarSize);
  return rtvalue;
}

NewExpr::NewExpr(yyltype loc, NamedType *c) : Expr(loc) { 
  Assert(c != NULL);
  (cType=c)->SetParent(this);
}

NewArrayExpr::NewArrayExpr(yyltype loc, Expr *sz, Type *et) : Expr(loc) {
    Assert(sz != NULL && et != NULL);
    (size=sz)->SetParent(this); 
    (elemType=et)->SetParent(this);
}

void NewArrayExpr::Check() {
    size->Check();
    elemType->Check();
}

Type* NewArrayExpr::GetType() {
    return new ArrayType(elemType);
}

Type* ReadLineExpr::GetType() {
    return Type::stringType;
}

Type* ReadIntegerExpr::GetType() {
    return Type::intType;
}
