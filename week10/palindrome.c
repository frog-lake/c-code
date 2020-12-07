#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STRING_SIZE 100

// raised if there are invalid characters in the input (numbers, etc)
int valid_flag = 0;
// raised if input is a palindrome
int palindrome_flag = 0;

// so i dont have to delcare it all the time
int i;

// cleaned string (no whitespace, punctuation... etc.)
//char *cleaned = NULL;

char *string = NULL;

void checker(char *ptr);
void cleaner(char *ptr, char *dst);
void if_palindrome(char *ptr);
//void reformat_string(char *src, char *dst);


void checker(char *ptr)
{
    for(i = 0; i < strlen(ptr); ++i)
    {
        if(isdigit(ptr[i]) != 0){valid_flag = 1;break;}
    }
}

void cleaner(char *src, char *dst) {
    // cleans up trailing
    if ((strlen(src) > 0) && (src[strlen (src) - 1] == '\n')){
        src[strlen (src) - 1] = '\0';
    }

    for (; *src; ++src){
        if (!ispunct((unsigned char) *src) && !isspace((unsigned char) *src)){
            *dst++ = tolower((unsigned char) *src);
        }
    }
    *dst = 0;
}


void if_palindrome(char *ptr)
{
    int c = 0;
    int l = strlen(ptr);
    for(i = 0; i < l; ++i){
        if(ptr[i] == ptr[l - i - 1]){
            ++c;
        }
    }
    if(c==i){
        palindrome_flag = 1;
    }
}


int main()
{
    char str[MAX_STRING_SIZE];
    printf("Please enter a string:\n");
    fgets(str, MAX_STRING_SIZE, stdin);
    
    string = str;
    

    
    // check for digits
    checker(string);
    if(valid_flag == 1){printf("Invalid!!\n");return 0;}
    
    cleaner(string, string);
    if_palindrome(string);
    
    if(palindrome_flag == 0){
        printf("This string is not a palindrome.\n");
    }
    else{
        printf("This string is a palindrome.\n");
    }

    return 0;
}
