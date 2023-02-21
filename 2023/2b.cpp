/*

Красотой строки назовем максимальное число идущих подряд одинаковых букв. (красота строки abcaabdddettq равна 3)

Сделайте данную вам строку как можно более красивой, если вы можете сделать не более k операций замены символа. 

*/

#include <iostream>
#include <string>
#include <fstream>


int main() {

    int n;
    char c;
    std::string str;
    

    std::ifstream fin("input.txt");

    fin >> n;
    fin >> str;

    int size = str.size();

    int max = n, k = n, max_tmp;

    for (int i = 0; i < 26; ++i) {
        
        c = i + 'a';
        //std::cout << c;
        int left = 0;
        int right = 0;
        k = n;
        max_tmp = 0;
        while (right < size) {        
            while (k >= 0 && right < size) {
                if (str[right] != c && k != 0) {
                    ++right;
                    ++max_tmp;
                    --k;
                }
                else if (str[right] == c) {
                    ++right;
                    ++max_tmp;
                }
                else break;
            }  
            if (max_tmp > max) max = max_tmp;
            ++left;
            --max_tmp;
            if (str[left - 1] != c) ++k;
        }

    }

    if (max <= size) std::cout << max;
    else std::cout << size;




    return 0;

}