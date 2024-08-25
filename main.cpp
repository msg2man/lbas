#include "LBASimulator.h"
#include "LBAConfig.h"
#include "Logger.h"
#include "LBAlgorithm.h"
#include "cmdparser.h"

int main(int argc, char* argv[]) {

    //help string
    std::string helpString = "Usage: ./LBASimulator --servers \"10\" --tasks \"10\" "
                            "--algorithm \"PTC\" --latencies \"5\" \"10\" --capabilities \"1\" \"2\"";
    
    Logger& logger = Logger::getLogger();

    cli::Parser parser(argc, argv);
    parser.set_required<int>("s", "servers","The number of servers for executing the task requests.");
    parser.set_required<int>("t", "tasks","The number of tasks to be executed.");
    parser.set_required<std::string>("a", "algorithm", "The load balancing algorithm to be run.");
    parser.set_required<std::vector<int>>("l", "latencies", "The probe message latency range.");
    parser.set_required<std::vector<int>>("c", "capabilities", "The performance capabilities range of the servers.");
    parser.set_optional<bool>("r", "range", false, "If provided, a range of values will be randomly selected for capabilies and latencies.");
    parser.run_and_exit_if_error();
    int servers = parser.get<int>("s");
    int tasks = parser.get<int>("t");
    std::string algo = parser.get<std::string>("a");
    auto lat = parser.get<std::vector<int>>("l");
    auto cap = parser.get<std::vector<int>>("c");
    auto range = parser.get<bool>("r");
    logger.log(Logger::LogLevel::DEBUG, "This cmd line args are:- server: %d tasks: %d algorithm %s ", servers, tasks, algo.c_str());
    for (auto e: lat) {
        logger.log(Logger::LogLevel::DEBUG, "Latencies: %d ", e);
    }

    for (auto e: cap) {
        logger.log(Logger::LogLevel::DEBUG, "Capabilities: %d ", e);
    }

    LBAConfig config(servers, tasks, algo, lat, cap, range);

    // Create LBASimulator instance
    LBASimulator simulator(config, helpString);

    // Run simulation
    simulator.run();

    // Print results
    simulator.printResults();
    
    return 0;
}

