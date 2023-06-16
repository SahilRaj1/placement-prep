/* TOPIC: Articulation Points in Graphs */

// TIME COMPLEXITY: O()
// SPACE COMPLEXITY: O()

// REFERENCE: https://youtu.be/fqkqx6OBRDE

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, int timer, vector<int> &disc, vector<int> &low,
    vector<bool> &visited, vector<bool> &articulationPoint, unordered_map<int, list<int>> &adj) {

    visited[node] = true;
    disc[node] = low[node] = timer++;
    int child = 0;

    for (auto &it: adj[node]) {

        // back to parent node condition
        if (it == parent) {
            continue;
        }

        if (!visited[it]) {
            dfs(it, node, timer, disc, low, visited, articulationPoint, adj);
            low[node] = min(low[node], low[it]);

            // check if node is an articulation point
            if (low[it] >= disc[node] and parent != -1) {
                articulationPoint[node] = true;
            }
            child++;

        } else {
            // back edge
            low[node] = min(low[node], disc[it]);
        }
    }

    if (parent == -1 and child > 1) {
        articulationPoint[node] = true;
    }

}

int main() {

    int v, e;
	cin>>v>>e;

	unordered_map<int, list<int>> adj;
	for (int i=0; i<e; i++) {
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

    // initialize data structures
    int timer = 0;
    vector<int> disc(v, -1);
    vector<int> low(v, -1);
    int parent = -1;
    vector<bool> visited(v, false);
    vector<bool> articulationPoint(v, false);

    // dfs
    for (int i=0; i<v; i++) {
        if (!visited[i]) {
            dfs(i, parent, timer, disc, low, visited, articulationPoint, adj);
        }
    }

    cout<<"Articulation Points : ";
    for (int i=0; i<v; i++) {
        if (articulationPoint[i]) {
            cout<<i<<" ";
        }
    } cout<<endl;

    return 0;
}