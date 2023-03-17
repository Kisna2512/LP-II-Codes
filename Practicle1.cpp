#include <bits/stdc++.h>

using namespace std;

void bfs(int start, vector<int> adj[], int n)
{

    vector<int> vis(n + 1, 0);

    queue<int> q;
    q.push(start);
    vis[start] = 1;

    while (!q.empty())
    {
        int top = q.front();
        q.pop();
        cout << top << " ";
        for (auto it : adj[top])
        {
            if (vis[it] == 0)
            {
                q.push(it);
                vis[it] = 1;
            }
        }
    }

    return;
}

void dfs(int start, vector<int> adj[], int n, vector<int> &vis)
{
    vis[start] = 1;
    cout << start << " ";
    for (auto it : adj[start])
    {
        if (vis[it] == 0)
        {
            vis[it] = 1;
            dfs(it, adj, n, vis);
        }
    }

    return;
}

int main()
{
    int n;
    int edges;
    cout << "Enter the no of vertices: " << endl;
    cin >> n;
    vector<int> adj[n + 1];
    cout << "Enter no of edges" << endl;
    cin >> edges;
    for (int i = 0; i < edges; i++)
    {

        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int choice;
    vector<int> vis(n + 1, 0);
    do
    {

        cout << "\nEnter Your Choice: 1.BFS\t2.DFS" << endl;
        cin >> choice;
        int start;
        switch (choice)
        {
        case 1:

            cout << "\nEnter Start node: " << endl;
            cin >> start;

            bfs(start, adj, n);
            break;
        case 2:

            cout << "\nEnter Start node: " << endl;
            cin >> start;

            dfs(start, adj, n, vis);
            break;
        case 3:
            break;
        }
    } while (choice <= 2);

    return 0;
}