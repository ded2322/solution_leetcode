class Solution {
public:
    bool isValid(string s) {
        std::vector<char> close_array{};

        for (char& symbol : s) {
            if (symbol == '(' || symbol == '[' || symbol == '{') {
                close_array.push_back(symbol);
            }
            else {
                if (close_array.empty()) return false;
                auto open_backet = close_array.back();
                if (symbol == ')' && open_backet != '(')
                    return false;
                else if (symbol == ']' && open_backet != '[')
                    return false;
                else if (symbol == '}' && open_backet != '{')
                    return false;

                close_array.pop_back();
            }

        }
        return close_array.empty();  
    }
};