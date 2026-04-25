class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        std::array<int, 26> count_s1{};
        for (char c : s1)
            count_s1[c - 'a']++;

        std::array<int, 26> cout_input{};
        int past_index{ 0 };
        for (int first_index{ 0 }; first_index < s2.size(); first_index++) {
            if ((first_index - past_index) > s1.size() - 1) {
                cout_input[s2[past_index] - 'a']--;
                past_index++;
            }
            cout_input[s2[first_index] - 'a']++;

            if (count_s1 == cout_input)
                return true;
        }

        return false;
    }
};