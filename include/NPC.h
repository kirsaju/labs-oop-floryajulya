#pragma once

#include <random>
#include <string>

class Visitor;

class NPC {
  protected:
   bool alive;
   std::string name;
   int x, y;
   double attackRadius;
   int moveRadius;

  public:
   NPC(const std::string& name, int x, int y, double attackRadius,
       int moveRadius);
   NPC(const NPC& other);
   ~NPC() = default;
   virtual const std::string getType() const;
   const std::string& getName() const;
   int getX() const;
   int getY() const;
   bool isAlive() const;
   void setAlive(bool state);
   double distanceTo(const NPC& other) const;
   virtual void accept(Visitor& visitor);
   bool isInRange(const NPC& other) const;
   void move(int dirX, int dirY);
   bool inBorders(int width, int height) const;
};