#include <iostream>
#include <stack>
#include <fstream>
#include <string>

// Функция для чтения данных из файла
void readFromFile(std::stack<int>& train, const std::string& filename) {
    std::ifstream file(filename);
    int wagonType;
    while (file >> wagonType) {
        train.push(wagonType);
    }
    file.close();
}

// Функция для чтения данных с клавиатуры
void readFromKeyboard(std::stack<int>& train) {
    int n, wagonType;
    std::cout << "Введите количество вагонов: ";
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cout << "Введите тип вагона (1 или 2): ";
        std::cin >> wagonType;
        train.push(wagonType);
    }
}

// Главная функция
int main() {
    setlocale(LC_ALL, "ru");
    std::stack<int> train, direction1, direction2;
    std::string inputMethod, filename;

    std::cout << "Введите метод ввода данных (keyboard/file): ";
    std::cin >> inputMethod;

    if (inputMethod == "file") {
        std::cout << "Введите имя файла: ";
        std::cin >> filename;
        readFromFile(train, filename);
    }
    else {
        readFromKeyboard(train);
    }

    // Сортировка вагонов по направлениям
    while (!train.empty()) {
        int wagonType = train.top();
        train.pop();
        if (wagonType == 1) {
            direction1.push(wagonType);
        }
        else {
            direction2.push(wagonType);
        }
    }

    // Вывод результатов
    std::cout << "Направление 1: ";
    while (!direction1.empty()) {
        std::cout << direction1.top() << " ";
        direction1.pop();
    }
    std::cout << "\nНаправление 2: ";
    while (!direction2.empty()) {
        std::cout << direction2.top() << " ";
        direction2.pop();
    }

    return 0;
}
