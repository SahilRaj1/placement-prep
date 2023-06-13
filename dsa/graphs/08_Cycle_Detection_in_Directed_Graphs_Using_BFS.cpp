/* TOPIC: Cycle Detection in Directed Graph using BFS */

// TIME COMPLEXITY: O()
// SPACE COMPLEXITY: O()

// REFERENCE: https://youtu.be/X2_tYUuthH8

#include <bits/stdc++.h>
using namespace std;

int bfs(int v, unordered_map<int, list<int>> &adj, vector<int> &indegree) {

    int ct = 0;
    queue<int> q;
    for (int i=0; i<v; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int front = q.front();
        q.pop();
        ct++;
        for (auto &it: adj[front]) {
            indegree[it]--;
            if (indegree[it] == 0) {
                q.push(it);
            }
        }
    }

    return ct;

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

    int ct = bfs(v, adj, indegree);

    if (ct == v) {
        cout<<"False"<<endl;
    } else {
        cout<<"True"<<endl;
    }

    return 0;
}