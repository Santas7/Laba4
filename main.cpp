#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <conio.h>
#include <windows.h>
#include <time.h>

using namespace std;

class Main {
public:
    virtual void Print() const = 0 {};
};
class Book : public Main {
protected:
    char* _cip, * _firstname, * _lastname, * _name;
    int _year;
public:
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
class collection {
private:
    int N;
    Main** _A;
public:
    void Add(Main* obj) {
        ++N;
        _A = (Main**)realloc(_A, N * sizeof(Main*));
        _A[N - 1] = obj;
    }
    void PrintC() const
    {
        for (int i = 0; i < N; ++i)
        {
            _A[i]->Print();
        }
        cout << "[0] Back-->";
    }
    void Read(char* filename) {
        //FILE* fp = fopen(filename, "w");
    }
    ~collection()
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
    collection* coll = new collection();
    cout << "[1] Open the File" << endl << "[2] Add Object" << endl << "[3] Save in File" << endl << "[4] Output all list books" << endl << "[BackSpace] Exit" << endl << "-->";
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
            cout << "Input Book Name--> ";
            cin >> c;
            cout << "Input Year--> ";
            cin >> y;
            coll->Add(new Book(a, b, d, c, y));
            system("cls");
            cout << "Added! [0] Back-->";
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
            cout << "[1] Open the File" << endl << "[2] Add Object" << endl << "[3] Save in File" << endl << "[4] Output all list books" << endl << "[BackSpace] Exit" << endl << "-->";
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
