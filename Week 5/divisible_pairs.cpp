#include <iostream>
#include <cstring>
#include <numeric>

using namespace std;

bool find_pair(long long int a, long long int b, long long int c, long long int d) {
    for (long long int x=a+1; x<=c; x++) {
        // Find minimum possible value of k such that for y=kab/x, y>b, i.e. k>x/a and x|kab. We have (x/gcd(x, ab)) | k
        // The arithmetic for that took me forever so it better work

        long long int k = x / gcd(x, a*b);
        k *= ((x/a)/k) + 1;
        long long int y = k*a*b / x;

        if (y<=d && y>b) {
            cout << x << ' ' << y << endl;
            return true;
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;

    for (int testcase=0; testcase<t; testcase++) {
        long long int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (!find_pair(a, b, c, d)) cout << -1 << ' ' << -1 << endl;
    }
}