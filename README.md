# Introduction to Algorithms and Data Structures Project

This repository has the project of the course of Introduction to Algorithms and Data Structures.

## Table of Contents

- [Objetives](https://github.com/EmanuelAlmirante/Introduction-to-Algorithms-and-Data-Structures-Project#objetives)
- [Part 1](https://github.com/EmanuelAlmirante/Introduction-to-Algorithms-and-Data-Structures-Project#part-1)
  - [Input Data](https://github.com/EmanuelAlmirante/Introduction-to-Algorithms-and-Data-Structures-Project/blob/master/README.md#input-data)
  - [Output Data](https://github.com/EmanuelAlmirante/Introduction-to-Algorithms-and-Data-Structures-Project/blob/master/README.md#output-data)
- [Part 2](https://github.com/EmanuelAlmirante/Introduction-to-Algorithms-and-Data-Structures-Project#part-2)
- [Part 3](https://github.com/EmanuelAlmirante/Introduction-to-Algorithms-and-Data-Structures-Project#part-3)

## Objetives

This repository will have the project I did for the course of IADS in college. The project is a simple one, but that contains the most fundamental concepts of the programming language C. The 3 parts are not related to each other and work as independent projects.

Over time, I will try to improve the code the best I can. Any help or recommendation is welcome, so feel free to change the code. 

## Part 1

Note: the abbreviations of the countries derived from their names in portuguese.

There are 17 countries in the Eurozone (EZ): Germany (ALE), Austria (AUT), Belgium (BEL), Cyprus (CHI), Slovakia (ESL), Slovenia (ELO), Spain (ESP), Estonia (EST), Finland (FIN), France (FRA), Greece (GRE), Netherlands (HOL), Ireland (IRL), Italy (ITA), Luxembourg (LUX), Malta (MAL), Portugal (POR).

At any given time, the countries can suffer an economic intervention or to default. The risk of suffering an intervention and to default are related with the country's debt and it's GDP. In this context we assume that when the debt of country **X** is greater than a **Pi** percentage of it's GDP, the country is in risk of suffering an intervention. The same way, when the debt of country **Y** is greater than a **Pd** of it's GDP, then the country is in risk of defaulting. **Pd** is always greater than **Pi**.

In this project, the objective is to develop a program that manipulates the information of the economic situation of each country of the EZ (debt, GDP, loans to other countries) and check which countries are in risk of suffering an interventation or defaulting. 

If a country is in risk of entering in default (**debt >= Pd * GDP**) the program should indicate which other countries are in risk of being "infected" and in risk of defaulting. 

### Input Data

- One line with a real number **Pi**, greater than 0, which indicates the percentage of the GPD from which the country is in risk of intervention;

- One line with a real number **Pd**, greater than **Pi**, which indicates the percentage of the GPD from which the country is in risk of defaulting;

- 17 lines, each one with information of the 17 countries of the EZ:
  - country code (3 letters);
  - debt (real number);
  - GDP (real number);

- 17 lines, each with the debts of each country to other countries, represented by 17 real numbers separated by blank spaces;

- One line with an integer **K**, greater than 0, that indicates the number of requests of what would happen if a specific country defaulted;

- **K** lines, each one in the following format:
  - letter **d**;
  - country code;
  
### Output Data

- Number of countries in risk of being interventioned, followed by the country codes;

- Number of countries in risk of defaulting, followed by the country codes;

- A sequence of lines, where each line corresponds to information about the consequences of a specific country defaulting. The lines respect the order given in the input and each line will have two numbers, with the first number representing the countries in risk of intervention and the second number representing the countries defaulting.

## Part 2 

UNDER CONSTRUCTION

## Part 3

UNDER CONSTRUCTION
