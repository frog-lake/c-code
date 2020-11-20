#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void convert2bin(int *binary);

int result;

int main(int argc, char *argv[])
{
    char c[1000];
    int i;
    // puts argv[1] into c
    sprintf(c, "%s", argv[1]);

    // puts args into 1 string
    if(argc > 2) {
        for(i = 2; i < argc; i++){
            strcat(c, argv[i]);
        }
    }

    // string length
    int len = strlen(c);

    // tests how many digits there are (max 8)
    // returns 0 if over character limit
    if(len > 8){
        printf("Too many binary digits entered.\n");
        return 0;
    }

    // checks if string has anything other than 1 or 0
    char *p = c;
    for (i = 0; i < strlen(p); i++){
        if(p[i] != '1' && p[i] != '0'){
            printf("Only digits 1 and 0 are permitted.\n");
            return 0;
        }
    }

    int bin = atoi(c);
    convert2bin(&bin);
    printf("%d\n", result);
    return 0;
}


// convert intgers to binary
void convert2bin(int *binary)
{
    int decimal = 0, i = 0, remainder, n;
    n = *binary;
    while (n != 0) {
        remainder = n % 10;
        n /= 10;
        decimal += remainder * pow(2, i);
        ++i;
    }
    result = decimal;
}
