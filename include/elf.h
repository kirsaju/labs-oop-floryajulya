#pragma once
#include "npc.h"
#include "visitor.h"

class Elf : public NPC
{
public:
    Elf(std::string name, int x, int y);
    void accept(Visitor &visitor) override;
    std::string getType() const override { return "Elf"; }
};