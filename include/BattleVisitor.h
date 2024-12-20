#pragma once

#include <memory>
#include <string>
#include <vector>
#include "Druid.h"
#include "Elf.h"
#include "Knight.h"
#include "NPC.h"
#include "Observer.h"
#include "Visitor.h"

class BattleVisitor : public Visitor {
  public:
   BattleVisitor(std::vector<std::shared_ptr<NPC>>& npcs,
                 std::vector<std::shared_ptr<Observer>>& observers);
   // void visit(Knight& knight);
   // void visit(Elf& elf);
   // void visit(Druid& druid);
   void visit(std::unique_ptr<NPC> npc) override;
};