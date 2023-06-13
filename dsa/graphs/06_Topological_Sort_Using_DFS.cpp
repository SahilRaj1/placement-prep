/* TOPIC: Topological Sort using DFS */

// TIME COMPLEXITY: O()
// SPACE COMPLEXITY: O()

// REFERENCE: https://youtu.be/T_boOrr0rvk

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
    stack<int> st;

    for (int i=0; i<v; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited, st);
        }
    }

    vector<int> ans;
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }

    cout<<"Topological Sort : ";
    for (auto &it: ans) {
        cout<<it<<" ";
    } cout<<endl;

    return 0;
}