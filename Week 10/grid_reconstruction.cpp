#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (; t>0; t--) {
        int n;
        cin >> n;

        for (int k=1; k<=n/2; k++)
            cout << 2*(n-k+1) << " " << 2*k << " ";
        
        cout << endl << 1 << " ";
                
        for (int k=2; k<=n/2; k++)
            cout << 2*(n-k+1) - 1 << " " << 2*k - 1 << " ";
        
        cout << 2*n - 1 << endl;
    }
}