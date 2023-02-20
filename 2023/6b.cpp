/*



Васин жесткий диск состоит из M секторов. Вася последовательно устанавливал на него различные операционные системы следующим методом: он создавал новый раздел диска из последовательных секторов, 
начиная с сектора номер ai и до сектора bi включительно, и устанавливал на него очередную систему. При этом, если очередной раздел хотя бы по одному сектору пересекается с каким-то ранее созданным разделом, 
то ранее созданный раздел «затирается», и операционная система, которая на него была установлена, больше не может быть загружена.

Напишите программу, которая по информации о том, какие разделы на диске создавал Вася, определит, сколько в итоге работоспособных операционных систем установлено и работает в настоящий момент на Васином компьютере.



*/

#include <iostream>
#include <unordered_set>
//#include <vector>

int main() {
    int v;
    std::cin >> v;
    unsigned int maxsize[2100];

    int n, index = 0;
    std::cin >> n;
    std::unordered_set <unsigned int> count;


    for (int i = 1; i <= n; ++i) {
        unsigned int a, b;
        std::cin >> a >> b;
        maxsize[index] = a;
        maxsize[index + 1] = b;
        count.insert(i);
        index += 2;

        if (index > 1) {
            for (unsigned int j = 0; j < index - 2; j += 2) {

                if ((a >= maxsize[j] && a <= maxsize[j + 1]) || (b >= maxsize[j] && b <= maxsize[j + 1]) || (a <= maxsize[j] && b >= maxsize[j + 1])) {
                    count.erase(j / 2 + 1);
                }
            }
        }

    }

    std::cout << count.size();

    return 0;
}