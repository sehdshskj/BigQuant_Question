#include <stdio.h>
#include <stdlib.h>

static int arr[] = {1, 1, 2, 3, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 6, 6};
static int arrSize = 17;
int func(int *arr, int arrSize)
{
    int max = 0;
    int i;
    int count = 0;
    int pos = -1;
    for(i = 0; i < arrSize; i ++)
    {
        if(i == 0 || *(arr + i) != *(arr + i - 1))
        {
            if(count > max)
            {
                max = count;
                pos = i - 1;
            }
            count = 1;
        }
        else
        {
            count ++;
        }
    }
    if(count > max)
    {
        max = count;
        pos = i - 1;
    }    
    return pos;
}

int main(void)
{
    int ret;
    if((ret = func(arr, arrSize)) >= 0)
    {
        printf("%d\n",*(arr + ret));
    }
    else
    {
        printf("输入数组为空数组\n");
    }
    return 0;
}