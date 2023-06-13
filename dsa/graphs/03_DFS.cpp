/* TOPIC: DFS Traversal in Graph */

// TIME COMPLEXITY: O()
// SPACE COMPLEXITY: O()

// REFERENCE: https://youtu.be/aJa3U-hydXc

#include <bits/stdc++.h>
using namespace std;

/* Adjacency List */
class graphList {
public:

    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction) {

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

    void dfs(int start, vector<int> &ans, vector<bool> &visited) {

        ans.push_back(start);
        visited[start] = true;

        for (auto &it: adj[start]) {
            if (!visited[it]) {
                dfs(it, ans, visited);
            }
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

    graphList g1;

    cout<<"Enter the pair of nodes that are connected :"<<endl;
    for (int i=0; i<m; i++) {
        int u, v;
        cin>>u>>v;
        g1.addEdge(u, v, 0);
    }

    vector<int> dfsTraversal;
    vector<bool> visited(n, false);
    g1.dfs(0, dfsTraversal, visited);

    cout<<"DFS : ";
    for (auto &it: dfsTraversal) {
        cout<<it<<" ";
    } cout<<endl;

    return 0;
}