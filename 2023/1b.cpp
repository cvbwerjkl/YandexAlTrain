/*


Вовочка ломает систему безопасности Пентагона. Для этого ему понадобилось узнать, какие символы в секретных зашифрованных посланиях употребляются чаще других. 
Для удобства изучения Вовочка хочет получить графическое представление встречаемости символов. Поэтому он хочет построить гистограмму количества символов в сообщении. 
Гистограмма — это график, в котором каждому символу, встречающемуся в сообщении хотя бы один раз, соответствует столбик, высота которого пропорциональна количеству этих символов в сообщении. 


*/

#include <iostream>
#include <map>


int main() {
    char a;
    int max = 0;
    //std::cin >> a;
    std::map<char, int> freq;

    do {
        a = getchar();
        //std::cout << a;
        if (a != 32 && a != '\n' && a != EOF) {
            ++freq[a];
            if (freq[a] > max) max = freq[a];
        }
        
    } while (a != EOF);


    for (int k = max; k > 0; --k) {
        for (const auto& [word, f] : freq) {
            if (f >= k) std::cout << "#";
            else std::cout << " ";
        }
        std::cout << "\n";
        
    }
    for (const auto& [word, f] : freq) {
        std::cout << word;
    }

    return 0;

}