/*
Panyshkin Andrey laba 4 variant 17
6113
*/



#include "Array.h"
#include "BookCompar.h"
#include "fcompar.h"
#include "fcompar.h"
#include "get_key1.h"
#include "get_key2.h"
#include "menuArray.h"
#include "examination.h"
#include "err.h"
#include "typesErr.h"



void MainMenu1Print() {
    cout << "[1] Read the File"
        << endl << "[2] Add Object"
        << endl << "[3] Save in File"
        << endl << "[4] Output all list books"
        << endl << "[5] Search by book title"
        << endl << "[A] GoTo Array{}"
        << endl << "[S] Function Sort"
        << endl << "[BackSpace] Exit"
        << endl << "-->";
}

int FuncFile(FILE* file, char* filename, Array* coll) {
    fopen_s(&file, filename, "ab");
    try {
        if (!file) {
            throw EFileOpen();
            getchar();
            return 1;
        }
        coll->Write(file);
    }
    catch (ESetError* error) {
        error->print();
        cout << "[0] Back--> ";
    }
}

int main()
{
    //setlocale(LC_ALL, "Rus");
    char a[255], b[255], c[255], d[255], f[255], value[255];
    FILE* file = NULL;
    Array* coll = new Array();
    //coll->Get();
    MainMenu1Print();
    while (true) {
        int commandKey = GetKey1();
        if (commandKey == 8)
            break;
        switch (commandKey) {
        case '1':
            system("cls");
            cout << "Please enter the path to the file--> ";
            cin >> a;
            //read
            fopen_s(&file, a, "rb");
            try {
                if (!file) {
                    throw EFileOpen();
                    getchar();
                    return 1;
                }
                coll->Read(file);
                cout << "Added! [0] Back-->";
            }
            catch (ESetError* error) {
                error->print();
                cout << "[0] Back--> ";
            }
            break;
        case '2':
        {
            system("cls");
            cout << "Input CIP--> ";
            cin >> a;
            FunctionAdd(b, d, f, c);
            while (true) {
                cout << "Input Year--> ";
                cin >> value;
                try {
                    if (!CheckTypeIndex(value))
                        throw EType();
                    try {
                        if (atoi(value) < 0 || atoi(value) > 2023)
                            throw EYear();
                        Book* tmp = new Book(a, b, d, f, c, atoi(value));
                        coll->Add(tmp);

                        system("cls");
                        cout << "Added! [0] Back-->";
                        break;
                    }
                    catch (ESetError& error) {
                        error.print();
                    }
                }
                catch (ESetError& error) {
                    error.print();
                }
            }
            break;
        }
        case '3':
            system("cls");
            cout << "Please enter the path to the file--> ";
            cin >> a;
            FuncFile(file, a, coll);
            try {
                if (coll->Count() <= 0) throw EDel();
                coll->DelAll();
                cout << "[0] Back--> ";
            }
            catch (ESetError& error) {
                error.print();
                cout << "[0] Back--> ";
            }
            break; 
        case '4':
            system("cls");
            try {
                if (coll->Count() <= 0) 
                    throw EOutput();
                PrintAll(coll->Get(), coll);
            }
            catch (ESetError& error) {
                error.print();
                cout << "[0] Back--> ";
            }
            break;
        case '5':
        {
            system("cls");
            cout << "Please input enter book title--> ";
            cin >> a;
            Array* newcoll = coll->SearchBook(a);
            system("cls");
            PrintAll(newcoll->Get(), newcoll);
            cout << endl << "1 - Save in file--> ";
            cin >> value;

            if (atoi(value) == 1) {
                system("cls");
                cout << "Please enter the path to the file--> ";
                cin >> b;
                FuncFile(file, a, newcoll);
                try {
                    if (newcoll->Count() <= 0) throw EDel();
                    newcoll->DelAll();
                    cout << "[0] Back--> ";
                }
                catch (ESetError& error) {
                    error.print();
                    cout << "[0] Back--> ";
                }
            }
            else if (atoi(value) == 0) {
                system("cls");
                MainMenu1Print();
                break;
            }
            else cout << "Error!" << endl;
            delete newcoll;
        }
        case 'A':
            system("cls");
            MenuArray(coll->Get(), coll);
            break;
        case 'S':
            system("cls");
            cout << "Please choose the type sort: "
                << endl << "1 - Sort the LastName"
                << endl << "2 - Sort the FirstName"
                << endl << "3 - Sort the Patrone"
                << endl << "4 - Sort the Book Name"
                << endl << "5 - Sort the Year" 
                << endl << "--> ";
            cin >> value;
            try {
                if (atoi(value) <= 0 || atoi(value) > 5)
                    throw ESort();
                IsFunctionCompar(coll, atoi(value));
                cout << "Sorted! [0] Back--> ";
            }
            catch (ESetError& error) {
                error.print();
                cout << "[0] Back--> ";
            }
            break;
        case '0':
            system("cls");
            MainMenu1Print();
            break;
        default:
            system("cls");
            MainMenu1Print();
            break;
        }
    }
    delete coll;
    return 0;
}
