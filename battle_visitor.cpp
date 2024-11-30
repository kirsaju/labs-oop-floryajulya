#include "../include/battle_visitor.h"
#include "../include/Elf.h"
#include "../include/Druid.h"
#include "../include/knight.h"

BattleVisitor::BattleVisitor(int range, std::vector<std::unique_ptr<NPC>> &npcs, std::vector<std::shared_ptr<Observer>> &observers)
    : range(range), npcs(npcs), observers(observers) {}

void BattleVisitor::visit(Elf &Elf)
{
    for (auto it = npcs.begin(); it != npcs.end();)
    {
        if (auto knight = dynamic_cast<Knight *>(it->get()))
        {

            if (isInRange(Elf, *knight))
            {
                notifyObservers("Elf killed " + it->get()->getName());

                it = npcs.erase(it);
            }
            else
            {
                ++it;
            }
        }
        else
        {
            ++it;
        }
    }
}

void BattleVisitor::visit(Knight &knight)
{
    for (auto it = npcs.begin(); it != npcs.end();)
    {

        if (auto Elf = dynamic_cast<Elf *>(it->get()))
        {

            if (isInRange(knight, *Elf))
            {
                notifyObservers("Knight killed " + it->get()->getName());

                it = npcs.erase(it);
            }
            else
            {
                ++it;
            }
        }
        else
        {
            ++it;
        }
    }
}

void BattleVisitor::visit(Druid &Druid)
{
    for (auto it = npcs.begin(); it != npcs.end();)
    {

        if (it->get() != &Druid && isInRange(Druid, *it->get()))
        {
            notifyObservers("Druid killed " + it->get()->getName());
            it = npcs.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

bool BattleVisitor::isInRange(const NPC &npc1, const NPC &npc2)
{
    return std::abs(npc1.getX() - npc2.getX()) + std::abs(npc1.getY() - npc2.getY()) <= range;
}

void BattleVisitor::notifyObservers(const std::string &event)
{
    for (auto &observer : observers)
    {
        observer->update(event);
    }
}

bool BattleVisitor::areAllOutOfRange()
{
    for (const auto &npc1 : npcs)
    {
        for (const auto &npc2 : npcs)
        {
            if (npc1 != npc2 && isInRange(*npc1, *npc2))
            {
                return false;
            }
        }
    }
    return true;
}
