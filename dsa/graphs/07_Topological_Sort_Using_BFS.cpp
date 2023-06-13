/* TOPIC: Topological Sort using BFS (Kahn's Algorithm) */

// TIME COMPLEXITY: O()
// SPACE COMPLEXITY: O()

// REFERENCE: https://youtu.be/6XmzL04mlgQ

#include <bits/stdc++.h>
using namespace std;

void bfs(int v, unordered_map<int, list<int>> &adj, vector<int> &indegree, vector<int> &ans) {

    queue<int> q;
    for (int i=0; i<v; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int front = q.front();
        q.pop();
        ans.push_back(front);
        for (auto &it: adj[front]) {
            indegree[it]--;
            if (indegree[it] == 0) {
                q.push(it);
            }
        }
    }

}

int main() {

    int v, e;
	cin>>v>>e;

	unordered_map<int, list<int>> adj;
    vector<int> indegree(v, 0);
	for (int i=0; i<e; i++) {
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
        indegree[v]++;
	}

    vector<int> ans;
    bfs(v, adj, indegree, ans);

    cout<<"Topological Sort : ";
    for (auto &it: ans) {
        cout<<it<<" ";
    } cout<<endl;

    return 0;
}