class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count_subarray{0};
        int prefix{ 0 };
        std::unordered_map<int, int> sum{ {0,1} };
        for (int i{ 0 }; i < nums.size(); i++) {
            prefix += nums[i];
            if (sum.count(prefix - k))
                count_subarray += sum[prefix - k];
            sum[prefix]++;
        }

        return count_subarray;
    }
};