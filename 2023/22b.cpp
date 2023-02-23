/*

У одного из студентов в комнате живёт кузнечик, который очень любит прыгать по клетчатой одномерной доске. Длина доски — N клеток. К его сожалению, он умеет прыгать только на 1, 2, …, k клеток вперёд.
Однажды студентам стало интересно, сколькими способами кузнечик может допрыгать из первой клетки до последней. Помогите им ответить на этот вопрос.

*/

#include <iostream>
#include <numeric>
#include <vector>
#include <fstream>


int main() {

    int n, k;

    std::ifstream fin("input.txt");


    fin >> n >> k;


    std::vector <int> trace (n + k + 1, 0);

    trace[0] = 1;
    trace[1] = 1;
    
    for (int i = 2; i <= k; ++i) {
        trace[i] = trace[i - 1] * 2;
    }
    
    
    for (int j = k + 1; j <= n; ++j) {
        trace[j] = std::accumulate(trace.begin() + j - k, trace.begin() + j, 0);
        
    }
    /*
    for (auto c : trace) {
    std::cout << c << " ";
    }
    */
    
    std::cout << trace[n - 1];

    
    return 0;

}