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

class MoveVisitor : public Visitor {
   int width, height;

  public:
   MoveVisitor(std::vector<std::shared_ptr<NPC>>& npcs,
               std::vector<std::shared_ptr<Observer>>& observers, int width,
               int height);
   //    void visit(Knight& knight);
   //    void visit(Elf& elf);
   //    void visit(Druid& druid);
   void visit(std::unique_ptr<NPC> npc) override;
   int genDir() const;
};