#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <unordered_map>
#include <stack>

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
                    cout << x << ",";
                
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

        void solverDFS(int node, vector<bool> &visited)
        {
            cout << node << " ";
            visited[node] = 1;

            for(auto &i : adj[node])
                if(!visited[i])
                    solverDFS(i, visited);
        }


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

void solverDfs(unordered_map<int, list<int>> &adj,unordered_map<int, bool> &visited, stack<int> &s, int node)
{
    visited[node] = true;

    for(auto &child : adj[node])
    {
        if(!visited[child])
            solverDfs(adj, visited, s, child);
    }

    s.push(node);
}

//T.C. = O(v+e)    S.C. = O(v+e)
void topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    // unordered_map<int, list<int>> adj;
    // for(int i=0; i<e; i++)
    //     adj[edges[i][0]].push_back(edges[i][1]);

    // unordered_map<int, bool> visited;
    // stack<int> s;

    // for(auto &i : adj)
    // {
    //     if(!visited[i.first])
    //         solverDfs(adj, visited, s, i.first);
    // }

    // while(!s.empty())
    // {
    //     cout << s.top() << " ";
    //     s.pop();
    // }


//Using BFS ....(Kahn's Algorithm)
//T.C. = O(v+e)    S.C. = O(v+e)

    unordered_map<int, list<int>> adj;
    vector<int> indegree(v+1);
    for(int i=0; i<e; i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        indegree[edges[i][1]]++;
    }

    queue<int> q;
    for(int i=1; i<=v; i++)
    {
        if(!indegree[i])
            q.push(i);
    }

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for(auto &i : adj[node])
        {
            if(--indegree[i] == 0)
                q.push(i);
        }
    }

    cout << endl << endl;
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

    vector<vector<int>> edges(e, vector<int>(2));
    for(int i=0; i<e; i++)
    {
        int u,v;
        cin >> u >> v;
        edges[i][0] = u;
        edges[i][1] = v;
        g.addEdge(u,v,1);
    }

    g.printAdjList();

    cout << endl << endl;

    topologicalSort(edges, v, e);


    cout << endl << endl;


    return 0;
}

/*
6 7
1 2 1 3 2 4 3 4 4 5 4 6 5 6
1 2 
1 3 
2 4 
3 4 
4 5 
4 6 
5 6

5 4
0 1 1 2 3 1 4 0

0 1
1 2
3 1
4 0
*/

/*
9 7
0 1 0 2 0 5 3 6 7 4 4 8 7 8


0 1
0 2
0 5
3 6
7 4
4 8
7 8
*/