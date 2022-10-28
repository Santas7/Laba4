#include "err.h"
#include "typesErr.h"


void EFileOpen::print() const  {
    cout << "Error open file!" << endl;
}
void EFileSave::print() const {
    cout << "Error save file!" << endl;
}
void EAddIndex::print() const  {
    cout << "Error! Index >= 0!" << endl;
}
void EElement::print() const {
    cout << "Error!Index < Number Elements!" << endl;
}
void EDel::print() const {
    cout << "Error delete!" << endl;
}
void EFile::print() const {
    cout << "Error File!" << endl;
}
void EOutput::print() const {
    cout << "NULL!" << endl;
}
void ESort::print() const {
    cout << "Error! value = {1,2,3,4,5}!" << endl;
}
void EEdit::print() const {
    cout << "Error edit!" << endl;
}
void EType::print() const {
    cout << "Error!" << endl;
}
void EYear::print() const {
    cout << "Error! Year > 0 and Year <= 2022!" << endl;
}