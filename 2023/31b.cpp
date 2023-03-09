/*

Дан неориентированный граф, возможно, с петлями и кратными ребрами. Необходимо построить компоненту связности, содержащую первую вершину. 

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


void check(std::vector <std::vector <int>> &graph, std::vector <int> &visit, int pos) {
    //std::cout << "flag" << "\n";
    visit[pos] = 1;
    for (auto c : graph[pos]) {
        if (visit[c] != 1) {
            check(graph, visit, c);
        }
    }
}



int main() {
    int vertex, edge, a, b;

    std::ifstream fin("input.txt");

    fin >> vertex >> edge;

    std::vector<std::vector<int>> graph(vertex + 1, std::vector<int> (0, 0));
    std::vector <int> visit(vertex + 1, 0);


    for (int i = 1; i <= edge; ++i) {
        fin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    
    check(graph, visit, 1);
    int count = 0;

    for (int i = 1; i <= vertex; ++i) {
        if (visit[i] == 1) ++count;
    }
    std::cout << count << "\n";

    for (int i = 1; i <= vertex; ++i) {
        if (visit[i] == 1) std::cout << i << " ";
    }
  
    return 0;
}