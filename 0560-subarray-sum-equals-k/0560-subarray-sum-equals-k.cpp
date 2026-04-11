class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count_subarray{0};

        for (int i{ 0 }; i < nums.size(); i++) {
            int sum_number{ 0 };
            for (int j{ i }; j < nums.size(); j++) {
                sum_number += nums[j];
                if (sum_number == k) {
                    count_subarray++;
                }
            }
        }
        return count_subarray;
    }
};