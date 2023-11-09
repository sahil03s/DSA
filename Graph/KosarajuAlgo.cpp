#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <unordered_map>
#include <queue>
#include <set>
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
                    cout << x << ", " ;  
                
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

void print(vector<int> &v)
{
    cout << endl << endl;

    for(auto &i : v)
        cout << i << " ";

    cout << endl << endl;
}

void dfs(int node, unordered_map<int, list<int>> &adj, stack<int> &st, vector<bool> &visited)
{
    visited[node] = true;
    
    for(auto &neighbour : adj[node])
    {
        if(!visited[neighbour])
            dfs(neighbour, adj, st, visited);
    }

    st.push(node);
}

void reverseDfs(int node, unordered_map<int, list<int>> &adj, vector<bool> &visited)
{
    visited[node] = true;
    
    for(auto &neighbour : adj[node])
    {
        if(!visited[neighbour])
            reverseDfs(neighbour, adj, visited);
    }

}

//T.C. = O(v+e) S.C. = O(v+e)
int kosarajuAlgo(vector<vector<int>> &edges, int v, int e)
{
    unordered_map<int, list<int>> adj;
    unordered_map<int, list<int>> transpose;
    for(int i=0; i<e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        transpose[v].push_back(u);
    }

    stack<int> st;
    vector<bool> visited(v);

    for(int i=0; i<v; i++)
    {
        if(!visited[i])
            dfs(i, adj, st, visited);
    }

    visited.clear();
    visited.resize(v);
    int count = 0;

    while(!st.empty())
    {
        int top = st.top();
        st.pop();

        if(!visited[top])
        {
            count++;
            reverseDfs(top, transpose, visited);
        }
    }

    return count;

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
    g.bfs(0);
    g.dfs(0);

    cout << "Strongly Connected Components = " << kosarajuAlgo(edges, v, e) << endl;


    return 0;
}

/*
8 13
0 1 1 2 2 0 1 3 3 2 3 4 2 4 5 3 4 5 6 4 5 6 7 5 6 7

0 1
1 2
2 0
1 3
3 2
3 4
2 4
5 3
4 5
6 4
5 6
7 5
6 7
Output :
1

10 14
1 0 0 2 0 3 4 1 3 4 2 5 2 6 7 2 4 7 8 5 9 6 7 9 8 7 9 8

1 0
0 2
0 3
4 1
3 4
2 5
2 6
7 2
4 7
8 5
9 6
7 9
8 7
9 8
Output :
5

*/