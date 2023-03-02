/*

Около Петиного университета недавно открылось новое кафе, в котором действует следующая система скидок: при каждой покупке более чем на 100 рублей покупатель получает купон, 
дающий право на один бесплатный обед (при покупке на сумму 100 рублей и меньше такой купон покупатель не получает).
Однажды Пете на глаза попался прейскурант на ближайшие N дней. Внимательно его изучив, он решил, что будет обедать в этом кафе все N дней, 
причем каждый день он будет покупать в кафе ровно один обед. Однако стипендия у Пети небольшая, и поэтому он хочет по максимуму использовать предоставляемую систему скидок так, 
чтобы его суммарные затраты были минимальны. Требуется найти минимально возможную суммарную стоимость обедов и номера дней, в которые Пете следует воспользоваться купонами.


*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


int main() {
    int m;

    std::ifstream fin("input.txt");

    fin >> m;

    std::vector<std::vector<int>> dp(m + 2, std::vector<int>(m + 2, 50000));
    std::vector <int> price (m + 1, 0);

    
    for (int i = 1; i <= m; ++i) {
        fin >> price[i];
    }

    if (m == 0) {
        std::cout << 0 << "\n";
        std::cout << 0 << " " << 0 << "\n";
        return 0;
    }


    if (m == 1) {
        std::cout << price[1] << "\n";
        if (price[1] > 100) std::cout << 1 << " " << 0 << "\n";
        else std::cout << 0 << " " << 0 << "\n";
        return 0;
    }


    int min_sum = 50000, coup_am = 0, coup_tot = 0;

    dp[1][0] = 0;

    
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (price[i] == 0) {
                dp[j][i] = dp[j][i - 1];
            }
            else if (price[i] <= 100) {
                dp[j][i] = std::min(dp[j][i - 1] + price[i], dp[j + 1][i - 1]);
            }
            else {
                dp[j][i] = std::min(dp[j - 1][i - 1] + price[i], dp[j + 1][i - 1]);
            }
            

        }       
    }
    
    
    for (int i = m; i >= 1; --i) {
        if (dp[i][m] <= min_sum) {
            min_sum = dp[i][m];
            coup_am = i - 1;
        }
    }


    int tmp = coup_am;

    int i = m;

    std::vector <int> ans;

    while (i > 1) {
        if (price[i] == 0) {
           --i;
        }
        else if (price[i] <= 100) {
            if (dp[coup_am + 1][i] == dp[coup_am + 2][i - 1]) {
                ++coup_tot;
                ans.push_back(i);
                --i;
                ++coup_am;
            }
            else {
                --i;
            }
        }
        else {
            if (dp[coup_am + 1][i] == dp[coup_am + 2][i - 1]) {
                ++coup_tot;
                ans.push_back(i);
                --i;
                ++coup_am;
                
            }
            else {
                --i;
                --coup_am;

            }
        }
    }


    std::cout << min_sum << "\n";
    std::cout << tmp << " " << coup_tot << "\n";

    
    
    for (int k = ans.size() - 1; k >= 0; --k) {
        std::cout << ans[k] << " ";
    }

    /*
    std::cout << "\n";
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= m; ++j) {
            std::cout << dp[i][j] << " ";

        }
        std::cout << "\n";
    }
    */
    

    return 0;
}