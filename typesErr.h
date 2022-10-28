#pragma once
#include "err.h"
#include "typesErr.h"
#include "Array.h"

class EFileOpen : public ESetError
{
public:
    void print() const override;
};
class EFileSave : public ESetError
{
public:
    void print() const override;
};
class EAddIndex : public ESetError
{
public:
    void print() const override;
};

class EElement : public ESetError
{
public:
    void print() const override;
};

class EDel : public ESetError
{
public:
    void print() const override;
};

class EFile : public ESetError
{
public:
    void print() const override;
};

class EOutput : public ESetError
{
public:
    void print() const override;
};

class ESort : public ESetError
{
public:
    void print() const override;
};
class EEdit : public ESetError
{
public:
    void print() const override;
};
class EType : public ESetError
{
public:
    void print() const override;
};
class EYear : public ESetError
{
public:
    void print() const override;
};