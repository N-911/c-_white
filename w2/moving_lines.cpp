#include <iostream>
#include <vector>
#include <string>

using namespace std;

void MoveStrings(vector<string>& source, vector<string>& destination) {
    for (auto x : source)
        destination.push_back(x);
    source.clear();
}

