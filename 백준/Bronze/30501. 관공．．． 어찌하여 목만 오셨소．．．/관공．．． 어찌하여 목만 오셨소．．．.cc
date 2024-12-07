#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    string name;
    bool killerFinded = false;

    for(int i = 0; i<n; ++i) {
        cin >> name;
        for(const auto& a : name) {
            if(a == 'S') {
                killerFinded = true;
                break;
            }
        }
        if(killerFinded) {
            cout << name << endl;
            break;
        }
    }
    return 0;
}