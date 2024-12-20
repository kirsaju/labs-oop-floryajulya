#pragma once

#include <memory>
#include <shared_mutex>
#include <string>
#include <vector>
#include "NPC.h"
#include "Observer.h"

class Visitor {
  protected:
   std::vector<std::shared_ptr<NPC>> npcs;
   std::vector<std::shared_ptr<Observer>> observers;

  public:
   Visitor(std::vector<std::shared_ptr<NPC>>& npcs,
           std::vector<std::shared_ptr<Observer>>& observers);
   void addObserver(std::shared_ptr<Observer> observer);
   void notifyObservers(const std::string& event);
   //    void visit(Knight& knight);
   //    void visit(Elf& elf);
   //    void visit(Druid& druid);
   virtual void visit(std::unique_ptr<NPC> npc) = 0;
   int dice() const;
};