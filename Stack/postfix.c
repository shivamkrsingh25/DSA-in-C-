#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
struct Stack{
  int top;
  unsigned capacity;
  int* array;};
struct Stack* createStack( unsigned capacity ){
  struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
  if (!stack) return NULL;
  stack->top = -1;
  stack->capacity = capacity;
  stack->array = (int*) malloc (stack->capacity * sizeof(int));
  if (!stack->array) return NULL;
  return stack;
}
int isEmpty(struct Stack* stack){
  return stack->top == -1;
}
char peek(struct Stack* stack){
  return stack->array[stack->top];
}
char pop(struct Stack* stack){
  if(!isEmpty(stack))
        return stack->array[stack->top--];
  return '$';
}
void push(struct Stack* stack, int op) {
  stack->array[++stack->top] = op;
}
int evaluatePostfix(char* exp){
  struct Stack* stack = createStack(strlen(exp));
  if (!stack) return -1;
  for(int i=0; exp[i]; i++){
    if (isdigit(exp[i])) push(stack, exp[i] - '0');
    else{
      int num1 = pop(stack);
      int num2 = pop(stack);
      switch (exp[i])
      { case '+': push(stack, num2 + num1); break;
        case '-': push(stack, num2 - num1); break;
        case '*': push(stack, num2 * num1); break;
        case '/': push(stack, num2 / num1); break;
      }
    }
  }
  return pop(stack);
}
int main() {
  char *exp;
  printf("Enter postfix expression : ");
  gets(exp);
  printf("postfix expression is : %s\n",exp);
  printf("postfix evaluation : %d", evaluatePostfix(exp)); 
  return 0;
}
