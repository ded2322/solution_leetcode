class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int past_index{ 0 };
        int cout_zero{ 0 };
        int max_cout{ 0 };
        for (int first_index{ 0 }; first_index < nums.size(); first_index++) {
            if (nums[first_index] == 0)
                cout_zero++;

            if (cout_zero > k) {
                if (nums[past_index] == 0)
                    cout_zero--;
                past_index++;

            }
            max_cout = std::max(max_cout, (first_index - past_index) + 1);
        }
        return max_cout;
    }
};