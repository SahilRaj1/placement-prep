/* TOPIC: Kosaraju's Algorithm for Strongly Connected Components */

// TIME COMPLEXITY: O()
// SPACE COMPLEXITY: O()

// REFERENCE: https://youtu.be/ndfjV_yHpgQ

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, unordered_map<int, list<int>> &adj, vector<bool> &visited, stack<int> &st) {

    visited[node] = true;
    for (auto &it: adj[node]) {
        if (!visited[it]) {
            dfs(it, adj, visited, st);
        }
    }

    st.push(node);

}

unordered_map<int, list<int>> createTranspose(unordered_map<int, list<int>> &adj, int v) {

    unordered_map<int, list<int>> transpose;
    for (int i=0; i<v; i++) {
        for (auto &it: adj[i]) {
            transpose[it].push_back(i);
        }
    }

    return transpose;

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

    // 1. topological sort
    vector<bool> visited(v, false);
    stack<int> st;
    for (int i=0; i<v; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited, st);
        }
    }

    // 2. transpose of graph
    unordered_map<int, list<int>> transpose = createTranspose(adj, v);
    for (int i=0; i<v; i++) {
        visited[i] = false;
    }

    // 3. dfs on topological sort ordering
    int cnt = 0;
    stack<int> temp;
    while (!st.empty()) {
        int top = st.top();
        st.pop();
        if (!visited[top]) {
            cnt++;
            dfs(top, transpose, visited, temp);
        }
    }

    return cnt;

    return 0;
}