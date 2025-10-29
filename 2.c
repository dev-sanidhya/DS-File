#include <stdio.h>
#define SIZE 5

int stack[SIZE], top=-1;

void push(int x){
    if(top==SIZE-1) printf("Stack Overflow\n");
    else {
        stack[++top]=x;
        printf("Pushed %d\n",x);
    }
}

void pop(){
    if(top==-1) printf("Stack Underflow\n");
    else printf("Popped %d\n",stack[top--]);
}

void traverse(){
    if(top==-1) printf("Stack Empty\n");
    else {
        printf("Stack: ");
        for(int i=top;i>=0;i--) printf("%d ",stack[i]);
        printf("\n");
    }
}

int main(){
    push(10);
    push(20);
    push(30);
    traverse();
    pop();
    traverse();
    push(40);
    traverse();
    return 0;
}