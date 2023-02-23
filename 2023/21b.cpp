/*
По данному числу N определите количество последовательностей из нулей и единиц длины N, в которых никакие три единицы не стоят рядом. 
*/

#include <iostream>
#include <fstream>


int main() {

    int n;

    std::ifstream fin("input.txt");


    fin >> n;




    long long unsigned int t1 = 2;
    long long unsigned int t2 = 4;
    long long unsigned int t3 = 7;
    long long unsigned int t4;




    for (int i = 4; i <= n; ++i) {

        t4 = t1 + t2 + t3;
        t1 = t2;
        t2 = t3;
        t3 = t4;

    }

    if (n == 1)  std::cout << 2;
    else if (n == 2)  std::cout << 4;
    else if (n == 3)  std::cout << 7;
    else std::cout << t4;




    return 0;

}