/*
???????????? ?????? ????? 3 ??????? 17 (2)
???????? ??????
6113
*/
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <conio.h>
#include <windows.h>
#include <time.h>

using namespace std;


class ESetError {
public:
    virtual void Print() const = 0 {};
};
class EAlreadyExists : public ESetError {
private: 
    char* value;
public:
    void Print() const override {
        cout << "Книга " << value << " уже существует!" << endl;
    }
    EAlreadyExists(char* name)
        : value(name)
    {
    }
};
class ENotExists : public ESetError {
private:
    int _value;
public:
    void Print() const override {
        cout << "Объект index = " << _value << " не существует!" << endl;
    }
    ENotExists(int value)
        : _value(value)
    {
    }
};
class Main {
public:
    virtual void Print() const = 0 {};
};
class Book : public Main {
protected:
    char* _cip, * _firstname, * _lastname, * _name;
    int _year;
public:
    char* getName() { return _name; }
    void Print() const override {
        cout << "CIP: " << _cip << endl << "FIO: " << _firstname << " " << _lastname << endl << "Book Name:" << _name << endl << "Year: " << _year << endl;
    }
    Book(char* cip, char* firstname, char* lastname, char* name, int year = 0)
        :_cip(cip), _firstname(firstname), _lastname(lastname), _name(name), _year(year)
    {
    }
    ~Book()
    {
    }
};
class Array {
private:
    int _N;
    Main** _A;
public:
    bool IsExist(char* value) {
        for (int i = 0; i < _N; ++i) {
            if (_A[i]->_name == value) throw EAlreadyExists(value);
        }
        return true;
    }
    void Add(Main* obj) {
        ++_N;
        _A = (Main**)realloc(_A, _N * sizeof(Main*));
        _A[_N - 1] = obj;
    }
    void DelAll() {
        for (int i = 0; i < _N; ++i)
            delete _A[i];
        _N = 0;
        _A = (Main**)realloc(_A, _N * sizeof(Main*));
    }
    void DelIndex(int index) {
        delete _A[index];
        for (int i = index; i < _N; ++i)
            _A[index] = _A[index + 1];
        --_N; 
        _A = (Main**)realloc(_A, _N * sizeof(Main*));
    }
    Main* Element(int index)
    {
        if (index >= _N) throw "invalid index";
        return _A[index];
    }
    void AddIndex(Main* obj, int index) {
        ++_N;
        for (int i = index; i < _N; ++i) {
            _A[i + 1] = _A[i];
        }
        _A = (Main**)realloc(_A, _N * sizeof(Main*));
        _A[index] = obj;
    }
    void Sort() {
        // sort()
    }
    int Number() {
        return _N;
    }
    void PrintC() const
    {
        for (int i = 0; i < _N; ++i)
        {
            _A[i]->Print();
        }
        cout << "[0] Back-->";
    }
    void Read(char* filename) {
        //FILE* fp = fopen(filename, "w");
    }
    Array() 
        : _N(0), _A(NULL)
    {
    }
    ~Array()
    {
    }
};
int Menu() {
    int key = _getch();
    if (key == 49 || key == 50 || key == 51 || key == 52 || key == 53 || key == 54 || key == 55 || key == 8)
        return key;
    return 0;
}

int main()
{
    //setlocale(LC_ALL, "Rus");
    char a[255], b[255], c[255], d[255];
    int y;
    Array* coll = new Array();
    cout << "[1] Open the File"
        << endl << "[2] Add Object"
        << endl << "[3] Save in File"
        << endl << "[4] Output all list books"
        << endl << "[5] Access to an element by index"
        << endl << "[6] Deleting one object by index"
        << endl << "[7] Deleting all objects"
        << endl << "[8] Insertion of an element before element with the specified index"
        << endl << "[9] Numbers All"
        << endl << "[S] Function Sort"
        << endl << "[BackSpace] Exit"
        << endl << "-->";
    while (true) {
        int commandKey = Menu();
        if (commandKey == 8)
            break;
        switch (commandKey) {
        case '1':
            system("cls");
            cout << "Please enter the path to the file--> ";
            cin >> a;
            coll->Read(a); // read the file
            break;
        case '2':
            system("cls");
            cout << "Input CIP--> ";
            cin >> a;
            cout << "Input FirstName--> ";
            cin >> b;
            cout << "Input LastName--> ";
            cin >> d;
            while (true) {
                cout << "Input Book Name--> ";
                cin >> c;
                if (coll->IsExist(c)) break;
            }
            cout << "Input Year--> ";
            cin >> y;
            coll->Add(new Book(a, b, d, c, y));
            system("cls");
            cout << "Added! [0] Back-->";
            coll->IsExist(c);
            break;
        case '3':
            system("cls");
            cout << "Please input name file--> ";
            cin >> a;
            cout << "Please input the path file--> ";
            cin >> b;
            system("cls");
            cout << "File is Saved! [0] Back--> ";
            break;
        case '4':
            system("cls");
            coll->PrintC();
            break;
        case 0:
            system("cls");
            cout << "[1] Open the File"
                << endl << "[2] Add Object"
                << endl << "[3] Save in File"
                << endl << "[4] Output all list books"
                << endl << "[5] Access to an element by index"
                << endl << "[6] Deleting one object by index"
                << endl << "[7] Deleting all objects"
                << endl << "[8] Insertion of an element before element with the specified index"
                << endl << "[9] Numbers All"
                << endl << "[S] Function Sort"
                << endl << "[BackSpace] Exit" 
                << endl << "-->";
            break;
        default:
            system("cls");
            cout << "Error!" << endl;
            break;
        }
        delete coll;
    }
    return 0;
}
