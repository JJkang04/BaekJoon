#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

#define X first
#define Y second
using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for(int i = 0; i < t; ++i) {

        vector<int> vec;
        string order;
        cin >> order;

        int n;
        cin >> n;

        string arr;
        cin >> arr;

        // 배열에 있는 숫자들을 벡터에 넣기

        string temp = "";

        for(size_t j = 0; j < arr.size(); ++j) {
            if (arr[j] == '[' || arr[j] == ']') {
                continue;
            } 

            else if(arr[j] == ',') {
                vec.push_back(stoi(temp));
                temp = "";
            }

            else {
                temp += arr[j];
            }
        }

        if(temp != "") {
            vec.push_back(stoi(temp));
        }

        bool error = false;
        bool reverse = false; 
        int front = 0; 
        int back = vec.size() - 1;

        for(const char& c : order) {
            if(c == 'R') {
                reverse = !reverse;
            }
            else if(c == 'D') {
                if(front > back) {
                    cout << "error" << '\n';
                    error = true;
                    break;
                }
                if(reverse) {
                    --back;
                }
                else {
                    ++front;    
                }
            }
        }
        
        if(error) {
            continue;
        }

        cout << '[';
        
        if(front <= back) {
            if(reverse) {
                for(int k = back; k > front; --k) {
                    cout << vec[k] << ',';
                }
                cout << vec[front];
            }
            else {
                for(int k = front; k < back; ++k) {
                    cout << vec[k] << ',';
                }
                cout << vec[back];
            }
        }

        cout << ']' << '\n';
    }

    return 0;
}