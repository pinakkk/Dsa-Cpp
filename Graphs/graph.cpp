#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <stack>
using namespace std;

class Graph
{
public:
    int nodes;
    vector<vector<int>> adjList;

    // Constructor
    Graph(int n)
    {
        nodes = n;
        adjList.resize(n);
    }

    void addEdge(int u, int v, bool direction){
        adjList[u].push_back(v);
        if (direction == 0){
            adjList[v].push_back(u);
        }
    }

    void PrintGraph(){
        for(int i=0; i<nodes; i++){
            cout << i << " -> ";
            for(int neighbour : adjList[i]){
                cout << neighbour << " ";
            }
            cout << endl;
        }
    }

    void BFS(int start){
        // Queue for nodes to be explored
        queue<int> q;

        // Set -> to mark as visited;
        set<int> visited;

        visited.insert(start);
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " "; //Visit the the;

            // enqueue all unvisited neighbours

            for(int neighbour : adjList[node]){
                if(visited.find(neighbour) == visited.end()){ // if neighbour is not visited;
                    visited.insert(neighbour);
                    q.push(neighbour);
                }
            }
        }
    }


    // DFS Using Recursion

    void DFS(int start){
        set<int> visited;
        DFSHelper(start, visited);
    }

    void DFSHelper(int node, set<int> & visited){
        visited.insert(node);
        cout << node << " ";

        for(int neighbour : adjList[node]){
            if(visited.find(neighbour) == visited.end()){
                // Not visited 
                DFSHelper(neighbour, visited);
            }
        }
    }

    // DFS Using stack
    void DFSUsingStack(int start){
        vector<bool> visited(nodes,false); //Track of visited nodes
        stack<int> s;
        
        s.push(start);
        visited[start] = true;
        while(!s.empty()){
            int node = s.top();
            s.pop();
            cout << node << " ";

            for(int neighbour: adjList[node]){
                // if not visited
                if(!visited[neighbour]){
                    s.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
    }

};

int main()
{
    int nodes,edges;
    cin >> nodes >> edges;
    Graph g(nodes);

    for(int i=0; i<edges; i++){
        int u,v; cin >> u >> v;
        g.addEdge(u, v, 0);
    }

    g.PrintGraph();

    int startNode; cin >> startNode;

    cout <<  "BFS Starting from node : "; 

    g.BFS(startNode);
    cout << endl;

    cout << "DFS Using Recursion : ";

    g.DFS(startNode);
    cout << endl;

    cout << "DFS Using Stack : ";
    g.DFSUsingStack(startNode);

    cout << endl;

    return 0;
}

