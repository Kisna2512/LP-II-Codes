#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> pathFinder(int n, int m, vector<vector<int>> &graph)
{
    vector<vector<int>> vis(n, vector<int>(m, 0));
    queue<pair<int, int>> q;
    q.push({0, 0});
    vis[0][0] = 1;
    int dx[] = {-1, -1, 0, +1, +1, +1, 0, -1, -1};

    int dy[] = {0, +1, +1, +1, 0, -1, -1, -1, 0};

    vector<pair<int, int>> ans;
    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        if (row == n - 1 && col == m - 1)
        {
            break;
        }

        ans.push_back({row, col});
        for (int i = 0; i < 8; i++)
        {
            int nrow = row + dx[i];
            int ncol = col + dy[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && graph[nrow][ncol] == 1)
            {
                q.push({nrow, ncol});
                vis[nrow][ncol] = 1;
            }
        }
    }

    return ans;
}

int main()
{
    int n, m;
    cout << "Enter no of rows and columns: ";
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>(m, 0));
    cout << "Enter your matrix: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> graph[i][j];
        }
    }

    vector<pair<int, int>> ans = pathFinder(n, m, graph);
    cout << "Your Path is from intial to final position: " << endl;
    for (auto it : ans)
    {
        cout << "(" << it.first << "," << it.second << ")"
             << "->";
    }

    cout << "(" << n - 1 << "," << m - 1 << ")" << endl;
    cout << "\nThe distence is: " << ans.size() << endl;
    return 0;
}