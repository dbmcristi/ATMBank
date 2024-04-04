//
// Created by Cristian on 4/3/2023.
//
#include "Consola.h"
#include "../collection/Collection.h"
#include "../atm/ATM.h"
#include <iostream>

using namespace std;

void printMenu() {
    cout << "1. Add banknotes\n";
    cout << "2. Add transaction\n";
    cout << "3. Print banknotes\n";
    cout << "4. Print transaction\n";
    cout << "0. Exit\n";
}

void bancknotes(Collection &collection) {
    int n;
    cout << "Total banknotes types number: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int value, howMany;
        cout << "Banknote's type. Input the value: ";
        cin >> value;
        cout << "Banknote's type. Input the number: ";
        cin >> howMany;
        collection.add(value, howMany);
    }
}

void init(ATM &atm, Collection &collection) {
    atm = ATM(collection);
}

void atmPrint(ATM &atm) {
    int size = atm.getCollection().size();
    cout <<endl;
    for (int poz = 0; poz < size; poz++) {
        cout << "value: " << atm.get_val(poz) <<
             ", quantity:" << atm.get_occ(poz) << endl;
    }
}

void transactionPrint(Transaction t) {
    int size = t.get_noElements();
    cout <<endl;
    for (int pos = 0; pos < size; pos++) {
        cout << "value: " << t.get_type(pos) <<
             ", quantity: " << t.get_occ(pos) << endl;
    }
}

void task2(ATM &atm) {

    int suma;
    cout << "Transaction value ...";
    cin >> suma;
    Transaction t = atm.checkSum(suma);
    int size = t.get_noElements();

    if (size == 0)
        cout << "No bancknotes availables. \n";
    else {
        transactionPrint(t);
        cout << "Press 1 for SAVE or 0 for CANCEL ...";
        bool ok;
        cin >> ok;
        if (ok)
            atm.transactionAdd(t);
    }
}

void task4(ATM atm) {
    Transaction *tranz = atm.getAllTransactions();
    int size = atm.getNoTransaction();
    for (int poz = 0; poz < size; poz++) {
        cout << "Transaction id: " << tranz[poz].get_id();
        cout <<endl;
        transactionPrint(tranz[poz]);
        cout << endl;
    }
}

void Consola::consola() {
    int option;
    ATM atm = ATM();
    Collection colectie = Collection();

    while (true) {
        printMenu();
        cout << "Option: ";
        cin >> option;
        if (option == 1) {
            bancknotes(colectie);
            init(atm, colectie);
            cout << endl;
        } else if (option == 2) {
            task2(atm);
        } else if (option == 3) {
            atmPrint(atm);
            cout << endl;
        } else if (option == 4) {
            task4(atm);
        } else if (option == 0) {
            break;
        }
    }
}
