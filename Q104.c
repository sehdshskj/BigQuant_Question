#include <stdio.h>
#include <stdlib.h>

static int arr[] = {1, 2, 3, 4, 5, 6, 9};
static int arrSize = 7;
static int target = 7;
int func(int *arr, int arrSize, int target)
{
    int count = 0;
    int left, right;
    for(left = 0, right = arrSize - 1; left < right; )
    {
        if(*(arr + left) + *(arr + right) == target)
        {
            count ++;
            left ++;
            right --;
        }
        else if(*(arr + left) + *(arr + right) > target)
        {
            right --;
        }
        else 
        {
            left ++;
        }
    }
    return count;
}

int main(void)
{
    printf("%d\n",func(arr, arrSize, target));
    return 0;
}