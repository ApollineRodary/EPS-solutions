#include <iostream>
#include <vector>

using namespace std;

int main() {
    int mod = 998244353;
    int n=0;
    cin >> n;
    
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    // arrays[n] = how many different arrays have n-90000 as the next integer being added and removed to the integers around it
    vector<int> arrays(180000, 0);
    arrays[a[1] + 90000] = 1;

    for (int i=0; i<n-3; i++) {
        vector<int> arrays_next(180000, 0);

        for (int j=-90000; j<90000; j++) {
            if (arrays[j+90000] == 0) {
                continue;
            }

            arrays_next[a[i+2] + j + 90000] += arrays[j+90000];
            arrays_next[a[i+2] + j + 90000] %= mod;
            if (j != 0) {
                arrays_next[a[i+2] - j + 90000] += arrays[j+90000];
                arrays_next[a[i+2] - j + 90000] %= mod;
            }
        }
        
        arrays.swap(arrays_next);
    }

    long long int s = -arrays[90000];
    for (int j=-90000; j<90000; j++) {
        s += 2*arrays[j+90000];
        s %= mod;
    }

    cout << s << endl;
    return 0;
}