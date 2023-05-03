#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int testcases;
    cin >> testcases;

    int n, p, i;
    char c;
    for (int t=0; t<testcases; t++) {
        bool inserted = false;
        cin >> n >> p;
        vector<int> number(n);
        getchar();
        for (i=0; i<n; i++) {
            c = getchar();
            if (p+48<=c || inserted) cout << c;
            else {
                cout << p << c;
                inserted = true;
            }
        }
        if (!inserted) cout << p;
        cout << endl;
    }
}