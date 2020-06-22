#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_aray(const vector<int>& v) {
    for (const auto& i : v) {
        cout << i << " ";
    }
}
int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int& x : v){
        cin >> x;
    }
    sort(begin(v), end(v), [](int a , int b) {
        return abs(a) < abs(b);
        }
    );
    print_aray(v);
    return 0;
}
