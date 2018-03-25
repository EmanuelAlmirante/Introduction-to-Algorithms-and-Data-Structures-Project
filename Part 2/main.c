#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COUNTRY 4
#define NUM 5
#define STA 2
#define TAME 13
#define TAMV 14
#define NUMP 9

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

/*Used to read and save, in a vector of structures, the size of "nBets", this is, the number of bets that were registered,
the country, the code of the bet and the bet (for example, POR 000001 1 2 3 4 5 6 7)*/
void fillTable(tableOfBets table[], int bets) {
    int i = 0;

    for(i = 0; i < bets; i++) {
        scanf("%s %d %d %d %d %d %d %d %d", table[i].country, &(table[i].code), &(table[i].number1), &(table[i].number2), &(table[i].number3), &(table[i].number4), &(table[i].number5),
                                            &(table[i].star1), &(table[i].star2));
        
        /*Initializes how many numbers were guessed*/
        table[i].rightNumbers = 0;
        /*Initializes how many stars were guessed*/
        table[i].rightStars = 0;
        /*Initializes the prizes won*/
        table[i].prize = 0;
    }
}

/*Reads the combination passed in the input*/
void getsCombination(int vector_n[], int vector_s[]) {
    int i = 0;

    for(i = 0; i < NUM; i++) {
        scanf("%d", &vector_n[i]);
    }

    for(i = 0; i < STA; i++) {
        scanf("%d", &vector_s[i]);
    }
}

/*Determines how many correct numbers and stars each bet has and compares the combinations betted with the winning combination*/
void checksCombination(tableOfBets table[], int combinationNumber[], int combinationStar[], int totalBets) {
    int i, j;

    for(i = 0; i < totalBets; i++) {
        for(j = 0; j < NUM; j++) {
            /*Compares the first number of the bet with the number j of the winning combination*/
            if((table[i].number1) == combinationNumber[j]) {
                /*If they are equal, increment the total of correct numbers*/
                ++(table[i].rightNumbers);

              /*Compares the second number of the bet with the number j of the winning combination*/
            } else if((table[i].number2) == combinationNumber[j]) {
                /*If they are equal, increment the total of correct numbers*/
                ++(table[i].rightNumbers);

              /*Compares the third number of the bet with the number j of the winning combination*/
            } else if((table[i].number3) == combinationNumber[j]) {
                /*If they are equal, increment the total of correct numbers*/
                ++(table[i].rightNumbers);

              /*Compares the fourth number of the bet with the number j of the winning combination*/
            } else if((table[i].number4) == combinationNumber[j]) {
                /*If they are equal, increment the total of correct numbers*/
                ++(table[i].rightNumbers);
                
              /*Compares the fifth number of the bet with the number j of the winning combination*/
            } else if((table[i].number5) == combinationNumber[j]) {
                /*If they are equal, increment the total of correct numbers*/
                ++(table[i].rightNumbers);
            }
        }

        for(i = 0; j < totalBets; i++) {
            for(j = 0; j < STA; j++) {
                if((table[i].star1) == combinationStar[j]) {
                    ++(table[i].rightStars);
                } else if((table[i].star2) == combinationStar[j]) {
                    ++(table[i].rightStars);
                }
            }
        }
    }
}

/*Puts all the positions of vector "vector" with the value zero*/
void cleanWinnersVector(int vector[]) {
    int i = 0;

    for(i = 0; i < TAME; i++) {
        vector[i] = 0;
    }
}

/*Initializes the number of winners of each prize with the value zero*/
void cleanPrizeCountry(tableOfPrizes table[]) {
    int i; 

    for(i = 0; i < NUMP; i++) {
        table[i].prize1 = 0;
        table[i].prize2 = 0;
        table[i].prize3 = 0;
        table[i].prize4 = 0;
        table[i].prize5 = 0;
        table[i].prize6 = 0;
        table[i].prize7 = 0;
        table[i].prize8 = 0;
        table[i].prize9 = 0;
        table[i].prize10 = 0;
        table[i].prize11 = 0;
        table[i].prize12 = 0;
        table[i].prize13 = 0;
    }
}

/*Receives a country (POR, for example) and a vector with the code of the thirteen countries.
  Compares the first letter of the country with the values in the vector and determines the value that corresponds to which country, returning the value*/
int searchCountry(char country[], char countries[]) {
    int i;

    for(i = 0; i < NUMP; i++) {
        if((country[0]) == countries[i]) {
            return i;
        } else {
            continue;
        }
    }

    return 0;
}

/*Returns the number of winners of each prize in each country*/
void winnersCountry(tableOfPrizes prizes[], char country[], char countries[], int totalPrizes) {
    int j;

    j = searchCountry(country, countries);

    switch(totalPrizes) {
        case 0:
            (prize[j].prize1)++;
        break;

        case 1:
            (prize[j].prize2)++;
        break;

        case 2:
            (prize[j].prize2)++;
        break;

        case 3:
            (prize[j].prize2)++;
        break;

        case 4:
            (prize[j].prize2)++;
        break;

        case 5:
            (prize[j].prize2)++;
        break;

        case 6:
            (prize[j].prize2)++;
        break;

        case 7:
            (prize[j].prize2)++;
        break;

        case 8:
            (prize[j].prize2)++;
        break;

        case 9:
            (prize[j].prize2)++;
        break;

        case 10:
            (prize[j].prize2)++;
        break;

        case 11:
            (prize[j].prize2)++;
        break;

        case 12:
            (prize[j].prize2)++;
        break;
    }
}

/*Checks how many winners there is for each prize*/
void checkWinners(tableOfBets table[], int vector[], tableOfPrizes prize[], char countries[], int totalBets) {
    int i, j;

    for(i = 0; i < totalBets; i++) {
        switch(table[i].correctNumbers) {
            case 5:
                if((table[i].correctStars) == 2) {
                    j = 0;
                    vector[j]++;
                    winnersCountry(prize, table[i].country, countries, j);
                    table[i].prize = 1;
                } else if((table[i].correctStars) == 1) {
                    j = 1;
                    vector[j]++;
                    winnersCountry(prize, table[i].country, countries, j);
                    table[i].prize = 2;
                } else if((table[i].correctStars) == 0) {
                    j = 1;
                    vector[j]++;
                    winnersCountry(prize, table[i].country, countries, j);
                    table[i].prize = 3;
                }
            break;

            case 4:
                if((table[i].correctStars) == 2) {
                    j = 0;
                    vector[j]++;
                    winnersCountry(prize, table[i].country, countries, j);
                    table[i].prize = 4;
                } else if((table[i].correctStars) == 1) {
                    j = 1;
                    vector[j]++;
                    winnersCountry(prize, table[i].country, countries, j);
                    table[i].prize = 5;
                } else if((table[i].correctStars) == 0) {
                    j = 1;
                    vector[j]++;
                    winnersCountry(prize, table[i].country, countries, j);
                    table[i].prize = 6;
                }
            break;

            case 3:
                if((table[i].correctStars) == 2) {
                    j = 0;
                    vector[j]++;
                    winnersCountry(prize, table[i].country, countries, j);
                    table[i].prize = 7;
                } else if((table[i].correctStars) == 1) {
                    j = 1;
                    vector[j]++;
                    winnersCountry(prize, table[i].country, countries, j);
                    table[i].prize = 8;
                } else if((table[i].correctStars) == 0) {
                    j = 1;
                    vector[j]++;
                    winnersCountry(prize, table[i].country, countries, j);
                    table[i].prize = 10;
                }
            break;

            case 2:
                if((table[i].correctStars) == 2) {
                    j = 0;
                    vector[j]++;
                    winnersCountry(prize, table[i].country, countries, j);
                    table[i].prize = 9;
                } else if((table[i].correctStars) == 1) {
                    j = 1;
                    vector[j]++;
                    winnersCountry(prize, table[i].country, countries, j);
                    table[i].prize = 12;
                } else if((table[i].correctStars) == 0) {
                    j = 1;
                    vector[j]++;
                    winnersCountry(prize, table[i].country, countries, j);
                    table[i].prize = 13;
                }
            break;

            case 1:
                if((table[i].correctStars) == 2) {
                    j = 10;
                    vector[j]++;
                    winnersCountry(prize, table[i].country, countries, j);
                    table[i].prize = 11;
                } 
            break;
        }
    }
}

/*Prints the values of each prize, number of winners and the value of the prize for each winner*/
void tableOfWinners(int vector[], double prize) {
    int i; 

    for(i = 0; i < TAME; i++) {
        switch(i) {
            case 0:
                if(vector[i] == 0){
                    printf("1 %0.2lf %d 0.00\n", prize * 0.32, vector[0]);
                } else {
                    printf("1 %0.2lf %d %0.2lf\n", prize * 0.32, vector[0], (prize * 0.32)/vector[0]);
                }
            break;

            case 1:
                if(vector[i] == 0){
                    printf("1 %0.2lf %d 0.00\n", prize * 0.048, vector[1]);
                } else {
                    printf("1 %0.2lf %d %0.2lf\n", prize * 0.048, vector[1], (prize * 0.048)/vector[1]);
                }
            break;

            case 2:
                if(vector[i] == 0){
                    printf("1 %0.2lf %d 0.00\n", prize * 0.016, vector[2]);
                } else {
                    printf("1 %0.2lf %d %0.2lf\n", prize * 0.016, vector[2], (prize * 0.016)/vector[2]);
                }
            break;

            case 3:
                if(vector[i] == 0){
                    printf("1 %0.2lf %d 0.00\n", prize * 0.008, vector[3]);
                } else {
                    printf("1 %0.2lf %d %0.2lf\n", prize * 0.008, vector[3], (prize * 0.008)/vector[3]);
                }
            break;

            case 4:
                if(vector[i] == 0){
                    printf("1 %0.2lf %d 0.00\n", prize * 0.007, vector[4]);
                } else {
                    printf("1 %0.2lf %d %0.2lf\n", prize * 0.007, vector[4], (prize * 0.007)/vector[4]);
                }
            break;

            case 5:
                if(vector[i] == 0){
                    printf("1 %0.2lf %d 0.00\n", prize * 0.007, vector[5]);
                } else {
                    printf("1 %0.2lf %d %0.2lf\n", prize * 0.007, vector[5], (prize * 0.007/vector[5]);
                }
            break;

            case 6:
                if(vector[i] == 0){
                    printf("1 %0.2lf %d 0.00\n", prize * 0.005, vector[6]);
                } else {
                    printf("1 %0.2lf %d %0.2lf\n", prize * 0.005, vector[6], (prize * 0.005)/vector[6]);
                }
            break;

            case 7:
                if(vector[i] == 0){
                    printf("1 %0.2lf %d 0.00\n", prize * 0.023, vector[7]);
                } else {
                    printf("1 %0.2lf %d %0.2lf\n", prize * 0.023, vector[7], (prize * 0.023/vector[7]);
                }
            break;

            case 8:
                if(vector[i] == 0){
                    printf("1 %0.2lf %d 0.00\n", prize * 0.022, vector[8]);
                } else {
                    printf("1 %0.2lf %d %0.2lf\n", prize * 0.022, vector[8], (prize * 0.022)/vector[8]);
                }
            break;

            case 9:
                if(vector[i] == 0){
                    printf("1 %0.2lf %d 0.00\n", prize * 0.037, vector[9]);
                } else {
                    printf("1 %0.2lf %d %0.2lf\n", prize * 0.037, vector[9], (prize * 0.037/vector[9]);
                }
            break;

            case 10:
                if(vector[i] == 0){
                    printf("1 %0.2lf %d 0.00\n", prize * 0.065, vector[10]);
                } else {
                    printf("1 %0.2lf %d %0.2lf\n", prize * 0.065, vector[10], (prize * 0.065)/vector[10]);
                }
            break;

            case 11:
                if(vector[i] == 0){
                    printf("1 %0.2lf %d 0.00\n", prize * 0.1760, vector[11]);
                } else {
                    printf("1 %0.2lf %d %0.2lf\n", prize * 0.1760, vector[11], (prize * 0.1760)/vector[11]);
                }
            break;

            case 12:
                if(vector[i] == 0){
                    printf("1 %0.2lf %d 0.00\n", prize * 0.18, vector[12]);
                } else {
                    printf("1 %0.2lf %d %0.2lf\n", prize * 0.18, vector[12], (prize * 0.18)/vector[12]);
                }
            break;
        }
    }
}

/**/