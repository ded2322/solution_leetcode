class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left_position{ 0 };
        int right_position = nums.size();

        while (left_position < right_position) {
            int middile_position = (left_position + right_position) / 2;

            if (nums[middile_position] < target)
                left_position++;
            else if (nums[middile_position] > target)
                right_position--;
            else if (nums[middile_position] == target)
                return middile_position;
        }
        return -1;
    }
};