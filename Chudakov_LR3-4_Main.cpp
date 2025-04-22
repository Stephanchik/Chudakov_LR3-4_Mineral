#include <map>
#include <locale>
#include "Chudakov_LR3-4_Methods.cpp"
//переопределить 6 оператров сравнения
//продемонстрировать операоры сравнения
//Рассказать про операторы ++ Mineral& Mineral::operator++()
//выполнить контроль ввода в cin
//в конструктор по умолчанию добавить рандомные значения для default mineral (5)
//void testOperations запрашивать номера элементов при демонстрации операторов
//демонстрация работы cin - std::istream& operator>>(std::istream& is, Mineral& m)
struct MenuItem {
    std::string title;
    void (*action)();
};

int main() {
    std::srand(std::time(NULL));
    setlocale(LC_ALL, "ru");
    std::map<int, MenuItem> menu = {
        {1, {"Create default mineral", createDefaultMinercal}},
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

        enterNumber(choice, "0. Exit\nEnter choice: ")();

        if (choice == 0) break;
        if (menu.find(choice) != menu.end()) {
            menu[choice].action();
        } else {
            std::cout << "Invalid choice!" << std::endl;
        }
    }
    return 0;
}