#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 200000;

int main() {
    // There are at least as many paths as there are leaves. Given that we want to minimise number of paths only, we can just iterate over every leaf and generate one path for each.
    
    int t;
    cin >> t;

    int p[MAX_N+1];
    bool is_leaf[MAX_N+1];
    bool included[MAX_N+1];       // Whether a given node was already included in a path
    int path[MAX_N];

    for (int testcase=0; testcase<t; testcase++) {
        int n;
        cin >> n;

        for (int i=1; i<=n; i++) {
            cin >> p[i];
            is_leaf[i] = true;
            included[i] = false;
        }
        
        // Identify leaves
        for (int i=1; i<=n; i++) {
            if (p[i] != i) is_leaf[p[i]] = false;
        }

        // Counting paths
        int paths=0;
        for (int i=1; i<=n; i++) {
            if (is_leaf[i]) paths++;
        }
        cout << paths << endl;

        // Creating a path down to each leaf
        for (int i=1; i<=n; i++) {
            if (!is_leaf[i]) continue;

            int node = i;
            int path_length = 0;
            
            // Go up the tree until we reach a root that's already been included
            while (!included[node]) {
                path[path_length] = node;
                path_length++;
                included[node] = true;
                node = p[node];
            }

            // Backtrack and output the path from top to bottom
            cout << path_length << endl;
            for (int k=path_length-1; k>=0; k--) {
                cout << path[k] << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }
}