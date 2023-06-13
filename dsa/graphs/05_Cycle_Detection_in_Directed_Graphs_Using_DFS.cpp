/* TOPIC: Cycle Detection in Directed Graphs uisng DFS */

// TIME COMPLEXITY: O()
// SPACE COMPLEXITY: O()

// REFERENCE: https://youtu.be/Tl5qbEmEQyY

#include <bits/stdc++.h>
using namespace std;

bool detectCycle(int node, unordered_map<int, list<int>> &adj, vector<bool> &visited, vector<bool> &dfsVisited) {

	visited[node] = true;
	dfsVisited[node] = true;

	for (auto &it: adj[node]) {
		if (!visited[it]) {
			if (detectCycle(it, adj, visited, dfsVisited)) {
				return true;
			}
		} else {
			if (dfsVisited[it]) {
				return true;
			}
		}
	}

	dfsVisited[node] = false;
	return false;

}

int main() {

    int v, e;
	cin>>v>>e;

	unordered_map<int, list<int>> adj;
	for (int i=0; i<e; i++) {
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
	}

	vector<bool> visited(v, false);
    vector<bool> dfsVisited(v, false);

    for (int i=0; i<v; i++) {
		if (!visited[i]) {
			if (detectCycle(i, adj, visited, dfsVisited)) {
				cout<<"True"<<endl;
                return 0;
			}
		}
	}

    cout<<"False"<<endl;

    return 0;
}