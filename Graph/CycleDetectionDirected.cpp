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

        //int.C. = O(v+e)    S.C. = O(v+e)
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
        
        //int.C. = O(v+e)    S.C. = O(v+e)
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

        //int.C. = O(v+e)    S.C. = O(v+e)
        void solverDFS(int node, vector<bool> &visited)
        {
            cout << node << " ";
            visited[node] = 1;

            for(auto &i : adj[node])
                if(!visited[i])
                    solverDFS(i, visited);
        }


        //int.C. = O(v+e)    S.C. = O(v+e)
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

bool solverDfs(unordered_map<int, list<int>> &adj, unordered_map<int,bool> &visited, unordered_map<int,bool> &dfsVisited, int node)
{
  visited[node] = 1;
  dfsVisited[node] = 1;

  for(auto child : adj[node])
  {
    if(!visited[child])
    {
      bool isCyclic = solverDfs(adj, visited, dfsVisited, child);
      if(isCyclic)
        return true;
    }
    else if(dfsVisited[child])
      return true;
  }

  dfsVisited[node] = 0;
  return false;
}

bool detectCycleInDirectedGraph(vector<vector<int>> &edges, int v, int e) 
{
    
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

    int count = 0;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        
        count++;

        for(auto &i : adj[node])
        {
            if(--indegree[i] == 0)
                q.push(i);
        }
    }

    return (count!=v);
    
    // graph g;
    // for(int i=0; i<e; i++)
    // {
    //     g.addEdge(edges[i][0], edges[i][1], 1);
    // }

    // unordered_map<int,bool> visited;
    // unordered_map<int,bool> dfsVisited;

    // for(auto &i : g.adj)
    // {
    //   if(!visited[i.first])
    //   {
    //     bool isCyclic = solverDfs(g.adj, visited, dfsVisited, i.first);
    //     if(isCyclic)
    //       return true;
    //   }
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
        g.addEdge(u,v,1);
    }

    g.printAdjList();

    bool isCyclic = detectCycleInDirectedGraph(edges, v, e);
    cout << (isCyclic?"Cyclic":"Acyclic") << endl;


    return 0;
}

/*
8 9
1 2 2 3 3 7 3 8 8 7 2 4 4 5 5 6 6 4

1 2
2 3
3 7
3 8
8 7
2 4
4 5
5 6
6 4

*/