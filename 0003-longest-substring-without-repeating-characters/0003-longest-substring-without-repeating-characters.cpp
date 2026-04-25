class Solution {
public:
int lengthOfLongestSubstring(std::string s) {
    if(s.size() < 0) return 0;

    int current_subarray{ 0 };
    int max_subarray{ 0 };
    std::unordered_map<char, int> map_letter{};
    int past_index{ 0 };
    for (int first_index{ 0 }; first_index < s.length(); ++first_index) {
        auto letter_map = map_letter.find(s[first_index]);
        if ( letter_map  == map_letter.end() ) {

            map_letter[s[first_index]] = first_index;
            current_subarray = (first_index - past_index) + 1;
            max_subarray = std::max(max_subarray, current_subarray);

        } else {

            past_index = std::max(past_index, letter_map->second + 1);
            map_letter[s[first_index]] = first_index;
            current_subarray = (first_index - past_index) + 1;
            max_subarray = std::max(max_subarray, current_subarray);

        }
    }

    return std::max(max_subarray, current_subarray);
}
};