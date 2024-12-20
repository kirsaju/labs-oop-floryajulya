#include "Visitor.h"
#include <shared_mutex>

Visitor::Visitor(std::vector<std::shared_ptr<NPC>>& npcs,
                 std::vector<std::shared_ptr<Observer>>& observers)
    : npcs(npcs), observers(observers) {}

void Visitor::addObserver(std::shared_ptr<Observer> observer) {
   observers.push_back(observer);
}

void Visitor::notifyObservers(const std::string& event) {
   for (const auto& observer : observers) {
      observer->notify(event);
   }
}

void Visitor::visit(std::unique_ptr<NPC> npc) {}

int Visitor::dice() const {
   std::random_device rd;
   std::mt19937 gen(rd());
   std::uniform_int_distribution<int> dis(1, 6);
   int diceThrow = dis(gen);
   return diceThrow;
}
