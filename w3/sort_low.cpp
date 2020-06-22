#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <locale>

using namespace std;

void print_aray(const vector<string>& v) {
    for (const auto& i : v) {
        cout << i << " ";
    }
}

bool to_low(const string& a, const string& b) {
    string a1;
    string b1;

    for (const auto& i : a){
        a1.push_back(tolower(i));
    }
    for (const auto& i : b){
        b1.push_back(tolower(i));
    }
    return a1 < b1;
}


int main() {
    int n;
    cin >> n;
    vector<string> v(n);
    for (string& x : v){
        cin >> x;
    }
    sort(begin(v), end(v), to_low);
    print_aray(v);
    return 0;
}













