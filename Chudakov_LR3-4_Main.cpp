#include "Chudakov_LR3-4_Methods.h"
#include <map>
#include <locale>

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
        {4, {"Show all minerals", showAllMinerals}},
        {5, {"Test operations", testOperations}},
        {6, {"Show sorted minerals", showSortedMinerals}}
    };

    int choice;
    while (true) {
        std::cout << "\nMenu:\n";
        for (const auto& item : menu) {
            std::cout << item.first << ". " << item.second.title << std::endl;
        }
        std::cout << "0. Exit\nEnter choice: ";
        std::cin >> choice;

        if (choice == 0) break;
        if (menu.find(choice) != menu.end()) {
            menu[choice].action();
        } else {
            std::cout << "Invalid choice!" << std::endl;
        }
    }
    return 0;
}