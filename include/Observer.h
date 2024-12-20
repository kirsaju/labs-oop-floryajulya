#pragma once

#include <string>

class Observer {
  public:
   virtual void notify(const std::string& event) = 0;
   virtual ~Observer() = default;
};