#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define VAT1 0.06
#define VAT2 0.13
#define VAT3 0.23
#define DESCRIPTION 21

/*Struct of the 6 parameters of each product. It saves the code of the product, the price without VAT, the VAT of that product, the description of the product (20 characters maximum),
the quantity bought by a client and the total quantity bought.*/
typedef struct node {
    int code;
    double priceWithouVAT;
    double VAT;
    char description[DESCRIPTION];
    int quantity;
    int totalQuantity;

    struct node *next;

} Product;

typedef Product* tableOfProducts;

/*Initiates a list*/
void Init(tableOfProducts* tab){

    *tab = NULL;
}

void delete(tableOfProducts* tab){
	while (*tab != NULL){
	    Product *tmp = *tab;
		*tab = (*tab)->next;
		free(tmp);
    }

return;
}

/*Function that rounds the prices to the cents*/
double myRound(double valor) {

    return floor(valor*100.0+0.5001)/100.0;
}

/*Read and save the description of the products*/
void readString(char v[]){
    char character = '0';
    int i = 0;

    scanf("%c", &character);

    for(i = 0; character != '\n'; i++){
        v[i] = character;
        scanf("%c", &character);
    }

    v[i] = '\0';
}

/*Adds a new product to the list of products*/
void insert(tableOfProducts* tab, int code, double priceWithouVAT, double VAT, char* description){

    if(*tab == NULL){
        *tab = (tableOfProducts) malloc (sizeof(Product));

        if (*tab == NULL)
            return;

        (*tab)->code = code;
        (*tab)->priceWithouVAT = priceWithouVAT;
        (*tab)->VAT = VAT;
        strcpy((*tab)->description, description);
        (*tab)->quantity = 0;
        (*tab)->totalQuantity = 0;
        (**tab).next = NULL;
    }

    else
        insert(&(**tab).next, code, priceWithouVAT, VAT, description);
}

/*Seacrches the bought product in the list and increments the variable "quantity" and "totalQuantity"*/
void processes(tableOfProducts* tab, int code){

        if (*tab == NULL)
            return;

        if(code == ((*tab)->code)){
            ++((*tab)->quantity);
            ++((*tab)->totalQuantity);
        }

        else
            processes(&(**tab).next, code);
}

/*Prints the ticket. Returns the percentage of VAT, the code of the product and it's description. 
It also returns the quantity bought in that purchase, the price of each unity and the total price of the bought unities.
Also adds to the total cost of the cart and to the total value of purchases of the day the value of the purchase of the product.*/
void nextTicket(tableOfProducts* tab, double VAT, double v[]){

        if((*tab) == NULL){
            return;
            }

        if((((*tab)->VAT) == VAT) && (((*tab)->quantity)!= 0)){
            printf("%0.0f%c %010d %s \n", ((*tab)->VAT) * 100,'%', (*tab)->code, (*tab)->description);
            printf("%d %c %0.2f %0.2f \n", (*tab)->quantity, 'x', myRound(((*tab)->priceWithouVAT)*(1+((*tab)->VAT))), myRound((myRound(((*tab)->priceWithouVAT)*(1+((*tab)->VAT))))*((*tab)->quantity)));

            v[0] = v[0] + ((myRound(((*tab)->priceWithouVAT)*(1+((*tab)->VAT))))*((*tab)->quantity));
            v[1] = v[1] + ((myRound(((*tab)->priceWithouVAT)*(1+((*tab)->VAT))))*((*tab)->quantity));
            ((*tab)->quantity)=0;
        }

            nextTicket(& (**tab).next, VAT, v);
}

/*Search in the list of products which was the best seller. In case of tie it returns the first it found*/
void topProduct(tableOfProducts* tab, int* codePMax, int* quantity){

    if((*tab) == NULL){
        return;
    }

    if(((*tab)->totalQuantity)> *quantity){
        *codePMax = ((*tab)->code);
        *quantity= ((*tab)->totalQuantity);
        topProduct(&(**tab).next, codePMax, quantity);
    }

    else{topProduct(&(**tab).next, codePMax, quantity);}
}


int main() {
    tableOfProducts tab;
    int code = 0, codePMax = 0, carts = 0, maxQuantity = 0;
    double priceWithouVAT = 0, VAT = 0;
    char description[DESCRIPTION];
    char option = '0';
    double costOfCart[2];
    costOfCart[0] = 0;
    costOfCart[1] = 0;


    Init(&tab);

    scanf("%c", &option);
    while (option == 'p' || option == 'c'){

        if(option == 'p'){
            scanf(" %d %lf %lf ", &code, &priceWithouVAT, &VAT);
            readString(description);

            insert(&tab, code, priceWithouVAT, VAT, description);
            option = getchar();
        }

        while((option == 'c') && (option != EOF )){
            carts++;

            while((getchar())!= 't'){
                scanf("%d", &code);
                processes(&tab, code);
                code = 0;
            }
        getchar();
        nextTicket(&tab, VAT1, costOfCart);
        nextTicket(&tab, VAT2, costOfCart);
        nextTicket(&tab, VAT3, costOfCart);
        printf("%0.2f\n", myRound(costOfCart[0]));
        costOfCart[0] = 0;
        option = getchar();
        }
    }

    printf("%d\n", carts);
    printf("%0.2f\n", myRound(costOfCart[1]));

    topProduct(&tab, &codePMax, &maxQuantity);
    if(costOfCart[1] != 0)
        printf("%010d", codePMax);
    else{}

delete(&tab);

return 0;
}
