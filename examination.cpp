#include "examination.h"

bool Examination(const char* str1, char* str2) {
    bool status = false;
    if (strlen(str1) < strlen(str2)) return status;
    for (int i = 0; i < strlen(str1); ++i) {
        status = true;
        for (int j = 0; j < strlen(str2); ++j) {
            if (str1[j + i] != str2[j])
            {
                status = false;
                break;
            }
        }
        if (status == true) return status;
    }
    return status;
}

