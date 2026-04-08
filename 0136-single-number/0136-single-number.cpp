class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // Сложность O(n) сложность по пямяти O(1)
        int output{ 0 };
        for (int a{ 0 }; a < nums.size(); a++) {
            output ^= nums[a];
        }

        return output;
    }
};