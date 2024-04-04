//
// Created by Cristian on 4/3/2023.
//
#ifndef ATMBANK_ATM_H
#define ATMBANK_ATM_H
#include "../collection/Collection.h"
#include "../transaction/Transaction.h"

class ATM {
private:
    Collection banknotes;
    Transaction *transaction;
    int noTransactions;
    int capacity;

public:
    ATM();
    ATM(Collection colectie);
    void transactionAdd(Transaction transaction);
    Transaction checkSum(int sum);
    void resize();
    Collection getCollection();

    int get_occ(int pos){
        return this->banknotes.get_occ(pos);
    }
    int get_val(int pos){
        return this->banknotes.get_val(pos);
    }

    Transaction *getAllTransactions();

    ~ATM(){

}

    int getNoTransaction();
};

#endif //ATMBANK_ATM_H