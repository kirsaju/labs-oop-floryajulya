#pragma once
#include "druid.h"
#include "elf.h"
#include "knight.h"
#include <vector>

class Visitor
{
public:
    virtual void visit(Druid &Elf) = 0;
    virtual void visit(Elf &Druid) = 0;
    virtual void visit(Knight &knight) = 0;
};
