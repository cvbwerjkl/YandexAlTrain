/*

Дана прямоугольная доска N × M (N строк и M столбцов). В левом верхнем углу находится шахматный конь, которого необходимо переместить в правый нижний угол доски. 
В данной задаче конь может перемещаться на две клетки вниз и одну клетку вправо или на одну клетку вниз и две клетки вправо.
Необходимо определить, сколько существует различных маршрутов, ведущих из левого верхнего в правый нижний угол. 

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main() {
    int m, n;

    std::ifstream fin("input.txt");

    fin >> m >> n;
    std::vector<std::vector<int>> dp(m + 2, std::vector<int>(n + 2, 0));
    
    dp[2][2] = 1;

    for (int i = 2; i <= m + 1; ++i) {
        for (int j = 2; j <= n + 1; ++j) {
            if (i == 2 && j == 2) continue;
            else dp[i][j] = dp[i - 2][j - 1] + dp[i - 1][j - 2];
        }
    }

    std::cout << dp[m + 1][n + 1];

    return 0;
}
