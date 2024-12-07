#include <iostream>
using namespace std;


int p, t;

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; ++i) {
        cin >> p >> t;
        p += t/4;
        p -= t/7;
        cout << p << '\n';
    }
    return 0;
}