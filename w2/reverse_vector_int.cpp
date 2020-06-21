#include <iostream>
#include <vector>

using namespace std;

void Reverse(vector<int>& v) {
    int tmp;
    int size = v.size();

    for (int i = 0; i < size / 2; ++i) {
        tmp = v[i] ;
        v[i] = v[size - i - 1];
        v[size - i - 1] = tmp;
    }
}

