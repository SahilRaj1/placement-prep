/* TOPIC: Minimum Spanning Tree - Prim's ALgorithm */

// TIME COMPLEXITY: O()
// SPACE COMPLEXITY: O()

// REFERENCE: https://youtu.be/rnYBi9N_vw4

#include <bits/stdc++.h>
using namespace std;

int minKeyNode(vector<int> &key, vector<bool> &mst) {
    int mn = INT_MAX, ans;
    for (int i=0; i<key.size(); i++) {
        if (key[i] < mn and mst[i] == false) {
            mn = key[i];
            ans = i;
        }
    }
    return ans;
}

vector<pair<pair<int, int>, int>> prims(int n, unordered_map<int, list<pair<int, int>>> &adj) {

    // creating the data structures required
    vector<int> key(n, INT_MAX);
    vector<bool> mst(n, false);
    vector<int> parent(n, -1);

    // initializing data structures for source node
    key[0] = 0;
    parent[0] = -1;

    for (int i=0; i<n; i++) {

        // find the minimum key node
        int u = minKeyNode(key, mst);

        // mark node as true
        mst[u] = true;

        // check its adjacent nodes
        for (auto &it: adj[u]) {
            int v = it.first;
            int w = it.second;
            if (mst[v] == false and w < key[v]) {
                parent[v] = u;
                key[v] = w;
            }
        }

    }

    vector<pair<pair<int, int>, int>> result;
    for (int i=1; i<n; i++) {
        result.push_back({{parent[i]+1, i+1}, key[i]});
    }

    return result;

}

int main() {

    int v, e;
	cin>>v>>e;

	unordered_map<int, list<pair<int, int>>> adj;
	for (int i=0; i<e; i++) {
		int u, v, w;
		cin>>u>>v>>w;
		adj[u-1].push_back({v-1, w});
		adj[v-1].push_back({u-1, w});
	}

    vector<pair<pair<int, int>, int>> ans = prims(v, adj);

    cout<<"MST :"<<endl;
    for(auto &it: ans) {
        cout<<it.first.first<<" "<<it.first.second<<" "<<it.second<<endl;
    } cout<<endl;

    return 0;
}