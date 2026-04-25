class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    std::map<std::array<int,26>, std::vector<std::string>> group_anagram_map{};

    for (int i{ 0 }; i < strs.size(); i++) {
        std::array<int, 26> k{};
        for ( char& letter : strs[i]) {
            k [letter - 'a'] += 1;
        }
        group_anagram_map[k].push_back(strs[i]);
    }

    std::vector<std::vector<std::string>> output_data{};
    for (auto& key : group_anagram_map) {
        output_data.push_back(key.second);
    }
    return output_data;
    }
};