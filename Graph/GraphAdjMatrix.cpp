#include <iostream>
#include <vector>

using namespace std;

class graph{
    public :
    vector<vector<int>> adj;
    graph(int n)
    {
        adj.resize(n, vector<int>(n));
    }

    void addEdge(int u, int v, bool directed)
    {
        adj[u][v] = 1;
        if(!directed)
            adj[v][u] = 1;
    }

    void printAdjMatrix()
    {
        cout << endl << endl;
        for(auto &v : adj)
        {
            for(auto &x : v)
                cout << x << " ";
            cout << endl;
        }

        cout << endl << endl;
    }
};

int main()
{
    int v,e;
    cout << "Enter no. of nodes/vertices : ";
    cin >> v;
    cout << "Enter no. of edges : ";
    cin >> e;
    graph g(v);

    cout << "Enter edges : " << endl;

    for(int i=0; i<e; i++)
    {
        int u,v;
        cin >> u >> v;
        g.addEdge(u,v,0);
    }

    g.printAdjMatrix();

    return 0;
}

/*
5 6

0 1 1 2 2 3 3 1 3 4 4 0
*/