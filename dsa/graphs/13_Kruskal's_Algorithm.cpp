/* TOPIC: Kruskal's Algorithm || Disjoint Set || Union by Rank & Path Compression */

// TIME COMPLEXITY: O()
// SPACE COMPLEXITY: O()

// REFERENCE: https://youtu.be/KxLtIrCyXwE

#include <bits/stdc++.h>
using namespace std;

bool compare(vector<int> &a, vector<int> &b) {
  return a[0] < b[0];
}

/* Function to initialize a disjoint set */
void makeSet(vector<int> &parent, vector<int> &rank, int v) {

    for (int i=0; i<v; i++) {
        // set parent of node as the node itself and rank as 0
        parent[i] = i;
        rank[i] = 0;
    }

}

/* Function to return the root parent of a given node */
int findParent(vector<int> &parent, int node) {

    // base case
    if (parent[node] == node) {
        return node;
    }

    // set parent of node as the root parent and return it
    return parent[node] = findParent(parent, parent[node]);

}

/* Function to union two disjoint sets */
void unionSet(int u, int v, vector<int> &parent, vector<int> &rank) {

    // find parents of both nodes
    u = findParent(parent, u);
    v = findParent(parent, v);

    // compare ranks and change parent accordingly
    if (rank[u] < rank[v]) {
        parent[u] = v;
    }
    else if (rank[v] < rank[u]) {
        parent[v] = u;
    }
    else {
        parent[v] = u;
        rank[u]++;
    }

}

int kruskal(vector<vector<int>> &edges, int v) {

    // preparing the disjoint set
    vector<int> parent(v);
    vector<int> rank(v);

    // initializing the disjoint set
    makeSet(parent, rank, v);

    // sort edges based on weights
    sort(edges.begin(), edges.end(), compare);

    int minCost = 0;

    // traverse all edges
    for (auto &it: edges) {

        int u = findParent(parent, it[1]);
        int v = findParent(parent, it[2]);
        int w = it[0];

        // check if both nodes belong to the same component or not
        if (u != v) {
            minCost += w;
            unionSet(u, v, parent, rank);
        }

    }

    return minCost;

}

int main() {

    int v, e;
	cin>>v>>e;

	vector<vector<int>> edges;
	for (int i=0; i<e; i++) {
		int u, v, w;
		cin>>u>>v>>w;
		edges.push_back({w, u, v});
	}

    int ans = kruskal(edges, v);
    cout<<ans<<endl;

    return 0;
}