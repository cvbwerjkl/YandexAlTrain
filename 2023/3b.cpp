/*

Диего увлекается коллекционированием наклеек. На каждой из них написано число, и каждый коллекционер мечтает собрать наклейки со всеми встречающимися числами.

Диего собрал N наклеек, некоторые из которых, возможно, совпадают. Как-то раз к нему пришли K коллекционеров. i-й из них собрал все наклейки с номерами не меньшими, чем pi. Напишите программу, которая поможет каждому из коллекционеров определить, сколько недостающих ему наклеек есть у Диего. Разумеется, гостей Диего не интересуют повторные экземпляры наклеек.


*/

#include <iostream>
#include <set>
#include <vector>


int search(std::vector<int>* vec2, int size, int aim) {
    if ((*vec2)[size] < aim) {
        //std::cout << "first" << "\n";
        return size + 1;
        
    }

    if ((*vec2)[0] > aim) {
        //std::cout << "second" << "\n";
        return 0;
        
    }


    int low = 0;
    int hig = size;
    int mid;
    while (hig - low > 1) {
        int mid = (hig + low) / 2;
        if ((*vec2)[mid] < aim) {
            low = mid;
        }
        else {
            hig = mid;
        }
    }
    if ((*vec2)[low] == aim) {
        //std::cout << "third" << "\n";
        return low;
        
    }
    else {
        //std::cout << "forth" << "\n";
        return low + 1;
        
    }

}



int main () {
    std::set <int >vec;
    std::vector <int> vec2;
    //std::cout << sizeof(vec);

    unsigned int a;
    std::cin >> a;
    //std::cout << vec[5] << "\n";

    for (size_t i = 0; i < a; ++i) {
        unsigned int b;
        std::cin >> b;
        vec.insert(b);

    }
    int size = 0;
    for (auto c : vec) {
        vec2.push_back(c);
        ++size;
    }



    std::cin >> a;

    for (size_t i = 0; i < a; ++i) {
        unsigned int b;
        std::cin >> b;
        std::cout << search(&vec2, size - 1, b) << "\n";
    }

    return 0;

}