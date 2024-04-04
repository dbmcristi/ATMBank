//
// Created by Cristian on 4/3/2023.
//
#include "ATM.h"

ATM::ATM() {
    this->banknotes = Collection();
    this->noTransactions = 0;
    this->capacity = 10;
    this->transaction = new Transaction[10];
}

ATM::ATM(Collection collection) {
    this->transaction = new Transaction[10];
    this->capacity = 10;
    this->noTransactions = 0;
    this->banknotes.operator=(collection);
}

void ATM::resize() {
    capacity *= 2;
    auto *tmp = new Transaction[this->capacity];
    for (int i = 0; i < this->noTransactions; i++) {
        tmp[i] = this->transaction[i];
    }
    delete[] this->transaction;
    this->transaction = tmp;
}

void ATM::transactionAdd(Transaction transaction) {
    if (noTransactions == capacity)
        resize();

    transaction.set_id(this->noTransactions);
    for (int poz = 0; poz < transaction.get_noElements(); poz++) {

        int elem = transaction.get_type(poz);
        int occ_bank = banknotes.get_occurrences_element(elem);
        int occ_transaction = transaction.get_occ(poz);
        banknotes.setOccurrences(elem, occ_bank - occ_transaction);
    }
    this->transaction[noTransactions] = transaction;
    this->noTransactions += 1;
}

int ATM::getNoTransaction() {
    return this->noTransactions;
}

Transaction ATM::checkSum(int sum) {
    int size = banknotes.size();
    int sumCopy = sum;
    int val, occ;
    int indexTrans = 0, indexBank = 0;

    Transaction transaction = Transaction();
    transaction.set_sum(sumCopy);

    while (indexBank < size && sumCopy) {
        val = banknotes.get_val(indexBank);
        if (sumCopy / val != 0) {
            occ = sumCopy / val;

            if (occ > banknotes.get_occ(indexBank) && occ != 0)
                occ = banknotes.get_occ(indexBank);
            transaction.set_new_type_transaction(val, indexTrans);
            transaction.set_new_occurrence_tranzaction(occ, indexTrans);
            sumCopy -= occ * val;
            indexTrans++;
        }
        indexBank++;
    }
    transaction.set_noElements(indexTrans);

    if (size == 0 || sumCopy != 0) {
        transaction = Transaction();
        return transaction;
    }
    return transaction;
}

Collection ATM::getCollection() {
    return banknotes;
}



Transaction *ATM::getAllTransactions() {
    return this->transaction;
}