class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        // https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
        // Алгортмическая сложность О(n)
        // Сложность по памяти O(n)
        std::vector<int> result {arr[0]};
        for (std::size_t index{0}; index < std::size(arr); ++index) {
            if (result[std::size(result)-1] != arr[index]) {
                result.push_back(arr[index]);
            }
        }
        arr = result;
        return std::size(result);
    }
};