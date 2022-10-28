#include "BookCompar.h"

int BookNameCompar(const Book& A, const Book& B)
{
    return strcmp(A.GetName(), B.GetName());
}
int FirstNameCompar(const Book& A, const Book& B)
{
    return strcmp(A.GetFirst(), B.GetFirst());
}
int LastNameCompar(const Book& A, const Book& B)
{
    return strcmp(A.GetLast(), B.GetLast());
}
int PatronCompar(const Book& A, const Book& B)
{
    return strcmp(A.GetPatron(), B.GetPatron());
}
int YearCompar(const Book& A, const Book& B)
{
    return A.GetYear() > B.GetYear();
}