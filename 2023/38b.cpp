/*

На клеточном поле, размером NxM (2 ≤ N, M ≤ 250) сидит Q (0 ≤ Q ≤ 10000) блох в различных клетках. 
"Прием пищи" блохами возможен только в кормушке - одна из клеток поля, заранее известная. Блохи перемещаются по полю странным образом, а именно, прыжками, совпадающими с ходом обыкновенного шахматного коня. 
Длина пути каждой блохи до кормушки определяется как количество прыжков. Определить минимальное значение суммы длин путей блох до кормушки или, если собраться блохам у кормушки невозможно, то сообщить об этом. 
Сбор невозможен, если хотя бы одна из блох не может попасть к кормушке. 

*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <utility>

int main() {
    int n, m, startX, startY, bags, endX, endY, p, total = 0;

    std::ifstream fin("input.txt");

    fin >> n >> m;

    std::vector<std::vector<int>> graph(n + 1, std::vector<int>(m + 1, -1));

    fin >> startX >> startY;

    fin >> bags;

    graph[startX][startY] = 0;

    std::vector<std::vector<std::pair<int, int>>> visited;
    std::vector<std::pair<int, int>> temp;
    visited.push_back(temp);
    visited.push_back(temp);  

    p = 1;
    visited[p].push_back({ startX, startY });
    while (true) {
        //std::cout << "c 1\n";
        for (auto c : visited[p]) {
            //std::cout << c.first << " " << c.second << " c1\n";
            visited.push_back(temp);
             if ((c.first + 2 <= n && c.second + 1 <= m) && graph[c.first + 2][c.second + 1] == -1) {
                graph[c.first + 2][c.second + 1] = p;
                visited[p + 1].push_back({ c.first + 2 , c.second + 1 });
            }
            if ((c.first + 2 <= n && c.second - 1 >= 1) && graph[c.first + 2][c.second - 1] == -1) {
                graph[c.first + 2][c.second - 1] = p;
                visited[p + 1].push_back({ c.first + 2 , c.second - 1 });
            }
            if ((c.first - 2 >= 1 && c.second + 1 <= m) && graph[c.first - 2][c.second + 1] == -1) {
                graph[c.first - 2][c.second + 1] = p;
                visited[p + 1].push_back({ c.first - 2 , c.second + 1 });
            }
            if ((c.first - 2 >= 1 && c.second - 1 >= 1) && graph[c.first - 2][c.second - 1] == -1) {
                graph[c.first - 2][c.second - 1] = p;
                visited[p + 1].push_back({ c.first - 2 , c.second - 1 });
            }
            if ((c.first + 1 <= n && c.second + 2 <= m) && graph[c.first + 1][c.second + 2] == -1) {
                graph[c.first + 1][c.second + 2] = p;
                visited[p + 1].push_back({ c.first + 1 , c.second + 2 });
            }
            if ((c.first + 1 <= n && c.second - 2 >= 1) && graph[c.first + 1][c.second - 2] == -1) {
                graph[c.first + 1][c.second - 2] = p;
                visited[p + 1].push_back({ c.first + 1 , c.second - 2 });
            }
            if ((c.first - 1 >= 1 && c.second + 2 <= m) && graph[c.first - 1][c.second + 2] == -1) {
                graph[c.first - 1][c.second + 2] = p;
                visited[p + 1].push_back({ c.first - 1 , c.second + 2 });
            }
            if ((c.first - 1 >= 1 && c.second - 2 >= 1) && graph[c.first - 1][c.second - 2] == -1) {
                graph[c.first - 1][c.second - 2] = p;
                visited[p + 1].push_back({ c.first - 1 , c.second - 2 });
            }

        }
        /*
        for (auto b : visited[p + 1]) {
            std::cout << b.first << " " << b.second << " ";
        }
        */
        if (visited[p + 1].size() == 0) {
            break;
        }
        ++p;
        //std::cout << "step\n";
    }

    for (int i = 0; i < bags; ++i) {
        fin >> endX >> endY;
        if (graph[endX][endY] == -1) {
            std::cout << - 1;
            exit(0);
        }
        total += graph[endX][endY];
    }
    
    std::cout << total;

    return 0;

}
