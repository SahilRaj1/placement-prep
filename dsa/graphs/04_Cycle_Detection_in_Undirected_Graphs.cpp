/* TOPIC: Cycle Detection in Undirected Graphs */

// TIME COMPLEXITY: O()
// SPACE COMPLEXITY: O()

// REFERENCE: https://youtu.be/1cSzxlhxOw8

#include <bits/stdc++.h>
using namespace std;

bool detectCycleBFS(int start, unordered_map<int, list<int>> &adj, vector<bool> &visited, vector<int> &parent) {

	queue<int> q;
	q.push(start);
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		visited[front] = true;
		for (auto &it: adj[front]) {
			if (!visited[it]) {
				parent[it] = front;
				q.push(it);
			} else {
				if (parent[front] != it) {
					return true;
				}
			}
		}
	}

	return false;

}

bool detectCycleDFS(int start, int parent, unordered_map<int, list<int>> &adj, vector<bool> &visited) {

    visited[start] = true;
    for (auto &it: adj[start]) {
        if (!visited[it]) {
            if (detectCycleDFS(it, start, adj, visited)) {
                return true;
            }
        } else {
            if (it != parent) {
                return true;
            }
        }
    }

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
		adj[v].push_back(u);
	}

	vector<bool> visited(v, false);
	vector<int> parent(v, -1);

	for (int i=0; i<v; i++) {
		if (!visited[i]) {
			// if (detectCycleBFS(i, adj, visited, parent)) {
			// 	cout<<"True"<<endl;
			// 	return 0;
			// }
			if (detectCycleDFS(i, -1, adj, visited)) {
				cout<<"True"<<endl;
				return 0;
			}
		}
	}

	cout<<"False"<<endl;

	return 0;
}