/* TOPIC: Shortest Path in Directed Acyclic Graphs */

// TIME COMPLEXITY: O()
// SPACE COMPLEXITY: O()

// REFERENCE: https://youtu.be/P_bfy0LOU5g

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, unordered_map<int, list<pair<int, int>>> &adj, vector<bool> &visited, stack<int> &st) {

    visited[node] = true;
    for (auto &it: adj[node]) {
        if (!visited[it.first]) {
            dfs(it.first, adj, visited, st);
        }
    }

    st.push(node);

}

int main() {

    int v, e;
	cin>>v>>e;

	unordered_map<int, list<pair<int, int>>> adj;
	for (int i=0; i<e; i++) {
		int u, v, w;
		cin>>u>>v>>w;
		adj[u].push_back({v, w});
	}

    vector<bool> visited(v, false);
    stack<int> st;

    for (int i=0; i<v; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited, st);
        }
    }

    vector<int> distance(v, -1);
    distance[0] = 0;    // distance from node 0
    while (!st.empty()) {
        int curr = st.top();
        st.pop();
        if (distance[curr] != -1) {
            for (auto &it: adj[curr]) {
                if (distance[it.first] == -1) {
                    distance[it.first] = distance[curr] + it.second;
                } else {
                    distance[it.first] = min(distance[it.first], distance[curr] + it.second);
                }
            }
        }
    }

    for (auto &it: distance) {
        cout<<it<<" ";
    } cout<<endl;

    return 0;
}