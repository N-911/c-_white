#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int count;
    map<vector<string>, int> bus_routes;
    int new_route = 0;

    cin >> count;
    for (int i = 0; i < count; ++i) {
        int count_stop;
        cin >> count_stop;
        vector<string> stops(count_stop);
        for (string& stop : stops) {
            cin >> stop;
        }
        if (bus_routes.count(stops) == 0) {
            new_route = bus_routes.size() + 1;
            bus_routes[stops] = new_route;
            cout << "New bus " << new_route << endl;
        }
        else {
            cout << "Already exists for " << bus_routes[stops] << endl;
        }
    }
    return 0;
}

