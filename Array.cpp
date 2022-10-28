#include "Array.h"
#include "err.h"
#include "typesErr.h"
#include "examination.h"

void Array::Check() {
    if (_N > _capacity) {
        _A = (Book**)realloc(_A, (_capacity + 10) * sizeof(Book*));
        _capacity += 10;
    }
}
void Array::Add(Book* obj) {
    ++_N;
    Check();
    _A[_N - 1] = obj;
}

void Array::DelAll() {
    for (int i = 0; i < _N; ++i)
        delete _A[i];
    _N = 0;
    _capacity = 0;
    free(_A);
    _A = NULL;
}
void Array::DelIndex(int index) {
    delete _A[index];
    for (int i = index; i < _N; ++i)
        _A[i] = _A[i + 1];
    --_N;
}
Book** Array::Get() {
    return _A;
}
Book* Array::Element(int index)
{
    if (index < 0 || index >= _N) 
        throw EElement();
    return _A[index];
}
void Array::AddIndex(Book* obj, int index) {
    ++_N;
    Check();
    for (int i = _N - 1; i > index; --i) {
        _A[i] = _A[i - 1];
    }
    _A[index] = obj;
}

void Array::Sort(int(*bool_compar)(const Book&, const Book&)) {
    for (int i = 0; i < _N - 1; ++i)
    {
        bool swapped = false;
        for (int j = 0; j < _N - i - 1; ++j)
        {
            if ((*bool_compar)(*_A[j], *_A[j + 1]) == 1)
            {
                Book* tmp = _A[j];
                _A[j] = _A[j + 1];
                _A[j + 1] = tmp;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

int Array::Count() {
    return _N;
}

void Array::Write(FILE* file) {
    for (int i = 0; i < _N; ++i)
    {
        fprintf(file, "%s %s %s %s %s %d\n", _A[i]->GetCip(), _A[i]->GetLast(), _A[i]->GetFirst(), _A[i]->GetPatron(), _A[i]->GetName(), _A[i]->GetYear());
    }
    fclose(file);
}

void Array::Read(FILE* file) {
    char cip[255], firstname[255], lastname[255], patron[255], name[255], year[10];
    
    while (!feof(file)) {
        if (fscanf_s(file, "%s\t%s\t%s\t%s\t\%s\t%s\n", cip, 10, lastname, 25, firstname, 25, patron, 25, name, 50, year, 5) == 6) {
            Book* tmp = new Book(cip, lastname, firstname, patron, name, atoi(year));
            this->Add(tmp);
        }
    }
    fclose(file);
}

Array* Array::SearchBook(char* str) {
    Array* newcoll = new Array();
    for (int i = 0; i < _N; ++i) {
        if (Examination(_A[i]->GetName(), str)) {
            Book* _NewA = new Book(*_A[i]);
            newcoll->Add(_NewA);
        }
    }
    return newcoll;
}

Array::Array(int _initialcapacity) {
    if (_initialcapacity > 0) {
        _capacity = _initialcapacity;
        _A = (Book**)realloc(_A, _capacity * sizeof(Book*));
    }
    else
        throw "Error!";
}

Array::Array()
    : _capacity(0), _N(0), _A(NULL)
{
}

Array::~Array()
{
    DelAll();
}