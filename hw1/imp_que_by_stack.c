#include <stdlib.h>
#include <stdio.h>
#define MaxSize 40   /* Capacity of array. */

#define PUSH 0
#define POP 1
#define GET_TOP 2
#define STACK_EMPTY 3
#define EXIT -1
#define ENQUEUE 4
#define DEQUEUE 5
#define GET_HEAD 6
#define QUEUE_EMPTY 7
#define EXIT -1

typedef int DataType;
typedef struct stack
{
    DataType data[MaxSize];
    int top;
} Stack;

typedef struct queue
{
    Stack *stack_in;
    Stack *stack_out;
} Queue;


/**
 * 初始化一个栈
 * @param s
 */
void InitStack(Stack *s)
{
    s->top = -1;
    return ;
}

/**
 * 向栈插入一个元素
 * @param s 操作栈
 * @param e 操作数
 * @return 成功返回1，否则返回0
 */
int Push(Stack *s, DataType e)
{
    if (s->top == MaxSize - 1) {
        return 0;
    }
    else {
        s->data[++(s->top)] = e;
        return 1;
    }
}

/**
 * 从栈中弹出一个元素
 * @param s 操作栈
 * @param e 接受栈弹出的值
 * @return 成功返回1，否则返回0
 */
int Pop(Stack *s, DataType *e)
{
    if (s->top == -1) {
        return 0;
    }
    else {
        *e = s->data[(s->top)--];
        return 1;
    }
}

/**
 * 获取栈顶元素，不删除该元素
 * @param s 操作栈
 * @param e 接受栈顶元素
 * @return 成功返回1，否则返回0
 */
int GetTop(Stack s, DataType *e)
{
    if (s.top == -1) {
        return 0;
    }
    else {
        *e = s.data[s.top];
        return 1;
    }
}

/**
 * 判断栈是否空，为空返回1，否则返回0
 * @param s
 * @return
 */
int StackEmpty(Stack s)
{
    if (s.top == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

/**
 * 获取栈的一个数组拷贝
 * @param s 操作栈
 * @param seq 栈中元素的一个拷贝
 */
void StackToArray(Stack s, DataType *seq)
{
    int i = 0;
    for (; i <= s.top; i++)
    {
        seq[i] = s.data[s.top-i];
    }
    return ;
}

/**
 * 返回栈已使用长度
 * @param s 操作栈
 * @return 返回栈的长度
 */
int StackLength(Stack s)
{
    return s.top + 1;
}

/**
 * 初始化队列
 * @param q 操作队列
 */
void InitQueue(Queue *q)
{
    q->stack_in = (Stack *)malloc(sizeof(Stack));
    q->stack_out = (Stack *)malloc(sizeof(Stack));
    InitStack(q->stack_in);
    InitStack(q->stack_out);
    return ;
}

/**
 * 获取队列头（不删除元素）
 * @param q 操作队列
 * @param e 接受队列头元素
 * @return 如果成功获取返回1，否则返回0
 */
int GetHead(Queue q, DataType *e)
{
    int temp = 0;
    if (StackEmpty(*(q.stack_in)) && StackEmpty(*(q.stack_out))) {
        return 0;
    }
    else if (!StackEmpty(*(q.stack_in)) && StackEmpty(*(q.stack_out))) {
        while (!StackEmpty(*(q.stack_in))) {
            Pop(q.stack_in,&temp);
            Push(q.stack_out,temp);
        }
        *e = q.stack_out->data[q.stack_out->top];
        return 1;
    }
    else {
        *e = q.stack_out->data[q.stack_out->top];
        return 1;
    }
}

/**
 * 判断队列是否为空
 * @param q 操作队列
 * @return 如果为空返回1，否则返回0
 */
int QueueEmpty(Queue q)
{
    if (q.stack_in->top == -1 && q.stack_out->top == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

/**
 * Enqueue operation, inserts an element into the queue,
 * and needs to handle the case of queue full (both true full and false full).
 * In fact, the size of the seq array used later is the same as the size of the stack.
 * In this case, the distinction between true full and false full is meaningless,
 * as it will always cause an array overflow when accessing seq. 
 * @param q 操作队列
 * @param e 插入的元素
 * @return 如果插入成功返回1，否则返回0
 */
int EnQueue(Queue *q, DataType e)
{
    int temp = 0;
    if (q->stack_in->top != MaxSize - 1) {
        q->stack_in->data[++(q->stack_in->top)] = e;
        return 1;
    }
    else if (q->stack_in->top == MaxSize - 1 && q->stack_out->top != MaxSize - 1) {
        while (q->stack_out->top != MaxSize - 1) {
            Pop(q->stack_in,&temp);
            Push(q->stack_out,temp);
        }
        Push(q->stack_in,e);
        return 1;
    }
    else {
        return 0;
    }
}

/**
 * 出队操作，从队列中取出一个元素
 * @param q 操作队列
 * @param e 接受出队元素
 * @return 如果成功取出返回1，否则返回0
 */
int DeQueue(Queue *q, DataType *e)
{
    int temp = 0;
    if (QueueEmpty(*q)) {
        return 0;
    }
    else if (!StackEmpty(*(q->stack_out))){
        Pop(q->stack_out,e);
        return 1;
    }
    else {
        while (!StackEmpty(*(q->stack_in))) {
            Pop(q->stack_in,&temp);
            Push(q->stack_out,temp);
        }
        Pop(q->stack_out,e);
        return 1;
    }
}

/**
 * 清空队列 操作队列
 * @param Q
 */
void ClearQueue(Queue *Q)
{
    InitStack(Q->stack_in);
    InitStack(Q->stack_out);
    return ;
}

/**
 *
 * @param Q 操作队列
 * @return 返回队列已使用长度
 */
int QueueLength(Queue Q)
{
    return StackLength(*Q.stack_in) + StackLength(*Q.stack_out);
}

/**
 * 获取队列的一个数组拷贝
 * @param q 操作队列
 * @param seq 栈中元素的一个拷贝
 */
void QueueToArray(Queue q, DataType *seq)
{
    int len = QueueLength(q);
    int sp2 = q.stack_out->top;
    int temp = sp2;

    for (int i = 0; i < len; i++) {
        if (sp2 >= 0) {
            seq[i] = q.stack_out->data[sp2];
            sp2--;
        }
        else {
            seq[i] = q.stack_in->data[i - temp - 1];
        }
    }
    return ;
}

void outputStack(Stack *S)
{
    int seq[2 * MaxSize], i = 0;
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


void outputQueue(Queue *Q)
{
    int seq[MaxSize], i = 0;
    int len = QueueLength(*Q);
    QueueToArray(*Q, seq);
    printf("Queue: ");
    for (i = 0; i < len; i++)
    {
        printf("%d", seq[i]);
        if(i<len-1){
            printf(" ");
        }
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    Queue *Q = (Queue *)malloc(sizeof(Queue));
    InitQueue(Q);
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
        case ENQUEUE:
            num = 0;
            scanf("%d", &num);
            while (num > 0)
            {
                num--;
                scanf("%d", &e);
                status = EnQueue(Q, e);
            }
            outputQueue(Q);
            break;
        case DEQUEUE:
            num = 0;
            scanf("%d", &num);
            while (num > 0)
            {
                num--;
                status = DeQueue(Q, &e);
                if(status)
                {
                    printf("DeQueue: %d\n", e);
                    outputQueue(Q);
                }
                else
                {
                    printf("DeQueue failed\n");
                }
            }
            break;
        case GET_HEAD:
            status = GetHead(*Q, &e);
            if(status)
            {
                printf("GetHead: %d\n", e);
                outputQueue(Q);
            }
            else
            {
                printf("GetHead failed\n");
            }
            break;
        case QUEUE_EMPTY:
            status = QueueEmpty(*Q);
            if(status)
            {
                printf("The Queue is Empty\n");
            }
            else
            {
                printf("The Queue is not Empty\n");
                outputQueue(Q);
            }
            break;
        default:
            break;
        }
    }
    free(Q);
    free(S);
    return 0;
}