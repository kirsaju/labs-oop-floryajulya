#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <random>
#include <string>
#include <vector>
#include "Arena.h"
#include "BattleVisitor.h"
#include "ConsoleLogger.h"
#include "FileLogger.h"
#include "NPC.h"
#include "NPCFactory.h"

int main() {
   Arena arena(100, 100);

   arena.registerNPC(NPCFactory::createNPC("Knight", "Arthur", 50, 50));
   arena.registerNPC(NPCFactory::createNPC("Elf", "Legolas", 70, 30));
   arena.registerNPC(NPCFactory::createNPC("Druid", "Merlin", 20, 80));

   arena.subscribeObserver(std::make_shared<ConsoleLogger>());
   arena.subscribeObserver(std::make_shared<FileLogger>());

   arena.initiateCombat();

   return 0;
}
