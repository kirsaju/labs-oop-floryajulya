#include "Knight.h"
#include <memory>
#include <string>

Knight::Knight(const std::string& name, int x, int y)
    : NPC(name, x, y, ATTACK_RADIUS, MOVE_RADIUS) {}

const std::string Knight::getType() const { return "Knight"; }

// bool Knight::fight(NPC& other) { return other.getType() != "Elf"; }

void Knight::accept(Visitor& visitor) {
   visitor.visit(std::make_unique<NPC>(*this));
}
