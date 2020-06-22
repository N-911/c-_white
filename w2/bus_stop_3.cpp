#include <set>
#include <map>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    map<set<string>, int> bus_routes;

    for (int i = 0; i < n; ++i) {
        int c_stop;
        set<string> stops;
        cin >> c_stop;
        string stop;
        for (int j = 0; j < c_stop; ++j) {
            cin >> stop;
            stops.insert(stop);
        }
        if (bus_routes.count(stops) == 0) {
           const int new_route = bus_routes.size() + 1;
            bus_routes[stops] = new_route;
            cout << "New bus " << new_route << endl;
        } else {
            cout << "Already exists for " << bus_routes[stops] << endl;

        }
    }
    return 0;
}
