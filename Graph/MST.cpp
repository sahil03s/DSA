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
        unordered_map<int, list<pair<int, int>>> adj;

        void addEdge(int u, int v, int w, bool directed)
        {
            adj[u].push_back({v,w});
            if(!directed)
                adj[v].push_back({u,w});
        }

        void printAdjList()
        {
            for(auto &t : adj)
            {
                cout << t.first << " -> " ;
                for(auto &x : t.second)
                    cout << "[" << x.first << "," << x.second << "] , ";  
                
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
                        if(!visited[i.first])
                            q.push(i.first);
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
                if(!visited[i.first])
                    solverDFS(i.first, visited);
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
    cout << endl;
    int sum = 0;
    for(auto &i : v)
    {
        cout << i << " ";
        sum += i;
    }

    cout << endl;
    cout << "MIN COST = " << sum << endl;
}

//T.C. = O(v^2)    S.C. = O(v+e)
vector<int> prim(vector<vector<int>> edges, int v, int e, int source)
{
    // unordered_map<int, list<pair<int,int>>> adj;
    // for(int i=0; i<e; i++)
    // {
    //     int u = edges[i][0];
    //     int v = edges[i][1];
    //     int w = edges[i][2];

    //     adj[u].push_back({v,w});
    //     adj[v].push_back({u,w});
    // }

    // vector<int> key(v, INT_MAX);
    // vector<int> parent(v, -1);
    // vector<bool> mst(v, false);

    // key[source] = 0;

    // for(int count=0; count < v; count++)
    // {
    //     int mini = INT_MAX;
    //     int u = -1;

    //     for(int i=0; i<v; i++)
    //     {
    //         if(!mst[i] && key[i] < mini)
    //         {
    //             mini = key[i];
    //             u = i;
    //         }
    //     }

    //     mst[u] = true;

    //     for(auto &k : adj[u])
    //     {
    //         int v = k.first;
    //         int w = k.second;
    //         if(!mst[v] && w < key[v])
    //         {
    //             key[v] = w;        
    //             parent[k.first] = u;
    //         }
    //     }
    // }

    // for(int i=0; i<v; i++)
    //     cout << i << " -> " << parent[i] << endl;

    // return key;

//T.C. = O(vlog(v))    S.C. = O(v+e)
    unordered_map<int, list<pair<int,int>>> adj;
    for(int i=0; i<e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vector<int> key(v, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> parent(v, -1);
    vector<bool> mst(v, false);

    key[source] = 0;
    pq.push({key[source], source});

    while(!pq.empty())
    {
        auto [_,u] = pq.top();
        pq.pop();

        mst[u] = true;

        for(auto &k : adj[u])
        {
            int v = k.first;
            int w = k.second;
            if(!mst[v] && w < key[v])
            {
                key[v] = w;        
                pq.push({w,v});
                parent[k.first] = u;
            }
        }
    }

    for(int i=0; i<v; i++)
        cout << i << " -> " << parent[i] << endl;

    return key;

}

//T.C. = O(1)    S.C. = O(1)
int findParent(vector<int> &parent, int node)
{
    if(parent[node] == node)
        return node;
    
    return parent[node] = findParent(parent, parent[node]);
}

//T.C. = O(1)    S.C. = O(1)
void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findParent(parent, u);
    v = findParent(parent, v);

    if(rank[u] == rank[v])
    {
        parent[v] = u;
        rank[u]++;
    }
    else if(rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else
        parent[v] = u;
}

//T.C. = O(1)    S.C. = O(1)
bool sortcol(const vector<int>& v1, const vector<int>& v2)
{
    return v1[2] < v2[2];
}


//T.C. = O(elog(e))    S.C. = O(v)
int kruskal(vector<vector<int>>& edges, int v)
{
    vector<int> parent(v);
    vector<int> rank(v);

    //makeSet
    for(int i=0; i<v; i++)
        parent[i] = i;

    //sorting based on weights in non-decreasing order
    sort(edges.begin(), edges.end(), sortcol);
    
    int cost = 0;
    for(int i=0; i<edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        if(findParent(parent, u) != findParent(parent, v))
        {
            unionSet(u,v,parent, rank);
            cost += w;
        }
    }

    return cost;
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
        int u,v,w;
        cin >> u >> v >> w;
        edges[i][0] = u;
        edges[i][1] = v;
        edges[i][2] = w;
        g.addEdge(u,v,w,0);
    }

    g.printAdjList();
    g.bfs(0);
    g.dfs(0);

    vector<int> key;
    key = prim(edges, v, e, 0);
    print(key);
    
    int cost = kruskal(edges, v);
    cout << "Cost = " << cost << endl;

    return 0;
}

/*
9 14
0 1 4 0 7 8 1 7 11 1 2 8 8 2 2 8 6 6 6 7 1 8 7 7 6 5 2 2 5 4 3 2 7 3 5 14 4 3 9 5 4 10

0 1 4
0 7 8
1 7 11
1 2 8
8 2 2
8 6 6
6 7 1 
8 7 7
6 5 2
2 5 4
3 2 7
3 5 14
4 3 9
5 4 10

Output : Cost = 37


8 12
0 1 12 0 5 4 1 2 20 1 3 5 1 4 7 2 7 19 3 7 18 3 4 2 4 7 15 6 7 13 4 5 10 5 6 8

0 1 12
0 5 4
1 2 20
1 3 5
1 4 7
2 7 19
3 7 18
3 4 2
4 7 15
6 7 13
4 5 10
5 6 8

*/
