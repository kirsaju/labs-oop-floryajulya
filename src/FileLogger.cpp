#include "FileLogger.h"
#include <iostream>
#include <string>

FileLogger::FileLogger() { logFile.open("log.txt", std::ios::app); }

void FileLogger::notify(const std::string& event) {
   if (logFile.is_open()) {
      logFile << event << std::endl;
   }
}

FileLogger::~FileLogger() {
   if (logFile.is_open()) {
      logFile.close();
   }
}