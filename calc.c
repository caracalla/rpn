#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

#define MAXOP 100

int main() {
  int type;
  double stored_operand;
  char input_stack[MAXOP];

  type = getop(input_stack);

  while (type != EOF) {
    switch (type) {
      case NUMBER:
        push(atof(input_stack));
        break;

      // mathematical operators
      case '+':
        push(pop() + pop());
        break;
      case '*':
        push(pop() * pop());
        break;
      case '-':
        stored_operand = pop();
        push(pop() - stored_operand);
        break;
      case '/':
        stored_operand = pop();

        if (stored_operand != 0.0) {
          push(pop() / stored_operand);
        } else {
          printf("error: zero division\n");
        }

        break;
      case '%':
        stored_operand = pop();

        if (stored_operand != 0.0) {
          push((int) pop() % (int) stored_operand);
        } else {
          printf("error: zero division in modulus\n");
        }

        break;

      // special commands
      case '?':
        stored_operand = pop();
        printf("top of stack is %.8g\n", stored_operand);
        push(stored_operand);
        break;
      case 'c':
        clear_stack();
        break;

      // final cases
      case '\n':
        printf("\t%.8g\n", pop());
        printf("------------\n");
        break;
      default:
        printf("error: unknown command %s\n", input_stack);
        break;
    }

    type = getop(input_stack);
  }

  return 0;
}
