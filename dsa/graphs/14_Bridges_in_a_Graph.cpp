/* TOPIC: Bridges in a Graph */

// TIME COMPLEXITY: O()
// SPACE COMPLEXITY: O()

// REFERENCE: https://youtu.be/CiDPT1xMKI0

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, int timer, vector<int> &disc, vector<int> &low,
    vector<bool> &visited, vector<vector<int>> &bridges, unordered_map<int, list<int>> &adj) {

    visited[node] = true;
    disc[node] = low[node] = timer++;

    for (auto &it: adj[node]) {

        // back to parent node condition
        if (it == parent) {
            continue;
        }

        if (!visited[it]) {
            dfs(it, node, timer, disc, low, visited, bridges, adj);
            low[node] = min(low[node], low[it]);

            // check if edge is bridge
            if (low[it] > disc[node]) {
                bridges.push_back({node, it});
            }
            
        } else {
            // back edge
            low[node] = min(low[node], disc[it]);
        }
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
    vector<vector<int>> bridges;

    // dfs
    for (int i=0; i<v; i++) {
        if (!visited[i]) {
            dfs(i, parent, timer, disc, low, visited, bridges, adj);
        }
    }

    cout<<"Bridge Edges :"<<endl;
    for (auto &edge: bridges) {
        cout<<edge[0]<<" "<<edge[1]<<endl;
    } cout<<endl;

    return 0;
}