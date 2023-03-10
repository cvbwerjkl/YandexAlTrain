/*

В неориентированном графе требуется найти длину минимального пути между двумя вершинами.

*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

int main() {
    int n, v, start, end;

    std::ifstream fin("input.txt");

    fin >> n;

    if (n == 1) {
        std::cout << 0;
        return 0;
    }

    std::vector<std::vector<int>> graph(n + 1, std::vector<int>(n + 1, 0));

    for (int j = 1; j <= n; ++j) {
        for (int k = 1; k <= n; ++k) {
            fin >> v;
            graph[j][k] = v;
        }
    }

    fin >> start >> end;

    if (start == end) {
        std::cout << 0;
        return 0;
    }

    std::vector<std::vector<int>> visited(n + 2, std::vector<int>(n + 2, 0));

    for (int i = 1; i <= n; ++i) {
        if (graph[i][start] == 1) {
            visited[1][i] = 1;
        }
    }

    
    int p = 1;
    while (true) {
        for (int j = 1; j <= n; ++j) {
            if (visited[p][j] == 1) {
                if (j == end) {
                    std::cout << p;
                    exit(0);
                }
                for (int m = 1; m <= n; ++m) {
                    if (graph[j][m] == 1) {
                        visited[p + 1][m] = 1;
                    }
                }
            }
        }
        ++p;
        if (p == n + 1) {
            std::cout << -1;
            break;
        }
    }
    return 0;

}
