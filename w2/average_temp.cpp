#include <iostream>
#include <vector>

using namespace std;

vector<int> calc_averag_t(const vector<int>& v);

void print_vector(const vector<int>& v ){
    for (auto x : v)
        cout << x << " ";
}

vector<int> calc_averag_t(const vector<int>& v) {
    int sum = 0;
    int size = v.size();
    vector<int> res;
    int count = 0;

    for (auto x : v) {
        sum += x;
    }
    for (int i = 0; i < size; ++i) {
        if (v[i] > (sum / size)) {
            count++;
            res.push_back(i);
        }
    }
    cout << count << endl;
    return res;
}
int main() {
    int n;

    cin >> n;
    vector<int> v(n);
    for (int &x : v)
        cin >> x;
    vector<int> res = calc_averag_t(v);
    print_vector(res);
    return 0;
}