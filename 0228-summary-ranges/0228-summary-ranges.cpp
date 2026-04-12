class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
    std::vector<std::string> output_data{};

    int low_pointer{ 0 };
    for (int i{ 0 }; i < nums.size(); i++) {

        if (i == nums.size() - 1) {
            if (low_pointer == i)
                output_data.push_back(std::to_string(nums[low_pointer]));
            else 
                output_data.push_back(std::to_string(nums[low_pointer]) + "->" + std::to_string(nums[i]));
        } else if (nums[i + 1] != nums[i] + 1 ) {
            if (low_pointer == i)
                output_data.push_back(std::to_string(nums[low_pointer]));
            else 
                output_data.push_back(std::to_string(nums[low_pointer]) + "->" + std::to_string(nums[i]));
            low_pointer = i + 1;
        }
    }

    return output_data;
    }
};