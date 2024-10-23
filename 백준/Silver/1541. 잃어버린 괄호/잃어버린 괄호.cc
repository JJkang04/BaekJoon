#include <iostream>
#include <cmath>

#define X first
#define Y second
using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;

    cin >> str;

    int result = 0;

    string temp = "";

    bool minus = false;

    for (char c : str) {
        
        if (c == '+' || c == '-') {
            
            if(minus) {
                result -= stoi(temp);
            }

            else {
                result += stoi(temp);
            }
            temp = "";
            if(c == '-') {
                minus = true;
            }
        }

        else {
            temp += c;
        }
    }

    if(minus) {
        result -= stoi(temp);
    }

    else {
        result += stoi(temp);
    }

    cout << result;

    return 0;
}