#include "ConsoleLogger.h"
#include <iostream>
#include <string>

void ConsoleLogger::notify(const std::string& event) {
   std::cout << event << std::endl;
}
