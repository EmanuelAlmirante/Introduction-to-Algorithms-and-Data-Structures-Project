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

void createCountryVector(countryTable tab[]) {
	int i;

	/*Fills the struct with countries, debt and gdp*/
	for(i = 0; i < VAL_2; i++) {
		scanf ("%s%f%f", tab[i].code, &(tab[i].debt), &(tab[i].gdp));
		/*Puts the flag with the value 1 to know that the country was not analysed or is defaulting*/
		tab[i].flag = 1;
	}
}

void createOriginalDebtVector(countryTable tab[], float v[]) {
	int i;

	/*Fills the struct each position of the vector with the debt of each country*/
	for(i = 0; i < VAL_2; i++) {
		v[i] = tab[i].debt;
	}
}

void fillMatrix(float v[LINE][COLUMN]) {
	int line;
	int column;

	/*To go through the lines of the matrix*/
	for(line = 0; line < LINE; line++) {
		/*To go through the columns of the matrix*/
		for(column = 0; column < COLUMN; column++) {
			/*Fills the matrix with the values of the debt of each country*/
			scanf ("%f", &(v[line][column]));
		}
	}
}

void riskInterventionDefaulting(countryTable tab[], float pi, float fd, int vectorRiskDefaulting[VAL_2], int vectorRiskIntervention[VAL_2]) {
	int picount = 0, pdcount = 0, j = 0, m = 0, i, p;

	for(i = 0; i < VAL_2; i++) {
		/*If the country is defaulting*/
		if(tab[i].debt >= ((tab[i].gdp) * pd)) {
			pdcount++;
			/*Puts the country's position in the vector*/
			vectorRiskDefaulting[j] = i;
			j++;
			continue;
		}
		/*If the country is in risk of intervention*/
		if((tab[i].debt >= (tab[i].gdp) * pi)) && (tab[i].debt < ((tab[i].gdp * pd))) {
			picount++;
			/*Puts the country's position in the vector*/
			vectorRiskIntervention[m] = i;
			m++;
		}
	}

	printf ("%d ", picount);
	for(i = 0; i < picount; i++) {
		p = vectorRiskIntervention[i];
		printf("%s ", tab[p].code);
	} 

	printf("\n");

	printf("%d", pdcount);
	for(i = 0; i < pdcount; i++) {
		p = vectorRiskDefaulting[i];
		printf("%s ", tab[p].code);
	}

	printf("\n");
}

void cleanVector(char v[VAL_1][4]) {
	int i, j;

	for(i = 0; i < VAL_3; i++) {
		for(j = 0; j < 4; j++) {
			/*Initializes the vector with the letter 'z'*/
			v[i][j] = 'z';
		}
	}
}

int searchTabCountries(char v[VAL_1], countryTable tab[]) {
	int i;

	/*To go through the table with the countries*/
	for(i = 0; i < VAL_2; i++) {
		/*Compares the string given with the code of the country that is given*/
		if((strcmp(v, (tab[i].code))) == 0) {
			/*If it is true, it returns the position of that country*/
			return i;
			break;
		}
	}

	return 0;
}

void sumsDebt(countryTable tab[], float v[LINE][COLUMN], int t) {
	int i;

	/*Sums to the countries table the values of the debt table*/
	for(i = 0; i < VAL_2; i++) {
		tab[i].debt = (tab[i].debt) + v[t][i];
	}
}

int checksDefaultInfection(countryTable tab[], char v[VAL_1][4], float pd, int l){
	int i;

	for(i = 0; i < VAL_2; i++){
		/*If the country is defaulting and was not analyzed*/
		if((tab[i].debt) >= ((tab[i].gdp) * pd) && ((tab[i].flag) == 1)){
			/*Puts the country in the vector of the defaulting countries*/
			strcpy(v[l], tab[i].code);
			l++;
		}		
	}
}

int casesDefault(char v[VAL_1][4], countryTable tab[], float debtMatrix[LINE][COLUMN], float pd, int l){
	int i = 0, o = 0;

	/*Loop until the special character is not in the  vector of the defaulting countries*/
	while(v[i][0] != 'z'){
		/*Integer that indicates the position of the country in the table*/
		p = searchTabCountries(v[i], tab);
		/*Flag that indicates if the country was already analyzed*/
		tab[p].flag = 0;
		/*Sum the value of the debt of that country to all the other countries*/
		o = checksDefaultInfection(tab, v, pd, l);
		i++;
	}
	return o;
}

int returnsCasesDefault(char v[VAL_1][4], int contD){
	int i;

	/*Loop to go through the vector where the defaulting countries are saved*/
	for(i = 0; i < VAL_2; i++){
		/*While special charater 'z' is not found increments the counter of defaulting countries*/
		if(v[i][0} != 'z'){
			contD++;
		} else{
			break;
		}
	}
	return contD;
}

