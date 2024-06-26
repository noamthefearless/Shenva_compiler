#pragma once


#include "llist.h"
struct Token;
#ifndef AST_H


#define AST_H

enum { LEAF=0,ONE_CHILD_NODE=1,TWO_CHILDREN_NODE=2};


// when handling with tokenless nodes
enum {ONLY_CHILD = 0, NEXT=0, EXPRESSION = 1};

// 'if' / 'while' nodes
enum {CONDITION = 0 , CODE = 1, ELSE = 2, OPPERATION_TO_DO_EVERY_ITER = 2};

// function nodes
enum {FUNC_ID = 0, CODE_BLOCK = 1};

struct ASTNode
{
	Token* token;
	struct ASTNode** children;
	
} typedef ASTNode;


ASTNode* createNewASTnode(Token* token);
void deleteAST(ASTNode* head);

int isOneChildNode(enum TokenTypes token);
int isTwoChildNode(enum TokenTypes token);
int isThreeChildNode(enum TokenTypes token);

int isPrintToken(Token token);
int isVarDeclerationToken(Token token);
int isPointerVariableToken(Token token);
int isNormalVariableToken(Token token);
int isExpressionToken(Token token);
int isConditionOrLoopToken(Token token);
int isBooleanExpressionToken(enum TokenTypes token);





#endif