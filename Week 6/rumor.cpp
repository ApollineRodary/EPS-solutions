#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void dfs(int node, vector<vector<int>> &friends, unordered_set<int> &visited, vector<int> &component) {
    // Run depth first search to identify the connected component of a given node within a graph represented as an adjacency list (friends)
    visited.insert(node);
    component.push_back(node);
    for (int friend_: friends[node]) {
        if (visited.find(friend_) == visited.end()) dfs(friend_, friends, visited, component);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> costs(n);
    vector<vector<int>> friends(n);

    for (int i=0; i<n; i++) {
        cin >> costs[i];
    }

    // Build adjacency lists
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        friends[a-1].push_back(b-1);
        friends[b-1].push_back(a-1);
    }

    // Find connected components
    vector<vector<int>> connected_components;
    unordered_set<int> visited;
    for (int i=0; i<n; i++) {
        if (visited.find(i) != visited.end()) continue;

        vector<int> c;
        dfs(i, friends, visited, c);
        connected_components.push_back(c);
    }

    // For each component, find whoever offers the smallest cost
    long long int cost = 0;
    for (vector<int> c: connected_components) {
        int min_offer = costs[c[0]];
        for (int p: c) {
            if (costs[p] < min_offer) min_offer = costs[p];
        }
        cost += min_offer;
    }

    cout << cost << endl;
}