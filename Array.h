#pragma once
#include "Book.h"

class Array {
private:
    int _capacity = 0;
    int _N = 0;
    Book** _A;
    void Check();
public:
    void Add(Book* obj);
    void DelAll();
    void DelIndex(int index);
    Book* Element(int index);
    void AddIndex(Book* obj, int index);
    void Sort(int(*bool_compar)(const Book&, const Book&));
    int Count();
    Book** Get();
    void Write(FILE* file);
    void Read(FILE* file);
    Array* SearchBook(char* str);
    Array(int _initialcapacity);
    Array();
    ~Array();
};