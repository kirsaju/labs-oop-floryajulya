#include "Elf.h"
#include <memory>
#include <string>

Elf::Elf(const std::string& name, int x, int y)
    : NPC(name, x, y, ATTACK_RADIUS, MOVE_RADIUS) {}

const std::string Elf::getType() const { return "Elf"; }

// bool Elf::fight(NPC& other) { std::uniform_int_distribution<int> dice(1, 6);
// }

void Elf::accept(Visitor& visitor) {
   visitor.visit(std::make_unique<NPC>(*this));
}
