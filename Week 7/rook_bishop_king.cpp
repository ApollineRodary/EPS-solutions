#include <iostream>

using namespace std;
int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int x=abs(c-a), y=abs(d-b);
    cout << ((a==c)?0:1)+((b==d)?0:1) << ' ' << ((x==y)?1:(((x-y)%2==0)?2:0)) << ' ' << ((x>y)?x:y) << '\n';
}