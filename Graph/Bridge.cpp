#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <unordered_map>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

class graph{
    public :
        unordered_map<int, list<int>> adj;

        void addEdge(int u, int v, bool directed)
        {
            adj[u].push_back(v);
            if(!directed)
                adj[v].push_back(u);
        }

        void printAdjList()
        {
            for(auto &t : adj)
            {
                cout << t.first << " -> " ;
                for(auto &x : t.second)
                    cout << x  << ", ";  
                
                cout << endl;
            }
        }

        //T.C. = O(v+e)    S.C. = O(v+e)
        void solverBFS(int node, vector<bool> &visited)
        {
            queue<int> q;
            q.push(node);
            while(!q.empty())
            {
                int temp = q.front();
                q.pop();

                if(!visited[temp])
                {
                    visited[temp] = 1;
                    cout << temp << " ";
                    for(auto &i : adj[temp])
                        if(!visited[i])
                            q.push(i);
                }
            }
        }
        
        //T.C. = O(v+e)    S.C. = O(v+e)
        void bfs(int node)
        {
            cout << endl << endl;

            vector<bool> visited(adj.size(), 0);
            solverBFS(node, visited);

            for(int i=0; i<adj.size(); i++)
                if(!visited[i])
                    solverBFS(i, visited);


            cout << endl << endl;
        }

        //T.C. = O(v+e)    S.C. = O(v+e)
        void solverDFS(int node, vector<bool> &visited)
        {
            cout << node << " ";
            visited[node] = 1;

            for(auto &i : adj[node])
                if(!visited[i])
                    solverDFS(i, visited);
        }


        //T.C. = O(v+e)    S.C. = O(v+e)
        void dfs(int node)
        {
            cout << endl << endl;

            vector<bool> visited(adj.size(), 0);
            solverDFS(node, visited);
            cout << endl;
            for(int i=0; i<adj.size(); i++)
            {
                if(!visited[i])
                {
                    solverDFS(i, visited);
                    cout << endl;
                }
                
            }

            cout << endl << endl;
        }
};

void print(vector<vector<int>> &v)
{
    cout << endl;
    for(auto &i : v)
    {
        for(auto &j : i)
            cout << j << " ";
        cout << endl;
    }

    cout << endl;
}

void dfs(int node, int parent, int &timer, vector<vector<int>> &ans, unordered_map<int, list<int>> &adj, vector<bool> &visited, vector<int> &discover, vector<int> &low)
{
    visited[node] = true;
    discover[node] = low[node] = timer++;

    for(auto &child : adj[node])
    {
        if(child != parent)
        {
            if(!visited[child])
            {
                dfs(child, node, timer, ans, adj, visited, discover, low);
                low[node] = min(low[node], low[child]);

                if(discover[node] < low[child])
                {
                    ans.push_back({node,child});
                }
            }
            else
            {
                low[node] = min(low[node], discover[child]);
            }
        }
    }
}


vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e)
{
    unordered_map<int, list<int>> adj;
    for(int i=0; i<e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(v);
    vector<int> discover(v, -1);
    vector<int> low(v, -1);
    int timer = 0;
    vector<vector<int>> ans;

    for(int i=0; i<v; i++)
    {
        if(!visited[i])
        {
            dfs(i, -1, timer, ans, adj, visited, discover, low);
        }
    }

    return ans;
}

int main()
{
    graph g;
    int v,e;
    cout << "Enter no. of vertices : ";
    cin >> v;
    cout << "Enter no. of edges : ";
    cin >> e;

    cout << "Enter edges : " << endl;

    vector<vector<int>> edges(e, vector<int>(3));
    for(int i=0; i<e; i++)
    {
        int u,v;
        cin >> u >> v;
        edges[i][0] = u;
        edges[i][1] = v;
        g.addEdge(u,v,0);
    }

    g.printAdjList();
    g.bfs(0);
    g.dfs(0);

    vector<vector<int>> ans;
    ans = findBridges(edges,v,e);
    print(ans);

    return 0;
}

/*
6 7 
1 2 1 0 0 2 0 4 5 4 5 3 3 4

1 2
1 0
0 2
0 4
5 4
5 3
3 4

Output :
0 4

5 4
0 1 3 1 1 2 3 4

0 1
3 1
1 2
3 4

Output :
0 1
1 2    
1 3
3 4
*/