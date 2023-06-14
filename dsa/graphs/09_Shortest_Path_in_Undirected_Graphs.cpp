/* TOPIC: Shortest Path in Undirected Graphs */

// TIME COMPLEXITY: O()
// SPACE COMPLEXITY: O()

// REFERENCE: https://youtu.be/abIEXKFpLNE

#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, m, s, t;
	cin>>n>>m>>s>>t;

	unordered_map<int, list<int>> adj;
	for (int i=0; i<m; i++) {
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

    vector<bool> visited(n, false);
	vector<int> parent(n, -1);

	// bfs
	queue<int> q;
	q.push(s);
	visited[s] = true;

	while (!q.empty()) {
		int front = q.front();
		q.pop();
		for (auto &it: adj[front]) {
			if (!visited[it]) {
				q.push(it);
				visited[it] = true;
				parent[it] = front;
			}
		}
	}

	vector<int> ans;
	int temp = t;
	ans.push_back(temp);
	while (temp != s) {
		temp = parent[temp];
		ans.push_back(temp);
	}

	reverse(ans.begin(), ans.end());
    cout<<"Shortest path : ";
    for (auto &it: ans) {
        cout<<it<<" ";
    } cout<<endl;

    return 0;
}