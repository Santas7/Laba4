#include "get_key2.h"
#include "Book.h"

int GetKey2() {
    int key = _getch();
    if (key == 48 || key == 49 || key == 50 || key == 51 || key == 52 || key == 53 || key == 54 || key == 75 || key == 77 ||key == 81 || key == 8 || key == 83)
        return key;
    return 0;
}