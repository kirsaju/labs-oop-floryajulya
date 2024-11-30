#pragma once
#include "visitor.h"
#include "observer.h"
#include <vector>
#include <memory>

class BattleVisitor : public Visitor
{
public:
    BattleVisitor(int range, std::vector<std::unique_ptr<NPC>> &npcs, std::vector<std::shared_ptr<Observer>> &observers);
    void visit(Elf &Elf) override;
    void visit(Druid &Druid) override;
    void visit(Knight &knight) override;
    bool areAllOutOfRange();

private:
    int range;
    std::vector<std::unique_ptr<NPC>> &npcs;
    std::vector<std::shared_ptr<Observer>> &observers;

    bool isInRange(const NPC &npc1, const NPC &npc2);
    void notifyObservers(const std::string &event);
};