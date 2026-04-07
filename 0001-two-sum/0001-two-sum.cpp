class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int> output_value;

        for (int i{ 0 }; i < nums.size(); i++) {
            for (int j{ i+1 }; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    output_value.push_back(i);
                    output_value.push_back(j);
                    return output_value;
                }
            }
        }

        return {};
    }
};