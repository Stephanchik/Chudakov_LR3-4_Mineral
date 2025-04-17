#ifndef CHUDAKOV_LR3_4_METHODS_H
#define CHUDAKOV_LR3_4_METHODS_H

#include "Chudakov_LR3-4_ClassMineral.h"
#include <vector>
#include <algorithm>

// Глобальный вектор объектов
std::vector<Mineral> minerals;

// Функции проверки корректности ввода
bool isValidDensity(double d) {
    return d >= 0;
}

bool isValidHardness(double h) {
    return h >= 0;
}

// Функции ввода данных
void inputDouble(double& value, const std::string& prompt) {
    std::cout << prompt;
    std::cin >> value;
    while (!std::cin.good() || !isValidDensity(value)) {
        std::cout << "Invalid input. " << prompt;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cin >> value;
    }
}

// Демонстрация конструкторов
void createDefaultMineral() {
    Mineral m;
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

// Отображение всех объектов
void showAllMinerals() {
    if (minerals.empty()) {
        std::cout << "No minerals available." << std::endl;
        return;
    }
    for (const auto& m : minerals) {
        std::cout << m << " - Avg Hardness: " << m.calculateAverageHardness() << std::endl;
    }
}

// Тестирование операций
void testOperations() {
    if (minerals.size() < 2) {
        std::cout << "Need at least 2 minerals to test operations!" << std::endl;
        return;
    }
    Mineral m1 = minerals[0];
    Mineral m2 = minerals[1];
    std::cout << "m1 + m2: " << (m1 + m2) << std::endl;
    std::cout << "m1++: " << (m1++) << std::endl;
    std::cout << "After ++m1: " << m1 << std::endl;
    std::cout << "m1 == m2: " << (m1 == m2 ? "true" : "false") << std::endl;
}

// Сортировка по средней твердости
std::vector<Mineral> getSortedMineralsByHardness() {
    std::vector<Mineral> sorted_minerals = minerals;
    std::sort(sorted_minerals.begin(), sorted_minerals.end(),
              [](const Mineral& a, const Mineral& b) {
                  return a.calculateAverageHardness() < b.calculateAverageHardness();
              });
    return sorted_minerals;
}

void showSortedMinerals() {
    std::vector<Mineral> sorted = getSortedMineralsByHardness();
    if (sorted.empty()) {
        std::cout << "No minerals to sort." << std::endl;
        return;
    }
    std::cout << "Minerals sorted by average hardness:" << std::endl;
    for (const auto& m : sorted) {
        std::cout << m << " - Avg Hardness: " << m.calculateAverageHardness() << std::endl;
    }
}

#endif // CHUDAKOV_LR3_4_METHODS_H