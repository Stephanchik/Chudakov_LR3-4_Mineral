#ifndef CHUDAKOV_LR3_4_CLASSMINERAL_H
#define CHUDAKOV_LR3_4_CLASSMINERAL_H

#include <string>
#include <vector>
#include <iostream>

class Mineral {
private:
    std::string name;              
    double density;                
    std::vector<double> hardness_list; 

public:
    // Конструкторы
    Mineral(); // По умолчанию
    Mineral(const std::string& n, double d, const std::vector<double>& h);
    Mineral(const Mineral& other); // Копирования
    explicit Mineral(const char* n); // Преобразования из строки
    Mineral(const std::string& n, double d); // Делегирующий

    // Методы get
    std::string getName() const;
    double getDensity() const;
    std::vector<double> getHardnessList() const;

    // Методы set
    void setName(const std::string& n);
    void setDensity(double d);
    void setHardnessList(const std::vector<double>& h);

    // Метод вычисления средней твердости
    double calculateAverageHardness() const;

    // Перегруженные операции
    bool operator==(const Mineral& other) const;
    bool operator>(const Mineral& other) const;
    bool operator<(const Mineral& other) const;
    bool operator!=(const Mineral& other) const;
    bool operator>=(const Mineral& other) const;
    bool operator<=(const Mineral& other) const;
    
    Mineral operator+(const Mineral& other) const;
    Mineral& operator=(const Mineral& other);
    Mineral& operator++();    // Префиксный инкремент (увеличивает плотность)
    Mineral operator++(int);  // Постфиксный инкремент
    friend std::ostream& operator<<(std::ostream& os, const Mineral& m);
    friend std::istream& operator>>(std::istream& is, Mineral& m);

    ~Mineral() = default;
};

#endif // CHUDAKOV_LR3_4_CLASSMINERAL_H