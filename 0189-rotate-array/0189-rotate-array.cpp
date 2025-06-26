class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // Алгоритмическая сложность O(n)
        // Сложность по памяти O(1)
        k %= std::size(nums);
        std::reverse( nums.begin(), nums.end() );
        std::reverse( nums.begin(), nums.begin() +  k  );
        std::reverse( nums.begin() + k, nums.end() );
    }
};