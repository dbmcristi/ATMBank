//
// Created by Cristian on 4/3/2023.
//
#include "Collection.h"
#include <iostream>
using namespace std;

Collection ::Collection() {
    this->capacity=10;
    this->value = new TElem [capacity](); //v1, v2, ..., vn
    this -> occurrences = new TElem [capacity](); //k1, k2, ..., kn
    this -> distinctElements = 0;
}

int Collection :: size(){
    return distinctElements;
}

void Collection :: resize(){
    capacity *= 2;
    auto *tmp = new TElem[this -> capacity];
    for(int i = 0 ; i < this -> distinctElements; ++i){
        tmp[i] = this -> value[i];
    }
    delete [] this -> value;
    this -> value = tmp;

    int *tmp2 = new int[this -> capacity];
    for(int i=0; i < this -> distinctElements; ++i){
        tmp2[i] = this -> occurrences[i];
    }
    delete [] this -> occurrences;
    this -> occurrences = tmp2;
    delete[]tmp;
    tmp= nullptr;
    delete[]tmp2;
    tmp2= nullptr;
}

void Collection::add(TElem v, int k){
    if (distinctElements == capacity)
        resize();
    value[distinctElements] = v;
    occurrences[distinctElements] = k;
    distinctElements +=1;
}

Collection::~Collection() {
}


int Collection::get_occ(int poz) {
    return this->occurrences[poz];
}

int Collection::get_val(int poz) {
    return this->value[poz];
}

void Collection::setOccurrences(TElem elem, int occ){
    if(searchPoz(elem) != -1){
        this->occurrences[searchPoz(elem)] = occ;
    }
}

int Collection :: searchPoz(TElem v){
    int i = 0;
    while(i < distinctElements){
        if(value[i] == v) return i;
        i++;
    }
    return -1;
}

void Collection::print() {
    for (int i = 0; i < distinctElements; i++) {
        cout << value[i] << " " << occurrences[i] << endl;
    }
}

Collection &Collection::operator=(Collection colectie) {
    this->distinctElements = colectie.distinctElements;
    this->capacity = colectie.capacity;
    this->occurrences = new TElem [capacity];
    this->value = new TElem [capacity];
    for(int i = 0; i < distinctElements; i++){
        occurrences[i] = colectie.get_occ(i);
        value[i] = colectie.get_val(i);
    }

    return *this;
}

int Collection::get_occurrences_element(TElem elem) {
    return this->occurrences[searchPoz(elem)];
}
