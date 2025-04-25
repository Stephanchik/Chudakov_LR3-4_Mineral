#ifndef CHUDAKOV_LR3_4_METHODS_H
#define CHUDAKOV_LR3_4_METHODS_H

#include "Chudakov_LR3-4_ClassMineral.cpp"
#include <vector>
#include <algorithm>

extern std::vector<Mineral> minerals; // Глобальный вектор минералов

// Функции для работы с меню
void createDefaultMineral();
void createParameterizedMineral();
void createCopyMineral();
void showAllMinerals();
void testOperations();
void showSortedMinerals();
void demonstrateIncriments();

#endif // CHUDAKOV_LR3_4_METHODS_H