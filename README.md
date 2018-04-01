# Introduction to Algorithms and Data Structures Project

This repository has the project of the course of Introduction to Algorithms and Data Structures.

## Table of Contents

- [Objetives](https://github.com/EmanuelAlmirante/Introduction-to-Algorithms-and-Data-Structures-Project#objetives)
- [Part 1](https://github.com/EmanuelAlmirante/Introduction-to-Algorithms-and-Data-Structures-Project#part-1)
  - [Input Data](https://github.com/EmanuelAlmirante/Introduction-to-Algorithms-and-Data-Structures-Project/blob/master/README.md#input-data)
  - [Output Data](https://github.com/EmanuelAlmirante/Introduction-to-Algorithms-and-Data-Structures-Project/blob/master/README.md#output-data)
  - [Example](https://github.com/EmanuelAlmirante/Introduction-to-Algorithms-and-Data-Structures-Project/blob/master/README.md#example)
    - [Input Data](https://github.com/EmanuelAlmirante/Introduction-to-Algorithms-and-Data-Structures-Project/blob/master/README.md#input-data-1)
    - [Output Data](https://github.com/EmanuelAlmirante/Introduction-to-Algorithms-and-Data-Structures-Project/blob/master/README.md#output-data-1)
  - [Compile and execute the code](https://github.com/EmanuelAlmirante/Introduction-to-Algorithms-and-Data-Structures-Project/blob/master/README.md#compile-and-execute-the-code)
- [Part 2](https://github.com/EmanuelAlmirante/Introduction-to-Algorithms-and-Data-Structures-Project#part-2)
  - [Input Data](https://github.com/EmanuelAlmirante/Introduction-to-Algorithms-and-Data-Structures-Project#input-data-2)
  - [Output Data](https://github.com/EmanuelAlmirante/Introduction-to-Algorithms-and-Data-Structures-Project#output-data-2)
  - [Example](https://github.com/EmanuelAlmirante/Introduction-to-Algorithms-and-Data-Structures-Project#example-1)
    - [Input Data](https://github.com/EmanuelAlmirante/Introduction-to-Algorithms-and-Data-Structures-Project#input-data-3)
    - [Output Data](https://github.com/EmanuelAlmirante/Introduction-to-Algorithms-and-Data-Structures-Project#output-data-3)
  - [Compile and execute the code](https://github.com/EmanuelAlmirante/Introduction-to-Algorithms-and-Data-Structures-Project/blob/master/README.md#compile-and-execute-the-code-1)
- [Part 3](https://github.com/EmanuelAlmirante/Introduction-to-Algorithms-and-Data-Structures-Project#part-3)

## Objetives

This repository will have the project I did for the course of IADS in college. The project is a simple one, but that contains the most fundamental concepts of the programming language C. The 3 parts are not related to each other and work as independent projects.

Over time, I will try to improve the code the best I can. Any help or recommendation is welcome, so feel free to change the code. 

## Part 1

**Note:** the abbreviations of the countries derived from their names in portuguese.

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

### Example

#### Input Data

0.7 <br/>
0.9 <br/>
ALE 40 100 <br/>
AUT 20 30 <br/>
BEL 20 30 <br/>
CHI 5 15 <br/>
ESL 10 20 <br/>
ELO 10 20 <br/>
ESP 60 80 <br/>
EST 2 10 <br/>
FIN 15 40 <br/>
FRA 50 90 <br/>
GRE 50 40 <br/>
HOL 15 40 <br/>
IRL 50 50 <br/>
ITA 70 80 <br/>
LUX 2 20 <br/>
MAL 4 10 <br/>
POR 16 20 <br/>
0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 <br/>
1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 <br/>
1 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 <br/>
1 0 0 0 0 0 1 0 0 1 1 0 0 1 0 0 0 <br/>
1 1 1 1 0 1 1 1 1 1 1 1 0 0 0 0 0 <br/>
1 1 1 1 1 0 1 1 1 1 1 1 0 0 0 0 0 <br/>
1 1 1 1 1 1 0 1 1 1 1 1 1 1 1 1 1 <br/>
1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 <br/>
1 1 1 0 1 1 1 1 0 1 1 1 1 1 1 1 1 <br/>
1 1 1 1 1 1 1 1 1 0 1 1 1 1 1 1 1 <br/>
1 1 1 1 1 1 1 1 1 1 0 1 1 1 1 1 1 <br/>
1 1 1 0 1 1 1 1 1 1 1 0 1 1 1 1 1 <br/>
1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 1 1 <br/>
1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 1 <br/>
1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 <br/>
1 0 0 0 0 0 1 0 0 1 0 1 0 0 0 0 0 <br/>
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 <br/>
3 <br/>
d GRE <br/>
d IRL <br/>
d ALE <br/>

#### Output Data

3 ESP ITA POR <br/>
2 GRE IRL <br/>
6 4 <br/>
6 4 <br/>
6 6 <br/>

### Compile and execute the code

- Compile -> $ gcc -ansi -Wall -pedantic -o proj1 *.c

- Execute -> $ ./proj1 < in.txt > out.txt

## Part 2 

**Note:** at the time there were only nine countries that had the contest. Also, the abbreviations of the countries derived from their names in portuguese.

Euromillions is a lottery played in nine european countries: Portugal, Spain, France, Ireland, United Kingdom, Austria, Belgium, Switzerland, Luxembourg. 

To play you bet on five numbers, that go from 1 to 50, and two stars, that go from 1 to 11. The probability of correctly guess the five numbers and two stars is 1 in 116 531 800. 

The prize given to each winner varies accordingly to how many numbers and stars the player guessed. The amount available for the lottery is distributed by the 13 prizes, as per the table below. To win the 1st prize, a player needs to guess correctly the five numbers and two stars, but to win the 13th prize the player only need to guess correctly two numbers.

| Prize      | Hits (numbers + stars) | Distribution |
| ---------- | ---------------------- | ------------ |
| 1st prize  | 5 + 2                  | 32.00%       |
| 2nd prize  | 5 + 1                  | 4.80%        |
| 2nd prize  | 5 + 0                  | 1.60%        |
| 3rd prize  | 4 + 2                  | 0.80%        |
| 4th prize  | 4 + 1                  | 0.70%        |
| 5th prize  | 4 + 0                  | 0.70%        |
| 6th prize  | 3 + 2                  | 0.50%        | 
| 7th prize  | 3 + 1                  | 2.30%        |
| 8th prize  | 2 + 2                  | 2.20%        |
| 9th prize  | 3 + 0                  | 3.70%        |
| 10th prize | 1 + 2                  | 6.50%        |
| 11th prize | 2 + 1                  | 17.60%       |
| 12th prize | 2 + 0                  | 18.00%       |

In ths project the objective is to develop a program that manipulates the information relative to a Euromillions contest, namely the value available for prizes, the bets made and the the correct winning key, and information about the results.

For simplicity purposes, it is considered that there is no possibility of jackpot and no multiple bets.

### Input Data

- A line with a real number **M (M > 0)** that indicates the amount avaible to distribute in prizes;
  
- A line with the winning sequence of numbers, separated by blank spaces: five numbers in the interval [1, 50] and two stars in the interval [1, 11];
  
- A line containing an integer **A (A > 0)** that indicates the number of registered bets;
  
- A sequence of **A** lines, containing information relative to **A** registered bets, which with the following format:
  - code of the country where the bet was registered (unique sequence of three letters) followed by a blank space;
  - code of the bet (unique sequence of six numbers) followed by a blank space;
  - 7 integer numbers corresponding to the winning sequence: ive numbers in the interval [1, 50] and two stars in the interval [1, 11], separated by blank spaces;
  
- A line with an integer **P (P > 0)** that indicates the number of information requests about the number of prizes (from 1st to 13th) that will be distributed in a certain country considering the bets registered and the winning sequence of numbers;

- A sequence of **P** lines with the information requests and the following format:
  - a letter **p** followed by a blank space;
  - the code of the country (unique sequence of three letters).

### Output Data

- For which of the 13 possible prizes (1st to 13th), a line with information separated by a blank space:
  - identification of the prize (integer **p** in the interval [1, 13];
  - available amount for the prize **p** (real number with two decimal places);
  - number of winners of prize **p** (integer);
  - value of the prize **p** (real number with two decimal places);
  
- Number of different countries with prized bets;

- Sequence of **P** lines, with each line corresponding to the answer to one of the **P** information requests made in the input and that contains 1st prizes, 2nd prizes, ..., 13th prizes that were distributed, separated by a blank space. The order of the lines of type **p** in the input is respected in the output;

- List of prized bets ordered by prize and, inside each prize, ordered by the code of the bet, this is, list of bets that won 1st prize ordered by code of the bet, followed by the bets that won 2nd prize ordered by the code of the bet, etc.

### Example

#### Input Data

100000.00 <br/>
20 10 5 1 49 1 11 <br/>
10 <br/>
ESP 000001 20 10 5 <br/>
IRL 000002 20 10 5 <br/>
POR 000003 20 10 5 <br/>
ESP 000004 20 10 5 <br/>
POR 000005 20 10 5 <br/>
FRA 000006 20 10 5 <br/>
POR 000007 21 11 6 <br/>
POR 000008 21 11 6 <br/>
POR 000009 21 11 6 <br/>
POR 000010 21 11 6 <br/>
5 <br/>
p POR <br/>
p ESP <br/>
p IRL <br/>
p GBR <br/>
p FRA <br/>

#### Output Data

1 32000.00 1 32000.00 <br/>
2 4800.00 2 2400.00 <br/>
3 1600.00 2 800.00 <br/>
4 800.00 1 800.00 <br/>
5 700.00 0 0.00 <br/>
6 700.00 0 0.00 <br/>
7 500.00 0 0.00 <br/>
8 2300.00 0 0.00 <br/>
9 2200.00 0 0.00 <br/>
10 3700.00 0 0.00 <br/>
11 6500.00 0 0.00 <br/>
12 17600.00 0 0.00 <br/>
13 18000.00 0 0.00 <br/>
4 <br/>
1 1 0 0 0 0 0 0 0 0 0 <br/>
0 1 0 1 0 0 0 0 0 0 0 <br/>
0 0 1 0 0 0 0 0 0 0 0 <br/>
0 0 0 0 0 0 0 0 0 0 0 <br/>
0 0 1 0 0 0 0 0 0 0 0 <br/>
000005 <br/>
000001 <br/>
000003 <br/>
000002 <br/>
000006 <br/>
000004 <br/>

### Compile and execute the code

- Compile -> $ gcc -ansi -Wall -pedantic -o proj2 *.c

- Execute -> $ ./proj2 < in.txt > out.txt

**Note:** When compiling, there may be two warnings. They can be safely ignored.

## Part 3

This project it is developed a program that manipulates information relative to available products and purchases made in a supermarket. During the day a set of clients buys products in the supermarket and their respective purchase tickets are processed. 

At the end of the day the program should produce a a listing of the tickets that were emitted and statistics about the cash register movements, namely the number of clients processed, total billied and most selled product.

### Input Data

- A sequence of lines with information relative to products. Each line has the following format:
  - the character 'p' followed by a blank space; 
  - code of the product (unique sequence of ten digits) followed by a blank space;
  - unitary price of the product without VAT followed by a blank space;
  - VAT of the product (0.06, 0.13 or 0.23) followed by a blank space;
  - description of the product (sequence of characters with a maximum size of 20);
  
- Sequence of shopping carts with the following format:
  - a line with the character 'c' that indicates the beginning of the shopping cart;
  - a sequence of lines with the code of the products in the cart (one per line);
  - a line with the character 't' that indicates the end of the shopping cart and the write in the ticket.

### Output Data

- 

### Example

#### Input Data

#### Output Data
