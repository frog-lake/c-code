#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// a program to take in numbers from the command line
// and output how many evens, odds and primes there are

int count_numbers(int args[], int argc);
int check_prime(int num);


int main(int argc, char *argv[])
{
    
    int i, numbers[argc];
    
    if(argc < 2){
        printf("insufficient command line arguments.\n");
        return 0;
    }
    
    // for checking if there are letters in argv
    char c[1000];
    sprintf(c, "%s", argv[1]);
    for(i = 2; i < argc; i++){
        strcat(c, argv[i]);
    }
    // checks for letters
    char *p = c;
    for (i = 0; i < strlen(p); i++){
        if(isalpha(p[i]) != 0){
            printf("Error: only numbers are permitted.\n");
            return 0;
        }
    }

    // convert numbers to ints
    for(i = 1; i < (argc); i++)
    {
        numbers[i] = atoi(argv[i]);
    }

    count_numbers(numbers, argc);
}


// will print evens, odds, and primes or an error if there are negatives
int count_numbers(int args[], int argc)
{
    int odds = 0, evens = 0, primes = 0;
    int i, p;

    for(i = 1; i < argc; i++)
    {
        p = check_prime(args[i]);

        if(args[i] > 0){
            // if prime
            if(p == 1){
                if(args[i] % 2 == 0){
                    primes += 1;
                    evens += 1;
                }
                else if(args[i] % 2 == 1){
                    primes += 1;
                    odds += 1;
                }
            }
            // if not a prime
            else if(p == 0){
                if(args[i] % 2 == 0){
                    evens += 1;
                }
                else if(args[i] % 2 == 1){
                    odds += 1;
                }
            }
        }
        else{
            printf("Error: Only positive integers are permitted.\n");
            return 0;
        }
    }
    printf("Number of odd numbers: %d\nNumber of even numbers: %d\nNumber of prime numbers: %d\n", odds, evens, primes);
    return 0;
}


// returns 1 if prime, 0 otherwise
int check_prime(int num)
{
    int i, flag = 1;
    
    // checks if number is not a prime
    for(i = 2; i <= num/2; i++){
        if ((num % i) == 0){
            flag = 0;
            break;
        }
    }

    // resets flag to 0 if num is 1
    // as 1 is not a prime number
    if (num == 1){
        flag = 0;
    }
    return flag;
}
