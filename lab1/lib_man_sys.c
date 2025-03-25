#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the book structure. */
typedef struct {
    char bookId[20]; // 书号
    char title[100]; // 书名
    char author[50]; // 作者
    int stock;       // 库存数量
} Book;

/* Define the linked list node structure. */
typedef struct Node {
    Book book;
    struct Node *next;
} Node;

/* Create new node. */
Node* CreateNode(Book book) {
    Node *p = (Node*)malloc(sizeof(Node));
    p->book = book;
    p->next = NULL;
    return p;
}

/* Insert book information at the end of the linked list. */
void InsertBook(Node **head, Book book) {
    Node *last = CreateNode(book);
    if (*head == NULL) {  /* Easy to make mistake */
        *head = last;
    }
    else {
        Node *temp = *head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = last;
    }
    return ;
}

/* Delete book information according to ISBN number. */
int DeleteBook(Node **head, char bookId[]) {
    Node *p = *head;
    if (*head == NULL) {
        return 1;
    }
    else {
        if (strcmp(p->book.bookId,bookId) == 0) {
            *head = (*head)->next;
            free(p);
            return 0;
        }
        else {
            Node *pr = *head;
            p = p->next;

            if (strcmp(p->book.bookId,bookId) == 0) {
                pr->next = p->next;
                free(p);
                return 0;
            }

            while (strcmp(p->book.bookId,bookId) != 0) {
                if (p->next == NULL) {
                    return 0;
                }
                else {
                    pr = pr->next;
                    p = p->next;
                }
            }

            pr->next = p->next;
            free(p);
            return 0;
        }
    }
}

/*  */
int UpdateStock(Node *head, char bookId[], int newStock) {
    for (Node *p = head; p->next != NULL; p = p->next) {
        if (strcmp(p->book.bookId,bookId) == 0) {
            p->book.stock = newStock;
            return 0;
        }
    }
    return 1;
}

/* Search for book information by ISBN. */
Node* FindBook(Node *head, char bookId[]) {
    for (Node *p = head; p->next != NULL; p = p->next) {
        if (strcmp(p->book.bookId,bookId) == 0) {
            return p;
        }
    }
    return NULL;
}

/* Traverse and output all book information. */
void TraverseList(Node *head) {
    for (Node *p = head; p != NULL; p = p->next) {
        printf("书号：%s,书名：%s,作者：%s,库存：%d",p->book.bookId,p->book.title,p->book.author,p->book.stock);
        if (p->next != NULL) {
            printf("\n");
        }
    }
    return ;
}

int main() {
    Node *head = NULL;
    char bookId_find[4], bookId_update[4], bookId_delete[4];
    int num;
    scanf("%s", bookId_find);
    scanf("%s", bookId_update);
    scanf("%d", &num);
    scanf("%s", bookId_delete);

    /* Add the information of books. */
    Book book1 = {"001", "C程序设计", "谭浩强", 10};
    Book book2 = {"002", "数据结构", "严蔚敏", 5};
    Book book3 = {"003", "算法导论", "Thomas H. Cormen", 3};
    InsertBook(&head, book1);
    InsertBook(&head, book2);
    InsertBook(&head, book3);

    /* Find the imformation of books. */
    Node *bookFind = FindBook(head, bookId_find);
    printf("查找的图书信息：\n");
    printf("书号：%s,书名：%s,作者：%s,库存：%d\n",bookFind->book.bookId,bookFind->book.title,bookFind->book.author,bookFind->book.stock);


    /* Change the stock of books. */
    if (!UpdateStock(head, bookId_update, num)) {
        printf("图书%s的库存数量已修改为%d！\n",bookId_update,num);
    }

    /* Delete the information of the books. */
    if (!DeleteBook(&head, bookId_delete)) {
        printf("图书%s删除成功！\n",bookId_delete);
    }

    /* Traverse and output all book information. */
    printf("图书列表：\n");
    TraverseList(head);

    return 0;
}