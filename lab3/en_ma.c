#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000

// 信封结构体
typedef struct {
    int width;
    int height;
} Envelope;

int maxEnvelopes(Envelope* envelopes, int n) {
    for (int i = 0; i < n - 1; i++) {
        Envelope temp;
        for (int j = 0; j < n - i - 1; j++) {
            if (envelopes[j].width > envelopes[j+1].width) {
                temp = envelopes[j];
                envelopes[j] = envelopes[j+1];
                envelopes[j+1] = temp;
            }
            else if (envelopes[j].width == envelopes[j+1].width) {
                if (envelopes[j].height < envelopes[j+1].height) {
                    temp = envelopes[j];
                    envelopes[j] = envelopes[j+1];
                    envelopes[j+1] = temp;
                }
            }
        }
    }

    int dp[MAX_SIZE];
    int maxLength = 0;

    for (int i = 0; i < n; i++) {
        dp[i] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (envelopes[i].height > envelopes[j].height) {
                dp[i] = (dp[i] > dp[j] + 1) ? dp[i] : dp[j] + 1;
            }
            maxLength = (maxLength > dp[i]) ? maxLength : dp[i]; 
        }
    }

    return maxLength;

}

int main() {
    int n;
    scanf("%d", &n);
    
    Envelope* envelopes = (Envelope*)malloc(n * sizeof(Envelope));
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &envelopes[i].width, &envelopes[i].height);
    }
    
    int result = maxEnvelopes(envelopes, n);
    printf("%d\n", result);
    
    free(envelopes);
    return 0;
}