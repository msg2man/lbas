#include "Logger.h"
#include <ctime>
#include <cstdio>
#include <stdexcept>

Logger::Logger(const std::string &filename, OutputMode mode)
    : outputMode(mode), logLevel(LogLevel::DEBUG) {
    if (mode == OutputMode::FILE || mode == OutputMode::BOTH) {
        fileStream.open(filename, std::ios_base::app);
        if (!fileStream.is_open()) {
            throw std::runtime_error("Unable to open log file: " + filename);
        }
    }
}

Logger::~Logger() {
    if (fileStream.is_open()) {
        fileStream.close();
    }
}

void Logger::log(LogLevel level, const std::string &format, ...) {
    if (!shouldLog(level)) return;

    std::lock_guard<std::mutex> lock(mtx);

    va_list args;
    va_start(args, format);
    std::string logMessage = levelToString(level) + ": " + formatString(format, args);
    va_end(args);

    if (outputMode == OutputMode::STDOUT || outputMode == OutputMode::BOTH) {
        logToStdout(logMessage);
    }
    if (outputMode == OutputMode::FILE || outputMode == OutputMode::BOTH) {
        logToFile(logMessage);
    }
}

void Logger::setLogLevel(LogLevel level) {
    logLevel = level;
}

std::string Logger::levelToString(LogLevel level) {
    switch (level) {
        case LogLevel::INFO:
            return "INFO";
        case LogLevel::ERROR:
            return "ERROR";
        case LogLevel::DEBUG:
            return "DEBUG";
        default:
            return "";
    }
}

bool Logger::shouldLog(LogLevel level) {
    switch (logLevel) {
        case LogLevel::DEBUG:
            return true;
        case LogLevel::INFO:
            return level == LogLevel::INFO || level == LogLevel::ERROR;
        case LogLevel::ERROR:
            return level == LogLevel::ERROR;
        default:
            return false;
    }
}

void Logger::logToFile(const std::string &message) {
    if (fileStream.is_open()) {
        fileStream << message << std::endl;
    }
}

void Logger::logToStdout(const std::string &message) {
    std::cout << message << std::endl;
}

std::string Logger::formatString(const std::string &format, va_list args) {
    char buffer[1024];
    vsnprintf(buffer, sizeof(buffer), format.c_str(), args);
    return std::string(buffer);
}
