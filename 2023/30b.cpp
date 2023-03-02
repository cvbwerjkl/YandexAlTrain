/*

Даны две последовательности, требуется найти и вывести их наибольшую общую подпоследовательность. 

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


int main() {
    int m, n;

    std::ifstream fin("input.txt");

    fin >> m;

    std::vector <int> basa1(m, 0);

    for (int i = 0; i < m; ++i) {
        fin >> basa1[i];
    }

    fin >> n;

    std::vector <int> basa2(n, 0);

    for (int i = 0; i < n; ++i) {
        fin >> basa2[i];
    }


    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (basa1[i - 1] == basa2[j - 1]) dp[i][j] = dp[i -1][j - 1] + 1;
            else dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    //std::cout<< dp[m][n] << "\n";

    std::vector <int> ans;

    int i = m;
    int j = n;

    while (i > 0 && j > 0) {
        if (dp[i][j] == dp[i - 1][j]) --i;
        else if (dp[i][j] == dp[i][j - 1]) --j;
        else {
            ans.push_back(basa1[i - 1]);
            --i;
            --j;
        }
        //std::cout << i << " " << j << "\n";

    }
    //std::cout << ans.size() << " " << dp[m][n];
    
    for (int k = dp[m][n] - 1; k >= 0; --k) {
        std::cout << ans[k] << " ";
    }
    

    return 0;
}