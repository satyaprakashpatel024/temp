#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9; // infinity value

vector<vector<int>> floyd_warshall(vector<vector<int>> graph) {
    int n = graph.size();

    // initialize distance matrix to infinity
    vector<vector<int>> dist(n, vector<int>(n, INF));

    // set diagonal values to 0
    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
    }

    // copy edge weights to distance matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] != INF) {
                dist[i][j] = graph[i][j];
            }
        }
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    return dist;
}

int main() {
    // example graph with 5 vertices
    vector<vector<int>> graph = {
        {  0,    3,   8,   INF,   -4},
        {INF,    0, INF,     1,    7},
        {INF,    4,   0,   INF,  INF},
        {  2,  INF,  -5,     0,  INF},
        {INF,  INF, INF,     6,    0}
    };

    // run Floyd-Warshall algorithm
    vector<vector<int>> dist = floyd_warshall(graph);

    // output the resulting distance matrix
    cout<<"\n\t FLOYD WARSHALL ALGORITHM "<<endl;
    cout<<"\t SATYA PRAKASH PATEL "<<endl;
    cout<<"\t BRANCH CSE(B2) "<<endl;
    cout<<"\t ENROLLMENT NO. 0131CS211099 "<<endl;
    // cout<<"\t";

    for (int i = 0; i < dist.size(); i++) 
    {
        cout<<"\t";
        for (int j = 0; j < dist.size(); j++) 
        {
            if (dist[i][j] == INF) 
            {
                cout << "INF "<<"\t";
            } else 
            {
                cout <<dist[i][j] << "\t";
            }
        }
        cout << endl;
    }

    return 0;
}
