#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <unordered_map>
#include <queue>
#include <set>

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

class Greater
{
    public :
    bool operator()(pair<int, int> &p, pair<int, int> &q)
    {
        return (p.second > q.second);
    }
};

//T.C. = O(elog(v))    S.C. = O(v+e)
vector<int> dijkstra(vector<vector<int>> &edges, int v, int e, int source) 
{
    unordered_map<int, list<pair<int,int>>> adj;
    for(int i=0; i<e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }


    vector<int> distance(v, INT_MAX);
    distance[source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, Greater> pq;
    pq.push({source,0});

    while(!pq.empty())
    {
        pair<int, int> temp = pq.top();
        pq.pop();

        for(auto &i : adj[temp.first])
        {
            int dist = temp.second + i.second;
            if(dist < distance[i.first])
            {
                distance[i.first] = dist;
                pq.push({i.first,dist});
            }
        }
    }

    return distance;

    // unordered_map<int, list<pair<int,int>>> adj;
    // for(int i=0; i<e; i++)
    // {
    //     int u = edges[i][0];
    //     int v = edges[i][1];
    //     int w = edges[i][2];

    //     adj[u].push_back({v,w});
    //     adj[v].push_back({u,w});
    // }

    // set<pair<int, int>> st;

    // vector<int> distance(v, INT_MAX);
    // distance[source] = 0;
    // st.insert({0,source});

    // while(!st.empty())
    // {
    //     pair<int, int> temp = *(st.begin());
    //     st.erase(st.begin());

    //     for(auto &i : adj[temp.second])
    //     {
    //         int dist = temp.first + i.second;
    //         if(dist < distance[i.first])
    //         {
    //             auto record = st.find({distance[i.first], i.first});
    //             if(record != st.end())
    //                 st.erase(record);
                    
    //             distance[i.first] = dist;
    //             st.insert({dist, i.first});
    //         }
    //     }
    // }

    // return distance;
}

void print(vector<int> &v)
{
    cout << endl << endl;

    for(auto &i : v)
        cout << i << " ";

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

    vector<int> dijk = dijkstra(edges, v, e, 0);
    print(dijk);

    return 0;
}

/*
5 7
0 1 7 0 2 1 0 3 2 1 2 3 1 3 5 1 4 1 3 4 7

0 1 7
0 2 1
0 3 2
1 2 3
1 3 5 
1 4 1
3 4 7
Output :
0 4 1 2 5


4 5
0 1 5 0 2 8 1 2 9 1 3 2 2 3 6

0 1 5
0 2 8
1 2 9
1 3 2
2 3 6
Output :
0 5 8 7
*/