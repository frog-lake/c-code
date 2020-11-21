#include <stdio.h>
#include <stdlib.h>

int ind = 0;

void secondLargest(int *numbers, int *index, int len);

int main(int argc, char *argv[])
{
    // checks if there are arguments provided
    if(argc == 1){
        printf("Insufficient arguments provided\n");
        return 0;
    }
    
    // convert numbers to ints through a loop
    int i, nums[argc];
    for(i = 1; i < argc; i++)
    {
        nums[i] = atoi(argv[i]);
    }
    
    // checks for negative numbers
    for(i = 1; i < argc; i++){
        if(nums[i] < 0){
            printf("Error: only positive integers are permitted.\n");
            return 0;
        }
    }

    // prints second largest number based on index returned from the function
    secondLargest(nums, &ind, argc);
    for(i = 1; i < argc; i++){
        if(i == ind){
            printf("%d\n", nums[i]);
        }
    }
    return 0;
}

void secondLargest(int *numbers, int *index, int len)
{
    int i = 1, max = 0, max2 = 0;
    int *n = numbers;
    int l = len;
    n = n+1;
    
    // searches for largest and second largest
    // and returns index of the second largest
    while(l - 1)
    {
        if(max < *n){
            max = *n;
        }
        
        else if(max2 < *n && max > *n){
            max2 = *n;
            ind = i;
        }
        ++i;
        ++n;
        --l;
    }

}
