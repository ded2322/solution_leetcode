class Solution {
public:
    int maxArea(vector<int>& height) {
        // S = a * b
        int max_area{ 0 };

        int left_point{ 0 };
        int right_point = height.size() - 1;
        while (left_point < right_point) {
            int current_area = std::min(height[left_point], height[right_point]) * (right_point - left_point);
            if (current_area > max_area)
                max_area = current_area;

            if (height[left_point] > height[right_point])
                --right_point;
            else
                ++left_point;
        }
        return max_area;
    }
};