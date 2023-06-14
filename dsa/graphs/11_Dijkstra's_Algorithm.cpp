/* TOPIC: Dijkstra's Algorithm */

// TIME COMPLEXITY: O()
// SPACE COMPLEXITY: O()

// REFERENCE: https://youtu.be/dVUR3Rm6biE

#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(unordered_map<int, list<pair<int, int>>> &adj, int source, int v) {

    // creation of distance vector with infinite values initially
    vector<int> dist(v, INT_MAX);

    // creation of set containing <node-distance, node>
    set<pair<int, int>> s;

    // initialize distance and set with source node
    dist[source] = 0;
    s.insert({0, source});

    // run algorithm until set is not empty or all nodes have been visited
    while (!s.empty()) {

        // fetch the top record which is the minimum weight unvisited node
        auto top = *(s.begin());
        int currCost = top.first;
        int currNode = top.second;

        // remove top record from the set so that it is visited
        s.erase(top);

        // traverse on neighbouring nodes
        for (auto &it: adj[currNode]) {

            // if distance from current node to the neighbouring node is less than it's current distance
            if (currCost + it.second < dist[it.first]) {

                // find any previous record of the node in the set
                auto record = s.find({dist[it.first], it.first});

                // delete record if found
                if (record != s.end()) {
                    s.erase(record);
                }

                // update the distance
                dist[it.first] = currCost + it.second;

                // insert record in set
                s.insert({dist[it.first], it.first});
            }
        }
    }

    return dist;

}

int main() {

    int v, e;
	cin>>v>>e;

	unordered_map<int, list<pair<int, int>>> adj;
	for (int i=0; i<e; i++) {
		int u, v, w;
		cin>>u>>v>>w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}

    vector<int> shortestPath = dijkstra(adj, 0, v);

    return 0;
}