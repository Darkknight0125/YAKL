#ifndef LOGGER_H
#define LOGGER_H

#include <fstream>
#include <string>
#include <mutex>

class Logger {
private:
    std::ofstream logFile;        // Log file stream
    std::mutex logMutex;          // Mutex to ensure thread safety
    bool isLoggingEnabled;        // Toggle for logging

public:
    Logger();                     // Constructor
    ~Logger();                    // Destructor

    void logKey(const std::string& key);   // Log a single key
    void toggleLogging(bool enable);      // Enable or disable logging
};

#endif // LOGGER_H
