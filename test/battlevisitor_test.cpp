#include "BattleVisitor.h"
#include <gtest/gtest.h>
#include <memory>
#include <vector>
#include "NPC.h"
#include "NPCFactory.h"
#include "Observer.h"

TEST(BattleVisitorTest, FightInRange) {
   std::vector<std::shared_ptr<NPC>> npcs = {
       NPCFactory::createNPC("Knight", "Arthur", 0, 0),
       NPCFactory::createNPC("Elf", "Legolas", 3, 4)};

   BattleVisitor battle(npcs, {});
   battle.visit(npcs[0]);

   EXPECT_FALSE(npcs[1]->isAlive());
   EXPECT_TRUE(npcs[0]->isAlive());
}

TEST(BattleVisitorTest, NoFightOutOfRange) {
   std::vector<std::shared_ptr<NPC>> npcs = {
       NPCFactory::createNPC("Knight", "Arthur", 0, 0),
       NPCFactory::createNPC("Elf", "Legolas", 10, 10)};

   BattleVisitor battle(npcs, {});
   battle.visit(npcs[0]);

   EXPECT_TRUE(npcs[0]->isAlive());
   EXPECT_TRUE(npcs[1]->isAlive());
}

TEST(BattleVisitorTest, ObserverNotifications) {
   std::vector<std::shared_ptr<NPC>> npcs = {
       NPCFactory::createNPC("Knight", "Arthur", 0, 0),
       NPCFactory::createNPC("Elf", "Legolas", 3, 4)};

   std::vector<std::shared_ptr<Observer>> observers;
   auto consoleLogger = std::make_shared<ConsoleLogger>();
   observers.push_back(consoleLogger);

   BattleVisitor battle(npcs, observers);

   testing::internal::CaptureStdout();
   battle.visit(npcs[0]);
   std::string output = testing::internal::GetCapturedStdout();

   EXPECT_NE(output.find("Arthur (Knight) fought Legolas (Elf)"),
             std::string::npos);
}
