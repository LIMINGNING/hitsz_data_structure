#include <stdlib.h>
#include <stdio.h>
#define MaxSize 40   /* Array capacity. */

#define PUSH 0
#define POP 1
#define GET_TOP 2
#define STACK_EMPTY 3
#define EXIT -1

typedef int DataType;
typedef struct
{
    DataType data[MaxSize];
    int top; /* Top of stack pointer. */
} Stack;     /* Stack type. */     

/**
 * Initialize a stack.
 * @param S
 */
void InitStack(Stack *s)
{
    s->top = -1;
    return ;
}

/**
 * Insert an element into the stack.
 * @param S Operation stack.
 * @param e Operands. 
 * @return Return 1 on success, otherwise return 0.
 */
int Push(Stack *s, DataType e)
{
    if (s->top == MaxSize - 1) {
        return 0; /* Stack is full. */
    }
    else {
        s->top++;
        s->data[s->top] = e; 
        return 1; /* Insertion successful. */
    }
}

/**
 * Pop an element from Stack.
 * @param S Operation Stack.
 * @param e Accept the value popped from the stack.
 * @return Return 1 on success, otherwise return 0.
 */
int Pop(Stack *S, DataType *e)
{
    if (S->top == -1) {
        return 0; /* Stack is empty. */
    }
    else {
        *e = S->data[(S->top)--];
        return 1;
    }
}

/**
 * Get the top element of the stack without deleting the element.
 * @param S Operation stack.
 * @param e Accept the top element.
 * @return Return 1 on success, otherwise return 0.
 */
int GetTop(Stack S, DataType *e)
{
    if (S.top == -1) {
        return 0; /* Stack is empty. */
    }
    else {
        *e = S.data[S.top];
        return 1;
    }
}

/**
 * Check if the stack is empty, return 1 if it is empty, otherwise return 0.
 * @param S Opeatation stack.
 * @return  1 for empty, 0 for other.
 */
int StackEmpty(Stack S)
{
    if (S.top == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

/**
 * Get a copy of an array from the stack.
 * @param S Operation stack.
 * @param seq A copy of the elements in the stack.
 */
void StackToArray(Stack S, DataType *seq)
{
    int i = 0;
    for (; i <= S.top; i++)
    {
        seq[i] = S.data[S.top-i]; /* From top of stack to bottom. */
    }
}

/**
 * Return stack used length.
 * @param S Operation stack.
 * @return Return length of stack.
 */
int StackLength(Stack S)
{
    return S.top + 1;
}


void outputStack(Stack *S)
{
    int seq[MaxSize], i = 0;
    StackToArray(*S, seq);
    printf("Stack: ");
    for (i = 0; i < StackLength(*S); i++)
    {
        printf("%d", seq[i]);
        if(i<StackLength(*S)-1){
            printf(" ");
        }
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    Stack *S = (Stack *)malloc(sizeof(Stack));
    InitStack(S);
    int mode, num, e, status;
    while (scanf("%d", &mode))
    {
        if (mode == EXIT)
        {
            break;
        }
        switch (mode)
        {
        case PUSH:
            num = 0;
            scanf("%d", &num);
            while (num > 0)
            {
                num--;
                scanf("%d", &e);
                status = Push(S, e);
            }
            outputStack(S);
            break;
        case POP:
            num = 0;
            scanf("%d", &num);
            while (num > 0)
            {
                num--;
                status = Pop(S, &e);
                if(status)
                {
                    printf("Pop: %d\n", e);
                    outputStack(S);
                }
                else
                {
                    printf("Pop failed\n");
                }
            }
            break;
        case GET_TOP:
            status = GetTop(*S, &e);
            if(status)
            {
                printf("GetTop: %d\n", e);
                outputStack(S);
            }
            else
            {
                printf("GetTop failed\n");
            }
            break;
        case STACK_EMPTY:
            status = StackEmpty(*S);
            if(status)
            {
                printf("The Stack is Empty\n");
            }
            else
            {
                printf("The Stack is not Empty\n");
                outputStack(S);
            }
            break;
        default:
            break;
        }
    }
    free(S);
    return 0;
}