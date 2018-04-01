#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define COUNTRY 4
#define NUM 5
#define STA 2
#define TAME 13
#define NUMP 9
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
    int correctStars;
    int correctNumbers;
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
void change(int* a, int* b) {
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

int partition(int v[], int begin, int end) {
  int i, j;

  i = begin;
  for (j = begin + 1; j <= end; ++j){

      if (v[j] < v[begin]){
          ++i;
          change(&v[i], &v[j]);
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

    for(i = 0; i < size; i++){
        v[i] = 0;
    }
}

/*Used to read and save, in a vector of structures, the size of "nBets", this is, the number of bets that were registered,
the country, the code of the bet and the bet (for example, POR 000001 1 2 3 4 5 6 7)*/
void fillTable(tableOfBets tab[], int bets) {
    int i = 0;

    for(i = 0; i < bets; i++){

        scanf("%s %d %d %d %d %d %d %d %d", tab[i].country, &(tab[i].code), &(tab[i].number1), &(tab[i].number2),  
                                            &(tab[i].number3), &(tab[i].number4), &(tab[i].number5),
                                            &(tab[i].star1), &(tab[i].star2));
        tab[i].correctStars = 0;       
        tab[i].correctNumbers = 0;       
        tab[i].prize = 0;        
    }
}

/*Reads the combination passed in the input*/
void getsCombination(int v[], int t[]) { 
    int i = 0;

    for(i = 0; i < NUM; i++) { 
        scanf("%d", &v[i]);
    }

    for(i = 0; i < STA; i++) {
        scanf("%d", &t[i]);
    }
}

/*Determines how many correct numbers and stars each bet has and compares the combinations betted with the winning combination*/
void checksCombination(tableOfBets tab[], int combinationNumbers[], int combinationStars[], int totalBets) { 
    int i, j;

    for(i = 0; i < totalBets; i++) {
        for(j = 0; j < NUM; j++) { 
            /*Compares the first number of the bet with the number j of the winning combination*/
            if((tab[i].number1) == combinationNumbers[j])
                /*If they are equal, increment the total of correct numbers*/  
                ++(tab[i].correctNumbers);     
            /*Compares the second number of the bet with the number j of the winning combination*/            
            else if
                ((tab[i].number2) == combinationNumbers[j]) 
                /*If they are equal, increment the total of correct numbers*/
                ++(tab[i].correctNumbers);           
            /*Compares the third number of the bet with the number j of the winning combination*/      
            else if
                ((tab[i].number3) == combinationNumbers[j]) 
                /*If they are equal, increment the total of correct numbers*/
                ++(tab[i].correctNumbers);   
            /*Compares the fourth number of the bet with the number j of the winning combination*/              
            else if
                ((tab[i].number4) == combinationNumbers[j]) 
                /*If they are equal, increment the total of correct numbers*/
                ++(tab[i].correctNumbers);                 
            /*Compares the fifth number of the bet with the number j of the winning combination*/
            else if
                ((tab[i].number5) == combinationNumbers[j]) 
                /*If they are equal, increment the total of correct numbers*/
                ++(tab[i].correctNumbers);                
        }
    }

    for(i = 0; i < totalBets; i++) {
        for(j = 0; j < STA; j++){
            /*Compares the first star of the bet with the star j of the winning combination*/
            if((tab[i].star1) == combinationStars[j]) 
                /*If they are equal, increment the total of correct numbers*/
                ++(tab[i].correctStars);
            /*Compares the second star of the bet with the star j of the winning combination*/                   
            else if
                ((tab[i].star2) == combinationStars[j])  
                /*If they are equal, increment the total of correct numbers*/
                ++(tab[i].correctStars);                     
        }
    }
}

/*Puts all the positions of vector v with the value zero*/
void cleanWinnersVector(int v[]) {
    int i = 0;

    for(i = 0; i < TAME; i++){
        v[i] = 0;
    }
}

/*Initializes the number of winners of each prize with the value zero*/
void cleanPrizeCountry(tableOfPrizes tab[]) {
    int i;

    for(i = 0; i < NUMP; i++){
        tab[i].prize1 = 0;       
        tab[i].prize2 = 0;       
        tab[i].prize3 = 0;       
        tab[i].prize4 = 0;       
        tab[i].prize5 = 0;       
        tab[i].prize6 = 0;       
        tab[i].prize7 = 0;       
        tab[i].prize8 = 0;       
        tab[i].prize9 = 0;       
        tab[i].prize10 = 0;      
        tab[i].prize11 = 0;      
        tab[i].prize12 = 0;      
        tab[i].prize13 = 0;      
    }
}

/*Receives a country (POR, for example) and a vector with the code of the thirteen countries. Compares the first letter of the country with the values 
in the vector and determines the value that corresponds to which country, returning the value*/
int searchCountry(char country[], char countries[]) {
    int i;

    for(i = 0; i < NUMP; i++){
        if((country[0]) == countries[i])
            return i;
        else continue;
    }

    return 0;
}

/*Fills a vector with the first letter of each country*/
void fillCountries(char v[]) {
    v[0] = 'P';
    v[1] = 'E';
    v[2] = 'F';
    v[3] = 'I';
    v[4] = 'G';
    v[5] = 'A';
    v[6] = 'B';
    v[7] = 'S';
    v[8] = 'L';
}

/*Returns the number of winners of each prize in each country*/
void winnersCountry(tableOfPrizes pri[], char country[], char countries[], int totalPrizes) { 
    int j;

    j = searchCountry(country, countries);

    switch (totalPrizes) {
		case 0:
		(pri[j].prize1)++;  
		break;

		case 1:
		(pri[j].prize2)++;	
		break;

		case 2:
		(pri[j].prize3)++;	
		break;

		case 3:
		(pri[j].prize4)++;	
		break;

		case 4:
		(pri[j].prize5)++;	
		break;

		case 5:
		(pri[j].prize6)++;	
		break;

		case 6:
		(pri[j].prize7)++;	
		break;

		case 7:
		(pri[j].prize8)++;	
		break;

		case 8:
		(pri[j].prize9)++;	
		break;

		case 9:
		(pri[j].prize10)++;
		break;

		case 10:
		(pri[j].prize11)++;	
		break;

		case 11:
		(pri[j].prize12)++;	
		break;

		case 12:
		(pri[j].prize13)++;	
		break;

    }
}

/*Checks how many winners there is for each prize*/
void checkWinners(tableOfBets tab[], int v[], tableOfPrizes pri[], char countries[], int totalBets){
    int i, j;

    for(i = 0; i < totalBets; i++) {
        switch(tab[i].correctNumbers) {					
            case 5:
                if((tab[i].correctStars) == 2) {				
                    j = 0;
                    v[j]++;						
                    winnersCountry(pri, tab[i].country, countries, j);
                    tab[i].prize = 1;					
                }
                if((tab[i].correctStars) == 1) {				
                    j = 1;
                    v[j]++;						
                    winnersCountry(pri, tab[i].country, countries, j);
                    tab[i].prize = 2;					
                }
                if((tab[i].correctStars) == 0) {			
                    j = 2;
                    v[j]++;						
                    winnersCountry(pri, tab[i].country, countries, j);
                    tab[i].prize = 3;					
                }
                break;

            case 4:
                if((tab[i].correctStars) == 2) {				
                    j = 3;
                    v[j]++;						
                    winnersCountry(pri, tab[i].country, countries, j);
                    tab[i].prize = 4;					
                }
                if((tab[i].correctStars) == 1) {			
                    j = 4;
                    v[j]++;						
                    winnersCountry(pri, tab[i].country, countries, j);
                    tab[i].prize = 5;					
                }
                if((tab[i].correctStars) == 0) {			
                    j = 5;
                    v[j]++;						
                    winnersCountry(pri, tab[i].country, countries, j);
                    tab[i].prize = 6;					
                }
                break;

            case 3:
                if((tab[i].correctStars) == 2) {				
                    j = 6;
                    v[j]++;						
                    winnersCountry(pri, tab[i].country, countries, j);
                    tab[i].prize = 7;				
                }
                if((tab[i].correctStars) == 1) {				
                    j = 7;
                    v[j]++;						
                    winnersCountry(pri, tab[i].country, countries, j);
                    tab[i].prize = 8;					
                }
                if((tab[i].correctStars) == 0) {				
                    j = 9;
                    v[j]++;						
                    winnersCountry(pri, tab[i].country, countries, j);
                    tab[i].prize = 10;				
                }
                break;

            case 2:
                if((tab[i].correctStars) == 2) {			
                    j = 8;
                    v[j]++;						
                    winnersCountry(pri, tab[i].country, countries, j);
                    tab[i].prize = 9;					
                }
                if((tab[i].correctStars)==1) {			
                    j = 11;
                    v[j]++;						
                    winnersCountry(pri, tab[i].country, countries, j);
                    tab[i].prize = 12;					
                }
                if((tab[i].correctStars) == 0) {				
                    j = 12;
                    v[j]++;						
                    winnersCountry(pri, tab[i].country, countries, j);
                    tab[i].prize = 13;				
                }
                break;

            case 1:
                if((tab[i].correctStars) == 2) {				
                    j = 10;
                    v[j]++;						
                    winnersCountry(pri, tab[i].country, countries, j);
                    tab[i].prize = 11;				
                }
                break;
        }
    }
}

/*Prints the values of each prize, number of winners and the value of the prize for each winner*/
void tableOfWinners(int v[], double prize) {
    int i;

    for(i = 0; i < TAME; i++) {
        switch (i) {

            case 0:								
                if(v[i] == 0)						
                    printf("1 %0.2f %d 0.00\n", prize*0.32, v[0]);
                else
                    printf("1 %0.2f %d %0.2f\n", prize*0.32, v[0], (prize*0.32)/v[0]);
                break;

            case 1:								
                if(v[i] == 0)						
                    printf("2 %0.2f %d 0.00\n", prize*0.048, v[1]);
                else
                    printf("2 %0.2f %d %0.2f\n", prize*0.048, v[1], (prize*0.048)/v[1]);
                break;

            case 2:								
                if(v[i] == 0)						
                    printf("3 %0.2f %d 0.00\n", prize*0.016, v[2]);
                else
                    printf("3 %0.2f %d %0.2f\n", prize*0.016, v[2], (prize*0.016)/v[2]);
                break;

            case 3:                                 
                if(v[i] == 0)							
                    printf("4 %0.2f %d 0.00\n", prize*0.008, v[3]);
                else
                    printf("4 %0.2f %d %0.2f\n", prize*0.008, v[3], (prize*0.008)/v[3]);
                break;

            case 4:								
                if(v[i] == 0)						
                    printf("5 %0.2f %d 0.00\n", prize*0.007, v[4]);
                else
                    printf("5 %0.2f %d %0.2f\n", prize*0.007, v[4], (prize*0.007)/v[4]);
                break;

            case 5:								
                if(v[i] == 0)						
                    printf("6 %0.2f %d 0.00\n", prize*0.007, v[5]);
                else
                    printf("6 %0.2f %d %0.2f\n", prize*0.007, v[5], (prize*0.007)/v[5]);
                break;

            case 6:                             
                if(v[i] == 0)                     
                    printf("7 %0.2f %d 0.00\n", prize*0.005, v[6]);
                else
                    printf("7 %0.2f %d %0.2f\n", prize*0.005, v[6], (prize*0.005)/v[6]);
                break;

            case 7:                             
                if(v[i] == 0)                     
                    printf("8 %0.2f %d 0.00\n", prize*0.023, v[7]);
                else
                    printf("8 %0.2f %d %0.2f\n", prize*0.023, v[7], (prize*0.023)/v[7]);
                break;

            case 8:                             
                if(v[i] == 0)                     
                    printf("9 %0.2f %d 0.00\n", prize*0.022, v[8]);
                else
                    printf("9 %0.2f %d %0.2f\n", prize*0.022, v[8], (prize*0.022)/v[8]);
                break;

            case 9:                             
                if(v[i] == 0)                     
                    printf("10 %0.2f %d 0.00\n", prize*0.037, v[9]);
                else
                    printf("10 %0.2f %d %0.2f\n", prize*0.037, v[9], (prize*0.037)/v[9]);
                break;

            case 10:                            
                if(v[i] == 0)                     
                    printf("11 %0.2f %d 0.00\n", prize*0.065, v[10]);
                else
                    printf("11 %0.2f %d %0.2f\n", prize*0.065, v[10], (prize*0.065)/v[10]);
                break;

            case 11:                            
                if(v[i] == 0)                     
                    printf("12 %0.2f %d 0.00\n", prize*0.1760, v[11]);
                else
                    printf("12 %0.2f %d %0.2f\n", prize*0.1760, v[11], (prize*0.1760)/v[11]);
                break;

            case 12:                            
                if(v[i] == 0)                     
                    printf("13 %0.2f %d 0.00\n", prize*0.18, v[12]);
                else
                    printf("13 %0.2f %d %0.2f\n", prize*0.18, v[12], (prize*0.18)/v[12]);
                break;
        }
    }
}

/*Checks which countries had prizes*/
int numberCountryPrize(tableOfPrizes pri[]) {
    int i = 0, j = 0;

    for(i = 0; i < NUMP; i++) {  
        /*Checks if, in each country, there was a bet that won one of the thirteen prizes*/  
        if( (pri[i].prize1!=0) || (pri[i].prize2)!=0  || (pri[i].prize3)!=0  || (pri[i].prize4)!=0 || (pri[i].prize5)!=0  || (pri[i].prize6)!=0  ||
            (pri[i].prize7)!=0  || (pri[i].prize8)!=0 || (pri[i].prize9)!=0  || (pri[i].prize10)!=0 || (pri[i].prize11)!=0  || (pri[i].prize12)!=0  || (pri[i].prize13)!=0)

        /*Increase the number of countries with prizes*/
        ++j;        
    }

    return j;      
}

/*Order the prized bets by the prize number and, in each prize, orders by the code of the bet*/
void orderWinners(tableOfBets tab[], int v[], int totalBets) {
    int i = 1, j, r = 0;

      while(i < TAMV) {
        int k = 0;                   
        cleanVector(v, totalBets);  

        for(j = 0; j < totalBets; j++) {
            if((tab[j].prize) == i) {  
                v[k] = (tab[j].code); 
                k++;                 
            } else continue;
        }

        quickSort(v, r, k - 1);        

        for(j = 0; j < k; j++) {
            printf("%06d\n", v[j]);     
        }

        i++;
    }
}


int main() {

    int p, i, j, totalBets;
    int combinationNumbers[NUM];
    int combinationStars[STA];
    int vectorOfWinners[TAME];
    double prize;
    char countries[NUMP];
    char countriesP[COUNTRY];
    tableOfPrizes countryPrize[NUMP];


    scanf("%lf", &prize);

    getsCombination(combinationNumbers, combinationStars);

    scanf("%d", &totalBets);

    int vectorPrize[totalBets];
    tableOfBets tab[totalBets];

    fillTable(tab, totalBets);

    cleanPrizeCountry(countryPrize);

    fillCountries(countries);

    checksCombination(tab, combinationNumbers, combinationStars, totalBets);

    cleanWinnersVector(vectorOfWinners);

    checkWinners(tab, vectorOfWinners, countryPrize, countries, totalBets);

    tableOfWinners(vectorOfWinners, prize);

    printf("%d\n", numberCountryPrize(countryPrize));

    scanf("%d", &p);

    for(i = 0; i < p; i++) {  
                        
        getchar();
        getchar();

        scanf("%s", countriesP);
        j = searchCountry(countriesP, countries);

        printf("%d %d %d %d %d %d %d %d %d %d %d %d %d\n", countryPrize[j].prize1, countryPrize[j].prize2, countryPrize[j].prize3,
                                                            countryPrize[j].prize4, countryPrize[j].prize5, countryPrize[j].prize6,
                                                            countryPrize[j].prize7, countryPrize[j].prize8, countryPrize[j].prize9,
                                                            countryPrize[j].prize10, countryPrize[j].prize11, countryPrize[j].prize12,
                                                            countryPrize[j].prize13);
    }

    orderWinners(tab, vectorPrize, totalBets);

    return 0;
}