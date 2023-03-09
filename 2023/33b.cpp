/*

Во время контрольной работы профессор Флойд заметил, что некоторые студенты обмениваются записками. 
Сначала он хотел поставить им всем двойки, но в тот день профессор был добрым, а потому решил разделить студентов на две группы: списывающих и дающих списывать, и поставить двойки только первым.
У профессора записаны все пары студентов, обменявшихся записками. Требуется определить, сможет ли он разделить студентов на две группы так, чтобы любой обмен записками осуществлялся от студента одной группы студенту другой группы.


*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int flag = 0;

void check(std::vector <std::vector <int>> &graph, std::vector <int> &visit, int pos, int mark) {
    visit[pos] = mark;
    for (auto c : graph[pos]) {
        if (visit[c] == 0) {
            check(graph, visit, c, 2 - mark / 2);
        }
        else if (visit[c] == mark) {
            flag = 1;
            return;
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

    for (int k = 1; k <= vertex; ++k) {
        int mark = 1;
        if (visit[k] != 1 && visit[k] != 2) check(graph, visit, k, mark);
    }

    if (flag == 1) {
        std::cout << "NO";
    }
    else std::cout << "YES";
  
    return 0;
}
