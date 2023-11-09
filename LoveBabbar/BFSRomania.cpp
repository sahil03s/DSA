/*
Implemented by :
1. Prashant Kumar Aryan (2105982)   
2. Sahil SIngh (21052481)

Selected Algorithm : BFS

*/

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm> 
#include <stdlib.h> 

using namespace std;

class node
{
    public:
    int nodeId;
    string currentCity;
    int priorityValue;

    node(int x, string y, int z)
    {
        nodeId = x;
        currentCity = y;
        priorityValue = z;
    }
};

class Compare{
    public :
    bool operator()(node a, node b)
    {
        if(a.priorityValue > b.priorityValue)
            return true;
        else
            return false;
    }
};

void print(map<string,pair<string, int>> &reached, priority_queue<node, vector<node>, Compare> frontier)
{
    map<string,pair<string, int>>::iterator itr = reached.begin();
    while(!frontier.empty() || itr != reached.end())
    {
        if(itr != reached.end())
        {
            string str =  itr->first + "(" + itr->second.first + ") " + to_string(itr->second.second);
            str.resize(35,' ');
            cout << str ;
        }
        if(!frontier.empty())
        {
            node temp = frontier.top();
            frontier.pop();
            cout << "\t\t#" << temp.nodeId << " " << temp.currentCity << " " << temp.priorityValue ;
        }
        cout << endl;

        itr++;
    }
}

bool BFSonRomania(map<string, vector<string>> city, map<string,pair<string, int>> &reached, priority_queue<node, vector<node>, Compare> &frontier, string initial, string dest)
{
    reached[initial] = {"", 0};
    frontier.push({0,initial, 0});
    int id = 0;

    node t = frontier.top();
    cout << "\n\n";
    string str = "Reached";
    str.resize(48, ' ');
    cout << str ;
    cout << "Priority Queue" << endl; 
    str = initial + " () " + to_string(reached[initial].second) ;
    str.resize(48, ' ');
    cout << str ;
    cout << "#" << t.nodeId << " " << t.currentCity << " " << t.priorityValue << endl; 


    while(!frontier.empty())
    {
        node n = frontier.top();
        frontier.pop();

        cout << "----------------------------------------------------------------------------------------------------" << endl;
        cout << "\nProcessing #";
        cout << n.nodeId << " " << n.currentCity << " " << n.priorityValue << endl << endl;

        if(n.currentCity == dest)
            return true;


        for(auto itr = city[n.currentCity].begin(); itr != city[n.currentCity].end(); itr++)  
        {
            int cost = reached[n.currentCity].second - 1;
            if(reached.find(*itr) == reached.end() || cost > reached[*itr].second)
            {
                reached[*itr] = {n.currentCity, cost};
                frontier.push({++id, *itr, cost});
            }
        }    

        print(reached, frontier);
    }
    return false;
}

int main()
{
    cout << "\n\nBFS ON ROMANIA : " << endl;

    map<string, vector<string>> city;
    city["Arad"] = {"Zerind", "Timisoara", "Sibiu"};
    city["Zerind"] = {"Arad", "Oradea"};
    city["Oradea"] = {"Zerind", "Sibiu"};
    city["Sibiu"] = {"Arad", "Oradea", "Fagaras", "Rimnicu Vilcea"};
    city["Fagaras"] = {"Sibiu", "Bucharest"};
    city["Rimnicu Vilcea"] = {"Sibiu", "Pitesti", "Craiova"};
    city["Pitesti"] = {"Rimnicu Vilcea", "Bucharest", "Craiova"};
    city["Bucharest"] = {"Pitesti", "Fagaras", "Urziceni", "Giurgiu"};
    city["Craiova"] = {"Drobeta", "Rimnicu Vilcea", "Pitesti"};
    city["Urziceni"] = {"Bucharest", "Hirsova", "Vaslui"};
    city["Giurgiu"] = {"Bucharest"};
    city["Timisoara"] = {"Arad", "Lugoj"};
    city["Lugoj"] = {"Timisoara", "Mehadia"};
    city["Mehadia"] = {"Lugoj", "Drobeta"};
    city["Drobeta"] = {"Mehadia", "Craiova"};
    city["Hirsova"] = {"Urziceni", "Eforie"};
    city["Vaslui"] = {"Urziceni", "Iasi"};
    city["Eforie"] = {"Hirsova"};
    city["Iasi"] = {"Vaslui", "Neamt"};
    city["Neamt"] = {"Iasi"};

    map<string,pair<string, int>> reached;
    priority_queue<node, vector<node>, Compare> frontier;

    string initial = "Arad";
    string dest = "Bucharest";

    bool found = BFSonRomania(city, reached, frontier, initial, dest);
    if(found)
    {
        cout << "Reached Goal State\n" << endl;
        vector<string> path;
        path.push_back(dest);
        string temp = dest;
        while(reached[temp].first != "")
        {
            temp = reached[temp].first; 
            path.push_back(temp);
        }

        reverse(path.begin(), path.end());
        cout << "Path : " ;
        for(auto i : path)
        {

            cout << i ;
            if(i != dest)
                cout << " -> " ;
        }

    }
    else
    {
        cout << "Path not possible\n\n";
    }

    cout << endl << endl;
    
    return 0;
}