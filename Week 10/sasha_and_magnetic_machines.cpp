#include <iostream>

using namespace std;

const int MAX_N = 50000;
const int MAX_POWER = 100;

int main() {
    int n;
    cin >> n;

    int a[MAX_N];
    int min=MAX_POWER;
    int sum=0;

    for (int i=0; i<n; i++) {
        cin >> a[i];
        if (a[i]<min) min=a[i];
        sum += a[i];
    }

    int min_sum = sum;
    for (int i=0; i<n; i++) {
        for (int j=2; j<=MAX_POWER/2; j++) {
            if (a[i]%j != 0) continue;
            int new_sum = sum - a[i] - min + a[i]/j + min*j;
            if (new_sum<min_sum) min_sum = new_sum;
        }
    }

    cout << min_sum << endl;
}