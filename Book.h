#pragma once

#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

class Book {
private:
    char _cip[100] = { 0 };
    char _firstname[100] = { 0 };
    char _lastname[100] = { 0 };
    char _patron[100] = { 0 };
    char _name[100] = { 0 };
    int _year;
public:
    void SetName(const char* name); // copy _name in name
    void SetPatron(const char* patron); // copy _patron in patron
    void SetLast(const char* last);
    void SetFirst(const char* first);
    void SetCip(const char* cip);
    void SetYear(int year);

    const char* GetName() const;
    const char* GetCip() const;
    const char* GetPatron() const;
    const char* GetLast() const;
    const char* GetFirst() const;
    int GetYear() const;
    Book(Book& A);
    Book(char* cip, char* firstname, char* lastname, char* patron, char* name, int year);
    ~Book();
};


