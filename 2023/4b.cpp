/*

Петя и Вася — одноклассники и лучшие друзья, поэтому они во всём помогают друг другу. Завтра у них контрольная по математике, и учитель подготовил целых K вариантов заданий.

В классе стоит один ряд парт, за каждой из них (кроме, возможно, последней) на контрольной будут сидеть ровно два ученика. Ученики знают, 
что варианты будут раздаваться строго по порядку: правый относительно учителя ученик первой парты получит вариант 1, левый — вариант 2, правый ученик второй парты получит вариант 3 (если число вариантов больше двух) и т.д. 
Так как K может быть меньше чем число учеников N, то после варианта K снова выдаётся вариант 1. На последней парте в случае нечётного числа учеников используется только место 1.

Петя самым первым вошёл в класс и сел на своё любимое место. Вася вошёл следом и хочет получить такой же вариант, что и Петя, при этом сидя к нему как можно ближе. 
То есть между ними должно оказаться как можно меньше парт, а при наличии двух таких мест с равным расстоянием от Пети Вася сядет позади Пети, а не перед ним. 
Напишите программу, которая подскажет Васе, какой ряд и какое место (справа или слева от учителя) ему следует выбрать. Если же один и тот же вариант Вася с Петей писать не смогут, то выдайте одно число -1.


*/

#include <iostream>


int main() {
    int stu_number;
    int var_numer;
    int peter_pos_one;
    int peter_pos_two;
    int peter_pos_tot;
    int vasya_pos_one;
    int vasya_pos_two;

    std::cin >> stu_number;
    std::cin >> var_numer;
    std::cin >> peter_pos_one;
    std::cin >> peter_pos_two;

    peter_pos_tot = (peter_pos_one - 1) * 2 + peter_pos_two;

    if (((peter_pos_tot - var_numer) <= 0) && ((peter_pos_tot + var_numer) > stu_number)) {
        std::cout << -1;
        return 0;
    }


    if ((peter_pos_tot - var_numer) <= 0) {
            vasya_pos_one = (peter_pos_tot + var_numer + 1) / 2;
            vasya_pos_two = - (peter_pos_tot + var_numer) % 2 + 2;
            std::cout << vasya_pos_one << " " << vasya_pos_two;
            return 0;
        
    }

    if ((peter_pos_tot + var_numer) > stu_number) {
        vasya_pos_one = (peter_pos_tot - var_numer + 1) / 2;
        vasya_pos_two = -(peter_pos_tot - var_numer) % 2 + 2;
        std::cout << vasya_pos_one << " " << vasya_pos_two;
        return 0;

    }


    if ((peter_pos_one - (peter_pos_tot - var_numer + 1) / 2) >= ((peter_pos_tot + var_numer + 1) / 2 - peter_pos_one)) {
        vasya_pos_one = (peter_pos_tot + var_numer + 1) / 2;
        vasya_pos_two = - (peter_pos_tot + var_numer) % 2 + 2;
        std::cout << vasya_pos_one << " " << vasya_pos_two;
        return 0;

    }

    else {
        vasya_pos_one = (peter_pos_tot - var_numer + 1) / 2;
        vasya_pos_two = - (peter_pos_tot - var_numer) % 2 + 2;
        std::cout << vasya_pos_one << " " << vasya_pos_two;
    }

    

    return 0;
}