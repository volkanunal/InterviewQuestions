#include "stdio.h"
#include "stdlib.h"
#include "string.h"


int solution(char *S)
{
    int ret = 0;

    if (S == NULL)
        return 0;
    
    char s = S[0];
    
    int array[4];

    memset(array, 0, sizeof(array));
    
    int ret_flag = 1;

    for (int i = 0; i < strlen(S); ++i)
    {
        if (s != S[i])
        {
            ret_flag = 0;
        }

        if (S[i] == '^') array[0] += 1;
        if (S[i] == 'v') array[1] += 1;
        if (S[i] == '<') array[2] += 1;
        if (S[i] == '>') array[3] += 1;
    }

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3 - i; ++j)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }            
        }
    }

    if (ret_flag == 1) return 0;

    ret = strlen(S) - array[3];

    return ret;

    
}

int main()
{
    char *test_data = "^vv<<v";

    printf("\r\n %i", solution(test_data));
}