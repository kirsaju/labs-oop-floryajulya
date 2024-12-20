#include "NPCFactory.h"
#include <gtest/gtest.h>
#include "NPC.h"

TEST(NPCFactoryTest, CreateKnight) {
   auto knight = NPCFactory::createNPC("Knight", "Arthur", 10, 20);
   EXPECT_EQ(knight->getType(), "Knight");
}

TEST(NPCFactoryTest, CreateInvalidNPC) {
   EXPECT_THROW(NPCFactory::createNPC("InvalidType", "Error", 0, 0),
                std::invalid_argument);
}
