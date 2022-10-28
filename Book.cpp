#include "Book.h"

void Book::SetName(const char* name) { strcpy_s(_name, 100, name); } // copy _name in name
void Book::SetPatron(const char* patron) { strcpy_s(_patron, 100, patron); } // copy _patron in patron
void Book::SetLast(const char* last) { strcpy_s(_lastname, 100, last); }
void Book::SetFirst(const char* first) { strcpy_s(_firstname, 100, first); }
void Book::SetCip(const char* cip) { strcpy_s(_cip, 100, cip); }
void Book::SetYear(int year) { _year = year; }

const char* Book::GetName() const { return _name; }
const char* Book::GetCip() const { return _cip; }
const char* Book::GetPatron() const { return _patron; }
const char* Book::GetLast() const { return _lastname; }
const char* Book::GetFirst() const { return _firstname; }
int Book::GetYear() const{ return _year; }
Book::Book(Book& A)
{
    SetName(A.GetName());
    SetPatron(A.GetPatron());
    SetLast(A.GetLast());
    SetFirst(A.GetFirst());
    SetCip(A.GetCip());
    SetYear(A.GetYear());
}
Book::Book(char* cip, char* firstname, char* lastname, char* patron, char* name, int year = 0)
{
    SetName(name);
    SetPatron(patron);
    SetLast(lastname);
    SetFirst(firstname);
    SetCip(cip);
    SetYear(year);
}
Book::~Book()
{
}