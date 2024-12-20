#include "BattleVisitor.h"
#include <memory>
#include <shared_mutex>
#include <string>
#include <vector>
#include "NPC.h"

BattleVisitor::BattleVisitor(std::vector<std::shared_ptr<NPC>>& npcs,
                             std::vector<std::shared_ptr<Observer>>& observers)
    : Visitor(npcs, observers) {}

void BattleVisitor::visit(std::unique_ptr<NPC> npc) {
   for (size_t i = 0; i < npcs.size(); ++i) {
      auto enemy = *npcs[i];
      if (npc->isInRange(enemy)) {
         if (!npc || !enemy.isAlive()) return;

         int attack1 = dice();
         int defense2 = dice();

         if (attack1 > defense2) {
            enemy.setAlive(false);
            return;
         }

         int attack2 = dice();
         int defense1 = dice();

         if (attack2 > defense1) {
            npc->setAlive(false);
         }
      }
   }
}
