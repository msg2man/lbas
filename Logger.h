#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <mutex>
#include <cstdarg>

class Logger {
public:
    enum class LogLevel {
        DEBUG,
        INFO,
        ERROR
    };

    enum class OutputMode {
        STDOUT,
        FILE,
        BOTH
    };

    Logger(const std::string &filename, OutputMode mode);
    ~Logger();

    void log(LogLevel level, const std::string &format, ...);
    void setLogLevel(LogLevel level);
    static Logger& getLogger() {
        static Logger logger("log.txt", Logger::OutputMode::BOTH);
        logger.setLogLevel(Logger::LogLevel::INFO);
        return logger;
    }

private:
    OutputMode outputMode;
    LogLevel logLevel;
    std::ofstream fileStream;
    std::mutex mtx;

    std::string levelToString(LogLevel level);
    void logToFile(const std::string &message);
    void logToStdout(const std::string &message);
    bool shouldLog(LogLevel level);
    std::string formatString(const std::string &format, va_list args);
};

#endif // LOGGER_H
