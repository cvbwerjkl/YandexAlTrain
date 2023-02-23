/*

В дощечке в один ряд вбиты гвоздики. Любые два гвоздика можно соединить ниточкой. Требуется соединить некоторые пары гвоздиков ниточками так, чтобы к каждому гвоздику была привязана хотя бы одна ниточка, а суммарная длина всех ниточек была минимальна. 

*/

#include <iostream>
#include <fstream>
#include <algorithm>


int main() {

    int n, sum = 0, k[105] = {50000}, dp[105] = {0};

    std::ifstream fin("input.txt");


    fin >> n;

    

    
    for (int i = 0; i < n; ++i) {
        fin >> k[i];
    }

    std::sort(k, k + n);

    if (n == 2) {
        std::cout << k[1] - k[0];
        return 0;
    }
    if (n == 3) {
        std::cout << k[2] - k[0];
        return 0;
    }


    /*
    for (int i = 0; i < n; ++i) {
        std::cout << k[i] << " ";
    }
    */


    dp[1] += k[1] - k[0];;
    dp[2] += k[2] - k[0];


    int flag = 0;
   
    for (int i = 3; i < n; ++i) {
        dp[i] = std::min(dp[i - 2], dp[i - 1]) + k[i] - k[i - 1];

    }

  
    
    std::cout << dp[n - 1];
 


    return 0;

}