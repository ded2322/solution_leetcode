class Solution {
public:
    std::vector<int> findAnagrams(std::string string, std::string sub_string) {
        //Input: s = "cbaebabacd", p = "abc"
        //Output : [0, 6]
        std::array<int, 26> array_s{};

        for (char letter : sub_string)
            array_s[letter - 'a']++;

        std::vector<int> output_array{};
        std::array<int, 26> input_array{};

        int past_index{ 0 };
        for (int first_index{ 0 }; first_index < string.size(); first_index++) {

            if ((first_index - past_index) > sub_string.size() -1) {
                input_array[string[past_index] - 'a']--;
                past_index++;
            }

            input_array[string[first_index] - 'a']++;
            if (input_array == array_s)
                output_array.push_back(past_index);
        }
        return output_array;
    }
};