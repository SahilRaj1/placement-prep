/* TOPIC: BFS Traversal in Graph */

// TIME COMPLEXITY: O(V+E)
// SPACE COMPLEXITY: O(V)

// REFERENCE: https://youtu.be/b5kij1Akf9I

#include <bits/stdc++.h>
using namespace std;

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

    vector<int> bfs(int start) {

        queue<int> q;
        vector<bool> visited(adj.size(), false);
        vector<int> ans;

        q.push(start);
        while (!q.empty()) {
            int temp = q.front();
            q.pop();
            if (!visited[temp]) {
                ans.push_back(temp);
                visited[temp] = true;
            }
            for (auto &it: adj[temp]) {
                if (!visited[it]) {
                    q.push(it);
                }
            }
        }

        return ans;

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

    vector<int> bfsTraversal = g1.bfs(0);
    cout<<"BFS : ";
    for (auto &it: bfsTraversal) {
        cout<<it<<" ";
    } cout<<endl;

    return 0;
}