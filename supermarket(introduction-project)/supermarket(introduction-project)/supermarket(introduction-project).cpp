#include <iostream>
#include<stdlib.h>//cls
#include<iomanip>//setw
using namespace std;
string id[50];    // global variables 
double price[50];
int c = 0; // counter to display the exact number the user entered 
void enter()
{
    char x;
    double tempP;
    string tempID;
    do { //to enter data
        cout << "enter the items ID :";
        cin >> id[c];
        cout << "enter the price :";
        cin >> price[c];
        cout << "if you want to continue press'c' and to return to menu press any button :";
        cin >> x;
        c++;
        if (x != 'c' && x != 'C') {
            system("CLS");
        }
        if (c == 50) {//so the data doesnt exceed 50 items
            cout << "you have reached the MaxIMUM capacity ofthe storage!" << endl;
            break;
        }



    } while (x == 'c' || x == 'C');


    for (int i = 0; i < c; i++) {//sorting prices ascending by swaping 
        for (int j = i + 1; j < c; j++) {
            if (price[i] > price[j]) {
                tempP = price[i];
                tempID = id[i];
                price[i] = price[j];
                id[i] = id[j];
                price[j] = tempP;
                id[j] = tempID;
            }
        }
    }



}
void display() {

    char z;
    if (c == 0)cout << "THERE IS NOTHING TO DISPLAY" << endl;
    else {
        cout << "The Id " << setw(20) << "The price" << endl;

        for (int i = 0; i < c; i++) {


            cout << i + 1 << " | " << id[i] << setw(15) << price[i] << endl;
        }

    }
    cout << "to return to the main menu press 'm'";
    cin >> z;
    if (z == 'm') {
        system("CLS");
    }

}
void retrive() {

    string x; // the id that the user is going to enter 
    if (c == 0)cout << "no items found";
    else {
        cout << "enter the items id you want to know its price" << endl;
        cin >> x;
        for (int i = 0; i < c; i++) {
            if (x == id[i]) {
                cout << "The items price is" << price[i] << endl;
            }
        }
    }
}
void range() {
    double x, y;//price range 
    char m;
    bool check = true; // to check wether there is prices in the range the user entered or not 
    if (c == 0)cout << "no items found " << endl;
    else {
        cout << "Enter the start of your price range : ";
        cin >> x;
        cout << "enter the end of your price range : " << endl;
        cin >> y;
        cout << "The Id " << setw(20) << "The price" << endl;
        for (int i = 0; i < c; i++) {
            if (price[i] >= x && price[i] <= y) {
                check = false;
                cout << id[i] << setw(10) << price[i] << endl;
            }
        }
    }                              if (check == true) {
        cout << "sorry,no items found  in that price range " << endl;

    }



    cout << "to return to the main menu press 'm'";
    cin >> m;
    if (m == 'm') system("CLS");

}
void deleteElement() {

    int x;// user choice 

    cout << "The Id " << setw(20) << "The price" << endl;

    for (int i = 0; i < c; i++) {                             // same as display function so the user can choose which item to delete


        cout << i + 1 << " | " << id[i] << setw(15) << price[i] << endl;
    }

    cout << "which item you want to delete";
    cin >> x;
    if (x <= c) {
        cout << "The Id " << setw(20) << "The price" << endl;
        for (int i = (x - 1); i < c; i++) {
            id[i] = id[i + 1];
            price[i] = price[i + 1];
        }
        c--;// the counter decrement because we removed an item so in order for us to replace it and doesnt take a space from memory as zeros
        for (int i = 0; i < c; i++) {
            //the items will be displayed after delete operation
            cout << i + 1 << " | " << id[i] << setw(15) << price[i] << endl;

        }

        cout << "****************item deleted successfully**************************" << endl;
    }
    else if (x > c) {
        cout << "invalid choice" << endl;
    }



}
void deleteAll() {
    int x;
    cout << "are you sure you want to delete all items ?" << endl;
    cout << "1)YES " << setw(20) << "2)NO" << endl;
    cin >> x;
    if (x == 1) {
        c = 0; // so that if the user wants to enter again we start from the begining 
        cout << "all items are deleted" << endl;
    }

}
int main()
{

    char select;
    do {

        cout << "main menu:" << endl;
        cout << "1.Enter an items id and price" << endl;
        cout << "2.retrieve the price of a specific item" << endl;
        cout << "3.display all items within a specific range" << endl;
        cout << "4.delete an item" << endl;
        cout << "5.display all elements" << endl;
        cout << "6.delete all items" << endl;
        cout << "NOTE::: if you want to exsit the programme press 'e'" << endl;
        cout << "**********************************" << endl;
        cout << "enter your selection please" << endl;
        cout << "************************************" << endl;
        cin >> select;
        system("CLS");
        switch (select) {
        case'1':

            enter();
            break;
        case'2':
            retrive();
            break;
        case'3':
            range();
            break;
        case'4':
            deleteElement();
            break;
        case'5':
            display();
            break;
        case'6':
            deleteAll();
            break;
        case'e':
            return 0;
        }
    } while (select != 'e');

}
