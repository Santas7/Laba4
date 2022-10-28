#include "menuArray.h"
#include "get_key2.h"
#include "err.h"
#include "typesErr.h"

void MainMenu2Print() {
    cout << "<< Back or Next>>"
        << endl << "[1] Access to an element by index"
        << endl << "[2] Deleting one object by index"
        << endl << "[3] Deleting all objects"
        << endl << "[4] Insertion of an element before element with the specified index"
        << endl << "[5] Numbers All"
        << endl << "[6] Edit"
        << endl << "[Q] Back In Main Menu"
        << endl << "-->";
}

void FunctionAdd(char* firstname, char* lastname, char* patron, char* bookname) {
    while (true) {
        cout << "Input FirstName--> ";
        cin >> firstname;
        if (!CheckTypeIndex(firstname))
            break;
    }
    while (true) {
        cout << "Input LastName--> ";
        cin >> lastname;
        if (!CheckTypeIndex(lastname))
            break;
    }
    while (true) {
        cout << "Input PatroNymic--> ";
        cin >> patron;
        if (!CheckTypeIndex(patron))
            break;
    }
    while (true) {
        cout << "Input Book Name--> ";
        cin >> bookname;
        if (!CheckTypeIndex(bookname))
            break;
    }
}

void PrintAll(Book** _A, Array* coll) {
    for (int i = 0; i < coll->Count(); ++i) {
        cout << "CIP: " << _A[i]->GetCip()
            << endl << "LastName: " << _A[i]->GetLast()
            << endl << "FirstName: " << _A[i]->GetFirst()
            << endl << "Patrone: " << _A[i]->GetPatron()
            << endl << "Book Name:" << _A[i]->GetName()
            << endl << "Year: " << _A[i]->GetYear()
            << endl << endl << endl;
    }
    cout << "[0] Back-->";
}

void Print(Book** _A, int index) {
    cout << "CIP: " << _A[index]->GetCip()
        << endl << "LastName: " << _A[index]->GetLast()
        << endl << "FirstName: " << _A[index]->GetFirst()
        << endl << "Patrone: " << _A[index]->GetPatron()
        << endl << "Book Name:" << _A[index]->GetName()
        << endl << "Year: " << _A[index]->GetYear()
        << endl << endl << endl;
}

bool CheckTypeIndex(char* index) {
    const char str[] = { "0123456789" };
    bool status = false;
    for (int i = 0; i < strlen(index); ++i) {
        for (int j = 0; j < strlen(str); ++j) {
            status = false;
            if (index[i] == str[j]) {
                status = true;
                break;
            }
        }
    }
    return status;
}

void PrintPerehod(Book** _A, Array* coll, int index) {
    if (index == coll->Count() && coll->Count() != 0) {
        Print(_A, index);
    }
    if (index == -1 && coll->Count() != 0) {
        Print(_A, index);
    }
    if (coll->Count() != 0)
        Print(_A, index);
    if (coll->Count() == 0) {
        cout << "NULL!" << endl;
    }
}
void Edit(Book** _A, int index, int typeEdit) {
    char str[255];
    if (typeEdit == 1) {
        while (true) {
            cout << "Input New CIP: ";
            cin >> str;
            if (!CheckTypeIndex(str)) {
                _A[index]->SetLast(str);
                break;
            }
        }
    }
    else if (typeEdit == 2) {
        while (true) {
            cout << "Input New LastName: ";
            cin >> str;
            if (!CheckTypeIndex(str)) {
                _A[index]->SetLast(str);
                break;
            }
        }
    }
    else if (typeEdit == 3) {
        while (true) {
            cout << "Input New FirstName: ";
            cin >> str;
            if (!CheckTypeIndex(str)) {
                _A[index]->SetLast(str);
                break;
            }
        }
    }
    else if (typeEdit == 4) {
        while (true) {
            cout << "Input New Patrone: ";
            cin >> str;
            if (!CheckTypeIndex(str)) {
                _A[index]->SetLast(str);
                break;
            }
        }

    }
    else if (typeEdit == 5) {
        while (true) {
            cout << "Input New Book Name: ";
            cin >> str;
            if (!CheckTypeIndex(str)) {
                _A[index]->SetLast(str);
                break;
            }
        }
    }
    else if (typeEdit == 6) {
        while (true) {
            cout << "Input New Year: ";
            cin >> str;
            try {
                if (!CheckTypeIndex(str))
                    throw EType();
                try {
                    if (atoi(str) < 0 || atoi(str) > 2023)
                        throw EYear();
                    _A[index]->SetYear(atoi(str));
                    cout << "[0] Back-->";
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
    }
}

void MenuArray(Book** _A, Array* coll) {
    char a[255], b[255], c[255], d[255], f[255]; 
    int i = 0;
    PrintPerehod(coll->Get(), coll, i);
    cout << "Index: " << i << endl;
    MainMenu2Print();
    while (true) {
        int commandKey = GetKey2();
        if (commandKey == 'Q')
            break;
        switch (commandKey) {
        case '1':
        {
            char index[255];
            system("cls");
            cout << "Input index--> ";
            cin >> index;
            try {
                Book* tmp = coll->Element(atoi(index));
                Print(coll->Get(), atoi(index));
                cout << "[0] Back--> ";
            }
            catch (ESetError& error) {
                error.print();
                cout << "[0] Back--> ";
            }
            break;
        }
        case '2':
            try {
                if (coll->Count() == 0)
                    throw EOutput();
                try {
                    if (i < 0 || i > coll->Count())
                        throw EDel();
                    coll->DelIndex(i);
                    if (i != 0) --i;
                    system("cls");
                    PrintPerehod(coll->Get(), coll, i);
                    cout << "Index: " << i << endl;
                    MainMenu2Print();
                }
                catch (ESetError& error) {
                    error.print();
                    system("cls");
                    cout << "Index: " << i << endl;
                    MainMenu2Print();
                }
            }
            catch (ESetError& error) {
                error.print();
                system("cls");
                cout << "Index: " << i << endl;
                MainMenu2Print();
            }
            break;
        case '3':
            system("cls");
            try {
                if (coll->Count() <= 0)
                    throw EDel();
                coll->DelAll();
                cout << "All Objects is deleted! [0] Back--> ";
            }
            catch (ESetError& error) {
                error.print();
                cout << "[0] Back--> ";
            }
            break;
        case '4':
        {
            char index[255], value[255];
            system("cls");
            cout << "Input index--> ";
            cin >> index;
            try {
                if (!CheckTypeIndex(index))
                    throw EType();
                try {
                    if (atoi(index) < 0 || atoi(index) > coll->Count())
                        throw EElement();
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
                                coll->AddIndex(new Book(a, b, d, f, c, atoi(value)), atoi(index));
                                system("cls");
                                cout << "[0] Back--> ";
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
                }
                catch (ESetError& error) {
                    error.print();
                    cout << "[0] Back--> ";
                }
            }
            catch (ESetError& error) {
                error.print();
                cout << "[0] Back--> ";
            }
            break;
        }
        case '5':
            system("cls");
            cout << "Number Books = " << coll->Count() << endl;
            cout << "[0] Back--> ";
            break;
        case '6':
        {
            char index[255], typeEdit[255];
            system("cls");
            cout << "Input index edit--> ";
            cin >> index;
            try {
                if (!CheckTypeIndex(index) || coll->Count() == 0)
                    throw EType();
                try {
                    if (atoi(index) < 0 || atoi(index) >= coll->Count())
                        throw EEdit();
                    cout << "Edit type: " << endl << "1 - edit cip"
                        << endl << "2 - edit lastname"
                        << endl << "3 - edit firstname"
                        << endl << "4 - edit patrone"
                        << endl << "5 - edit book name"
                        << endl << "6 - edit year" << endl << "--> ";
                    cin >> typeEdit;
                    try {
                        if (atoi(typeEdit) <= 0 || atoi(typeEdit) > 6)
                            throw EEdit();
                        Edit(coll->Get(), atoi(index), atoi(typeEdit));
                    }
                    catch (ESetError& error) {
                        error.print();
                    }
                }
                catch (ESetError& error) {
                    error.print();
                }
            }
            catch (ESetError& error) {
                error.print();
            }
            
            cout << endl << "[0] Back--> ";
            break;
        }
        case 75: // left
            try {
                if (coll->Count() == 0) 
                    throw EType();
                --i;
                system("cls");
                if (i == -1 && coll->Count() != 0) i = 0;
                PrintPerehod(coll->Get(), coll, i);
                cout << "Index: " << i << endl;
                MainMenu2Print();
            }
            catch (ESetError& error) {
                error.print();
            }
            break;
        case 77: // right
            try {
                if (coll->Count() == 0) 
                    throw EType();
                ++i;
                system("cls");
                if (coll->Count() == i && coll->Count() != 0) i = coll->Count() - 1;
                PrintPerehod(coll->Get(), coll, i);
                cout << "Index: " << i << endl;
                MainMenu2Print();
            }
            catch (ESetError& error) {
                error.print();
            }
            break;
        case '0':
            system("cls");
            cout << "Index: " << i << endl;
            PrintPerehod(coll->Get(), coll, i);
            MainMenu2Print();
            break;
        default:
            system("cls");
            cout << "Error!" << endl << "[0] Back-->";
            break;
        }
    }
}