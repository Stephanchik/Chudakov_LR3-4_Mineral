#include "Chudakov_LR3-4_ClassMineral.h"
#include <numeric>

double Mineral::calculateAverageHardness() const {
    if (hardness_list.empty()) return 0.0;
    double sum = std::accumulate(hardness_list.begin(), hardness_list.end(), 0.0);
    return sum / hardness_list.size();
}

bool Mineral::operator==(const Mineral& other) const {
    return calculateAverageHardness() == other.calculateAverageHardness();
}

Mineral Mineral::operator+(const Mineral& other) const {
    std::string new_name = name + "_" + other.name;
    double new_density = (density + other.density) / 2;
    std::vector<double> new_hardness;
    new_hardness.reserve(hardness_list.size() + other.hardness_list.size());
    new_hardness.insert(new_hardness.end(), hardness_list.begin(), hardness_list.end());
    new_hardness.insert(new_hardness.end(), other.hardness_list.begin(), other.hardness_list.end());
    return Mineral(new_name, new_density, new_hardness);
}

Mineral& Mineral::operator=(const Mineral& other) {
    if (this != &other) {
        name = other.name;
        density = other.density;
        hardness_list = other.hardness_list;
    }
    return *this;
}

Mineral& Mineral::operator++() {
    density += 1.0; // Увеличиваем плотность
    return *this;
}

Mineral Mineral::operator++(int) {
    Mineral temp = *this;
    ++(*this);
    return temp;
}

std::ostream& operator<<(std::ostream& os, const Mineral& m) {
    os << "Mineral: " << m.name << ", Density: " << m.density << ", Hardness: [";
    for (size_t i = 0; i < m.hardness_list.size(); ++i) {
        os << m.hardness_list[i];
        if (i < m.hardness_list.size() - 1) os << ", ";
    }
    os << "]";
    return os;
}

std::istream& operator>>(std::istream& is, Mineral& m) {
    std::cout << "Enter mineral name: ";
    is >> m.name;
    std::cout << "Enter density: ";
    is >> m.density;
    std::cout << "Enter number of hardness values: ";
    size_t num;
    is >> num;
    m.hardness_list.resize(num);
    for (size_t i = 0; i < num; ++i) {
        std::cout << "Enter hardness " << i + 1 << ": ";
        is >> m.hardness_list[i];
    }
    return is;
}