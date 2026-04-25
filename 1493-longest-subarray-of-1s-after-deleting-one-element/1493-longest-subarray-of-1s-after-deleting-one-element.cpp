class Solution {
public:
    int longestSubarray(vector<int>& nums) {
            int count{ 0 };
        int past_index{ 0 };
        int count_zero{ 0 };

        for (int first_index{ 0 }; first_index < nums.size(); first_index++) {
            if (nums[first_index] == 0)
                count_zero++;
            if (count_zero > 1) {
                if (nums[past_index] == 0)
                    count_zero--;
                past_index++;
            }
            count = std::max(count, first_index - past_index);
        }
        return count;
    }
};