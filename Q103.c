#include <stdio.h>
#include <stdlib.h>

static int arr[] = {1, 1, 2, 3, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 6, 6};
static int arrSize = 17;
void func(int *arr, int* arrSize)
{
    int i;
    int *B = malloc(sizeof(int) * *arrSize);
    int count = 0;
    for(i = 0; i < *arrSize; i ++)
    {
        if(i == 0 || *(arr + i) != *(arr + i - 1))
        {
            *(B + (count ++)) = *(arr + i);
        }
    }

    for(i = 0; i < count; i ++)
    {
        *(arr + i) = *(B + i);
    }
    *arrSize = count;
    free(B);
}

int main(void)
{
    int i;
    func(arr, &arrSize);
    if(arrSize > 0)
    {
        for(i = 0; i < arrSize; i ++)
        {
            printf("%d ", *(arr + i));
        }        
    }
    else
    {
        printf("结果为空数组");
    }
    printf("\n");
    return 0;
}