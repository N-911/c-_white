#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

struct student {
    string f_name;
    string l_name;
    int day;
    int month;
    int year;
};

int main() {
    int n;
    cin >> n;
    vector<student> v_student;
    for (int i = 0; i < n; ++i) {
        string f_name, l_name;
        int d, m, y;
        cin >> f_name >> l_name >> d >> m >> y;
        v_student.push_back({f_name, l_name, d, m, y});
    }
    int m;
    cin >> m;
    string command;
    int index;
    for (int j = 0; j < m; ++j) {
	    cin >> command >> index;
	    --index;
	    if (command == "name" && index >= 0 && index < n) {
            cout << v_student[index].f_name << ' ' << v_student[index].l_name << endl;
        }
	    else if (command == "date" && index >= 0 && index < n) {
	        cout << v_student[index].day << '.' << v_student[index].month << '.' << v_student[index].year << endl;
	    }
        else {
            cout << "bad request" << endl;
        }
    }
    return 0;
}

