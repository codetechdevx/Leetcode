/*
BFS (Breadth-First Search) approach to find the number of islands in a 2D grid.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0)
            return 0;
        int nr = grid.size();
        int nc = grid[0].size();

        int num = 0;
        for(int i = 0; i < nr; i++)
        {
            for(int j = 0; j < nc; j++)
            {
                if(grid[i][j] == '1')
                {
                    num++;
                    grid[i][j] = '0';
                    queue<pair<int, int>> q;
                    q.push({i, j});

                    while(!q.empty())
                    {
                        auto current = q.front();
                        q.pop();
                        int row = current.first;
                        int col = current.second;

                        if(row-1 >= 0 && grid[row-1][col] == '1')
                        {
                            q.push({row-1, col});
                            grid[row-1][col] = '0';
                        }
                        if(row+1 < nr && grid[row+1][col] == '1')
                        {
                            q.push({row+1, col});
                            grid[row+1][col] = '0';
                        }
                        if(col-1 >= 0 && grid[row][col-1] == '1')
                        {
                            q.push({row, col-1});
                            grid[row][col-1] = '0';
                        }
                        if(col+1 < nc && grid[row][col+1] == '1')
                        {
                            q.push({row, col+1});
                            grid[row][col+1] = '0';
                        }
                    }
                }
            }   
        }

        return num;
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
    return 0;
}

