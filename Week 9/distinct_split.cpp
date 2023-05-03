#include <iostream>
#include <vector>

using namespace std;

int main() {
    int testcases, n, c;
    string s;
    cin >> testcases;

    for (int t=0; t<testcases; t++) {
        cin >> n >> s;
        bool letters_left[26];
        bool letters_right[26];
        for (int i=0; i<26; i++) {
            letters_left[i] = false;
            letters_right[i] = false;
        }

        vector<int> distinct_left(n-1);
        vector<int> distinct_right(n-1);
        int l=0, r=0;

        for (int i=0; i<n-1; i++) {
            c = s[i]-97;
            if (!letters_left[c]) {
                letters_left[c] = true;
                l++;
            }
            distinct_left[i] = l;
            
            c = s[n-1-i]-97;
            if (!letters_right[c]) {
                letters_right[c] = true;
                r++;
            }
            distinct_right[i] = r;
        }

        int max=0, sum;
        for (int i=0; i<n-1; i++) {
            sum = distinct_left[i] + distinct_right[n-2-i];
            if (sum>max) max=sum;
        }
        cout << max << endl;
    }
}