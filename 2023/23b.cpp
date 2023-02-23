/*

Имеется калькулятор, который выполняет следующие операции:

    умножить число X на 2;
    умножить число X на 3;
    прибавить к числу X единицу.

Определите, какое наименьшее количество операций требуется, чтобы получить из числа 1 число N. 
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;
const int MAXN = 1000500;
long dp[MAXN];
long dp2[MAXN];
long dp3[MAXN];
long dp4[MAXN];


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    cin >> n;

    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    dp2[0] = 0;
    dp2[1] = 1;
    dp2[2] = 2;
    dp2[3] = 3;
    dp3[0] = 0;
    dp3[1] = 0;
    dp3[2] = 1;
    dp3[3] = 1;

    for (int i = 4; i <= n; ++i) {
        if (i % 3 == 0 && i % 2 == 0) {
            dp[i] = min(dp[i / 2], min(dp[i / 3], dp[i - 1])) + 1;
            if (dp[i / 3] <= dp[i - 1] && dp[i / 3] <= dp[i / 2]) {
                dp2[i] = dp2[i / 3] * 3;
                dp3[i] = i / 3;
            }
            else if (dp[i / 2] <= dp[i - 1] && dp[i / 2] <= dp[i / 3]) {
                dp2[i] = dp2[i / 2] * 2;
                dp3[i] = i / 2;
            }
            else {
                dp2[i] = dp2[i - 1] + 1;
                dp3[i] = i - 1;
            }
        }
        else if (i % 3 == 0) {
            dp[i] = min(dp[i / 3], dp[i - 1]) + 1;
            if (dp[i / 3] <= dp[i - 1]) {
                dp2[i] = dp2[i / 3] * 3;
                dp3[i] = i / 3;
            }
            else {
                dp2[i] = dp2[i - 1] + 1;
                dp3[i] = i - 1;
            }
        }
        else if (i % 2 == 0) {
            dp[i] = min(dp[i / 2], dp[i - 1]) + 1;
            if (dp[i / 2] < dp[i - 1]) {
                dp2[i] = dp2[i / 2] * 2;
                dp3[i] = i / 2;
            }
            else {
                dp2[i] = dp2[i - 1] + 1;
                dp3[i] = i - 1;
            }
        }
        else {
            dp[i] = dp[i - 1] + 1;
            dp2[i] = dp2[i - 1] + 1;
            dp3[i] = i - 1;
        }

    }
    int j = 0;
    dp4[j] = dp2[n];
    int k = dp3[n];
    while (k != 0) {
        ++j;
        dp4[j] = dp2[k];
        k = dp3[k];
    }
    
    cout << dp[n] << "\n";

    while (j >= 0) {
        std::cout << dp4[j] << " ";
        --j;
    }

    return 0;
}