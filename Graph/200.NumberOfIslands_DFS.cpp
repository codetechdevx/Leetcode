/*
Ankit Anudeep
DFS (Depth-First Search) approach to find the number of islands in a 2D grid.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int r, int c)
    {
        int nr = grid.size();
        int nc = grid[0].size();
        grid[r][c] = '0';

        if(r - 1 >= 0 && grid[r-1][c] == '1')   dfs(grid, r-1, c);  
        if(r + 1 < nr && grid[r+1][c] == '1')   dfs(grid, r+1, c);
        if(c - 1 >= 0 && grid[r][c-1] == '1')   dfs(grid, r, c-1);
        if(c + 1 < nc && grid[r][c+1] == '1')   dfs(grid, r, c+1);
    }

    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0)
            return 0;
        int nr = grid.size();
        int nc = grid[0].size();
        int num_islands = 0;

        for(int i = 0; i < nr; i++)
        {
            for(int j = 0; j < nc; j++)
            {
                if(grid[i][j] == '1')
                {
                    dfs(grid, i, j);
                    num_islands++;
                }
            }
        }

        return num_islands;
    }
};

int main() {
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    Solution sol;
    int result = sol.numIslands(grid);
    cout << "Number of islands: " << result << endl;
}