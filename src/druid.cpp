#include "../include/druid.h"

Druid::Druid(std::string name, int x, int y) : NPC(name, x, y) {}

void Druid::accept(Visitor &visitor)
{
    visitor.visit(*this);
}