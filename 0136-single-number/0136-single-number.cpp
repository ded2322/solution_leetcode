class Solution {
public:
    int singleNumber(vector<int>& nums) {
    // O(n) - O(k) 
    int output_nums{ 0 };
    std::unordered_map<int, int> cout_input;
    for (int num : nums) {
        if (cout_input.find(num) == cout_input.end())
            cout_input[num] = 1;
        else cout_input[num] += 1;
    }

    for (auto& [value, count] : cout_input) {
        if (count == 1) return value;
    }
    return 0;
    }
};