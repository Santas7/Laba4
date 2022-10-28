#pragma once

#include "Array.h"

void MenuArray(Book** _A, Array* coll);
void PrintPerehod(Book** _A, Array* coll, int index);
void Print(Book** _A, int index);
void PrintAll(Book** _A, Array* coll);
bool CheckTypeIndex(char* index);
void FunctionAdd(char* firstname, char* lastname, char* patron, char* bookname);