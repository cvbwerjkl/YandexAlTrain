/*

Отсортируйте данный массив. Используйте пирамидальную сортировку. 
*/

#include <iostream>
#include <vector>
#include <string>
//#include <queue>

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;

}

int main() {

    std::vector<int> vec;
    //std::priority_queue<int> pq;

    int a, index = 0;

    std::cin >> a;


    // insert
    for (int i = 0; i < a; ++i) {
        
        int c;
        std::cin >> c;
        vec.push_back(c);
        //pq.push(c);
        int inner_index = index + 1;
        while (inner_index != 1) {
            int upper_index = inner_index;
            inner_index /= 2;
            if (vec[inner_index - 1] > vec[upper_index - 1]) {
                swap(&vec[upper_index - 1], &vec[inner_index - 1]);
            }
            else {
                break;
            }
            //std::cout << "check";
        }

        ++index;
        /*
        for (int j = 0; j < vec.size(); ++j) {
            std::cout << vec[j] << " ";
        }
        std::cout << "\n";
        */

    }

    //erase

    for (int i = 0; i < a; ++i) {
        
        std::cout << vec[0] << " ";

        //if (pq.top() != vec[0]) std::cout << "\nerror!!!!   " << pq.top() << "\n";
        //pq.pop();

        vec[0] = vec[index - 1];
            
        vec.pop_back();
        --index;
        int inner_index = 1;
        while (inner_index != index) {
            int p = inner_index;
            int upper_index = 2 * inner_index;
            for (int i = 0; i <= 1; i++) {
                if ((upper_index + i) <= index) {
                    if (vec[inner_index - 1] > vec[upper_index - 1 + i]) {
                        inner_index = upper_index + i;
                        // std::cout << "inner" << inner_index << "\n";
                    }

                }
            }

            if (inner_index != p) {
                swap(&vec[p - 1], &vec[inner_index - 1]);
            }
            else break;

        }

    }

    /*
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";
    */



    return 0;
}