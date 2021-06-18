#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i, sum = 0, k = 0, unit[4] = {2, 2, 2, 2}, reunit[4] = {2, 2, 2, 2},
       count, priceMenu[6] = {30, 30, 30, 45, 40, 35}, priceSize[2] = {0, 10}, priceFlavor[4] = {0, 5, 5, 10}, priceTopping[4] = {5, 15, 10, 10};
int unitdum[4] = {0, 0, 0, 0}, machinecashdum[5] = {0, 0, 0, 0};
int j, money1[5], MoneyChange[5] = {0, 0, 0, 0, 0}, TotalMoney = 0, change, total[4], bank[5], returncash[5], bangnote, machinecash[5] = {2, 2, 2, 2, 2}, machinebanknote[5] = {100, 50, 20, 10, 5};
char InputMoney[5][10];
char ready[0], add;
int checkloop = 0;

char size[0];
char flavor[0], topping[0], toppings[0], ht, select_menu;
char order[5][30];
char menu[0];
char menu0[30] = "Black tea";
char menu1[30] = "Green tea";
char menu2[30] = "Thai tea";
char menu3[30] = "Passion fruit green tea";
char menu4[30] = "Taro smoothie tea";
char menu5[30] = "Peach tea";

char flavor0[30] = "Normal";
char flavor1[30] = "Milk";
char flavor2[30] = "Honey";
char flavor3[30] = "Brown sugar";

char topping0[30] = "Boba";
char topping1[30] = "Popping boba";
char topping2[30] = "Jelly";
char topping3[30] = "Pudding";

void GIVECHANGESANDITEMUPDATEINVENTORY(int arrunit[], int arrmoney[], int n)
{
    int i = n, a, b;
    for (i = 0; i < 5; i++)
    {
        arrmoney[i] -= arrunit[i];
    }

    if (n == 0)
    {
        arrunit[0] -= 1;
    }
    if (n == 1)
    {
        arrunit[1] -= 1;
    }
    if (n == 2)
    {
        arrunit[2] -= 1;
    }
    if (n == 3)
    {
        arrunit[3] -= 1;
    }
}
void Display()
{
    printf("|---------------------------------------------------------|\n");
    printf("|WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW|\n");
    printf("|     ..     _       __      __  __    _  _  __      ..   |\n");
    printf("|    ||''     | /| /|__ |   |   |  |  /| /| |__     ||''  |\n");
    printf("| :-----:      V  V |__ |__ |__ |__| /  v | |__   :-----: |\n");
    printf("| |=====|                 ___ _                   |=====| |\n");
    printf("| |     |                  | (_)                  |     | |\n");
    printf("| |o8o8o|      _                ___               |o8o8o| |\n");
    printf("| |oo8oo|     |_)   |_ |_ |  __  |  __ __         |oo8oo| |\n");
    printf("| |o8o8o|     |_)|_||_)|_)|_(-_  | (-_(__L        |o8o8o| |\n");
    printf("| '-----'                                         '-----' |\n");
    printf("|                 ____   ____   ____  ____                |\n");
    printf("|                |      |____| |____ |___                 |\n");
    printf("|   <(^w^)>      |____  |    | |     |____       <(^w^)>  |\n");
    printf("|                                                         |\n");
    printf("|MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM|\n");
    printf("|---------------------------------------------------------|\n");
    printf("\n =ORDERNO= =MENU=                    =MEDIUM=LARGE=\n");
    printf("\n    0:     %-25s:   %d    %d ", menu0, priceMenu[0], (priceMenu[0] + priceSize[1]));
    printf("\n    1:     %-25s:   %d    %d ", menu1, priceMenu[1], (priceMenu[1] + priceSize[1]));
    printf("\n    2:     %-25s:   %d    %d ", menu2, priceMenu[2], (priceMenu[2] + priceSize[1]));
    printf("\n    3:     %-25s:   %d    %d ", menu3, priceMenu[3], (priceMenu[3] + priceSize[1]));
    printf("\n    4:     %-25s:   %d    %d ", menu4, priceMenu[4], (priceMenu[4] + priceSize[1]));
    printf("\n    5:     %-25s:   %d    %d ", menu5, priceMenu[5], (priceMenu[5] + priceSize[1]));
    printf("\n\n");
    printf("    =FLAVORS=");
    printf("\n");
    printf("\n    0:     %-25s:   +%d", flavor0, priceFlavor[0]);
    printf("\n    1:     %-25s:   +%d", flavor1, priceFlavor[1]);
    printf("\n    2:     %-25s:   +%d", flavor2, priceFlavor[2]);
    printf("\n    3:     %-25s:   +%d", flavor3, priceFlavor[3]);
    printf("\n\n");
    printf("    =TOPPINGS=");
    printf("\n");
    printf("\n    0:     %-25s:   +%d   ( %d Unit left)", topping0, priceTopping[0], unit[0]);
    printf("\n    1:     %-25s:   +%d  ( %d Unit left)", topping1, priceTopping[1], unit[1]);
    printf("\n    2:     %-25s:   +%d  ( %d Unit left)", topping2, priceTopping[2], unit[2]);
    printf("\n    3:     %-25s:   +%d  ( %d Unit left)\n", topping3, priceTopping[3], unit[3]);
    printf("|                                                         |\n");
    printf("|MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM|\n");
    printf("|---------------------------------------------------------|\n");
}

int CreateAndCalculate()
{
    do
    {
        //select menu

        do
        {
            printf("Please select your base tea (enter 'q' to exit):");
            gets(menu);
            if ((menu[0] < 48 && menu[0] > 53 && menu[0] != 'q') || strlen(menu) > 1)
            {
                printf("Please re-select your base tea.\n");
            }
        } while ((menu[0] < 48 && menu[0] > 53 && menu[0] != 'q') || strlen(menu) > 1);

        rewind(stdin);
        if (menu[0] == 48)
        {
            sum += priceMenu[0];
            strcpy(order[0], menu0);
            break;
        }
        else if (menu[0] == 49)
        {
            sum += priceMenu[1];
            strcpy(order[0], menu1);
            break;
        }
        else if (menu[0] == 50)
        {
            sum += priceMenu[2];
            strcpy(order[0], menu2);
            break;
        }
        else if (menu[0] == 51)
        {
            sum += priceMenu[3];
            strcpy(order[0], menu3);
            break;
        }
        else if (menu[0] == 52)
        {
            sum += priceMenu[4];
            strcpy(order[0], menu4);
            break;
        }
        else if (menu[0] == 53)
        {
            sum += priceMenu[5];
            strcpy(order[0], menu5);
            break;
        }
        else if (menu[0] == 113)
        {
            mainly();
        }
        else
        {
            printf("Please re-select your base tea.\n");
        }

    } while (menu[0] != 113);

    do
    {
        //select size
        do
        {
            printf("Please select the size medium (m) or large (l) ? (enter 'q' to exit) : ");
            gets(size);
            if ((size[0] != 'l' && size[0] != 'm' && size[0] != 'q') || strlen(size) > 1)
            {
                printf("Please re-select your size.\n");
            }
        } while ((size[0] != 'l' && size[0] != 'm' && size[0] != 'q') || strlen(size) > 1);

        rewind(stdin);
        if (size[0] == 'm')
        {
            sum += priceSize[0];
            strcpy(order[1], "medium size");
            break;
        }
        else if (size[0] == 'l')
        {
            sum += priceSize[1];
            strcpy(order[1], "large size");
            break;
        }
        else if (size[0] == 'q')
        {
            mainly();
        }
        else
        {
            printf("Please re-select your size.\n");
        }
    } while (size[0] != 113);

    do
    {
        //select flavor
        do
        {
            printf("Please select your flavors (enter 'q' to exit) : ");
            gets(flavor);
            if ((flavor[0] < 48 && flavor[0] > 51 && flavor[0] != 'q') || strlen(flavor) > 1)
            {
                printf("Please re-select your flavor \n");
            }
        } while ((flavor[0] < 48 && flavor[0] > 51 && flavor[0] != 'q') || strlen(flavor) > 1);

        rewind(stdin);
        if (flavor[0] == '0')
        {
            sum += priceFlavor[0];
            strcpy(order[2], flavor0);
            break;
        }
        else if (flavor[0] == '1')
        {
            sum += priceFlavor[1];
            strcpy(order[2], flavor1);
            break;
        }
        else if (flavor[0] == '2')
        {
            sum += priceFlavor[2];
            strcpy(order[2], flavor2);
            break;
        }
        else if (flavor[0] == '3')
        {
            sum += priceFlavor[3];
            strcpy(order[2], flavor3);
            break;
        }
        else if (flavor[0] == 'q')
        {
            mainly();
        }
        else
        {
            printf("Please re-select your flavor \n");
        }

    } while (flavor[0] != 'q');

    do
    {
        //choose hom many topping do you want

        do
        {
            printf("How many toppings do you like (maximum 2) (enter 'q' to exit) : ");
            gets(topping);
            if ((topping[0] < '0' && topping[0] > '2' && topping[0] != 'q') || strlen(topping) > 1)
            {
                printf("is invalid!, please re-select.\n");
            }
        } while ((topping[0] < '0' && topping[0] > '2' && topping[0] != 'q') || strlen(topping) > 1);

        rewind(stdin);
        if (topping[0] == '0')
        {
            sum += 0;
            strcpy(order[3], "no topping");
            break;
        }
        //if you choose 1 or 2 topping
        else if (topping[0] == '1' || topping[0] == '2')
        {
            int count = 0, r = 1;
            do
            {
                do
                {
                    printf("Please select your toppings %d (enter 'q' to exit): ", r);
                    gets(toppings);
                    int topcheck = atoi(toppings);

                    if ((toppings[0] != '0' && toppings[0] != '1' && toppings[0] != '2' && toppings[0] != '3' && toppings[0] != 'q') || strlen(toppings) > 1)
                    {
                        printf("is invalid!, please re-select.\n");
                    }
                } while ((toppings[0] != '0' && toppings[0] != '1' && toppings[0] != '2' && toppings[0] != '3' && toppings[0] != 'q') || strlen(toppings) > 1);

                rewind(stdin);
                //check stock topping

                if (toppings[0] == '0' && (unit[0] == 0))
                {
                    printf("Sorry, the topping you chose is out of stock, please re-select.\n");
                }
                else if (toppings[0] == '0' && (unit[0] > 0))
                {
                    i = 0;
                    sum += priceTopping[0];
                    GIVECHANGESANDITEMUPDATEINVENTORY(unit, machinecashdum, i);
                    count++;
                    r++;
                    strcpy(order[r + 2], topping0);
                    printf("\nThis is toppings the rest.");
                    printf("\n0:%-25s: ( %d Unit left)", topping0, unit[0]);
                    printf("\n1:%-25s: ( %d Unit left)", topping1, unit[1]);
                    printf("\n2:%-25s: ( %d Unit left)", topping2, unit[2]);
                    printf("\n3:%-25s: ( %d Unit left)\n\n", topping3, unit[3]);
                }
                else if (toppings[0] == '1' && (unit[1] == 0))
                {
                    printf("Sorry, the topping you chose is out of stock, please re-select.\n");
                }
                else if (toppings[0] == '1' && (unit[1] > 0))
                {
                    i = 1;
                    sum += priceTopping[1];
                    GIVECHANGESANDITEMUPDATEINVENTORY(unit, machinecashdum, i);
                    count++;
                    r++;
                    strcpy(order[r + 2], topping1);
                    printf("\nThis is toppings the rest.");
                    printf("\n0:%-25s: ( %d Unit left)", topping0, unit[0]);
                    printf("\n1:%-25s: ( %d Unit left)", topping1, unit[1]);
                    printf("\n2:%-25s: ( %d Unit left)", topping2, unit[2]);
                    printf("\n3:%-25s: ( %d Unit left)\n\n", topping3, unit[3]);
                }
                else if (toppings[0] == '2' && (unit[2] == 0))
                {
                    printf("Sorry, the topping you chose is out of stock, please re-select.\n");
                }
                else if (toppings[0] == '2' && (unit[2] > 0))
                {
                    i = 2;
                    sum += priceTopping[2];
                    GIVECHANGESANDITEMUPDATEINVENTORY(unit, machinecashdum, i);
                    count++;
                    r++;
                    strcpy(order[r + 2], topping2);
                    printf("\nThis is toppings the rest.");
                    printf("\n0:%-25s: ( %d Unit left)", topping0, unit[0]);
                    printf("\n1:%-25s: ( %d Unit left)", topping1, unit[1]);
                    printf("\n2:%-25s: ( %d Unit left)", topping2, unit[2]);
                    printf("\n3:%-25s: ( %d Unit left)\n\n", topping3, unit[3]);
                }
                else if (toppings[0] == '3' && (unit[3] == 0))
                {
                    printf("Sorry, the topping you chose is out of stock, please re-select.\n");
                }
                else if (toppings[0] == '3' && (unit[3] > 0))
                {
                    i = 3;
                    sum += priceTopping[3];
                    GIVECHANGESANDITEMUPDATEINVENTORY(unit, machinecashdum, i);
                    count++;
                    r++;
                    strcpy(order[r + 2], topping3);
                    printf("\nThis is toppings the rest.");
                    printf("\n0:%-25s: ( %d Unit left)", topping0, unit[0]);
                    printf("\n1:%-25s: ( %d Unit left)", topping1, unit[1]);
                    printf("\n2:%-25s: ( %d Unit left)", topping2, unit[2]);
                    printf("\n3:%-25s: ( %d Unit left)\n\n", topping3, unit[3]);
                }
                else if (toppings[0] == 'q')
                {
                    for (i = 0; i < 4; i++)
                    {
                        unit[i] = reunit[i];
                    }

                    mainly();
                }
                if (count == topping[0] - '0')
                {
                    break;
                }

            } while (toppings[0] != 'q');
            break;
        }
        else if (topping[0] == 'q')
        {
            for (i = 0; i < 4; i++)
                    {
                        unit[i] = reunit[i];
                    }
            mainly();
            printf("\nThis is toppings the rest.");
            printf("\n0:%-25s: ( %d Unit left)", topping0, unit[0]);
            printf("\n1:%-25s: ( %d Unit left)", topping1, unit[1]);
            printf("\n2:%-25s: ( %d Unit left)", topping2, unit[2]);
            printf("\n3:%-25s: ( %d Unit left)\n\n", topping3, unit[3]);
            
        }
        else
        {
            printf("is invalid! Please try again.\n");
        }

    } while (topping[0] != 'q' && topping[0] != '2' && topping[0] != '1' && topping[0] != '0');

    printf("\nTotal price: %d\n", sum);

    do
    {
        printf("Are you ready to pay (y/n)? (enter 'q' to exit)");
        gets(ready);
        if ((ready[0] != 'y' && ready[0] != 'n' && ready[0] != 'Y' && ready[0] != 'N' && ready[0] != 'q' && ready[0] != 1) || strlen(ready) > 1)
        {
            printf("is invalid\n");
        }
    } while ((ready[0] != 'y' && ready[0] != 'n' && ready[0] != 'Y' && ready[0] != 'N' && ready[0] != 'q' && ready[0] != 1) || strlen(ready) > 1);

    if (ready[0] == 'y') //
    {
        return 1;
    }
    else if (ready[0] == 'n')
    {
        for (i = 0; i < 4; i++)
                    {
                        unit[i] = reunit[i];
                    }
        for (i = 0; i < 4; i++)
        {
            printf("%d ", unit[i]);
        }
        mainly();
    }
    else if (ready[0] == 'q')
    {
        for (i = 0; i < 4; i++)
                    {
                        unit[i] = reunit[i];
                    }
        mainly();
    }
    return 0;
}
void CALCULATECHANGES()
{

    change = TotalMoney - sum;
    printf("This is the change you will recive.: %d\n", change);
    //part of function calculate from money to bangnote
    bangnote = (int)change / 100;
    returncash[0] = bangnote;
    printf("\n%d Note of 100.00\n", bangnote);
    change = change - (bangnote * 100);

    bangnote = (int)change / 50;
    returncash[1] = bangnote;
    printf("%d Note of 50.00\n", bangnote);
    change = change - (bangnote * 50);

    bangnote = (int)change / 20;
    returncash[2] = bangnote;
    printf("%d Note of 20.00\n", bangnote);
    change = change - (bangnote * 20);

    bangnote = (int)change / 10;
    returncash[3] = bangnote;
    printf("%d Note of 10.00\n", bangnote);
    change = change - (bangnote * 10);

    bangnote = (int)change / 5;
    returncash[4] = bangnote;
    printf("%d Note of 5.00\n", bangnote);
    change = change - (bangnote * 5);

    for (i = 0; i < 5; i++)
    {
        machinecash[i] += atoi(InputMoney[i]);
    }
    GIVECHANGESANDITEMUPDATEINVENTORY(returncash, machinecash, i);
    for (i = 0; i < 5; i++)
    {
        printf("%d ", machinecash[i]);
    }
    for (i = 0; i < 5; i++)
    {
        if (machinecash[i] < 0)
        {
            printf("Sorry,cash change is not enough");
            for (i = 0; i < 4; i++)
                    {
                        unit[i] = reunit[i];
                    }
            mainly();
        }
    }

    printf("\n\nHere is your %s %s %s %s%s!\n", order[0], order[1], order[2], order[3], order[4]);
    printf("\nMachine cash:\n");

    printf("This is money left.\n");
    printf("%d : Note of 100\n", machinecash[0]);
    printf("%d : Note of 50 \n", machinecash[1]);
    printf("%d : Note of 20\n", machinecash[2]);
    printf("%d : Note of 10\n", machinecash[3]);
    printf("%d : Note of 5\n", machinecash[4]);
}

void InsertCash()
{
    //Check
    int CompleteYet = 0;

    for (i = 0; i < 5; i++)
    {
        money1[i] = 0;
    }
    for (i = 0; i < 5; i++)
    {
        MoneyChange[i] = 0;
    }
    for (i = 0; i < 5; i++)
    {
        bank[i] = 0;
    }
    if (ready[0] == 'y')
    {

        do
        {
            printf("Machine cash: (");
            for (i = 0; i < 5; i++)
            {
                printf("%d=%d,", machinebanknote[i], machinecash[i]);
            }
            printf(")\n");
            //cash that you aree going to insert
            printf("Please insert cash (enter 'q' to exit): \n");

            do
            {
                do
                {
                    printf("100:");
                    rewind(stdin);
                    fgets(InputMoney[0], 10, stdin);

                    if (InputMoney[0][0] == 'q')
                    {
                        for (i = 0; i < 4; i++)
                    {
                        unit[i] = reunit[i];
                    }
                        mainly();
                    }
                } while (InputMoney[0][0] < '0' || InputMoney[0][0] > '9' || InputMoney[0][0] == '-' || strlen(InputMoney[0]) > 2);

                do
                {
                    printf("50:");
                    rewind(stdin);
                    fgets(InputMoney[1], 10, stdin);

                    if (InputMoney[1][0] == 'q')
                    {
                        for (i = 0; i < 4; i++)
                    {
                        unit[i] = reunit[i];
                    }
                        mainly();
                    }
                } while (InputMoney[1][0] < '0' || InputMoney[1][0] > '9' || InputMoney[1][0] == '-' || strlen(InputMoney[1]) > 2);

                do
                {
                    printf("20:");
                    rewind(stdin);
                    fgets(InputMoney[2], 10, stdin);

                    if (InputMoney[2][0] == 'q')
                    {
                        for (i = 0; i < 4; i++)
                    {
                        unit[i] = reunit[i];
                    }
                        mainly();
                    }
                } while (InputMoney[2][0] < '0' || InputMoney[2][0] > '9' || InputMoney[2][0] == '-' || strlen(InputMoney[2]) > 2);

                do
                {
                    printf("10:");
                    rewind(stdin);
                    fgets(InputMoney[3], 10, stdin);

                    if (InputMoney[3][0] == 'q')
                    {
                        for (i = 0; i < 4; i++)
                    {
                        unit[i] = reunit[i];
                    }
                        mainly();
                    }
                } while (InputMoney[3][0] < '0' || InputMoney[3][0] > '9' || InputMoney[3][0] == '-' || strlen(InputMoney[3]) > 2);

                do
                {
                    printf("5:");
                    rewind(stdin);
                    fgets(InputMoney[4], 10, stdin);
                    if (InputMoney[4][0] == 'q')
                    {
                        for (i = 0; i < 4; i++)
                    {
                        unit[i] = reunit[i];
                    }
                        mainly();
                    }
                } while (InputMoney[4][0] < '0' || InputMoney[4][0] > '9' || InputMoney[4][0] == '-' || strlen(InputMoney[4]) > 2);

                //Char to int
                MoneyChange[0] = atoi(InputMoney[0]);
                MoneyChange[1] = atoi(InputMoney[1]);
                MoneyChange[2] = atoi(InputMoney[2]);
                MoneyChange[3] = atoi(InputMoney[3]);
                MoneyChange[4] = atoi(InputMoney[4]);

                for (int i = 0; i < 5; i++)
                {
                    if (MoneyChange[i] < 0)
                    {
                        checkloop = 1;
                    }
                }

            } while (checkloop == 1);

            if (machinecash[0] == 0 && machinecash[1] == 0 && machinecash[2] == 0 && machinecash[3] == 0 && machinecash[4] == 0)
            {
                printf("Not enough cash to give change! ");
            }

            MoneyChange[0] *= 100;
            MoneyChange[1] *= 50;
            MoneyChange[2] *= 20;
            MoneyChange[3] *= 10;
            MoneyChange[4] *= 5;

            //for check that MoneyChange is assign valuable from money1

            for (i = 0; i < 5; i++)
            {
                TotalMoney += MoneyChange[i];
            }
            printf("Total money: ");
            printf("%d \n", TotalMoney);
            //it is going to change

            if (TotalMoney >= sum)
            {
                CALCULATECHANGES();
                CompleteYet = 1;
            }
            else
            {
                //your money cant buy a tea you should add more
                printf("Sorry, your payment is not enough, add more (y/n)");
                scanf("%c", &add);
                if (add == 'y')
                {
                    for (i = 0; i < 5; i++)
                    {
                        money1[i] = 0;
                    }
                    continue;
                }
                else if (add == 'n')
                {
                    change = TotalMoney;
                    printf("This is the change you will recive.: %d\n", change);
                    //part of function calculate from money to bangnote
                    bangnote = (int)change / 100;
                    returncash[0] = bangnote;
                    printf("\n%d Note of 100.00\n", bangnote);
                    change = change - (bangnote * 100);

                    bangnote = (int)change / 50;
                    returncash[1] = bangnote;
                    printf("%d Note of 50.00\n", bangnote);
                    change = change - (bangnote * 50);

                    bangnote = (int)change / 20;
                    returncash[2] = bangnote;
                    printf("%d Note of 20.00\n", bangnote);
                    change = change - (bangnote * 20);

                    bangnote = (int)change / 10;
                    returncash[3] = bangnote;
                    printf("%d Note of 10.00\n", bangnote);
                    change = change - (bangnote * 10);

                    bangnote = (int)change / 5;
                    returncash[4] = bangnote;
                    printf("%d Note of 5.00\n", bangnote);
                    change = change - (bangnote * 5);
                    for (i = 0; i < 4; i++)
                    {
                        unit[i] = reunit[i];
                    }
                    getchar();
                    getch();
                    mainly();
                }
                else if (add == 'q')
                {
                    for (i = 0; i < 4; i++)
                    {
                        unit[i] = reunit[i];
                    }
                    mainly();
                }
                else
                {
                    printf("is invalid");
                    continue;
                }
            }

        } while (ready[0] != 'q' && CompleteYet != 1);
    }
}

void Clear()
{
    i = 0, sum = 0, k = 0;
    count = 0;
    j = 0, TotalMoney = 0, change = 0, bangnote = 0;
    checkloop = 0;

    for (i = 0; i < 5; i++)
    {
        machinecashdum[i] = 0;
        MoneyChange[i] = 0;
        bank[i] = 0;
        returncash[i] = 0;
        money1[i] = 0;
    }
    for (i = 0; i < 4; i++)
    {
        unitdum[i] = 0;
        total[i] = 0;
    }
}

void mainly()
{
    while (1)
    {
        Clear();
        system("@cls||clear");
        int a = 0;
        Display();
        a += CreateAndCalculate();
        InsertCash();
        //Hold screen without any buffer
        int hold;
        while ((hold = getchar()) != '\n' && hold != EOF);
    }
}

int main()
{
    mainly();
    // while (1)
    // {
    //     Clear();
    //     system("@cls||clear");
    //     int a = 0;
    //     Display();
    //     a += CreateAndCalculate();
    //     InsertCash();
    //     //Hold screen without any buffer
    //     int hold;
    //     while ((hold = getchar()) != '\n' && hold != EOF)
    //         ;
    // }
}