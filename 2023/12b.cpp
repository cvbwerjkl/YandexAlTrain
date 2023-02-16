/*




Рассмотрим последовательность, состоящую из круглых, квадратных и фигурных скобок. Программа дожна определить, является ли данная скобочная последовательность правильной. 
Пустая последовательность явлется правильной. Если A – правильная, то последовательности (A), [A], {A} – правильные. Если A и B – правильные последовательности, то последовательность AB – правильная. 


*/

#include <iostream>
#include <vector>
#include <string>

int main(){
        
    std::vector<char> vec;
    char a;
    
    do {
        a = getchar();
        if (a != EOF && a != '\n') {
            if (a == '(' || a == '[' || a == '{') {
                vec.push_back(a);
            }
            else if (a == ')' || a == ']' || a == '}') {
                if (vec.empty()) {
                    std::cout << "no";
                    return 0;
                }
                else {
                    if ((a == ')' && vec.back() == '(') || (a == ']' && vec.back() == '[') || (a == '}' && vec.back() == '{')) {
                        vec.pop_back();
                    }
                    else {
                        std::cout << "no";
                        return 0;
                    }
                }
            }
        }

    } while (a != EOF);

    if (vec.size() != 0) {
        std::cout << "no";
        return 0;
    }

    std::cout << "yes";

    return 0;
}