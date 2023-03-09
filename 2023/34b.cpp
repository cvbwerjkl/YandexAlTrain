/*

Дан ориентированный граф. Необходимо построить топологическую сортировку.

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

void check(std::vector <std::vector <int>>& graph, std::vector <int>& visit, std::vector <int>& visited_nodes, std::vector <int>& visited_nodes2, int pos) {
    visit[pos] = 1;
    visited_nodes2.push_back(pos);
    for (auto c : graph[pos]) {
        /*
        for (auto b : visited_nodes2) {
            std::cout << b << " ";
        }
        */
        //std::cout << c << " ";

        if (visit[c] == 0) {
            check(graph, visit, visited_nodes, visited_nodes2, c);
            //std::cout << "step" << c << " ";
            visited_nodes2.pop_back();
        }
        else if (std::find(visited_nodes2.begin(), visited_nodes2.end(), c) != visited_nodes2.end()) {
            std::cout << -1;
            exit(0);
        }
    }
    visited_nodes.push_back(pos);
}



int main() {
    int vertex, edge, a, b;

    std::ifstream fin("input.txt");

    fin >> vertex >> edge;

    std::vector<std::vector<int>> graph(vertex + 1, std::vector<int>(0, 0));
    std::vector <int> visit(vertex + 1, 0);
    std::vector <int> ans(vertex, 0);
    int j = vertex - 1;


    for (int i = 1; i <= edge; ++i) {
        fin >> a >> b;
        graph[a].push_back(b);
    }
    std::vector <int> visited_nodes;
    std::vector <int> visited_nodes2;
    for (int k = 1; k <= vertex; ++k) {
        visited_nodes.clear();
        visited_nodes2.clear();
        //std::cout << "begin\n";
        if (visit[k] != 1) check(graph, visit, visited_nodes, visited_nodes2, k);
        for (auto c : visited_nodes) {
            ans[j] = c;
            --j;
        }
    }

    for (int i = 0; i < ans.size(); ++i) {
        std::cout << ans[i] << " ";
    }

    return 0;
}
