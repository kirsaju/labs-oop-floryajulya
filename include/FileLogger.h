#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include "Observer.h"

class FileLogger : public Observer {
   std::ofstream logFile;

  public:
   FileLogger();
   void notify(const std::string& event) override;
   ~FileLogger();
};