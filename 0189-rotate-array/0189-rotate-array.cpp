class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // Алгоритмическая сложность O(n)
        // Сложность по памяти O(n)

        int size_arr = std::size(nums);
        k %=  size_arr;

        std::vector<int> void_arr;
        std::size_t current_index = 0;
        for (int index {0}; index < size_arr; ++index) {
            if (k > 0 && (size_arr - k) < size_arr && k < size_arr) {
                void_arr.push_back(nums[size_arr - k]);
                --k;
            } else {
                void_arr.push_back(nums[current_index]);
                ++current_index;
            }
        }
        nums = void_arr; 
    }
};