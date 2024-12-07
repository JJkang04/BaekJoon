#include <iostream>
using namespace std;

int main() {
    int s,h,k;

    cin >> s >> h >> k;

    if(s+h+k >= 100) cout << "OK";

    else if(s < h && s < k) cout << "Soongsil";

    else if(h < s && h < k) cout << "Korea";

    else cout << "Hanyang";
    
    return 0;
}