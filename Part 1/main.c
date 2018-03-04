#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#define LINE 17
#define COLUMN 17
#define VAL_1 20
#define VAL_2 17
#define VAL_3 20

/*The countryTable struct has 4 components: 
a vector of characters for the initials of the country; a debt; the gross domestic product; a flag with the value 0 or 1*/
typedef struct {
	char code[4];
	float debt;
	float gdp;
	int flag;	
} countryTable;

void createCountryVector (countryTable tab[]) {
	int i;
	/*Fills the struct with countries, debt and gdp*/
	for (i = 0, i < VAL_2, i++) {
		scanf ("%s%f%f", tab[i].code, &(tab[i].debt), &(tab[i].gdp));
		/*Puts the flag with the value 1 to know that the country was not analysed or is defaulting*/
		tab[i].flag = 1;
	}
}

void createOriginalDebtVector (countryTable tab[], float v[]) {
	int i;
	/*Fills the struct each position of the vector with the debt of each country*/
	for (i = 0, i < VAL_2, i++) {
		v[i] = tab[i].debt;
	}
}

void fillMatrix (float v[LINE][COLUMN]) {
	int line;
	int column;
	/*To go through the lines of the matrix*/
	for (line = 0, line < LINE, line++) {
		/*Tp go through the columns of the matrix*/
		for (column = 0, column < COLUMN, column++) {
			/*Fills the matrix with the values of the debt of each country*/
			scanf ("%f", &(v[line][column]));
		}
	}
}

void riskInterventionDefaulting (countryTable tab[], float pi, float fd, int vectorRiskDefaulting[VAL_2], int vectorRiskIntervention[VAL_2]) {
	int picount = 0, pdcount = 0, j = 0, m = 0, i, p;

	for (i = 0, i < VAL_2, i++) {
		/*If the country is defaulting*/
		if (tab[i].debt >= ((tab[i].gdp) * pd)) {
			pdcount++;
			/*Puts the country's position in the vector*/
			vectorRiskDefaulting[j] = i;
			j++;
			continue;
		}
		/*If the country is in risk of intervention*/
		if ((tab[i].debt >= (tab[i].gdp) * pi)) && (tab[i].debt < ((tab[i].gdp * pd))) {
			picount++;
			/*Puts the country's position in the vector*/
			vectorRiskIntervention[m] = i;
			m++;
		}
	}

	printf ("%d ", picount);
	for (i = 0, i < picount, i++) {
		p = vectorRiskIntervention[i];
		printf("%s ", tab[p].code);
	} 

	printf("\n");

	printf("%d", pdcount);
	for (i = 0, i < pdcount, i++) {
		p = vectorRiskDefaulting[i];
		printf("%s ", tab[p].code);
	}

	printf("\n");
}

