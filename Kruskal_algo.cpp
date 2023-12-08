#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> iPair;

class Graph {
    int V, E;
    vector<pair<int, iPair>> edges;

public:
    Graph(int V, int E) {
        this->V = V;
        this->E = E;
    }

    void addEdge(int u, int v, int w) {
        edges.push_back({w, {u, v}});
    }

    int kruskalMST();

    class DisjointSets {
        int *parent, *rank;
        int n;

    public:
        DisjointSets(int n) {
            this->n = n;
            parent = new int[n+1];
            rank = new int[n+1];

            for (int i = 0; i <= n; i++) {
                rank[i] = 0;
                parent[i] = i;
            }
        }

        int find(int u) {
            if (u != parent[u])
                parent[u] = find(parent[u]);
            return parent[u];
        }

        void merge(int x, int y) {
            x = find(x), y = find(y);

            if (rank[x] > rank[y])
                parent[y] = x;
            else if (rank[x] < rank[y])
                parent[x] = y;
            else
                parent[x] = y, rank[y]++;
        }
    };
};

int Graph::kruskalMST() {
    int mst_wt = 0;
    sort(edges.begin(), edges.end());
    DisjointSets ds(V);

    for (int i = 0; i < E; i++) {
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        int w = edges[i].first;

        int set_u = ds.find(u);
        int set_v = ds.find(v);

        if (set_u != set_v) {
            cout <<"\t "<< u << "---" << v << "  :  " << w << endl;
            mst_wt += w;
            ds.merge(set_u, set_v);
        }
    }

    return mst_wt;
}

int main() {
    int V = 9, E = 14;
    Graph g(V, E);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    cout << "\n\tEdges of MST are \n";
	cout <<"\t"<< " edges "<<" "<< " weight"<<endl;
    int mst_wt = g.kruskalMST();
    cout << "\n\tWeight of MST is " << mst_wt<<endl;

    return 0;
}
