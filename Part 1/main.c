#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#define LINE 17
#define COLUMN 17
#define VAL_1 17
#define VAL_2 20

/*Struct has 4 fields: vector for the code of the country, debt, GDP, flag that has value 0 or 1*/
typedef struct {
    char code[4];
    float debt;
    float gdp;
    int flag;
} tableOfCountries;

void createCountryVector(tableOfCountries table[]) {
    int i;

    /*Loop to fill the country, debt, GDP and flag*/
    for(i = 0; i < VAL_1; i++) {
        scanf("%s%f%f", table[i].code, &(table[i].debt), &(table[i].gdp));
        /*Flag 1 equals that the country is not defaulting and was not analyzed*/
        table[i].flag = 1;
    }
}

void createVectorOriginalDebt(tableOfCountries table[], float vector[]) {
    int i;

    /*Fills the vector with the original debts of each country*/
    for(i = 0; i < VAL_1; i++) {
        vector[i] = table[i].debt;
    }
}

void fillDebtMatrix(float vector[LINE][COLUMN]) {
    int line;
    int column;

    /*Loops that goes through the line of the matrix*/
    for(line = 0; line < LINE; line++) {
        /*Loops that goes through the column of the matrix*/
        for(column = 0; column < COLUMN; column++) {
            /*Fills the matrix with the value of the debt of each country*/
            scanf("%f", &(vector[line][column]));
        }
    }

}

void riskInterventionAndDefault(tableOfCountries table[], float pi, float pd, int vectorRiskDefault[VAL_1], int vectorRiskIntervention[VAL_1]) {
    int pi_count = 0, pd_count = 0, j = 0, m = 0, i, p;

    for(i = 0; i < VAL_1; i++) {
        /*If the country is defaulting*/
        if(table[i].debt >= ((table[i].gdp) * pd)) {
            pd_count++;
            /*Passes to the vector the position of the country*/
            vectorRiskDefault[j] = i;
            j++;
            continue;
        }

            /*If the country is in risk of intervention*/
            if((table[i].debt >= ((table[i].gdp) * pi)) && (table[i].debt < ((table[i].gdp) * pd))) {
                pi_count++;
                /*Passes to the vector the position of the country*/
                vectorRiskIntervention[m] = i;
                m++;
            }
    }
    printf("%d ", pi_count);
    for(i = 0; i < pi_count; i++) {
        p = vectorRiskIntervention[i];
        printf("%s ", table[p].code);
    }

    printf("\n");

    printf("%d ", pd_count);
    for(i = 0; i < pd_count; i++) {
        p = vectorRiskDefault[i];
        printf("%s ", table[p].code);
    }

    printf("\n");
}




int main() {
    
    int i, k, contI = 0, contD = 0, l = 1;
    float pi, pd;
    char vectorDefault[VAL_2][4];
    int vectorRiskDefault[VAL_1];
    int vectorRiskIntervention[VAL_1];
    float createVectorOriginalDebts[VAL_1];
    float debtMatrix[LINE][COLUMN];
    tableOfCountries table[VAL_2];

    scanf("%f", &pi);
    scanf("%f", &pd);

    createCountryVector(table);
    createVectorOriginalDebt(table, createVectorOriginalDebts);
    fillDebtMatrix(debtMatrix);

    riskInterventionAndDefault(table, pi, pd, vectorRiskDefault, vectorRiskIntervention);

    return 0;
}