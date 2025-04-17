#ifndef CHUDAKOV_LR3_4_CLASSMINERAL_H
#define CHUDAKOV_LR3_4_CLASSMINERAL_H

#include <string>
#include <vector>
#include <iostream>

class Mineral {
private:
    std::string name;              // Название минерала
    double density;                // Плотность минерала
    std::vector<double> hardness_list; // Список твердости при разной температуре

public:
    // Конструкторы
    Mineral() : name("Unknown"), density(0.0), hardness_list() {} // По умолчанию
    Mineral(const std::string& n, double d, const std::vector<double>& h) // Параметризованный
        : name(n), density(d), hardness_list(h) {}
    Mineral(const Mineral& other) // Копирования
        : name(other.name), density(other.density), hardness_list(other.hardness_list) {}
    // Делегирующий конструктор
    Mineral(const std::string& n) : Mineral(n, 0.0, {}) {}
    // Конструктор преобразования (из строки в объект)
    explicit Mineral(const char* n) : name(n), density(0.0), hardness_list() {}

    // Методы get
    inline std::string getName() const { return name; }
    inline double getDensity() const { return density; }
    inline std::vector<double> getHardnessList() const { return hardness_list; }

    // Методы set
    inline void setName(const std::string& n) { name = n; }
    inline void setDensity(double d) { density = d; }
    inline void setHardnessList(const std::vector<double>& h) { hardness_list = h; }

    // Прототипы методов
    double calculateAverageHardness() const; // Вычисление средней твердости

    // Перегруженные операции
    bool operator==(const Mineral& other) const; // Сравнение по средней твердости
    Mineral operator+(const Mineral& other) const; // Сложение
    Mineral& operator=(const Mineral& other); // Присваивание
    Mineral& operator++(); // Префиксный инкремент
    Mineral operator++(int); // Постфиксный инкремент
    friend std::ostream& operator<<(std::ostream& os, const Mineral& m); // Вывод
    friend std::istream& operator>>(std::istream& is, Mineral& m); // Ввод

    // Деструктор
    ~Mineral() {}
};

#endif // CHUDAKOV_LR3_4_CLASSMINERAL_H