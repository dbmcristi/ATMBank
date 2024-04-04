//
// Created by Cristian on 4/3/2023.
//
#ifndef ATMBANK_TRANSACTION_H
#define ATMBANK_TRANSACTION_H

class Transaction {
private:
    int idtrans;
    int sum;
    int noElements;
    int type[100] = {};
    int occurrences[100] = {};

public:
    Transaction();
    Transaction(int sum, int noElements);
    Transaction(int suma, int noElements, int tip[], int occ[]);
    void set_new_type_transaction(int type, int position);
    void set_new_occurrence_tranzaction(int occ, int position);

    int get_type(int position);
    int get_occ(int position);
    int get_id(){
        return this->idtrans;
    }

    void set_noElements(int nr);
    void set_id(int nr);
    int get_noElements(){
        return this->noElements;
    }
    void set_sum(int sum);
};

#endif //ATMBANK_TRANSACTION_H