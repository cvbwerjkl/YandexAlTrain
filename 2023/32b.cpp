/*

Дан неориентированный невзвешенный граф. Необходимо посчитать количество его компонент связности и вывести их. 

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


void check(std::vector <std::vector <int>> &graph, std::vector <int> &visit, std::vector <std::vector <int>>& ans, int pos, int fix_pos) {
    //std::cout << "flag" << "\n";
    visit[pos] = 1;
    ans[fix_pos].push_back(pos);
    for (auto c : graph[pos]) {
        if (visit[c] != 1) {
            check(graph, visit, ans, c, fix_pos);
        }
    }
}



int main() {
    int vertex, edge, a, b;

    std::ifstream fin("input.txt");

    fin >> vertex >> edge;

    std::vector<std::vector<int>> graph(vertex + 1, std::vector<int> (0, 0));
    std::vector <int> visit(vertex + 1, 0);
    std::vector<std::vector<int>> ans(vertex + 1, std::vector<int>(0, 0));


    for (int i = 1; i <= edge; ++i) {
        fin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int k = 1; k <= vertex; ++k) {
        if (visit[k] != 1) check(graph, visit, ans, k, k);
    }
    int count = 0;

    for (int i = 1; i <= vertex; ++i) {
        if (ans[i].size() >= 1) ++count;
    }
    std::cout << count << "\n";

    for (int i = 1; i <= vertex; ++i) {
        if (ans[i].size() >= 1) {
            std::cout << ans[i].size() << "\n";
            for (auto c : ans[i]) {
                std::cout << c << " ";
            }
            std::cout << "\n";
        }
    }
  
    return 0;
}
