#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <unordered_map>

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

bool isCyclicBfs(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, int node)
{
    unordered_map<int, int> parent;
    queue<int> q;
    q.push(node);
    visited[node] = 1;
    parent[node] = -1;

    while(!q.empty())
    {
        int temp = q.front();
        q.pop();

        for(auto &i : adj[temp])
        {
            if(visited[i] && i != parent[temp])
                return true;
            else if(!visited[i])
            {
                visited[i] = 1;
                parent[i] = temp;
                q.push(i);
            }
        }
    }
    return false;
}

bool isCyclicDfs(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, int node, int &parent)
{
    visited[node] = 1;

    for(auto &i : adj[node])
    {
        if(visited[i] && parent != i)
            return true;
        else if(!visited[i])
        {
            bool flag = isCyclicDfs(adj, visited, i, node);
            if(flag)
                return true;
        }
    }

    return false;
}


//Using dfs
//T.C. = O(v+e)    S.C. = O(v+e)
bool isCyclicGraph(vector<vector<int>> &edges, int v, int e)
{
    graph g;

    //making adjacency list
    for(int i=0; i<e; i++)
        g.addEdge(edges[i][0], edges[i][1], 0);

    unordered_map<int, bool> visited;

    for(auto &i : g.adj)
    {
        if(!visited[i.first])
        {
            int parent = -1; 
            bool flag = isCyclicDfs(g.adj, visited, i.first, parent);
            if(flag)
                return true;
        }
    }

    return false;

//Using bfs
//T.C. = O(v+e)    S.C. = O(v+e)
    // graph g;

    // //making adjacency list
    // for(int i=0; i<e; i++)
    //     g.addEdge(edges[i][0], edges[i][1], 0);

    // unordered_map<int, bool> visited;

    // for(auto &i : g.adj)
    // {
    //     if(!visited[i.first])
    //     {
    //         bool flag = isCyclicBfs(g.adj, visited, i.first);
    //         if(flag)
    //             return true;
    //     }
    // }

    // return false;

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
        g.addEdge(u,v,0);
    }

    g.printAdjList();

    bool isCyclic = isCyclicGraph(edges, v, e);
    cout << (isCyclic?"Cyclic":"Acyclic") << endl;

    return 0;
}

/*
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