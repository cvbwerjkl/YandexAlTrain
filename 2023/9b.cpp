/*


Вам необходимо ответить на запросы узнать сумму всех элементов числовой матрицы N×M в прямоугольнике с левым верхним углом (x1, y1) и правым нижним (x2, y2) 


*/

#include <iostream>
#include <vector>


int main() {

    int n, m, k;

    int a;

    std::cin >> n >> m >> k;

    std::vector<std::vector <int>> matrix(n + 1, std::vector<int>(m + 1, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> a;
            matrix[i + 1][j + 1] = a + matrix[i][j + 1] + matrix[i + 1][j] - matrix[i][j];

        }
    }

    int a1, a2, b1, b2;
    for (int i = 0; i < k; ++i) {
        std::cin >> a1 >> a2 >> b1 >> b2;

        std::cout << matrix[b1][b2] + matrix[a1 - 1][a2 - 1] - matrix[a1 - 1][b2] - matrix[b1][a2 - 1] << "\n";
    
    
    }




    return 0;
}