#include <iostream>
using namespace std;

int main() {
    int center_X, center_Y, r;
    cin >> center_X >> center_Y >> r;
    
    int dot1_X, dot1_Y, dot2_X, dot2_Y, dot3_X, dot3_Y, dot4_X, dot4_Y;

    dot1_X = center_X - r;
    dot1_Y = center_Y + r;
    dot2_X = center_X + r;
    dot2_Y = center_Y + r;
    dot3_X = center_X + r;
    dot3_Y = center_Y - r;
    dot4_X = center_X - r;
    dot4_Y = center_Y - r;

    cout << dot1_X << " " << dot1_Y << endl;
    cout << dot2_X << " " << dot2_Y << endl;
    cout << dot3_X << " " << dot3_Y << endl;
    cout << dot4_X << " " << dot4_Y << endl;

    
    return 0;
}