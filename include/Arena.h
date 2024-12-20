#pragma once

#include <atomic>
#include <memory>
#include <mutex>
#include <shared_mutex>
#include <vector>
#include "BattleVisitor.h"
#include "MoveVisitor.h"
#include "NPC.h"
#include "NPCFactory.h"
#include "Observer.h"

class Arena {
   const int GAME_DURATION = 30;

  public:
   Arena(int arenaWidth, int arenaHeight);
   void registerNPC(std::shared_ptr<NPC> character);
   void subscribeObserver(std::shared_ptr<Observer> listener);
   void initiateCombat();
   void interactNPC(Visitor& visitor);
   void displayNPCs() const;
   void printMap() const;
   void generateNPCs();

  private:
   int arenaWidth, arenaHeight;
   mutable std::shared_mutex npc_mutex;
   mutable std::mutex cout_mutex;
   mutable std::atomic<bool> game_running;
   std::vector<std::shared_ptr<NPC>> characterList;
   std::vector<std::shared_ptr<Observer>> observerList;

   int generateRandomCoordinate(int lowerBound, int upperBound);
};