#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COUNTRY 4
#define NUM 5
#define EST 2
#define TAME 13
#define TAMV 14

/*Struct that has the 12 parameters of each bet.
It saves the country, the winning code of the bet, the winning numbers (5 numbers and 2 stars), 
how many correct numbers and stars are correct and the prize that corresponds to that bet*/
typedef struct {
    char country[COUNTRY];
    int code;
    int number1;
    int number2;
    int number3;
    int number4;
    int number5;
    int star1;
    int star2;
    int correctNumbers;
    int correctStars;
    int prize;
} tableOfBets;

/*Struct that saves how many winning bets there was for each of the 13th prizes*/
typedef struct {
    int prize1;
    int prize2;
    int prize3;
    int prize4;
    int prize5;
    int prize6;
    int prize7;
    int prize8;
    int prize9;
    int prize10;
    int prize11;
    int prize12;
    int prize13;
} tableOfPrizes;

/*Auxiliar algorihm of Quicksort. It changes the value of two variables*/
void change(int *a, int *b) {
    int tmp;
    *a = *b;
    *b = tmp;
}

int partition(int v[], int begin, int end) {
    int i, j;

    i = begin;

    for(j = begin + 1; j <= end; ++j) {
        if(v[j] < v[begin]) {
            ++i;
            change(&v[i], &v[j](;))
        }
    }
    change(&v[begin], &v[i]);

    return i;
}

/*Quicksort algorithm, that orders a vector of integers*/
void quickSort(int v[], int begin, int end) {
    int r;

    if (end > begin) {
        r = partition(v, begin, end);
        quickSort(v, begin, r - 1);
        quickSort(v, r + 1, end);
    }
}

/*Initializes all the positions of a vector of integers with zero*/
void cleanVector(int v[], int size) {
    int i;

    for(i = 0; i < size; i++) {
        v[i] = 0;
    }
}