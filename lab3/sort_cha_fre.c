#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char ch;
    int freq;
} CharFreq;

void swap(CharFreq *a, CharFreq *b) {
    CharFreq temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(CharFreq *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].freq < arr[j + 1].freq) {
                swap(&arr[j], &arr[j + 1]);
            } else if (arr[j].freq == arr[j + 1].freq && arr[j].ch > arr[j + 1].ch) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

char* frequencySort(char* s) {
    int len = strlen(s);

    int freq[256] = {0};
    for (int i = 0; i < len; i++) {
        freq[s[i]]++;
    }

    int count = 0;
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            count++;
        }
    }

    CharFreq *charFreqs = malloc(count * sizeof(CharFreq));
    int index = 0;
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            charFreqs[index].ch = (char)i;
            charFreqs[index].freq = freq[i];
            index++;
        }
    }

    bubbleSort(charFreqs, count);

    char *result = malloc((len + 1) * sizeof(char));
    int pos = 0;
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < charFreqs[i].freq; j++) {
            result[pos++] = charFreqs[i].ch;
        }
    }
    result[pos] = '\0';

    free(charFreqs);
    return result;
}

int main() {
    char s[1000];
    scanf("%s", s);
    
    char* result = frequencySort(s);
    printf("%s\n", result);
    
    free(result);
    return 0;
}