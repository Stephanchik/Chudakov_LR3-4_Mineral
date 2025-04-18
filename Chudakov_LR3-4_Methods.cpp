#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
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
		std::cout << label << " - ";
		std::getline(std::cin, rawInput);

		while (!userInput(rawInput)) {
			std::cout << label << " - ";
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







std::vector<Mineral> minerals;

void createDefaultMinercal() {
    std::string m_name;
    double m_density;
    std::vector<double> m_hardness;

    enterString(m_name, "Input the name of the mineral: ")();
    enterDouble(m_density, "Input the density of the mineral: ")();
    
    std::cout << "Input the hardness list of the mineral: " << std::endl;
    for (int start = 0; start < 3; start++) {
        double hardness = 0.0;
        enterDouble(hardness, "Input the hardness of the mineral: ")();
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