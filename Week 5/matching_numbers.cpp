#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int testcase=0; testcase<t; testcase++) {
        int n;
        cin >> n;

        if (n%2 == 0) {
            cout << "No" << endl;
            continue;
        }

        cout << "Yes" << endl;
        for (int i=1; i<=n; i+=2) cout << i << ' ' << 2*n - (n+i)/2 + 1 << endl;
        for (int i=2; i<n; i+=2) cout << i << ' ' << 2*n - (i/2) + 1 << endl; 
    }
}