#include <iostream>
#include <unordered_set>
using namespace std;

bool valid(int* arr, int i, int j) {
    unordered_set<int> s;
    s.insert(arr[i++]);

    for(; i <= j; i++) {
        if(s.find(arr[i]) != s.end()) return false;
        s.insert(arr[i]);
    }
    return true;
}
int main() {
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    int maxVal = 0;

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if((j-i+1)%2 == 0) { // if even length
                if(valid(arr, i, j)) {
                    int sum = 0;
                    for(int k = i; k <= j; k++) {
                        sum += arr[k];
                    }
                    if(sum > maxVal) maxVal = sum;
                }
            }
        }
    }
    cout << maxVal;
    return 0;
}
