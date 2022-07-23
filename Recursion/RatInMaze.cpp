#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Rat In a maze

/*
Input Matrx/path:
            {1,0,0,0}
            {1,1,0,1}
            {1,1,0,0}
            {0,1,1,1}

Output: [DDRDRR] [DRDDRR]
*/
//TC: O(4 ^ (m*n)
//SC: O(m*n)        [for visited array]
//AX: O(m*n)        [recursive space]
void solve(int i, int j, vector<vector<int>>& m, int n, vector<string>& ans, vector<vector<int>>& vis, string path)
{
    if(i == n-1 && j == n-1)
    {
        ans.push_back(path);
        return;
    }

    //DLRU
    //Down
    if(i+1 < n && !vis[i+1][j] && m[i+1][j] == 1)
    {
        vis[i][j] = 1;
        solve(i+1, j, m, n, ans, vis, path+'D');
        vis[i][j] = 0;
    }

    //Left
    if(j-1 >=0 < n && !vis[i][j-1] && m[i][j-1] == 1)
    {
        vis[i][j] = 1;
        solve(i, j-1, m, n, ans, vis, path+'L');
        vis[i][j] = 0;
    }

    //Right
    if(j+1 < n && !vis[i][j+1] && m[i][j+1] == 1)
    {
        vis[i][j] = 1;
        solve(i, j+1, m, n, ans, vis, path+'R');
        vis[i][j] = 0;
    }

    //Upper
    if(i-1 >=0 && !vis[i-1][j] && m[i-1][j] == 1)
    {
        vis[i][j] = 1;
        solve(i-1, j, m, n, ans, vis, path+'U');
        vis[i][j] = 0;
    }
}

void solveOptimized(int i, int j, vector<vector<int>>& m, int n, vector<string>& ans, vector<vector<int>>& vis, string path, vector<int> di, vector<int> dj)
{
    if(i == n-1 && j == n-1)
    {
        ans.push_back(path);
        return;
    }

    string dir = "DLRU";
    for(int index = 0; index < 4; index++)
    {
        int nexti = i+di[index];
        int nextj = j+dj[index];

        if(nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !vis[nexti][nextj] && m[nexti][nextj] == 1)
        {
            vis[i][j] = 1;
            solve(nexti, nextj, m, n, ans, vis, path+dir[index]);
            vis[i][j] = 0;
        }
    }
}


vector<string> findPath(vector<vector<int>>& m, int n)
{
    vector<string> ans;
    vector<vector<int>> vis(n, vector<int>(n, 0));

    vector<int> di = {1, 0, 0 , -1};
    vector<int> dj = {0, -1, 1 , 0};

    if(m[0][0] == 1)
    {
        //solve(0, 0, m, n, ans, vis, "");
        solve(0, 0, m, n, ans, vis, "");
    }

    return ans;
}

int main()
{
    int n = 4;

    vector<vector<int>> m = {{1,0,0,0},
                             {1,1,0,1},
                             {1,1,0,0},
                             {0,1,1,1}};

    vector<string> result = findPath(m, n);
    for (int i = 0; i < result.size(); i++)
        cout << "["<< result[i] << "] ";

    cout << endl;

    return 0;
}
