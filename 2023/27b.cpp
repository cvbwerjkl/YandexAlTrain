/*

В левом верхнем углу прямоугольной таблицы размером N×M находится черепашка. В каждой клетке таблицы записано некоторое число. 
Черепашка может перемещаться вправо или вниз, при этом маршрут черепашки заканчивается в правом нижнем углу таблицы.
Подсчитаем сумму чисел, записанных в клетках, через которую проползла черепашка (включая начальную и конечную клетку). 
Найдите наибольшее возможное значение этой суммы и маршрут, на котором достигается эта сумма. 

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main() {
    int m, n;

    std::ifstream fin("input.txt");

    fin >> m >> n;
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, -100));
    std::vector<std::vector<int>> dp2(m + 1, std::vector<int>(n + 1, -100));
    std::vector <char> ans;
    
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            fin >> dp[i][j];
        }   
    }

    dp2[1][1] = dp[1][1];

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == 1 && j == 1) continue;
            else {
                dp2[i][j] = std::max(dp2[i - 1][j], dp2[i][j - 1]) + dp[i][j];
            }
        }
    }

    std::cout << dp2[m][n] << "\n";

    int i = m, j = n;

    while (i >= 1 && j >= 1) {
        if ((dp2[i][j] - dp[i][j] == dp2[i][j - 1]) && i > 0 && j > 0) {
            ans.push_back('R');
            --j;
        }
        else {
            ans.push_back('D');
            --i;
        }
    }

    //std::cout << ans.size();

    for (int k = m + n - 3; k >= 0; --k) {
        std::cout << ans[k] << " ";
    }

    return 0;
}
