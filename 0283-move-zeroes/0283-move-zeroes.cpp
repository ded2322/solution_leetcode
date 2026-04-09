class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // Сложность O (n), сложность по памяти O(1)
        int slow_index{ 0 };
        for (int fast_index{ 0 }; fast_index < nums.size(); fast_index++) {
            if (nums[fast_index] != 0 && fast_index != slow_index) {
                std::swap(nums[slow_index], nums[fast_index]);
            }
            if (nums[slow_index] != 0) slow_index++;
        }
    }
};