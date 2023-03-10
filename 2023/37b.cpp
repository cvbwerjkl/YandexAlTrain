/*

В неориентированном графе требуется найти минимальный путь между двумя вершинами.

*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <utility>

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

    std::vector<std::vector<std::pair<int, int>>> visited;
    std::vector <int> ans;
    std::vector<std::pair<int, int>> temp;

    visited.push_back(temp);
    visited.push_back(temp);
    visited.push_back(temp);
    for (int i = 1; i <= n; ++i) {
        if (graph[start][i] == 1) {
            visited[1].push_back(std::pair(start, i));
        }
    }
        
    int p = 1;
    while (true) {
        for (auto c : visited[p]) {
            if (c.second == end) {
                std::cout << p << "\n";
                
                ans.push_back(end);
                --p;
                end = c.first;
                while (p) {
                    //std::cout << "cycle2\n";
                    for (auto d : visited[p]) {
                        if (d.second == end) {
                            ans.push_back(end);
                            end = d.first;
                            --p;
                            break;
                        }
                    }
                }
                ans.push_back(start);
                for (int y = ans.size() - 1; y >= 0; --y) {
                    std::cout << ans[y] << " ";
                }
               
                exit(0);
                
            }
            for (int m = 1; m <= n; ++m) {
                if (graph[c.second][m] == 1 && c.first != m) {
                    visited[p + 1].push_back(std::pair(c.second, m));
                }
            }
        }
        ++p;
        visited.push_back(temp);
        //std::cout << "cycle\n";
        if (p == n + 1) {
            std::cout << -1;
            break;
        }
    }
    return 0;

}
