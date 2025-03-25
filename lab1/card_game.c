#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct {
    ElemType *elem;    /* Base address of the space, the space stores the card's front and back status values, 
                          with 1 representing the front and 0 representing the back. */
    int length;        /* Stores the number of cards. */
    int listsize;      /* Stores the capacity of the space. */
} SqList;

/* 
 * Initialize the list:
 * Allocate space for the cards based on the input size n, and set all cards to face up (1).
 */
void InitList(SqList *L, int n) {
    L->length = n;
    L->listsize = n + 1;
    L->elem = (ElemType*)malloc(sizeof(ElemType)*(n + 1));
    if (!L->elem) {
        printf("Memory allocation failed.\n");
        exit(-1);
    }
    for (int i = 1; i < n + 1; i++) {
        L->elem[i] = 1;  /* All cards are initially face up */
    }
}

/*
 * Destroy the list:
 * Free the dynamically allocated space.
 */
void DestroyList(SqList *L) {
    if (L->elem) {
        free(L->elem);
        L->elem = NULL;
    }
    L->length = 0;
    L->listsize = 0;
}

/* Flip cards based on the given factor k. */
void FlipCards(SqList *L, int k) {
    for (int i = k; i < L->listsize; i += k) {
        L->elem[i] = 1 - L->elem[i];  /* Flip the card: 0 -> 1 or 1 -> 0. */
    }
}

/*
 * Print all face-up cards:
 * Output the card numbers that are face up, separated by spaces.
 */
void PrintFaceUpCards(SqList *L) {
    int sum = 0;
    for (int i = 1; i < L->listsize; i++) {
        if (L->elem[i] == 1) {
            printf("%d ", i);  /* Print the card number i. */
            sum += 1;
        }
    }
    printf("\n");
    printf("%d",sum);
}

int main() {
    int n;
    scanf("%d", &n);   /* Read the total number of cards, e.g., 52 */
    
    /* Initialize the list and set all cards to face up. */
    SqList list;
    InitList(&list, n);

    /* 
     * Starting from the second card, flip every card that is a multiple of k 
     * for k = 2, 3, 4, ..., n.
     */
    for (int k = 2; k < n + 1; k++) {
        FlipCards(&list, k);
    }

    /* Print all face-up cards' numbers. */
    PrintFaceUpCards(&list);

    /* Free the dynamically allocated memory. */
    DestroyList(&list);

    return 0;
}