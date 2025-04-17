#include "Chudakov_LR3-4_ClassMineral.h"
#include <numeric>

// Конструкторы
Mineral::Mineral() : name("Unknown"), density(0.0), hardness_list() {}

Mineral::Mineral(const std::string& n, double d, const std::vector<double>& h)
    : name(n), density(d), hardness_list(h) {}

Mineral::Mineral(const Mineral& other)
    : name(other.name), density(other.density), hardness_list(other.hardness_list) {}

Mineral::Mineral(const char* n) : name(n), density(0.0), hardness_list() {}

Mineral::Mineral(const std::string& n, double d) : Mineral(n, d, {}) {}

// Методы get
std::string Mineral::getName() const { return name; }
double Mineral::getDensity() const { return density; }
std::vector<double> Mineral::getHardnessList() const { return hardness_list; }

// Методы set
void Mineral::setName(const std::string& n) { name = n; }
void Mineral::setDensity(double d) { density = d; }
void Mineral::setHardnessList(const std::vector<double>& h) { hardness_list = h; }

// Средняя твердость
double Mineral::calculateAverageHardness() const {
    if (hardness_list.empty()) return 0.0;
    return std::accumulate(hardness_list.begin(), hardness_list.end(), 0.0) / hardness_list.size();
}

// Операторы
bool Mineral::operator==(const Mineral& other) const {
    return (calculateAverageHardness() == other.calculateAverageHardness());
}

Mineral Mineral::operator+(const Mineral& other) const {
    std::vector<double> combined_hardness = hardness_list;
    combined_hardness.insert(combined_hardness.end(), other.hardness_list.begin(), other.hardness_list.end());
    return Mineral(name + "+" + other.name, (density + other.density) / 2, combined_hardness);
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
    density += 1.0;
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