/*
A number is a perfect square, or a square number, if it is the square of a positive integer.
For example, 25 is a square number because  5² = 5 * 5   ; it is also an odd square.

The first 5 square numbers are: 1, 4, 9, 16, 25, and the sum of the odd squares is 1 + 9 + 25 = 35.

Among the first 302 thousand square numbers, what is the sum of all the odd squares?
*/

#include <stdio.h>

long oddSquares(int limit){
    long sum = 0;
    for(long i = 1; i <= limit; i+=2){
        sum+=(i*i);
    }
    return sum;
}

int main(){
    printf("%ld\n", oddSquares(302000));
}