#include <iostream>

using namespace std;

const int MAX_N = 200000;

int main() {
    int n, q;
    cin >> n >> q;

    int a[MAX_N];
    for (int i=0; i<n; i++) cin >> a[i];

    int defaults[MAX_N];            // defaults[k] = how many indices i between 1 and k are within a 3+ long decreasing sequence (i.e. a(i-1, i+1) is decreasing)
    defaults[0] = 0;                // We count them rather than enumerating them because otherwise we couldn't do something in constant time for every query (see that one chicken wing problem from the midterm and the delta-encoding trick)
    for (int i=1; i<n-1; i++) {
        defaults[i] = defaults[i-1];
        if (a[i]>=a[i+1] && a[i-1]>=a[i]) defaults[i]++;
    }

    int l, r;
    for (int i=0; i<q; i++) {
        cin >> l >> r;
        if (l==r) {
            cout << 1 << endl;
            continue;
        }
        if (l+1==r) {
            cout << 2 << endl;
            continue;
        }
        cout << (r-l) + defaults[l-1] - defaults[r-2] + 1 << endl;  // We pick everything but the defaults
                                                                    // (except actually we can pick the last default because we have a margin of two)
    }
}