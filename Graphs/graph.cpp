#include <iostream>
#include <vector>
#include <queue>
#include <set>
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

            for(int neighbour : adjList[nodes]){
                if(visited.find(neighbour) == visited.end()){ // if neighbour is not visited;
                    visited.insert(neighbour);
                    q.push(neighbour);
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

    return 0;
}

