#include "MoveVisitor.h"
#include <gtest/gtest.h>
#include <memory>
#include <random>
#include <vector>
#include "NPC.h"

class TestNPC : public NPC {
  public:
   TestNPC(int x, int y) : x_(x), y_(y), alive_(true) {}

   bool isAlive() const { return alive_; }
   void move(int dx, int dy) {
      x_ += dx;
      y_ += dy;
   }

   int getX() const { return x_; }
   int getY() const { return y_; }
   void kill() { alive_ = false; }

  private:
   int x_, y_;
   bool alive_;
};

TEST(MoveVisitorTest, GenDirProducesValidRange) {
   std::vector<std::shared_ptr<NPC>> npcs;
   std::vector<std::shared_ptr<Observer>> observers;
   MoveVisitor visitor(npcs, observers, 10, 10);

   for (int i = 0; i < 100; ++i) {
      int dir = visitor.genDir();
      EXPECT_GE(dir, -1);
      EXPECT_LE(dir, 1);
   }
}

TEST(MoveVisitorTest, VisitMovesAliveNPC) {
   auto npc = std::make_shared<TestNPC>(5, 5);
   std::vector<std::shared_ptr<NPC>> npcs = {npc};
   std::vector<std::shared_ptr<Observer>> observers;

   MoveVisitor visitor(npcs, observers, 10, 10);

   int initialX = npc->getX();
   int initialY = npc->getY();

   visitor.visit(std::make_unique<TestNPC>(*npc));

   EXPECT_NE(initialX, npc->getX());
   EXPECT_NE(initialY, npc->getY());
}

TEST(MoveVisitorTest, VisitDoesNotMoveDeadNPC) {
   auto npc = std::make_shared<TestNPC>(5, 5);
   npc->kill();

   std::vector<std::shared_ptr<NPC>> npcs = {npc};
   std::vector<std::shared_ptr<Observer>> observers;

   MoveVisitor visitor(npcs, observers, 10, 10);

   int initialX = npc->getX();
   int initialY = npc->getY();

   visitor.visit(std::make_unique<TestNPC>(*npc));

   EXPECT_EQ(initialX, npc->getX());
   EXPECT_EQ(initialY, npc->getY());
}
