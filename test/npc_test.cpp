#include "NPC.h"
#include <gtest/gtest.h>
#include <cmath>
#include "Knight.h"

TEST(NPCTest, Constructor) {
   NPC npc("TestNPC", 10, 20, 0.0, 0);

   EXPECT_EQ(npc.getType(), "DefaultNPC");
}

TEST(NPCTest, CopyConstructor) {
   NPC original("OriginalNPC", 5, 15, 0.0, 0);
   NPC copy(original);

   EXPECT_EQ(copy.getName(), original.getName());
}

TEST(NPCTest, DistanceTo) {
   NPC npc1("NPC1", 0, 0, 0.0, 0);
   NPC npc2("NPC2", 3, 4, 0.0, 0);

   EXPECT_DOUBLE_EQ(npc1.distanceTo(npc2), 5.0);
}

TEST(NPCTest, IsInRange) {
   NPC npc1("NPC1", 0, 0, 0.0, 0);
   NPC npc2("NPC2", 3, 4, 0.0, 0);

   EXPECT_TRUE(npc1.isInRange(npc2));
}

TEST(NPCTest, AliveState) {
   NPC npc("NPC", 10, 20, 0.0, 0.0);

   npc.setAlive(false);

   EXPECT_FALSE(npc.isAlive());
}

TEST(NPCTest, Move) {
   Knight npc("Some", 0, 0);

   npc.move(1, 0);
   EXPECT_EQ(npc.getX(), 30);
   EXPECT_EQ(npc.getY(), 0);
}

TEST(NPCTest, InBorders) {
   NPC npc("BordersNPC", 10, 20, 0.0, 0.0);

   EXPECT_TRUE(npc.inBorders(100, 100));
}
