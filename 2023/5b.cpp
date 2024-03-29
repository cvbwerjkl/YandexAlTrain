/*




На день рождения маленький Ипполит получил долгожданный подарок — набор дощечек с написанными на них буквами латинского алфавита. 
Теперь-то ему будет чем заняться долгими вечерами, тем более что мама обещала подарить ему в следующем году последовательность целых неотрицательных чисел, если он хорошо освоит этот набор. Ради такого богатства Ипполит готов на многое.

Прямо сейчас юный исследователь полностью поглощён изучением хорошести строк. Хорошестью строки называется количество позиций от 1 до L - 1 (где L — длина строки), 
таких, что следующая буква в строке является следующей по алфавиту. Например, хорошесть строки "abcdefghijklmnopqrstuvwxyz" равна 25, а строки "abdc" — только 1.

Ипполит размышляет над решением закономерно возникающей задачи: чему равна максимально возможная хорошесть строки, которую можно собрать, используя дощечки из данного набора? Вы-то и поможете ему с ней справиться.

 


*/

#include <iostream>
#include <algorithm>


int main() {
    unsigned int vec[27] = {0};


    unsigned int a;
    std::cin >> a;


    for (int i = 0; i < a; ++i) {
        unsigned int b;
        std::cin >> b;
        vec[i] = b;

    }

    long long unsigned int count = 0;
    for (int i = 0; i < a - 1; ++i) {
        
        count = std::min(vec[i], vec[i + 1]) + count;

        
    }


    std::cout << count;

    return 0;

}