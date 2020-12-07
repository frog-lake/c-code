#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STRING_SIZE 100

// raised if there are invalid characters in the input (numbers, etc)
int valid_flag = 0;
// raised if input is a palindrome
int palindrome_flag = 0;
// so i isn't declared all the time
int i;
// the string that will be scrubbed and tested
char *string = NULL;

// function declarations
void checker(char *ptr);
void cleaner(char *ptr, char *dst);
void if_palindrome(char *ptr);


// checks input for numbers and raises valid_flag if there are
void checker(char *ptr)
{
    for(i = 0; i < strlen(ptr); ++i)
    {
        if(isdigit(ptr[i]) != 0){valid_flag = 1; break;}
    }
}


// scrubs punctuation and whitespace from the input
void cleaner(char *src, char *dst) {

    // copies alphabetic characters to dst and ignores everything else
    for (; *src; ++src){
        if (!ispunct((unsigned char) *src) && !isspace((unsigned char) *src)){
            *dst++ = tolower((unsigned char) *src);
        }
    }
    *dst = 0;
}


// raises palindrome_flag if entered string is a palindrome
void if_palindrome(char *ptr)
{
    int c = 0;
    int l = strlen(ptr);
    // increments c
    for(i = 0; i < l; ++i){
        if(ptr[i] == ptr[l - i - 1]){
            ++c;
        }
    }
    // if c is equal to i, then the string is a palindrome
    if(c==i){
        palindrome_flag = 1;
    }
}

int main()
{
    // get input
    char *str = (char*) malloc(100 * sizeof(char));
    printf("Please enter a string:  \n");
    fgets(str, MAX_STRING_SIZE, stdin);
    string = str;

    // check for digits
    checker(string);
    if(valid_flag == 1){printf("Invalid input: Numbers not permitted.\n");return 0;}
    
    // scrub and test input
    cleaner(string, string);
    if_palindrome(string);
    
    // if flag was raised, then string is a palindrome, otherwise string is not a palindrome
    if(palindrome_flag == 0){
        printf("This string is not a palindrome.\n");
    }
    else{
        printf("This string is a palindrome.\n");
    }

    return 0;
}
