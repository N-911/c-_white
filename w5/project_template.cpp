#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>

using namespace std;

class Date {
public:
    Date() {
        year = 1;
        month = 1;
        day = 1;
    }
    Date(int new_year, int new_month, int new_day) {
        year = new_year;
        month = new_month;
        day = new_day;
    }

  int GetYear() const;
  int GetMonth() const;
  int GetDay() const;

private:
    int year;
    int month;
    int day;
};

istream& operator>>(istream& stream, Date& new_date) {
    int y = 0;
    int m = 0;
    int d = 0;
    char delim;
    char delim2;

    if (stream) {
        stream >> y >> delim >> m >> delim2 >> d;
        if (stream && delim == '-' && delim2 == '-') {
            new_date = Date(y, m, d);
        }
    }
    return stream;
}

/*
bool operator<(const Date& lhs, const Date& rhs) {

}
*/

class Database {
public:
  void AddEvent(const Date& date, const string& event) {
      if (d_base.count(date) > 0) {
          if (find(d_base[date].begin(), d_base[date].end(), event) == d_base[date].end()) {
              d_base[date].push_back(event);
          }
          else {
              d_base[date].push_back(event);
          }
      }
  }
  bool DeleteEvent(const Date& date, const string& event);

//      cout << "Deleted successfully" << cout << endl;
//      cout << "Event not found" << cout << endl;


  int  DeleteDate(const Date& date) {
      int n = d_base.count(date);
      if (d_base.count(date) > 0) {
          d_base.erase(date);
      }
      cout << "Deleted " << n << " events" << endl;
      return n;
  }

//  /* ??? */ Find(const Date& date) const;
  
  void Print() const;

private:
    map<Date, vector<string>> d_base;
};

int main() {
  Database db;
  set<string> active_commands = {"Add", "Del", "Find", "Print"};
    
  string command;
  while (getline(cin, command)) {
      if (active_commands.count(command) == 0) {
          cout << "Unknown command: " << command << endl;
          continue;
      }
      Date new_date;
      string event;

      cin >> new_date;
      cin >> event;

      if (command == "Add" && event.size() > 0) {
          db.AddEvent(new_date, event);
      }
    // Считайте команды с потока ввода и обработайте каждую
  }

  return 0;
}