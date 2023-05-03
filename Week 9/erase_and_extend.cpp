#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    char s[500000];
    for (int i=0; i<n; i++) cin >> s[i];
    
    int where_to_cut = n;
    for (int i=1; i<n; i++) {
        bool cut = false;
        for (int j=i; j<n; j++) {
            if (s[j]<s[j-i]) {
                i = j;
                break;
            }
            if (s[j]==s[j-i] && j!=n-1) continue;
            cut = true;
            break;
        }
        if (cut) {
            where_to_cut = i;
            break;
        }
    }

    for (int i=0; i<k; i++) cout << s[i%where_to_cut];
    cout << endl;
}