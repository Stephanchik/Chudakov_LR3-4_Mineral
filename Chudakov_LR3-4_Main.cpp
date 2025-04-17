#include "Chudakov_LR3-4_Methods.h"
#include <map>

struct MenuItem {
    std::string title;
    void (*action)();
};

int main() {
    setlocale(LC_ALL, "ru");
    std::map<int, MenuItem> menu = {
        {1, {"Create default mineral", createDefaultMineral}},
        {2, {"Create parameterized mineral", createParameterizedMineral}},
        {3, {"Create copy mineral", createCopyMineral}},
        {4, {"Input mineral from console", []() {
            Mineral m;
            std::cin >> m;
            minerals.push_back(m);
            std::cout << "Added: " << m << std::endl;
        }}},
        {5, {"Show all minerals", showAllMinerals}},
        {6, {"Test operations", testOperations}},
        {7, {"Show sorted minerals by hardness", showSortedMinerals}}
    };

    int choice;
    while (true) {
        std::cout << "\nMenu:\n";
        for (const auto& item : menu) {
            std::cout << item.first << ". " << item.second.title << std::endl;
        }
        std::cout << "0. Exit\nEnter choice: ";
        std::cin >> choice;

        if (choice == 0) {
            std::cout << "Exiting program.\n";
            break;
        }

        if (menu.find(choice) != menu.end()) {
            std::cout << "\n=== Action: " << menu[choice].title << " ===\n";
            menu[choice].action();
        } else {
            std::cout << "Invalid choice!\n";
        }
    }

    return 0;
}