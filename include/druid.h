#pragma once
#include "npc.h"
#include "visitor.h"

class Druid : public NPC
{
public:
    Druid(std::string name, int x, int y);
    void accept(Visitor &visitor) override;
    std::string getType() const override { return "Druid"; }
};