/*
*
* Алгоритмическая сложность O(log n)
* Сложность по памяти O(log  n) 
* 
*/

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>


std::string convert_number(int input) {
    if (!input) return "0";

    bool is_negaitve = input < 0;
    input = is_negaitve ? -input : input;

    int size = (int)log10(input) + 1;
    if (is_negaitve) size += 1;
    
    std::string output (size, ' ');

    for (int index {size}; index > 0; --index) {
        int number { input % 10};
        input /=10;

        char char_number = '0' + number;
        output[index-1] = char_number;
    }
    if (is_negaitve) output[0] = '-';
    return output;
}

int main() {
    std::cout << "Number in str: " << convert_number(-123) << "\n";
    // std::string output (3, ' ');
    // std::cout << output[0]; 
}
