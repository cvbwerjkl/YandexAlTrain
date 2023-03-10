/*

Пещера представлена кубом, разбитым на N частей по каждому измерению (то есть на N3 кубических клеток). 
Каждая клетка может быть или пустой, или полностью заполненной камнем. 
Исходя из положения спелеолога в пещере, требуется найти, какое минимальное количество перемещений по клеткам ему требуется, чтобы выбраться на поверхность. 
Переходить из клетки в клетку можно, только если они обе свободны и имеют общую грань. 

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>



int main() {
    int n;
    char v;
    std::ifstream fin("input.txt");

    fin >> n;



    if (n == 1) {
        std::cout << 0;
        return 0;
    }

    std::vector<std::vector<std::vector<int>>> matrix(n + 1, std::vector<std::vector<int>> (n + 1, std::vector<int> (n + 1)));

    std::vector <int> start(3, 0);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= n; ++k) {
                fin.get(v);
                while (v != '#' && v != 'S' && v != '.') {
                    fin.get(v);
                }
                if (v == '#') {
                    matrix[i][j][k] = -1;
                }
                else if (v == '.') {
                    matrix[i][j][k] = 0;
                }
                else {
                    matrix[i][j][k] = 0;
                    start[0] = i;
                    start[1] = j;
                    start[2] = k;
                }
            }
        }
    }

    if (start[0] == 1) {
        std::cout << 0;
        return 0;
    }

    std::vector<std::vector<std::vector<int>>> visited;

    std::vector<std::vector<int>> temp;

    visited.push_back(temp);
    visited.push_back(temp);
    visited[1].push_back(start);
    
    
    int p = 1;
    while (true) {
        visited.push_back(temp);
        for (auto c : visited[p]) {
            if (c[0] == 1) {
                std::cout << p - 1;
                exit(0);
            }
            if (c[0] - 1 >= 1 && matrix[c[0] - 1][c[1]][c[2]] != -1) {
                visited[p + 1].push_back({c[0] - 1, c[1], c[2]});
                matrix[c[0] - 1][c[1]][c[2]] = -1;
            }
            if (c[0] + 1 <= n && matrix[c[0] + 1][c[1]][c[2]] != -1) {
                visited[p + 1].push_back({ c[0] + 1, c[1], c[2] });
                matrix[c[0] + 1][c[1]][c[2]] = -1;
            }
            if (c[1] - 1 >= 1 && matrix[c[0]][c[1] - 1][c[2]] != -1) {
                visited[p + 1].push_back({ c[0], c[1] - 1, c[2] });
                matrix[c[0]][c[1] - 1][c[2]] = -1;
            }
            if (c[1] + 1 <= n && matrix[c[0]][c[1] + 1][c[2]] != -1) {
                visited[p + 1].push_back({ c[0], c[1] + 1, c[2] });
                matrix[c[0]][c[1] + 1][c[2]] = -1;
            }
            if (c[2] - 1 >= 1 && matrix[c[0]][c[1]][c[2] - 1] != -1) {
                visited[p + 1].push_back({ c[0], c[1], c[2] - 1 });
                matrix[c[0]][c[1]][c[2] - 1] = -1;
            }
            if (c[2] + 1 <= n && matrix[c[0]][c[1]][c[2] + 1] != -1) {
                visited[p + 1].push_back({ c[0], c[1], c[2] + 1 });
                matrix[c[0]][c[1]][c[2] + 1] = -1;
            }
        }
        ++p;
    }
    
    

    /*
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= n; ++k) {
                std::cout << matrix[i][j][k] << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }
    */

    return 0;

}
