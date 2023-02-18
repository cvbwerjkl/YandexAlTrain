/*



Научитесь пользоваться стандартной структурой данных deque для целых чисел.  Напишите программу, содержащую описание дека и моделирующую работу дека, реализовав все указанные здесь методы. 
Программа считывает последовательность команд и в зависимости от команды выполняет ту или иную операцию. После выполнения каждой команды программа должна вывести одну строчку.

Возможные команды для программы:

push_front n
Добавить (положить) в начало дека новый элемент. Программа должна вывести ok.

push_back n
Добавить (положить) в конец дека новый элемент. Программа должна вывести ok.

pop_front
Извлечь из дека первый элемент. Программа должна вывести его значение.

pop_back
Извлечь из дека последний элемент. Программа должна вывести его значение.

front
Узнать значение первого элемента (не удаляя его). Программа должна вывести его значение.

back
Узнать значение последнего элемента (не удаляя его). Программа должна вывести его значение.

size
Вывести количество элементов в деке.

clear
Очистить дек (удалить из него все элементы) и вывести ok.

exit
Программа должна вывести bye и завершить работу.

Гарантируется, что количество элементов в деке в любой момент не превосходит 100. Перед исполнением операций pop_front, pop_back, front, back программа должна проверять, содержится ли в деке хотя бы один элемент. 
Если во входных данных встречается операция pop_front, pop_back, front, back, и при этом дек пуст, то программа должна вместо числового значения вывести строку error.

*/

#include <iostream>
#include <vector>
#include <string>

int main() {

    std::vector<int> vec;
    std::string command;
    int a;
    std::cin >> command;

    while (true) {
        if (command == "push_front") {
            std::cin >> a;
            vec.insert(vec.begin(), a);
            std::cout << "ok\n";
        }
        else if (command == "pop_front") {
            if (vec.empty()) std::cout << "error\n";
            else {
                std::cout << vec.front() << "\n";
                vec.erase(vec.begin());
            }
        }
        else if (command == "push_back") {
            std::cin >> a;
            vec.push_back(a);
            std::cout << "ok\n";
        }
        else if (command == "pop_back") {
            if (vec.empty()) std::cout << "error\n";
            else {
                std::cout << vec.back() << "\n";
                vec.pop_back();
            }
        }

        else if (command == "front") {
            if (vec.empty()) std::cout << "error\n";
            else {
                std::cout << vec.front() << "\n";
            }
        }
        else if (command == "back") {
            if (vec.empty()) std::cout << "error\n";
            else {
                std::cout << vec.back() << "\n";
            }
        }
        else if (command == "size") {
            std::cout << vec.size() << "\n";

        }
        else if (command == "clear") {
            vec.clear();
            std::cout << "ok\n";

        }
        else if (command == "exit") {
            std::cout << "bye\n";
            break;

        }

        std::cin >> command;
    }


    return 0;
}