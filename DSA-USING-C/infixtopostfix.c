#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define MAX_SIZE 100


// Define a stack structure
typedef struct
{
    int top;
    char items[MAX_SIZE];
} Stack;


// Function prototypes
// Function to push an item onto the stack
void push(Stack *stack, char item)
{
    if (stack->top == MAX_SIZE - 1)
    {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->items[++stack->top] = item;
}


// Function to pop an item from the stack
char pop(Stack *stack)
{
    if (stack->top == -1)
    {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->items[stack->top--];
}


// Function to check if a character is an operator
int isoperator(char ch){
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}
int prec(char ch){
    if(ch=='+'||ch=='-'){
        return 1;
    }
    if(ch=='*'||ch=='/'){
        return 2;
    }
    return 0;
}
void intopost(char infix[],char postfix[]){
    Stack s;
    s.top=-1;
    int i,j;
    char ch;

    for (i=0,j=0;infix[i]!='\0';i++){
        if (isalnum(infix[i])){
            postfix[j++]=infix[i];
        }
        else if(infix[i]=='('){
            push(&s,infix[i]);
        }
        else if(infix[i]==')'){
            while(s.top!=-1 && s.items[s.top]!='('){
                postfix[j++]=pop(&s);
            }
            if(s.top!=-1 && s.items[s.top]=='('){
                pop(&s);
            }
        }
        else if(isoperator(infix[i])){
            while(prec(s.items[s.top])>=prec(infix[i])){
                postfix[j++]=pop(&s);
            }
            push(&s,infix[i]);
        }
    }
    while(s.items[s.top]!=-1)
    {
        postfix[j++]=pop(&s);
    }
    postfix[j]='\0';
}
int main (){
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    intopost(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}