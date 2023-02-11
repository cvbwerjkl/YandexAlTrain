/*

Даны три натуральных числа. Возможно ли построить треугольник с такими сторонами. Если это возможно, выведите строку YES, иначе выведите строку NO.

Треугольник — это три точки, не лежащие на одной прямой.

*/

#include <iostream>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;

    if (a <= 0 || b <= 0 || c <= 0) {
        std::cout << "NO";
        return 0;
    }

    else if (a + b <= c || a + c <= b || c + b <= a) {
        std::cout << "NO";
        return 0;
    }
    
    else {
        std::cout << "YES";
        return 0;
    }

    return 0;

}