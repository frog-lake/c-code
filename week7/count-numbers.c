#include <stdio.h>
#include <stdlib.h>

// a program to take in numbers from the command line
// and output how many evens, odds and primes there are
// perhaps far too messy for it's purpose, but hey, it works :P

int count_numbers(int args[], int argc);
int check_prime(int num);


int main(int argc, char *argv[])
{
    // convert numbers to ints through a loop
    int i, numbers[argc];
    for(i = 1; i < (argc); i++)
    {
        numbers[i] = atoi(argv[i]);
    }
    count_numbers(numbers, argc);
}


// will print evens, odds, and primes or an error if there are negatives
int count_numbers(int args[], int argc)
{
    int odds, evens, primes = 0;
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
            printf("error: negative numbers are not permitted.\n");
            return 0;
        }
    }
    printf("evens: %d\nodds: %d\nprimes: %d\n", evens, odds, primes);
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
