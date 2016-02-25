#include <stdio.h>
#include <stdlib.h>
#include "fp.h"

typedef enum {PRINT_OP, ASSIGN_OP, ADD_OP, MULT_OP} operation;

typedef struct l {
   operation op;
   int id1,id2,id3;
   float fpv;
} op_rec;

// shared with the lexer
extern int lineno;
extern float fp_val;

// functions you will implement are:
extern int computeFP(float val);
extern float getFP(int val) ;
extern int addVals(int source1, int source2); 
extern int multVals(int source1, int source2); 


int variable[26];
op_rec current_operation;

int lookahead;


main() {
   lookahead = yylex();
   while (is_id(lookahead) || (lookahead==PRINT)) {line();}
   if (lookahead == 0) printf("input correct\n");
   else printf("input incorrect\n");
}

// Calls the functions you will implement based on the input program

execute_op() {
   switch(current_operation.op) {
     case PRINT_OP :  printf("%c = %f\n",current_operation.id1+'a' -1,
	  	   getFP(variable[current_operation.id1])); 
		break;

      case ASSIGN_OP: 
	variable[current_operation.id1] =  computeFP(current_operation.fpv); 
	break;

	case ADD_OP:
      	variable[current_operation.id1] =
        	addVals(variable[current_operation.id2],
			variable[current_operation.id3]); 
		break;

	case MULT_OP:
      	variable[current_operation.id1] =
       		multVals(variable[current_operation.id2],
			variable[current_operation.id3]); 
		break;
   }
}

// The code below is a recursive descent parser that processes the input
//    program and builds the current_operation information.  If there is a
//    syntax error in the input, the program will halt.  Once a line has
//    been processed, execute_op() is called. 

match(int token) {
   if (token == lookahead)  lookahead = yylex();
   else {
      printf("Unexpected token (%d) line %d\n",token,lineno);
      exit(2);
   }
}

is_id(int token) {
   return ((token > 0) && (token <=26));
}

line() {
   if (lookahead == PRINT) print(); else assign();
   execute_op();
}


print() {
  match(PRINT);
  current_operation.op = PRINT_OP;
  current_operation.id1 = lookahead;
  if (is_id(lookahead)) match(lookahead); 
  else {printf("ID expected line %d\n",lineno); exit(3);}
  match(EOLN);
}

assign() {
  current_operation.id1 = lookahead;
  if (is_id(lookahead)) match(lookahead);
  else {printf("ID expected line %d\n",lineno); exit(3);}
  match(ASSIGN);

  if (lookahead == FLOAT) {
     current_operation.op = ASSIGN_OP;
     current_operation.fpv = fp_val;
     match(FLOAT);
  } else {
    current_operation.id2 = lookahead;
    if (is_id(lookahead)) match(lookahead);
    else {printf("ID expected line %d\n",lineno); exit(3);}
    if (lookahead == PLUS) {
	match(PLUS);
        current_operation.op = ADD_OP;
    } else {
	match(MULT);
        current_operation.op = MULT_OP;
    }
    current_operation.id3 = lookahead;
    if (is_id(lookahead)) match(lookahead);
    else {printf("ID expected line %d\n",lineno); exit(3);}
  }
  match(EOLN);
}


