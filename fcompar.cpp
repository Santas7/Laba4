#include "fcompar.h"

#include "BookCompar.h"


void IsFunctionCompar(Array* coll, int typeSort) {
    if (typeSort == 1) {
        coll->Sort(&LastNameCompar);
    }
    else if (typeSort == 2) {
        coll->Sort(&FirstNameCompar);
    }
    else if (typeSort == 3) {
        coll->Sort(&PatronCompar);
    }
    else if (typeSort == 4) {
        coll->Sort(&BookNameCompar);
    }
    else if (typeSort == 5) {
        coll->Sort(&YearCompar);
    }
}