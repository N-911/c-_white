#include <iostream>
#include <map>
#include <vector>

using namespace std;

void print_all_routes (const map<string, vector<string>>& buses) { // ответ на запрос ALL_BUSES
    if (buses.empty()) {
        cout << "No buses" << endl;
    }
    else {
        for (const auto& bus : buses) {
            cout << "Bus " << bus.first << ": ";
            for (const string& s : bus.second) {
                cout << s << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    int count;
    string command;
    string bus_stop;
    map<string, vector<string>> buses;
    vector<string> original_buses;

    cin >> count;
    for (int i = 0; i < count; ++i) {
        cin >> command;
        if (command == "NEW_BUS") {
            string bus_route;
            cin >> bus_route;  // name bus route
            int number;
            cin >> number;
            vector<string> stops;
            for (int j = 0; j < number; ++j) {
                cin >> bus_stop;
                stops.push_back(bus_stop);
            }
            buses[bus_route] = stops;
            original_buses.push_back(bus_route);

        } else if (command == "BUSES_FOR_STOP") {
            cin >> bus_stop;
            int flag = 0;
            for (auto route : original_buses) {
                for (auto s : buses[route]) {
                    if (s == bus_stop) {
                        flag = 1;
                        cout << route << " ";
                    }
                }
            }
            if (flag) {
                cout << endl;
            }
            else {
                cout << "No stop" << endl;
            }
        } else if (command == "ALL_BUSES") {
            print_all_routes(buses);
        } else if (command == "STOPS_FOR_BUS") {
            string bus; // bus route
            cin >> bus;
            if (buses.count(bus) == 0) {
                cout << "No bus" << endl;
            } else {
                for (auto stop : buses[bus]) {  // vector stops
                    int flag = 0;
                    cout << "Stop " << stop << ": ";
                    for (auto o_b : original_buses) {  // vector route original
                        if (o_b != bus) {  // not equl current route
                            for (auto stops : buses[o_b]) {
                                if (stop == stops) {
                                    flag = 1;
                                    cout << o_b << " ";
                                }
                            }
                        }
                    }
                    if (flag) {
                        cout << endl;
                    } else {
                        cout << "no interchange" << endl;
                    }
                }
            }
        }
    }
    return 0;
}

