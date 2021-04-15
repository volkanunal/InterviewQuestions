

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

char* search(const char* pattern, const char* text, const char* table_array, int bb_or_ba /*if bb set 1 */)
{
    int i = 0;
    int j = 0;
    int strlen_pattern = strlen(pattern);
    int strlen_text = strlen(text);
    int result = 0;
    
    char* ret_idx_array = (char*) malloc(strlen_text * sizeof(char));

    memset(ret_idx_array, 0, sizeof(char) * strlen_text);

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

            
            ret_idx_array[i - j] = bb_or_ba ? 1 : 2;

            j = table_array[j -  1];

            //result++;
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

    return ret_idx_array;
}

int main(int argc, char** argv)
{
    char* text = "bbbbbbbb";
    char* pattern = "ba";   
    char* pattern_second = "bb";

    char* table_array = (char*) malloc(strlen(pattern) * sizeof(char));

    memset(table_array, 0, sizeof(table_array));

    if (prepare_look_up_table(table_array, pattern) == 1)
    {
        int ret = 0;
        char* result_pattern = search(pattern, text, table_array, 0);
        char* result_pattern_second = search(pattern_second, text, table_array, 1);

        char* merge_array = (char*) malloc(sizeof(char) * strlen(text));

        memset(merge_array, 0, sizeof(char) * strlen(text));
        
        for (int i = 0; i < strlen(text); ++i)
        {
            merge_array[i] = result_pattern[i] + result_pattern_second[i];
            printf("\r\n merge_array[i] : %i", merge_array[i]);
        }

        int is_any_a_flag = 0;

        for (int i = 0; i < strlen(text); ++i)
        {       
            if (merge_array[i + 1] == 0 && merge_array[i] == 1)
            {
                ret += 2;
                i++;
            }

            else if (merge_array[i + 1] == 2 && merge_array[i] == 1) //for bba
            {
                ret += 2;
                i++;
                is_any_a_flag = 1;
            }

            else if (merge_array[i] == 2 && merge_array[i + 1] == 0)
            {
                ret++;
                i++;
                is_any_a_flag = 1;
            }         
    
        }

        printf("\r\n Ret %d",  is_any_a_flag ? ret : 0);

        free(result_pattern);
        free(result_pattern_second);
        free(merge_array);
    }

    free(table_array);   

    return 0;
}