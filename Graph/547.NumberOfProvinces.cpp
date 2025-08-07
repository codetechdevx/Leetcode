/*
Leetcode 547. Number of Provinces
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<vector<int>>& isConnected, vector<bool>& visited)
    {
        visited[node] = true;
        for(int i = 0; i < isConnected.size(); i++)
        {
            if(isConnected[node][i] && !visited[i])
            {
                dfs(i, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int N = isConnected.size();
        if(N == 0)
            return 0;
        int num = 0;
        vector<bool> visited(N, false);
        for(int i = 0; i < N; i++)
        {
            if(!visited[i])
            {
                num++;
                dfs(i, isConnected, visited);
            }
        } 

        return num;
    }
};

int main()
{
    vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };
    Solution sol;
    int result = sol.findCircleNum(isConnected);
    cout << "Number of provinces: " << result << endl; // Output: 2
    return 0;
}