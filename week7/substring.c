#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*

program to find substrings within strings without using the string.h library

*/

// flag to be raised when invalid characters are encountered
int flag = 0;
int found = 0;

int find_substring(char string[], char substr[]);
int checker(char s[]);

int main()
{
    char string[100];
    char sub[100];
    int i;
    
    printf("Enter the first string:\n");
    scanf("%s", string);
    if(checker(string) == 1){
        printf("Invalid character entered\n");
        return 0;
    }


    printf("Enter the second string:\n");
    scanf("%s", sub);
    if(checker(sub) == 1){
        printf("Invalid character entered\n");
        return 0;
    }

    find_substring(string, sub);
    

    if(found == 1){

        printf("the string '%s' is contained in the string '%s'\n", sub, string);
        return 0;
    }
    else{
        printf("the string '%s' is not contained in the string '%s'\n", sub, string);
        return 0;
    }
}

int checker(char s[])
{
    int i;
    for(i = 0; s[i] != '\0'; i++){
        if(isalpha(s[i]) == 0){
            return 1;
        }
    }
    return 0;
}


int find_substring(char string[], char substr[])
{
    int i = 0, j = 0;
    int occur;
    
    while (string[i] != '\0'){

        // string to find first charcter of substring
        while(string[i] != substr[0] && string[i] != '\0'){
            ++i;
        }

        // loop to find if the all characters of the substring match the source
        while (string[i] == substr[j] && string != '\0' && substr[j] != '\0'){
            ++i;
            ++j;
        }

        // if all values of the substring have been iterated over
        // then the substring exists within the string
        if(substr[j] == '\0'){
            found = 1;
        }

        i++;
        j = 0;

    }
    return found;
}