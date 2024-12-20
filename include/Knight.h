#pragma once

#include <string>
#include "NPC.h"
#include "Visitor.h"

class Knight : public NPC {
   const double ATTACK_RADIUS = 10.0;
   const int MOVE_RADIUS = 30;

  public:
   Knight(const std::string& name, int x, int y);
   const std::string getType() const override;
   void accept(Visitor& visitor);
};
