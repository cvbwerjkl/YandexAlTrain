/*

К тупику со стороны пути 1 (см. рисунок) подъехал поезд. Разрешается отцепить от поезда один или сразу несколько первых вагонов и завезти их в тупик (при желании, можно даже завезти в тупик сразу весь поезд). 
После этого часть из этих вагонов вывезти в сторону пути 2. После этого можно завезти в тупик еще несколько вагонов и снова часть оказавшихся вагонов вывезти в сторону пути 2. 
И так далее (так, что каждый вагон может лишь один раз заехать с пути 1 в тупик, а затем один раз выехать из тупика на путь 2). Заезжать в тупик с пути 2 или выезжать из тупика на путь 1 запрещается. Нельзя с пути 1 попасть на путь 2, не заезжая в тупик.

Известно, в каком порядке изначально идут вагоны поезда. Требуется с помощью указанных операций сделать так, чтобы вагоны поезда шли по порядку (сначала первый, потом второй и т.д., считая от головы поезда, едущего по пути 2 в сторону от тупика). 
Напишите программу, определяющую, можно ли это сделать.

*/

#include <iostream>
#include <stack>
#include <fstream>


int main() {

    int n, tmp = 0;
    int vagon = 0;
    std::stack<int> str;

    int limit = 1;
    

    std::ifstream fin("input.txt");

    fin >> n;

    for (int i = 0; i < n; ++i) {
        fin >> vagon;
        str.push(vagon);

        while (vagon != limit && i < n) {
            fin >> vagon;
            str.push(vagon);
            ++i;
        }
        //std::cout << str.size() << "\n";

        tmp = str.top();
        str.pop();

        while (true && !str.empty()) {
            //std::cout << "inside " << str.top() << " " << tmp << "\n";
            if (tmp + 1 != str.top() || str.empty()) break;
            tmp = str.top();
            str.pop();
        }
        limit = tmp + 1;
        //std::cout << str.size() << " " << limit << "\n";

    }

    if (str.empty()) std::cout << "YES";
    else std::cout << "NO";
    

    return 0;

}