#include <stdio.h>
#define max 5
typedef struct stack
{
    int top;
    int arr[max];
    int size;
} stack;
void init(stack *s)
{
    s->top = -1;
    s->size = 0;
}
void push(stack *s, int x)
{
    if (s->top == max - 1)
    {
        printf("Stack is full\n");
        return;
    }
    s->top++;
    s->arr[s->top] = x;
    s->size++;
    for (int i = 0; i <= s->top; i++)
    {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}
void pop(stack *s)
{
    if (s->top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    s->top--;
    s->size--;
    for (int i = 0; i <= s->top; i++)
    {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}
int peek(stack *s)
{
    if (s->top == -1)
    {
        printf("Stack is empty\n");
        return -1;
    }
    return s->arr[s->top];
}
int getSize(stack *s)
{
    return s->size;
}


int main()
{
    stack s;
    init(&s);
    push(&s, 10);
    push(&s, 20);
    // push(&s, 30);
    // push(&s, 40);
    printf("%d\n", peek(&s));
    printf("%d\n", getSize(&s));
    // push(&s, 50);
    // push(&s, 60);
    // pop(&s);
    // pop(&s);
    // pop(&s);
    // pop(&s);
    // pop(&s);
    // pop(&s);
}
