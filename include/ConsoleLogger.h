#pragma once

#include <string>
#include "Observer.h"

class ConsoleLogger : public Observer {
  public:
   void notify(const std::string& event) override;
};