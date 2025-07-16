class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        for(std::size_t index {0}; index < nums.size() - 1; ++index) {
            if( nums[index] == nums[index+1] ) {
                return true;
            }
        }

        return false;
    }
};