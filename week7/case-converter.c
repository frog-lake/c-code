#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*

has a bunch of warnings that i'm not arsed to fix atm
it works at the very least :P

*/

// ----------------------

// flag for invalid characters (numbers)
int flag = 0;

void convert(char *s[]);

int main() {
    int i;
    char str[100];

    // take in input from user
    printf("Enter a string of upper and lowercase letters: ");
    scanf("%s", &str);

    
    convert(&str);
    
    // if the flag was raised, throw an error
    // else, print as normal
    if(flag == 1)
        printf("Invalid character entered.\n");
    else{
        printf("%s", str);
    }
    return 0;
}


void convert(char *s[])
{
    int i = 0;
    char *n = s;

    // convert lowercase to uppercase and vice versa
    while(n[i] != '\0') {
        if(n[i] >= 'a' && n[i] <= 'z') {
            n[i] = n[i] -32;
        }
        else if(n[i] >= 'A' && n[i] <= 'Z'){
            n[i] = n[i] +32;
        }
        i++;
   }

   // raise flag if any numbers are encountered
    for (i = 0; n[i]!='\0'; i++) {
        if(isdigit(n[i]) != 0){
            flag = 1;
        }
    }
    
}
