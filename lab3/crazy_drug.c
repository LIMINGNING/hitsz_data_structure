#include <stdio.h>
#include <stdlib.h>

int main() {
    int C, n;
    scanf("%d %d", &C, &n);
    
    int *dp = (int *)malloc((C + 1) * sizeof(int));
    // 初始化dp数组
    for (int j = 0; j <= C; j++) {
        dp[j] = 0;
    }
    
    for (int i = 0; i < n; i++) {
        int ci, wi;
        scanf("%d %d", &ci, &wi);
        
        // 对于每种草药，从ci开始正向遍历到C
        // 注意这里是正向遍历，以允许同一种草药被多次选择
        for (int j = ci; j <= C; j++) {
            if (dp[j] < dp[j - ci] + wi) {
                dp[j] = dp[j - ci] + wi;
            }
        }
    }
    
    printf("%d\n", dp[C]);
    free(dp);
    
    return 0;
}