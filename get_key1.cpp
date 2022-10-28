#include "get_key1.h"
#include "Book.h"

int GetKey1() {
    int key = _getch();
    if (key == 48 || key == 49 || key == 50 || key == 51 || key == 52 || key == 53 || key == 54 || key == 55 || key == 65 || key == 56 || key == 57 || key == 8 || key == 83)
        return key;
    return 0;
}