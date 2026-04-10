class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
            std::vector<std::vector<std::string>> output_data;

    std::vector <std::string> strs1 = strs;

    std::unordered_map<std::string, std::vector<std::string>> group_anagram_map{};

    for (int i{ 0 }; i < strs1.size(); i++) {
        std::sort(strs1[i].begin(), strs1[i].end());
        group_anagram_map[strs1[i]] = {};
    }

    for (int i{ 0 }; i < strs1.size(); i++) {
        if (group_anagram_map.find(strs1[i]) != group_anagram_map.end())
            group_anagram_map[strs1[i]].push_back(strs[i]);
    }

    for ( auto& [key, value] : group_anagram_map) {
        output_data.push_back(value);
    }
    return output_data;
    }
};