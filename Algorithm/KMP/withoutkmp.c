#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int main()
{
    int ret  = 0;

    char* text = "bbbababbbbabbbabbbb";
   
    char* temp_array = (char*)malloc(sizeof(char) * strlen(text));

    memset(temp_array, 0, strlen(text) * sizeof(char));

    for (int i = 0; i < strlen(text); ++i)
    {
        if (text[i] == 'b' && text[i + 1] == 'a')
        {
            temp_array[i] = 2;
            temp_array[i + 1] = 0;
            i++;
        }

        else if (text[i] == 'b' && text[i + 1] == 'b')
        {
            temp_array[i] = 1;
            temp_array[i + 1] = 0;
            i++;
        }

        else if(text[i] == 'a')
        {
            temp_array[i] = 0;
        }
                  
    }

    int is_any_a_flag = 0;

    for (int i = 0; i < strlen(text); ++i)
    {       
        if (temp_array[i + 1] == 0 && temp_array[i] == 1 && !is_any_a_flag) //bb is exist before aa or ba
        {
            ret += 2;
            i++;
        }

        else if (temp_array[i + 1] == 2 && temp_array[i] == 1) //for bba
        {
            ret += 2;
            i++;
            is_any_a_flag = is_any_a_flag ? 0 : 1;
        }

        else if (temp_array[i] == 2 && temp_array[i + 1] == 0) //for aa
        {
            ret++;
            i++;
            is_any_a_flag = is_any_a_flag ? 0 : 1;
        }         

    }

    printf("\r\n Ret %d",  is_any_a_flag ? ret : 0);

    for (int i = 0; i < strlen(text); ++i)
    {
        printf("\r\n temp_array[i] : %i", temp_array[i]);
    }

    free(temp_array);
}