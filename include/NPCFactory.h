#pragma once

#include <memory>
#include <string>
#include "NPC.h"

class NPCFactory {
  public:
   static std::shared_ptr<NPC> createNPC(const std::string& type,
                                         const std::string& name, int x, int y);
};