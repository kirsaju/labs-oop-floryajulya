#include <gtest/gtest.h>
#include "../src/arena.cpp"
#include "../src/console_logger.cpp"
#include "../src/file_logger.cpp"
#include "../src/druid.cpp"
#include "../src/elf.cpp"
#include "../src/knight.cpp"
#include "../src/battle_visitor.cpp"

TEST(NPCTest, CreateNPC)
{
    auto Elf = NPCFactory::createNPC("Elf", "FireElf", 100, 100);
    EXPECT_NE(Elf, nullptr);
    EXPECT_EQ(Elf->getName(), "FireElf");
    EXPECT_EQ(Elf->getX(), 100);
    EXPECT_EQ(Elf->getY(), 100);
}

TEST(ArenaTest, AddNPC)
{
    Arena arena(500, 500);

    auto Druid = NPCFactory::createNPC("Druid", "DruidKing", 50, 50);
    arena.addNPC(std::move(Druid));

    testing::internal::CaptureStdout();
    arena.printNPCs();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("DruidKing"), std::string::npos);
}

TEST(ArenaTest, SpawnNPCRandomCoordinates)
{
    Arena arena(500, 500);

    arena.spawnNPC("Elf", "RandomElf");

    testing::internal::CaptureStdout();
    arena.printNPCs();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("RandomElf"), std::string::npos);
}

TEST(ArenaTest, SpawnNPCAtGivenCoordinates)
{
    Arena arena(500, 500);

    arena.spawnNPC("Elf", "FireElf", 100, 100);

    testing::internal::CaptureStdout();
    arena.printNPCs();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("FireElf"), std::string::npos);
    EXPECT_NE(output.find("100"), std::string::npos);
    EXPECT_NE(output.find("100"), std::string::npos);
}

TEST(ArenaTest, StartBattle)
{
    Arena arena(500, 500);

    auto Druid = NPCFactory::createNPC("Druid", "DruidKing", 50, 50);
    auto Elf = NPCFactory::createNPC("Elf", "FireElf", 100, 100);
    arena.addNPC(std::move(Druid));
    arena.addNPC(std::move(Elf));

    testing::internal::CaptureStdout();
    arena.startBattle(100);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output.find("DruidKing"), std::string::npos);
    EXPECT_EQ(output.find("FireElf"), std::string::npos);
}

TEST(ArenaTest, LoadNPCs)
{
    Arena arena(500, 500);

    auto Druid = NPCFactory::createNPC("Druid", "DruidKing", 50, 50);
    auto Elf = NPCFactory::createNPC("Elf", "FireElf", 100, 100);

    arena.addNPC(std::move(Druid));
    arena.addNPC(std::move(Elf));

    testing::internal::CaptureStdout();
    arena.printNPCs();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("DruidKing"), std::string::npos);
    EXPECT_NE(output.find("FireElf"), std::string::npos);
}

TEST(ArenaTest, NPCWithDamageDisappears)
{
    Arena arena(500, 500);

    auto Druid = NPCFactory::createNPC("Druid", "DruidKing", 50, 50);
    arena.addNPC(std::move(Druid));

    testing::internal::CaptureStdout();
    arena.startBattle(0);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output.find("DruidKing"), std::string::npos);
}

TEST(ArenaTest, PrintAllNPCs)
{
    Arena arena(500, 500);

    auto Druid = NPCFactory::createNPC("Druid", "DruidKing", 50, 50);
    auto Elf = NPCFactory::createNPC("Elf", "FireElf", 100, 100);
    arena.addNPC(std::move(Druid));
    arena.addNPC(std::move(Elf));

    testing::internal::CaptureStdout();
    arena.printNPCs();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("DruidKing"), std::string::npos);
    EXPECT_NE(output.find("FireElf"), std::string::npos);
}
