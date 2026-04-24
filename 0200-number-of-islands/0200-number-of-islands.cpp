class Solution {
public:
    void dfs(std::vector<std::vector<char>>& grid, int row_point, int line_point) {
        if ( row_point >= grid.size() || line_point >= grid[0].size() || grid[row_point][line_point] == '0' ) {
            return;
        }

        grid[row_point][line_point] = '0';
        dfs(grid, row_point, line_point + 1);
        dfs(grid, row_point, line_point - 1);
        dfs(grid, row_point + 1, line_point );
        dfs(grid, row_point - 1, line_point );
    }

    int numIslands(vector<vector<char>>& grid) {
        int count_islands{ 0 };

        int size_line = grid[0].size();
        for (int current_rows{ 0 }; current_rows < grid.size(); current_rows++) {
            for (int current_index_line{ 0 }; current_index_line < grid[0].size(); current_index_line++) {
                if (grid[current_rows][current_index_line] == '1') {
                    count_islands++;
                    dfs(grid, current_rows, current_index_line);
                }
            }
        }
        return count_islands;
    }
};