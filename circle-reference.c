#include <stdio.h>

// calls vars by reference, calculates area of circle
// i just need a way to make sure i don't lose this somehow because i put (some) work into making sure this functions

// define constant
#define PI 3.1415

// declare function
void calculateArea (int* radius, float* area);

// main code
// searches for user input of an integer to use as the radius
int main(void)
{
    int radius = 0;
    float circleArea = 0;

    printf ("Enter the radius for the circle: ");
    scanf("%d", &radius);
    calculateArea (&radius, &circleArea);

    printf ("The area of the circle is: %.2f\n", circleArea);
    return 0;
}

// calculates the area of a circle when given the radius
void calculateArea (int* radius, float *circleArea)
{

    *circleArea = PI*((*radius)*(*radius));
}
