#include <iostream>

using namespace std;

bool is_k_quotation(int a[100], int k, int n) {
    // Checks whether 'a' represents a k-quotation
    // Magic trick: a sequence of k-quotations, even with additional text in-between, is also a single k-quotation

    int leftPos=0, rightPos=n-1;
    int usedLeft=0, usedRight=0;

    for (; k>0; k--) {
        if (leftPos>rightPos) return false;

        if (a[leftPos]-usedLeft > k) {
            usedLeft += k;
            if (leftPos==rightPos) usedRight += k;
        } else if (a[leftPos]-usedLeft == k) {
            usedLeft = 0;
            leftPos++;
        } else if (a[leftPos]-usedLeft < k) {
            return false;
        }

        if (a[rightPos]-usedRight > k) {
            usedRight += k;
            if (leftPos==rightPos) usedLeft += k;
        } else if (a[rightPos]-usedRight == k) {
            usedRight = 0;
            rightPos--;
        } else if (a[rightPos]-usedRight < k) {
            return false;
        }
    }

    return true;
}

int find_biggest_quotation() {
    int a[100];
    int n, sum=0;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    // If there is an odd number of quotes, then this cannot represent a valid quotation
    if (sum%2 != 0) return 0;

    // If there are exactly two quotes, this is a 1-quotation
    if (sum==2) return 1;

    // An upper bound for the degree of the biggest quotation is the min of the first and last groups of quotes
    for (int k=min(a[0], a[n-1]); k>1; k--) {
        if (is_k_quotation(a, k, n)) return k;
    }
    
    // If no quotation could be found, then fail
    return 0;
}

int main() {
    int k = find_biggest_quotation();
    if (k==0) cout << "no quotation" << endl;
    else cout << k << endl;
}