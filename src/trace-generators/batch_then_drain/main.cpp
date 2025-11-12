#include <iostream>
#include <iomanip>
#include <fstream>
#include <random>
#include <string>
#include <vector>
#include "../../../utils/TraceConfig.hpp"

void generateTrace(const unsigned seed, const std::size_t n, TraceConfig &config, std::uniform_int_distribution<int> &dist, std::mt19937& gen) {

    auto outputFileName = config.makeTraceFileName(seed, n);
    std::cout << "Generating file: " << outputFileName << std::endl;

    std::ofstream out(outputFileName.c_str());
    if (!out.is_open()) {
        std::cerr << "Failed to open file " << outputFileName << std::endl;
        exit(1);
    }

    out << config.profileName << " " << n << " " << seed << std::endl;

    unsigned id = 0;
    int spaceBeforeNumber = 10;

    for (unsigned i = 0; i < n; ++i) {
        int key = dist(gen);
        out << "I "
            << std::setw(spaceBeforeNumber) << key
            << std::setw(spaceBeforeNumber) << id
            << "\n";
        id++;
    }

    for (unsigned i = 0; i < n; ++i) {
        out << "E\n";
    }

    out.close();
}

int main() {
    TraceConfig config(std::string("batch_then_drain"));

    for (auto seed : config.seeds) {
        std::mt19937 rng(seed);

        for (auto n : config.Ns) {
            const unsigned key_min = 1;
            const unsigned key_max = n * n; // N^2
            std::uniform_int_distribution<int> dist(key_min, key_max);

            generateTrace(seed, n, config, dist, rng);
        }
    }

    return 0;
}