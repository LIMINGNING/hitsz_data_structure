#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int original;
    long long mapped;
}NumberPair;

/******************* 排序 *******************/
void sortJumbled(int *mapping, int *nums, int numsSize) {
    int *res_nums = (int *)malloc(numsSize * sizeof(int));
    NumberPair *pairs=(NumberPair *)malloc(numsSize * sizeof(NumberPair));
    
    for (int i = 0; i < numsSize; i++) {
        pairs[i].original = nums[i];

        if (nums[i] == 0) {
            pairs[i].mapped = mapping[0];
            continue;
        }

        char numStr[20];
        sprintf(numStr,"%d",nums[i]);

        char mappedStr[20] = "";
        int len = strlen(numStr);
        for (int j = 0; j < len; j++) {
            int digit = numStr[j] - '0';
            char temp[2]; /* 结尾的\0 */
            sprintf(temp,"%d",mapping[digit]);
            strcat(mappedStr,temp);
        }

        pairs[i].mapped = atoll(mappedStr);
    }

    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = 0; j < numsSize - i - 1; j++) {
            if (pairs[j].mapped > pairs[j+1].mapped) {
                NumberPair temp = pairs[j];
                pairs[j] = pairs[j+1];
                pairs[j+1] = temp;
            }
        }
    }

    for (int i = 0; i < numsSize; i++) {
        res_nums[i] = pairs[i].original;
    }


    for(int i = 0; i < numsSize; i++)
        printf("%d ", res_nums[i]);
    printf("\n");

    free(pairs);
    free(res_nums);
}
/*****************************************************/

/******************* 读取数据 *******************/
void readInput(int **mapping, int **nums, int *numsSize) {
    scanf("%d", numsSize);

    *mapping = (int *)malloc(10 * sizeof(int));
    for (int i = 0; i < 10; i++) {
        scanf("%d", &((*mapping)[i]));
    }

    *nums = (int *)malloc((*numsSize) * sizeof(int));
    for (int i = 0; i < *numsSize; i++) {
        scanf("%d", &((*nums)[i]));
    }
}
/*****************************************************/

int main() {
    int *mapping, *nums, numsSize;
    readInput(&mapping, &nums, &numsSize);
    sortJumbled(mapping, nums, numsSize);

    return 0;
}