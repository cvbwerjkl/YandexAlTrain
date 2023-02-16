/*




Научитесь пользоваться стандартной структурой данных stack для целых чисел. Напишите программу, содержащую описание стека и моделирующую работу стека, реализовав все указанные здесь методы. 
Программа считывает последовательность команд и в зависимости от команды выполняет ту или иную операцию. После выполнения каждой команды программа должна вывести одну строчку. Возможные команды для программы:

push n
Добавить в стек число n (значение n задается после команды). Программа должна вывести ok.

pop
Удалить из стека последний элемент. Программа должна вывести его значение.

back
Программа должна вывести значение последнего элемента, не удаляя его из стека.

size
Программа должна вывести количество элементов в стеке.

clear
Программа должна очистить стек и вывести ok.

exit
Программа должна вывести bye и завершить работу.

Перед исполнением операций back и pop программа должна проверять, содержится ли в стеке хотя бы один элемент. Если во входных данных встречается операция back или pop, и при этом стек пуст, то программа должна вместо числового значения вывести строку error.



*/

#include <iostream>
#include <vector>
#include <string>

int main(){
        
    std::vector<int> vec;
    std::string command;
    int a;
    std::cin >> command;

    while(true) {
        if (command == "push") {
            std::cin >> a;
            vec.push_back(a);
            std::cout << "ok\n";
        }
        else if (command == "pop") {
            if (vec.empty()) std::cout << "error\n";
            else {
                std::cout << vec.back() << "\n";
                vec.pop_back();
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