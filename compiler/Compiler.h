

#ifndef COMPILER_H
#define COMPILER_H
#endif

struct node;
typedef struct node* llist;

#ifndef TOKENGETTER_H
#include "TokenGetter.h"
#endif

#ifndef ASTMANAGER_H
#include "ASTManager.h"
#endif

#ifndef INSTRUCTIONWRITING_H
#include "InstructionWriting.h"
#endif

#ifndef MASMANDLINK_H
#include "masmAndLink.h"
#endif

#ifndef VARIABLE_MANAGER_H
#include "VariableManager.h"
#endif

/* main function, compile a txt file into a .exe file */
int Compile(char* inputFileName, char* outputFileName);

/* activate lexer on input code */
int activateLexer(char* inputFileName);

/* extract tokens from lexer result */
llist* extractTokensFromLexResult(char* fileName);

/* creates a variable list from token list */
VariableList* createVariableList(llist* tokenList);

void printTokenList(llist* tokenList);

void printVariaballsList(VariableList* varList);



