#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <fstream>
#include <sstream>
#include <algorithm>

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

  int GetYear() const {
      return year;
    }
  int GetMonth() const {
      return month;
    }
  int GetDay() const {
      return day;
    }

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

bool operator<(const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() != rhs.GetYear()) {
        return lhs.GetYear() < rhs.GetYear();
    }
    else {
        if (lhs.GetMonth() != rhs.GetMonth()) {
            return lhs.GetMonth() < rhs.GetMonth();
        } else {
            if (lhs.GetDay() != rhs.GetDay()) {
                return lhs.GetDay() < rhs.GetDay();
            } else {
                return false;
            }
        }
    }
}

class Database {
public:
  void AddEvent(const Date& date, const string& event) {
      if (d_base.count(date) > 0) {
          if (find(d_base[date].begin(), d_base[date].end(), event) == d_base[date].end()) {
              d_base[date].push_back(event);
          }
      }
      else {
          d_base[date].push_back(event);
      }
      sort(d_base[date].begin(), d_base[date].end());
  }

  bool DeleteEvent(const Date& date, const string& event) {
      if (d_base.count(date) > 0) {
          int i = 0;
          for (auto& item : d_base[date]) {
              if (item == event) {
                  d_base[date].erase(d_base[date].begin() + i);
                  return true;
              }
              ++i;
          }
      }
      return false;
  }

  int  DeleteDate(const Date& date) {
      int n = d_base[date].size();
      if (d_base.count(date) > 0) {
          d_base.erase(date);
      }
      return n;
  }

  vector<string> Find(const Date& date) const {
      vector<string> res;

      if (d_base.count(date) > 0) {
          res = d_base.at(date);
      }
      return res;
  }
  
  void Print() const {
      for (const auto& [date, strs] : d_base) {
          cout << date << ' ';
          for (const auto& j : strs) {
              cout << j;
          }

      }
  }

private:
    map<Date, vector<string>> d_base;
};

int main() {
    Database db;
    set<string> active_commands = {"Add", "Del", "Find", "Print"};
    
    string command;


    while (getline(cin, command)) {
        istringstream input(command);
        if (input) {
            Date new_date;
            string event;
            string operation;

            input >> operation >> new_date >> event;
            if (active_commands.count(operation) == 0) {
                cout << "Unknown command: " << operation << endl;
                continue;
            }
            if (operation == "Add" && event.size() > 0) {
                db.AddEvent(new_date, event);
            }
            else if (operation == "Del" && event.size() == 0 ) {
                cout << "Deleted " << db.DeleteDate(new_date) << " events" << endl;
            }
            else if (operation == "Del" && event.size() != 0 ) {
                if (db.DeleteEvent(new_date, event)) {
                    cout << "Deleted successfully" << endl;
                }
                else {
                    cout << "Event not found" << endl;
                }
            }
            else if (operation == "Find") {
                for (auto item : db.Find(new_date)) {
                    cout << item << endl;
                }
            }
            else if (operation == "Print") {
                db.Print();
            }
        }
        else {
            break;
        }
  }
  return 0;
}