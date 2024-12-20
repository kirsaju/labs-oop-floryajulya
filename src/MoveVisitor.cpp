#include "MoveVisitor.h"
#include <memory>
#include <shared_mutex>
#include <string>
#include <vector>
#include "NPC.h"

MoveVisitor::MoveVisitor(std::vector<std::shared_ptr<NPC>>& npcs,
                         std::vector<std::shared_ptr<Observer>>& observers,
                         int width, int height)
    : Visitor(npcs, observers), width(width), height(height) {}

void MoveVisitor::visit(std::unique_ptr<NPC> npc) {
   if (!npc->isAlive()) return;

   int x = genDir(), y = genDir();
   npc->move(x, y);
}

int MoveVisitor::genDir() const {
   std::random_device rd;
   std::mt19937 gen(rd());
   std::uniform_int_distribution<int> dis(-1, 1);
   int diceThrow = dis(gen);
   return diceThrow;
}