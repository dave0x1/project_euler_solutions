/*2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

*/
#include <stdio.h>

int main(){
    long start = 2520;
    for(long i = 11; i <= 20; i++){
        if(start % i != 0){
            if(i % 2 == 0){
                printf("\n%d x %ld = %ld\n", 2, start, start*2);
                start = start * 2;
                continue;
            }
            printf("\n%ld x %ld = %ld\n", i, start, start*i);
            start*=i;
        } 

    }
    printf("%ld\n", start);
}