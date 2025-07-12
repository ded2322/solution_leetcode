#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>


std::string convert_number(int&& input) {
    if (!input) return "0";

    int number;
    std::string output {""};
    int size = (int)log10(input);

    for (int index {0}; size >= index; ++index) {
        number = input % 10;
        input /=10;

        char char_number = '0' + number;
        output += char_number;
    }

    std::reverse(output.begin(), output.end());

    return output;
}

int main() {

    std::cout << "Number in str: " << convert_number(123) << "\n";
}
