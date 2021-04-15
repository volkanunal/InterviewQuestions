/* 

clear explanation :  https://www.youtube.com/watch?v=GTJr8OvyEVQ

*/

#include "stdio.h"
#include "string.h"
#include "stdlib.h"

static int prepare_look_up_table(char* table_array, const char* pattern)
{
    if (strlen(pattern) == 0) 
    {
        printf("\r\n There is no pattern");
        return -1;
    }  

    int i = 1;
    int j = 0;
    int strlen_pattern = strlen(pattern);

    while (i < strlen_pattern)
    {
        if (pattern[j] == pattern[i])
        {
            table_array[i] = j + 1;
            i++;
            j++;
        }

        else
        {
            if (j != 0) 
            {
                j = table_array[j - 1];
            }

            else
            {
                table_array[i] = 0;
                i++;
            }
        }
    }

    return 1;
}

/*
    For pattern : aabaabaaa
    Table : 010123452
*/

int main(int argc, char** argv)
{
    char* text = "abxabcabcaby";
    char* pattern = "abcaby";   

    char* table_array = (char*) malloc(strlen(pattern) * sizeof(char));

    memset(table_array, 0, sizeof(table_array));

    if (prepare_look_up_table(table_array, pattern) == 1)
    {
        int i = 0;
        int j = 0;
        int strlen_pattern = strlen(pattern);
        int strlen_text = strlen(text);

        while (i < strlen_text)
        {
            if (text[i] == pattern[j])
            {
                j++;
                i++;
            }

            if (j == strlen_pattern)
            {
                printf("\r\n Found pattern at index %d", i - j);    
                j = table_array[j -  1];
            }

            //After found
            else if (i < strlen_text && pattern[j] != text[i])
            {
                if (j != 0)
                {
                    j = table_array[j - 1];
                }

                else
                {
                    i++;
                }
            }
        }
    }

    free(table_array);   
}



