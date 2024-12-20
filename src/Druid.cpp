#include "Druid.h"
#include <memory>
#include <string>
#include "Visitor.h"

Druid::Druid(const std::string& name, int x, int y)
    : NPC(name, x, y, ATTACK_RADIUS, MOVE_RADIUS) {}

const std::string Druid::getType() const { return "Druid"; }

// bool Druid::fight(NPC& other) { return true; }

void Druid::accept(Visitor& visitor) {
   visitor.visit(std::make_unique<NPC>(*this));
}
