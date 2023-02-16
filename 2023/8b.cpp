/*


На клетчатой плоскости закрашено K клеток. Требуется найти минимальный по площади прямоугольник, со сторонами, параллельными линиям сетки, покрывающий все закрашенные клетки. 


*/

#include <iostream>

int main() {
    int a;
    int b, c;
    std::cin >> a;
    std::cin >> b >> c;
    int maxx = b;
    int maxy = c;
    int minx = b;
    int miny = c;

    for (int i = 0; i < a - 1; ++i) {
        std::cin >> b >> c;
        if (b > maxx) maxx = b;
        else if (b < minx) minx = b;
        if (c > maxy) maxy = c;
        else if (c < miny) miny = c;


    }

    std::cout << minx << " " << miny << " " << maxx << " " << maxy;


}