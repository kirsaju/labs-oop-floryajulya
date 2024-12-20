#include "Arena.h"
#include <algorithm>
#include <atomic>
#include <fstream>
#include <iostream>
#include <shared_mutex>
#include <thread>
#include "BattleVisitor.h"
#include "MoveVisitor.h"

class InteractionHandler {
  public:
   InteractionHandler(Visitor& visitor, std::atomic<bool>& game_running,
                      std::shared_mutex& npc_mutex,
                      std::vector<std::shared_ptr<NPC>>& characterList)
       : visitor(visitor),
         game_running(game_running),
         npc_mutex(npc_mutex),
         characterList(characterList) {}

   void operator()() const {
      while (game_running) {
         std::unique_lock lock(npc_mutex);

         for (auto& npc : characterList) {
            npc->accept(visitor);
         }
         std::this_thread::sleep_for(std::chrono::milliseconds(1000));
      }
   }

  private:
   Visitor& visitor;
   std::atomic<bool>& game_running;
   std::shared_mutex& npc_mutex;
   std::vector<std::shared_ptr<NPC>>& characterList;
};

Arena::Arena(int arenaWidth, int arenaHeight)
    : arenaWidth(arenaWidth), arenaHeight(arenaHeight) {}

void Arena::registerNPC(std::shared_ptr<NPC> character) {
   characterList.push_back(std::move(character));
}

void Arena::subscribeObserver(std::shared_ptr<Observer> listener) {
   observerList.push_back(listener);
}

void Arena::initiateCombat() {
   std::cout << "Initiating combat." << std::endl;

   for (auto& listener : observerList) {
      listener->notify("Combat started.");
   }

   BattleVisitor battleVisitor(characterList, observerList);
   MoveVisitor moveVisitor(characterList, observerList, arenaWidth,
                           arenaHeight);

   InteractionHandler battleHandler(battleVisitor, game_running, npc_mutex,
                                    characterList);
   InteractionHandler moveHandler(moveVisitor, game_running, npc_mutex,
                                  characterList);

   std::thread battleThread(battleHandler);
   std::thread moveThread(moveHandler);

   printMap();

   game_running = false;
   battleThread.join();
   moveThread.join();
}

void Arena::interactNPC(Visitor& visitor) {
   while (game_running) {
      std::unique_lock lock(npc_mutex);

      for (auto& npc : characterList) {
         npc->accept(visitor);
      }
      std::this_thread::sleep_for(std::chrono::milliseconds(1000));
   }
}

void Arena::printMap() const {
   for (int i = 0; i < GAME_DURATION; i++) {

      std::shared_lock lock(npc_mutex);

      std::vector<std::vector<char>> map(arenaHeight,
                                         std::vector<char>(arenaWidth, ' '));
      for (const auto& npc : characterList) {
         std::cout << "isAlive: " << npc->isAlive() << "; " << npc->getY()
                   << "," << npc->getX() << std::endl;
         if (npc->isAlive()) {
            map[npc->getY()][npc->getX()] = 'N';
         }
      }

      std::lock_guard guard(cout_mutex);
      for (const auto& row : map) {
         for (const auto& cell : row) {
            std::cout << cell;
         }
         std::cout << '\n';
      }
      std::cout << "\n";

      std::this_thread::sleep_for(std::chrono::seconds(1));
   }
}