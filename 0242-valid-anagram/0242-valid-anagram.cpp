class Solution {
public:
    bool isAnagram(string s, string t) {
        // O (n)
        std::array<int, 26> anagram_letter{};
        for (char letter : s) {
            anagram_letter[letter - 'a'] += 1;
        }
        for (char letter : t) {
            anagram_letter[letter - 'a'] -= 1;
        }
        for ( int a : anagram_letter) {
            if (a != 0) return false;
        }
        return true;
    }
};