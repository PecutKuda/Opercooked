#include <stdio.h>
#include <string.h>

int totalDrink;
int totalDessert;
int totalHDessert = 0;
int totalHDrink = 0;

struct OrderTime
{
    int year,month,date,hour,min,sec;
    char form[3];
};

struct pesanDrink
{
 char menuName[255];
 int menuPrice;
 char typeMenu[255];
 char menuSize[2];
 char menuFlavor[50];
 int drinkTime;
 //order time
 OrderTime ordertime;
};

struct pesanDessert
{
 char typeMenu[255];
 char menuName[255];
 char topping[255];
 double calories;
 int menuPrice;
 int dessertTime;
 //order time
OrderTime ordertime;
};

typedef struct histdessert
{
    char name[255];
    char topping[255];
    double callories;
    int price;
    //order time
    OrderTime ordertime;
};

typedef struct histdrink
{
    char name[255];
    char size[2];
    char flavor[255];
    int price;
    //order time
    OrderTime ordertime;
};

histdessert historyDessert[105];
histdrink historyDrink[105];
pesanDessert orderDessert[105];
pesanDrink orderDrink[105];


void displayTime();

void displayTime()
{
    printf("| No  | Type     | Name   | Price  | Time Left |\n--------------------------------------------------------------\n");
    int list=1;
    ///////////////////////////////////////////////////////////////////
    for (int i = 1; i <= totalDessert; ++i){
        if (orderDessert[i].dessertTime <= 0) continue;
        orderDessert[i].dessertTime -= 10;
        if (orderDessert[i].dessertTime <= 0){
            //Pindahin data ke struct history
            strcpy(historyDessert[totalHDessert].name, orderDessert[i].menuName);
            strcpy(historyDessert[totalHDessert].topping, orderDessert[i].topping);
            historyDessert[totalHDessert].callories = orderDessert[i].calories;
            historyDessert[totalHDessert].price = orderDessert[i].menuPrice;
            profit += orderDessert[i].menuPrice;
            //Tambahin order time
            historyDessert[i].ordertime.year = orderDessert[i].ordertime.year;
            historyDessert[i].ordertime.month = orderDessert[i].ordertime.month;
            historyDessert[i].ordertime.date = orderDessert[i].ordertime.date;
            historyDessert[i].ordertime.hour = orderDessert[i].ordertime.hour;
            historyDessert[i].ordertime.min = orderDessert[i].ordertime.min;
            historyDessert[i].ordertime.sec = orderDessert[i].ordertime.sec;
        }
    }

    for (int i = 1; i <= totalDrink; ++i){
        if (orderDrink[i].drinkTime <= 0) continue;
        orderDrink[i].drinkTime -= 10;
        if (orderDrink[i].drinkTime <= 0){
            //Pindahin data ke struct history
            strcpy(historyDrink[totalHDrink].name, orderDrink[i].menuName);
            strcpy(historyDrink[totalHDrink].size, orderDrink[i].menuSize);
            strcpy(historyDrink[totalHDrink].flavor, orderDrink[i].menuFlavor);
            historyDrink[totalHDrink].price = orderDrink[i].menuPrice;
            profit += orderDrink[i].menuPrice;
            //Tambahin order time
            historyDrink[i].ordertime.year = orderDrink[i].ordertime.year;
            historyDrink[i].ordertime.month = orderDrink[i].ordertime.month;
            historyDrink[i].ordertime.date = orderDrink[i].ordertime.date;
            historyDrink[i].ordertime.hour = orderDrink[i].ordertime.hour;
            historyDrink[i].ordertime.min = orderDrink[i].ordertime.min;
            historyDrink[i].ordertime.sec = orderDrink[i].ordertime.sec;
        }
    }
    ///////////////////////////////////////////////////////////////////
    printf("\t\tDISPLAY MENU\n\n");
    int idx=1;
    //print data dessert
    while(idx <= totalDessert)
    {
        if (orderDessert->dessertTime > 0)
        {
            printf(" %-4d| %-9s| %-21s| %-7d| %-10d\n", list, "Dessert", orderDessert[idx].menuName, orderDessert->menuPrice, orderDessert->dessertTime);
            list++;
        }
    }
    idx=1;
    //print data drink
    while (idx <= totalDrink)
    {
        if (orderDrink->drinkTime > 0)
        {
            printf(" %-4d| %-9s| %-21s| %-7d| %-10d\n", list, "Drink", orderDrink[idx].menuName, orderDrink->menuPrice, orderDrink->drinkTime);
            list++;
        }
    }
    printf("Press Enter to return main menu");
    getchar();
    //input function mainmenu nya
}