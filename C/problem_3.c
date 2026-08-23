/*
The prime factors of 13195 are 5,7,13 and 29.

What is the largest prime factor of the number 600851475143?
*/

//David's note:
//So I might have over-engineered this a bit...for practice

#include <stdio.h>
#include <stdlib.h>

typedef struct _arr{
    long* array;
    int capacity;
    int used;
} Arr;

Arr initArray(int capacity){
    long* array = malloc(capacity * sizeof(long));
    Arr arr;
    arr.array = array;
    arr.capacity = capacity;
    arr.used = 0;

    return arr;
}

void insert(long value, Arr* arr){
    if((arr->capacity - arr->used) <= 1){
        long* temp = realloc(arr->array, 2 * arr->capacity * sizeof(long));
        if(temp != NULL){
            arr->array = temp;
            arr->capacity = 2 * arr->capacity;
        }
    }
    arr->array[arr->used] = value;
    arr->used++;
}

void find_factors(long number, Arr* arr){
    //First attempt at the algorithm, definitely very inefficient
    long factor = 2;
    while(factor <= number/2){
        if(number % factor == 0){
            insert(factor, arr);
        }
        factor++;
    }
    insert(number, arr);
}

void find_factors2(long number, Arr* arr){
    //iteration 2
    long factor = 1;
    while(factor * factor <= number){
        if(number % factor == 0){
            insert(factor, arr);
            if(factor != number/factor){
                insert(number/factor, arr);
            }
        }
        factor++;
    }
}
void print_arr(Arr* arr){
    int i = 0;
    while(i < arr->used){
        printf("%ld ", arr->array[i]);
        i++;
    }
    printf("\n");
}

int is_prime(long number){
    if(number == 1) return 0;
    long factor = 1;
    while(factor * factor <= number){
        if(number % factor == 0){
            if(factor != 1 && factor != number){
                return 0;
            }
        }
        factor++;
    }
    return 1;
}

long largest_prime(Arr* arr){
    long largest = 0;
    for(int i = 0; i < arr->used; i++){
        if(is_prime(arr->array[i]) == 1 && largest < arr->array[i]){
            largest = arr->array[i];
        }
    }
    return largest;
}

int main(){
    //First task: Try to print an array of factors
    Arr factors_array = initArray(20);
    long num = 600851475143;
    find_factors2(num, &factors_array);
    print_arr(&factors_array);

    //Find the primes and print largest
    printf("%ld\n", largest_prime(&factors_array));
}