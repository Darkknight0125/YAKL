#include "logger.h"
#include <iostream>
#include <iomanip>
#include <ctime>

Logger::Logger() : isLoggingEnabled(true) {
    logFile.open("log.txt", std::ios::app);
    if (!logFile.is_open()) {
        std::cerr << "Error: Unable to open log.txt for logging.\n";
    }
}

Logger::~Logger() {
    if (logFile.is_open()) {
        logFile.close();
    }
}

void Logger::logKey(const std::string& key) {
    if (!isLoggingEnabled || !logFile.is_open()) {
        return;
    }

    std::lock_guard<std::mutex> guard(logMutex);

    std::time_t now = std::time(nullptr);
    logFile << "[" << std::put_time(std::localtime(&now), "%Y-%m-%d %H:%M:%S") << "] ";
    logFile << key << "\n";

    logFile.flush();
}

void Logger::toggleLogging(bool enable) {
    isLoggingEnabled = enable;
}
