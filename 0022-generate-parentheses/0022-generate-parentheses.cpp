class Solution {
public:
    void recursive_backets( std::vector<std::string>& output, std::string current_str,
    int open, int close, int lenght_string) {

    if (current_str.size() == 2 * lenght_string) {
        output.push_back(current_str);
        return;
    }
    
    if (open < lenght_string ) {
        recursive_backets(output, current_str + '(', open + 1 , close, lenght_string);
    }

    if (close < open ) {
        recursive_backets(output, current_str + ')', open, close + 1, lenght_string);
    }
}

std::vector<std::string> generateParenthesis(int n) {

    std::vector<std::string> output{};
    recursive_backets(output,"", 0, 0, n);
    
    return output;
}
};