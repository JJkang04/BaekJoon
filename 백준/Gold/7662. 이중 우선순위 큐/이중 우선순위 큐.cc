#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

#define X first
#define Y second
using namespace std;

class DualPriorityQueue {
private:
    priority_queue<int> maxHeap;
    priority_queue<int,vector<int>, greater<int>> minHeap;
    unordered_map<int,int> isValid;

    void removeInvalid(priority_queue<int>& heap) {
        while(!heap.empty() && isValid[heap.top()] == 0) {
            heap.pop();
        }
    }

    void removeInvalid(priority_queue<int,vector<int>, greater<int>>& heap) {
        while(!heap.empty() && isValid[heap.top()] == 0) {
            heap.pop();
        }
    }

public:
    
    void insert(int x) {
        maxHeap.push(x);
        minHeap.push(x);
        isValid[x]++;
    }

    void deleteMax() {
        removeInvalid(maxHeap);
        
        if(!maxHeap.empty()) {
            int maxVal = maxHeap.top();
            isValid[maxVal]--;
            maxHeap.pop();
        }
    }

    void deleteMin() {
        removeInvalid(minHeap);

        if(!minHeap.empty()) {
            int minVal = minHeap.top();
            isValid[minVal]--;
            minHeap.pop();
        }
    }

    int getMax() {
        removeInvalid(maxHeap);
        return maxHeap.empty() ? -1 : maxHeap.top();
    }

    int getMin() {
        removeInvalid(minHeap);
        return minHeap.empty() ? -1 : minHeap.top();
    }

    bool empty() {
        removeInvalid(maxHeap);
        removeInvalid(minHeap);
        return maxHeap.empty() && minHeap.empty();
    }
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for(int i = 0; i < t; ++i) {

        DualPriorityQueue dpq;

        int k;
        cin >> k;

        for(int j = 0; j < k; ++j) {
            
            char c;
            int n;

            cin >> c >> n;

            if(c == 'I') {
                
                dpq.insert(n);

                
            }
            else if(c == 'D') {
                
                if(n == -1) {
                    dpq.deleteMin();
                }

                else {
                    dpq.deleteMax();
                }
            }
        }

        if(dpq.empty()) {
            cout << "EMPTY" << '\n';
        }

        else {
            cout << dpq.getMax() << " " << dpq.getMin() <<'\n';
        }

    }

    return 0;
}