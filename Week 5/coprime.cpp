#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

bool is_coprime(int a, int b) {
    // Return GCD of a and b, assuming a>=b
    int temp;
    while (b != 0) {
        temp = b;
        b = a%b;
        a = temp;
    }
    return (a==1);
}

int main() {
    // Get table of coprimes
    bool coprime[1000][1000];
    for (int i=1; i<=1000; i++) {
        for (int j=1; j<=i; j++) {
            int c = is_coprime(i, j);
            coprime[i-1][j-1] = c;
        }
    }

    int t;
    cin >> t;

    for (int testcase=0; testcase<t; testcase++) {
        int n;
        cin >> n;

        // Read array, and find last index where each number occurs
        vector<int> array(n);
        int max_index[1000];
        memset(max_index, 0, 1000*sizeof(int));
        for (int i=0; i<n; i++) {
            cin >> array[i];
            max_index[array[i]-1] = i+1;
        }

        // Find biggest value of i+j such that a_i and a_j are coprime
        int max = -1;
        for (int i=0; i<1000; i++) {
            for (int j=0; j<=i; j++) {
                if (max_index[i]==0 || max_index[j]==0) continue;
                if (max_index[i] + max_index[j] <= max) continue;
                if (coprime[i][j]) max = max_index[i] + max_index[j];
            }
        }

        cout << max << endl;
    }
}