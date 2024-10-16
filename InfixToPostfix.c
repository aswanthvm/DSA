#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char item){
  if(top >= SIZE-1){
    printf("Stack overflow!");
  }
  else{
    top++;
    stack[top] = item;
  }

}

char pop(){
  char item;

  if(top == -1){
    printf("Stack underflow!");
    exit(1);
  }
  else{
    item = stack[top];
    top--;
    return(item);
  }
}

int isOperator(char symbol){
  if(symbol == '^'||symbol == '*'||symbol == '/'||symbol == '+'||symbol == '-'){
    return 1;
  }
  else{
    return 0;
  }
}

int precedence(char symbol){
  if(symbol == '^') /* exponent operator, highest precedence*/
	{
		return(3);
	}
	else if(symbol == '*' || symbol == '/')
	{
		return(2);
	}
	else if(symbol == '+' || symbol == '-')          /* lowest precedence */
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

void InfixToPostfix(char infixExp[],char postfixExp[]){
  int i, j;
	char item;
	char x;

  push('(');                               /* push '(' onto stack */
	strcat(infixExp,")");                  /* add ')' to infix expression */


  i = 0;
  j = 0;
  item = infixExp[i];

  while(item!='\0'){
    if(item == '('){
      push(item);
    }
    else if(isdigit(item)||isalpha(item)){
      postfixExp[j] = item;
      j++;
    }
    else if(isOperator(item) == 1){
      x = pop();
      while(isOperator(x)==1 && precedence(x)>=precedence(item)){
        postfixExp[j] = x;
        j++;
        x = pop();
      }
      push(x);
      push(item);
    }
    else if(item==')'){
      x=pop();
      while(x!='('){
        postfixExp[j] = x;
        j++;
        x = pop();
      }
    }
    else{
      printf("\nInvalid infix expression");
      getchar();
      exit(1);
    }
    i++;

    item = infixExp[i];

  }

  if(top>0){
    printf("\nInvalid Expression\n");
    exit(1);
  }

  if(top>0){
    printf("\nInvalid infix Expression\n");
    getchar();
    exit(1);
  }

  postfixExp[j] = '\0';

}

int main()
{
	char infix[SIZE], postfix[SIZE];         /* declare infix string and postfix string */

	/* why we asked the user to enter infix expression
	* in parentheses ( )
	* What changes are required in porgram to
	* get rid of this restriction since it is not
	* in algorithm
	* */
	printf("ASSUMPTION: The infix expression contains single letter variables and single digit constants only.\n");
	printf("\nEnter Infix expression : ");
	scanf("%s",infix);

	InfixToPostfix(infix,postfix);                   /* call to convert */
	printf("Postfix Expression: ");
	puts(postfix);                     /* print postfix expression */

	return 0;
}