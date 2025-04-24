#include <iostream>
#include <functional>
#include <vector>
#include <random>
#include <algorithm>
#include <cstdlib>
#include "Chudakov_LR3-4_ClassMineral.cpp"


bool userInput(std::string input) {
	if (input.empty()) {
		return false;
	}
	try {
		int lastTry = stoi(input);
		if (lastTry < 0) {
			return false;
		}
	}
	catch (...) {
		return false;
	}
	return true;
}

bool userInputDouble(std::string input) {
	if (input.empty()) {
		return false;
	}
	try {
		double lastTry = stod(input);
		if (lastTry < 0) {
			return false;
		}
	}
	catch (...) {
		return false;
	}
	return true;
}

std::function<void()> enterNumber(int& variousLink, std::string label) {
	return [&variousLink, label]() {
		std::string rawInput;
		std::cout << label;
		std::getline(std::cin, rawInput);

		while (!userInput(rawInput)) {
			std::cout << label;
			std::getline(std::cin, rawInput);
		}
		variousLink = stoi(rawInput);
		};
}

std::function<void()> enterDouble(double& variousLink, std::string label) {
	return [&variousLink, label]() {
		std::string rawInput;
		std::cout << label << " - ";
		std::getline(std::cin, rawInput);

		while (!userInputDouble(rawInput)) {
			std::cout << label << " - ";
			std::getline(std::cin, rawInput);
		}
		variousLink = stod(rawInput);
		};
}

std::function<void()> enterString(std::string& variousLink, std::string label) {
	return [&variousLink, label]() {
		std::cout << label << " - ";
		std::getline(std::cin, variousLink);
	};
}


bool user_comparison_operator(std::string various_link) {
	if (various_link == "==" || various_link == "!=" || various_link == ">" || various_link == "<" || various_link == ">=" || various_link == "<=") {
		return true;
	}
	return false;
}

std::function<void()> enter_the_сcomparison_operator(std::string& varlink, std::string label) {
	return [&varlink, label]() {
		std::string rawinput;
		std::cout << label << " - ";
		std::getline(std::cin, rawinput);

		while(!user_comparison_operator(rawinput)) {
			std::cout << label << " - ";
			std::getline(std::cin, rawinput);
		}
		varlink = rawinput;
	};
}

std::vector<Mineral> minerals;

double fRand(double fMin, double fMax) {
	double f = (double)rand() / RAND_MAX;
	return fMin + f * (fMax - fMin);
}

template<typename T>
T random(std::vector<T> const &vector) {
	auto it = vector.cbegin();
	int random = rand() % vector.size();
	std::advance(it, random);

	return *it;
}

void createDefaultMinercal() {
	std::vector<std::string> names = {"Quartz", "Diorite", "Andezit", "Stone", "Gold", "Diamod", "Sapphire"};
	std::string name = random(names);
	double density = fRand(5.0, 20.0);
	std::vector<double> hardness_list = {};
	for (int start = 0; start < 3; start++) {
		hardness_list.push_back(fRand(2.0, 15.0));
	}

	Mineral m(name, density, hardness_list);
    minerals.push_back(m);
    std::cout << "Created defolt mineral: " << m << std::endl;
}

void createParameterizedMineral() {
	std::string m_name;
    double m_density;
    std::vector<double> m_hardness;

    enterString(m_name, "Input the name of the mineral: ")();
    enterDouble(m_density, "Input the density of the mineral: ")();
    
    for (int start = 0; start < 3; start++) {
        double hardness = 0.0;
        enterDouble(hardness, "Input the hardness of the mineral: ")();
        m_hardness.push_back(hardness);
    }
    
    Mineral m(m_name, m_density, m_hardness);
    minerals.push_back(m);

    std::cout << "Created default mineral: " << m << std::endl;
}

void createCopyMineral() {
    if (!minerals.empty()) {
		int index = 0;
		enterNumber(index, "Enter the number of the mineral what copy you wanna do - ")();
		while (index > minerals.size()) {
			std::cout << "The number of the mineral what you wanna copy does not exist..." << std::endl;
			enterNumber(index, "Enter the number of the mineral what copy you wanna do - ")();
		}
        Mineral m = minerals[index - 1];
        minerals.push_back(m);
        std::cout << "Created copy mineral: " << m << std::endl;
    } else {
        std::cout << "There are no minerals to copy..." << std::endl;
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
	int index1;
	enterNumber(index1, "Input the number of the first mineral what you wanna compare")();
	while (index1 > minerals.size()) {
		std::cout << "The number of the mineral what you wanna compare does not exist..." << std::endl;
		enterNumber(index1, "Input the number of the first mineral what you wanna compare")();
	}
	int index2;
	enterNumber(index2, "Input the number of the second mineral what you wanna compare")();
	while (index2 > minerals.size()) {
		std::cout << "The number of the mineral what you wanna compare does not exist..." << std::endl;
		enterNumber(index2, "Input the number of the first mineral what you wanna compare")();
	}
    Mineral m1 = minerals[index1 - 1];
    Mineral m2 = minerals[index2 - 1];

	std::string choice_operation;
	enter_the_сcomparison_operator(choice_operation, "Input the comparison operator what you wanna apply to")();
	
	if (choice_operation == "==") {
		std::cout << "m1 + m2: " << (m1 + m2) << std::endl;
		std::cout << "m1 == m2: " << (m1 == m2 ? "true" : "false") << std::endl;
	} else if (choice_operation == "!=") {
		std::cout << "m1 + m2: " << (m1 + m2) << std::endl;
		std::cout << "m1 != m2: " << (m1 != m2 ? "true" : "false") << std::endl;
	} else if (choice_operation == ">") {
		std::cout << "m1 + m2: " << (m1 + m2) << std::endl;
		std::cout << "m1 > m2: " << (m1 > m2 ? "true" : "false") << std::endl;
	} else if (choice_operation == "<") {
		std::cout << "m1 + m2: " << (m1 + m2) << std::endl;
		std::cout << "m1 < m2: " << (m1 < m2 ? "true" : "false") << std::endl;
	} else if (choice_operation == ">=") {
		std::cout << "m1 + m2: " << (m1 + m2) << std::endl;
		std::cout << "m1 >= m2: " << (m1 >= m2 ? "true" : "false") << std::endl;
	} else {
		std::cout << "m1 + m2: " << (m1 + m2) << std::endl;
		std::cout << "m1 <= m2: " << (m1 <= m2 ? "true" : "false") << std::endl;
	}
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