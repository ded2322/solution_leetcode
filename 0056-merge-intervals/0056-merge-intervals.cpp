class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end());

        std::vector<std::vector<int>> output{ intervals[0]};
        for (int i{ 1 }; i < intervals.size(); i++) {
            auto& past_array = output[output.size() - 1];

            if (past_array[1] >= intervals[i][0])
                past_array[1] = std::max(past_array[1], intervals[i][1]);
            else
                output.push_back({ intervals[i]});
        }
        return output;
    }
};