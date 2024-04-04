//
// Created by Cristian on 4/3/2023.
//
#ifndef ATMBANK_COLLECTION_H
#define ATMBANK_COLLECTION_H
typedef int TElem;

class Collection {
private:
    TElem *value;
    int *occurrences;
    int distinctElements;
    int capacity;
public:
    Collection();
    void add(TElem v, int k);
    void resize();
    int size();

    int get_occ(int poz);
    int get_val(int poz);

    int get_occurrences_element(TElem elem);

    void setOccurrences(TElem elem, int occ);
    int searchPoz(TElem v);
    Collection& operator=(Collection colectie);

    ~Collection();

    void print();
};

#endif //ATMBANK_COLLECTION_H