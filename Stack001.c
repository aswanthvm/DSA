#include<stdio.h>
int size = 5;
int stack[5];
int top = -1;
int c = 0;
int ch=0;

void push(int value){
  if(top == size-1){
    printf(" Stack overflow\n");
  }
  else{
    top++;
    stack[top] = value;
    printf("pushed successfully\n");
    
  }
}

void pop(){
  if(top == -1){
    printf("Stack underflow\n");
  }
  else{
    printf("popped value:%d\n",stack[top]);
    top--;
  }
}

void peek(){
  if(top == -1){
    printf("Stack is empty\n");
  }
  else{
  printf("Top element: %d",stack[top]);
  }
}

void display(){
  if(top == -1){
    printf("stack is empty!");
  }
  else{
    for(int i = 0;i<top;i++){
      printf("%d",stack[i]);
    }
    printf("\n");
  }
}

int main(){
  
  while (c==0){
    printf("1 for push\n2 for pop\n3 for peek\n4 for display\n5 for exit\n");
    scanf("%d",&ch);
    if(ch == 1){
      printf("Enter the value:");
      int value;
      scanf("%d",&value);

      push(value);
    }
    

    if(ch == 2)
    {
      pop();
    }
    if(ch == 3){
      peek();
    }
    if(ch == 4){
      display();
    }
    if(ch == 5){
      c++;
    }

  }
  
  
  

  return 0;
}