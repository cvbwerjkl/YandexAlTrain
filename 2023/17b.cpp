/*

В игре в пьяницу карточная колода раздается поровну двум игрокам. Далее они вскрывают по одной верхней карте, и тот, чья карта старше, забирает себе обе вскрытые карты, которые кладутся под низ его колоды. 
Тот, кто остается без карт – проигрывает. Для простоты будем считать, что все карты различны по номиналу, а также, что самая младшая карта побеждает самую старшую карту ("шестерка берет туза"). 
Игрок, который забирает себе карты, сначала кладет под низ своей колоды карту первого игрока, затем карту второго игрока (то есть карта второго игрока оказывается внизу колоды). 
Напишите программу, которая моделирует игру в пьяницу и определяет, кто выигрывает. В игре участвует 10 карт, имеющих значения от 0 до 9, большая карта побеждает меньшую, карта со значением 0 побеждает карту 9. 


*/

#include <iostream>
#include <vector>

int main() {

    std::vector<int> first;
    std::vector<int> second;
    int a, b, n = 0;

    for (int i = 0; i < 5; ++i) {
        std::cin >> a;
        first.push_back(a);
    }

    for (int i = 0; i < 5; ++i) {
        std::cin >> a;
        second.push_back(a);
    }



    while (true) {
        n += 1;

        if (n > 1000000) {
            std::cout << "botva";
            return 0;
        }

        if (first.empty()) {
            std::cout << "second " << n - 1;
            return 0;
        }

        if (second.empty()) {
            std::cout << "first " << n - 1;
            return 0;
        }

        a = first.front();
        first.erase(first.begin());
        b = second.front();
        second.erase(second.begin());

        if ((!(a == 9 && b == 0) && a > b) || (a == 0 && b == 9)) {
            first.push_back(a);
            first.push_back(b);
        }
        else {
            second.push_back(a);
            second.push_back(b);
        }
        /*
        for (int i = 0; i < first.size(); ++i) {
            std::cout << first[i] << " ";
        }
        std::cout << "\n";

        for (int i = 0; i < second.size(); ++i) {
            std::cout << second[i] << " ";
        }
        std::cout << "\n";
        */
        
    }

    return 0;
}