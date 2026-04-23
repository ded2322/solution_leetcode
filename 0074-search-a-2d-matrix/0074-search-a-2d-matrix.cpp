class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int size_subb_array = matrix[0].size();
        int total_size = size_subb_array * matrix.size();
        int left_row_point{ 0 };
        int right_row_point = total_size - 1;

        while (left_row_point <= right_row_point) {
            int middle = (right_row_point + left_row_point) / 2;

            int row = middle / size_subb_array;
            int postion = middle % (size_subb_array);

            if (matrix[row][postion] == target)
                return true;
            else if (matrix[row][postion] > target)
                right_row_point = middle - 1;
            else if (matrix[row][postion] < target)
                left_row_point = middle + 1;
        }

        return false;
    }
};