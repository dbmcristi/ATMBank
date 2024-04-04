//
// Created by Cristian on 4/3/2023.
//

#include "Transaction.h"

Transaction::Transaction() {
    this ->noElements = 0;
}

Transaction::Transaction(int sum, int noElements) {
    this-> sum = sum;
    this -> noElements = noElements;
}

void Transaction::set_new_type_transaction(int type, int position) {
    this->type[position] = type;
}

void Transaction::set_new_occurrence_tranzaction(int occ, int position) {
    this->occurrences[position] = occ;
}

int Transaction::get_type(int position) {
    return this->type[position];
}

int Transaction::get_occ(int position) {
    return occurrences[position];
}

void Transaction::set_sum(int sum) {
    this->sum = sum;
}

void Transaction::set_noElements(int nr) {
    this->noElements = nr;
}

Transaction::Transaction(int sum, int noElements, int tip[], int occ[]) {
    this-> sum = sum;
    this -> noElements = noElements;
    for(int i = 0; i < noElements; i++){
        this->type[i] = tip[i];
        this->occurrences[i] = occ[i];
    }
}

void Transaction::set_id(int nr) {
    this->idtrans = nr;
}
