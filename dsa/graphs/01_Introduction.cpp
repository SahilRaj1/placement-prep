/* TOPIC: Introduction to Graphs */

// REFERENCE: https://youtu.be/EaK6aslcC5g

#include <bits/stdc++.h>
using namespace std;

/* Adjacency Matrix */
class graphMatrix {
public:

    int n;
    vector<vector<int>> matrix;

    graphMatrix(int n) {
        this->n = n;
        for (int i=0; i<n; i++) {
            matrix.push_back({});
            for (int j=0; j<n; j++) {
                matrix[i].push_back(0);
            }
        }
    }

    void addEdge(int u, int v, bool direction) {

        // direction = 0 -> undirected
        // direction = 1 -> directed

        matrix[u][v] = 1;
        
        if (direction == 0) {
            matrix[v][u] = 1;
        }

    }

    void printMatrix() {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                cout<<matrix[i][j]<<" ";
            } cout<<endl;
        }
    }

};

template <typename T>

/* Adjacency List */
class graphList {
public:

    unordered_map<T, list<T>> adj;

    void addEdge(T u, T v, bool direction) {

        // direction = 0 -> undirected
        // direction = 1 -> directed

        adj[u].push_back(v);

        if (direction == 0) {
            adj[v].push_back(u);
        }

    }

    void printAdjList() {
        for (auto &node: adj) {
            cout<< node.first << " -> ";
            for (auto &it: node.second) {
                cout<<it<<" ";
            } cout<<endl;
        }
    }

};

int main() {

    int n;
    cout<<"Enter the number of nodes : ";
    cin>>n;

    int m;
    cout<<"Enter the number of edges : ";
    cin>>m;

    graphList<int> g1;
    graphMatrix g2(n);

    cout<<"Enter the pair of nodes that are connected :"<<endl;
    for (int i=0; i<m; i++) {
        int u, v;
        cin>>u>>v;
        g1.addEdge(u, v, 0);
        g2.addEdge(u, v, 0);
    }

    g1.printAdjList();
    g2.printMatrix();

    return 0;
}