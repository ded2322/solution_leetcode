class Solution {
public:
bool isPalindrome(std::string s) {
    // сложность - O (n) По пямяти = O(1)
    s.erase(
        std::remove_if(s.begin(), s.end(), [&](unsigned char c) {
            return !std::isalnum(c);
        }),
        s.end()
    );

    std::transform(s.begin(), s.end(), s.begin(),
        [](unsigned char c) { return std::tolower(c); }
    );

    int end_size = s.size() - 1;
    int start_size{ 0 };
    while (start_size < end_size) {
        if (s[start_size] == s[end_size]) {
            end_size--;
            start_size++;
        }else {
            return false;
        }
    }

    return true;
}
};