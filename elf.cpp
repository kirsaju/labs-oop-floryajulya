#include "../include/elf.h"

Elf::Elf(std::string name, int x, int y) : NPC(name, x, y) {}

void Elf::accept(Visitor &visitor)
{
    visitor.visit(*this);
}