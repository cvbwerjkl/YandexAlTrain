/*




В постфиксной записи (или обратной польской записи) операция записывается после двух операндов. 
Например, сумма двух чисел A и B записывается как A B +. Запись B C + D * обозначает привычное нам (B + C) * D, а запись A B C + D * + означает A + (B + C) * D. 
Достоинство постфиксной записи в том, что она не требует скобок и дополнительных соглашений о приоритете операторов для своего чтения. 

*/

#include <iostream>
#include <vector>
#include <string>

int main(){
        
    std::vector<int> vec;
    char a;
    int tmp = 0, mul = 1;

    //vec.push_back(0);
    
    do {
        a = getchar();
        if (a != EOF && a != '\n') {
            if (std::isdigit(a)) {
                tmp = (a - '0') + tmp * mul;
                mul *= 10;

            }
            else if (a == ' ' && tmp != 0) {
                mul = 0;
                vec.push_back(tmp);
                tmp = 0;
            }


            else if (a == '+') {
                int b = vec.back();
                vec.pop_back();
                int c = vec.back();
                vec.pop_back();
                vec.push_back(b + c);
            }
            else if (a == '-') {
                int b = vec.back();
                vec.pop_back();
                int c = vec.back();
                vec.pop_back();
                vec.push_back(c - b);
            }
            else if (a == '*') {
                int b = vec.back();
                vec.pop_back();
                int c = vec.back();
                vec.pop_back();
                vec.push_back(b * c);
            }
            //std::cout << vec.back() << "\n";
        }
            
    } while (a != EOF);

    std::cout << vec.back();

    return 0;
}