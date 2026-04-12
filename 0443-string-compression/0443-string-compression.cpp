class Solution {
public:
    int compress(vector<char>& chars) {
         // По сложности O (n), сложность по памяти O (1), потому что low_pointer, write_pointer заранее выделенные переменные 
    int low_pointer{ 0 };
    int write_pointer{ 0 };
    for (int i{ 0 }; i < chars.size(); ++i) {
        if (i == chars.size() - 1 || (chars[i] != chars[i + 1])) {
            int delta = (i - low_pointer) + 1;
            if (delta > 1 && delta <= 9) {
                chars[++write_pointer] = delta + '0';
                if (i != chars.size() - 1) chars[++write_pointer] = chars[i + 1];
            } else if (delta > 9) {
                std::string delta_string = std::to_string(delta);
                for (char number: delta_string) {
                    chars[++write_pointer] = static_cast<char>(number);
                }
                if (i != chars.size() - 1) chars[++write_pointer] = chars[i + 1];
            }
            else if (delta == 1) {
                if (i != chars.size() - 1) chars[++write_pointer] = chars[i + 1];
            }
            low_pointer = i + 1;
        }
    }

    return write_pointer + 1;
    }
};