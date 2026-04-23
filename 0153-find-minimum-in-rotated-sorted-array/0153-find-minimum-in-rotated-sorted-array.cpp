class Solution {
public:
    int findMin(vector<int>& nums) {
        int left_point{ 0 };
        int right_point = nums.size() - 1;

        int output = nums[0];

        while (left_point <= right_point) {
            int middle_point = (right_point + left_point) / 2;

            if (nums[middle_point] > nums[right_point])
                left_point = middle_point + 1;
            else
                right_point = middle_point - 1;

            output = std::min(output, nums[middle_point]);
        }

        return output;
    }
};