#include "Chudakov_LR3-4_Methods.h"
#include <iostream>

std::vector<Mineral> minerals;

void createDefaultMinercal() {
    std::string m_name;
    double m_density;
    std::vector<double> m_hardness;

    std::cout << "Input the name of the mineral: " << std::endl;
    std::getline(std::cin, m_name);
    
    std::cout << "Input the density of the mineral: " << std::endl;
    std::cin >> m_density;
    
    std::cout << "Input the hardness list of the mineral: " << std::endl;
    for (int start = 0; start < 3; start++) {
        double hardness = 0.0;
        std::cout << "Input the hardness of the mineral: " << std::endl;
        std::cin >> hardness;
        m_hardness.push_back(hardness);
    }
    
    Mineral m(m_name, m_density, m_hardness);
    minerals.push_back(m);

    std::cout << "Created default mineral: " << m << std::endl;
}

void createParameterizedMineral() {
    Mineral m("Quartz", 2.65, {7.0, 7.0, 7.0});
    minerals.push_back(m);
    std::cout << "Created parameterized mineral: " << m << std::endl;
}

void createCopyMineral() {
    if (!minerals.empty()) {
        Mineral m = minerals[0];
        minerals.push_back(m);
        std::cout << "Created copy mineral: " << m << std::endl;
    } else {
        std::cout << "No minerals to copy!" << std::endl;
    }
}

void showAllMinerals() {
    if (minerals.empty()) {
        std::cout << "No minerals available." << std::endl;
        return;
    }
    for (const auto& m : minerals) {
        std::cout << m << " - Avg Hardness: " << m.calculateAverageHardness() << std::endl;
    }
}

void testOperations() {
    if (minerals.size() < 2) {
        std::cout << "Need at least 2 minerals!" << std::endl;
        return;
    }
    Mineral m1 = minerals[0];
    Mineral m2 = minerals[1];
    std::cout << "m1 + m2: " << (m1 + m2) << std::endl;
    std::cout << "m1 == m2: " << (m1 == m2 ? "true" : "false") << std::endl;
}

void showSortedMinerals() {
    std::vector<Mineral> sorted = minerals;
    std::sort(sorted.begin(), sorted.end(), [](const Mineral& a, const Mineral& b) {
        return a.calculateAverageHardness() < b.calculateAverageHardness();
    });
    for (const auto& m : sorted) {
        std::cout << m << " - Avg Hardness: " << m.calculateAverageHardness() << std::endl;
    }
}