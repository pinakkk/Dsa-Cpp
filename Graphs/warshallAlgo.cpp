#include <iostream>
#include <vector>
using namespace std;

void warshallAlgo(int nodes, vector<vector<int>> & graph){
    for(int k=0; k<nodes; k++){
        for(int i=0; i<nodes; i++){
            for(int j=0; j<nodes; j++){
                graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
            }
        }
    }
}

int main(){
    int nodes; cin >> nodes;
    vector<vector<int>> graph(nodes, vector<int>(nodes));
    
    for(int i=0; i<nodes; i++){
        for(int j=0; j<nodes; j++){
            cin >> graph[i][j];
        }
    }

    warshallAlgo(nodes, graph);

    for(int i=0; i<nodes; i++){
        for(int j=0; j<nodes; j++){
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}