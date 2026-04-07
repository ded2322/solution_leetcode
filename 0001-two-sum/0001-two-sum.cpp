class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    std::unordered_map<int, int> value;
    for ( int i{ 0 }; i < nums.size(); i++ ) {
        auto find_value = value.find(target - nums[i]);
        if ( find_value != value.end() ) {
            return { i, find_value->second};
        }
        value[nums[i]] = i;
    }
    return {};
    }
};