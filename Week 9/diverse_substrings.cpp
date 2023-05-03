#include <iostream>

using namespace std;

int main() {
    int t, n;
    char s[100000];

    cin >> t;

    for (int testcase=0; testcase<t; testcase++) {
        cin >> n;
        for (int i=0; i<n; i++) cin >> s[i];
        
        int substrings = 0;
        int count[10];
        int distinct, c, max;

        for (int i=0; i<n; i++) {
            for (int k=0; k<10; k++) count[k]=0;
            distinct = 0;
            max = 0;

            for (int j=i; j<n && j<i+100; j++) {
                c = s[j]-'0';
                if (count[c]==0) distinct++;
                count[c]++;
                if (count[c]>max) max = count[c];

                if (max<=distinct) substrings++;
            }
        }

        cout << substrings << endl;
    }
}