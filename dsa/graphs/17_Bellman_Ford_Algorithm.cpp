/* TOPIC: Bellman Ford Algorithm */

// TIME COMPLEXITY: O()
// SPACE COMPLEXITY: O()

// REFERENCE: https://youtu.be/ijpVpsmpJtQ

#include <bits/stdc++.h>
using namespace std;

vector<int> bellmanFord(int v, int e, int src, vector<vector<int>> &edges) {

    vector<int> dist(v, 1e9);
    dist[src] = 0;

    for (int i=0; i<v-1; i++) {
        for (auto &edge: edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            dist[v] = min(dist[v], dist[u] + w);
        }
    }

    return dist;

}

bool isNegativeCycle(int v, int e, int src, vector<vector<int>> &edges) {

    vector<int> dist(v, 1e9);
    dist[src] = 0;

    for (int i=0; i<v-1; i++) {
        for (auto &edge: edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            if (dist[u] + w < dist[v]) {
                return true;
            }
        }
    }

    return false;

}

int main() {

    int v, e;
	cin>>v>>e;

	vector<vector<int>> edges;
	for (int i=0; i<e; i++) {
		int u, v, w;
		cin>>u>>v>>w;
		edges.push_back({u, v, w});
	}

    // check if negative cycle present
    if (isNegativeCycle(v, e, 0, edges)) {
        cout<<"Negative Cycle Detected"<<endl;
        return 0;
    }

    vector<int> shortestPath = bellmanFord(v, e, 0, edges);

    return 0;
}