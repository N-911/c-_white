#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <fstream>
#include <sstream>
#include <exception>
#include <stdexcept>
#include <algorithm>
#include <iomanip>

using namespace std;

class Date {
public:
    Date() {
        year = 1;
        month = 1;
        day = 1;
    }
    Date(int new_year, int new_month, int new_day) {
      string error;

        if (new_month < 1 || new_month > 12) {
            error = "Month value is invalid: " + to_string(new_month);
            throw runtime_error(error);
        }
        else if (new_day < 1 || new_day > 31) {
            error = "Day value is invalid: " + to_string(new_day);
            throw runtime_error(error);
        }
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
    int y;
    int m;
    int d;
    string error;

    if (stream) {
        if (!(stream >> y)) {
          error = "Wrong date format: " + to_string(y);
          throw runtime_error(error);
        }
        if (stream.peek() != '-') {
          error = "Wrong date format: " + to_string(y);
          throw runtime_error(error);
        }
        stream.get();
        if (!(stream >> m)) {
          error = "Wrong date format: " + to_string(y);
          throw runtime_error(error);
        }
        if (stream.peek() != '-') {
          error = "Wrong date format: " + to_string(y);
          throw runtime_error(error);
        }
        stream.get();
        if (!(stream >> d)) {
          error = "Wrong date format: " + to_string(y);
          throw runtime_error(error);
        }
        if (!(stream.peek() == EOF)) {
            error = "Wrong date format: " + to_string(y);
            throw runtime_error(error);
        }
      }
      new_date = Date(y, m, d);
    return stream;
}


ostream& operator << (ostream& stream, const Date& new_date) {
                      stream << setw(4) << setfill('0') << new_date.GetYear()
                      << '-' << setw(2) << new_date.GetMonth()
                      << '-' << setw(2) << new_date.GetDay();
    return stream;
}

/*
 * bool operator<(const Date& lhs, const Date& rhs) {
  // воспользуемся тем фактом, что векторы уже можно сравнивать на <:
  // создадим вектор из года, месяца и дня для каждой даты и сравним их
  return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} <
      vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}
 */

bool operator < (const Date& lhs, const Date& rhs) {
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

  int DeleteDate(const Date& date) {
      int n = 0;
      if (d_base.count(date) > 0) {
          n = d_base[date].size();
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
        for (const auto& [date, events] : d_base) {
            for (const auto& event : events) {
                cout << date << ' ' << event << endl;
            }
        }
    }

private:
    map<Date, vector<string>> d_base;
};

void parser(const string& command, Database& db) {
    set<string> active_commands = {"Add", "Del", "Find", "Print"};
    istringstream input(command);

    if (input) {
        Date new_date;
        string event;
        string operation;
        string error;

        input >> operation;
        if (active_commands.count(operation) == 0) {
          error = "Unknown command: " + operation;
          throw runtime_error(error);
        }
        else if (operation == "Add") {
          input >> new_date >> event;

          if (event.size() > 0) {
            db.AddEvent(new_date, event);
          }
        }
        else if (operation == "Del") {
          input >> new_date >> event;
          if (event.size() == 0) {
            cout << "Deleted " << db.DeleteDate(new_date) << " events" << endl;
          }
          else if (event.size() > 0) {
            if (db.DeleteEvent(new_date, event)) {
                cout << "Deleted successfully" << endl;
            } else {
                cout << "Event not found" << endl;
            }
          }
        } 
        else if (operation == "Find") {
          input >> new_date;
            for (auto item : db.Find(new_date)) {
                cout << item << endl;
            }
        } 
        else if (operation == "Print") {
            db.Print();
        }
    }
}

int main() {
    Database db;
    string command;
    while (getline(cin, command)) {
        try {
            if (command.size() == 0) {
                // cout << "" << endl;

            }
            else {
                parser(command, db);
            }
        } catch (runtime_error& ex) {
            cout << ex.what() << endl;
            return 0;
        }
      }
  return 0;
}


/*
 * Date ParseDate(const string& date) {
  istringstream date_stream(date);
  bool ok = true;

  int year;
  ok = ok && (date_stream >> year);
  ok = ok && (date_stream.peek() == '-');
  date_stream.ignore(1);

  int month;
  ok = ok && (date_stream >> month);
  ok = ok && (date_stream.peek() == '-');
  date_stream.ignore(1);

  int day;
  ok = ok && (date_stream >> day);
  ok = ok && date_stream.eof();

  if (!ok) {
    throw logic_error("Wrong date format: " + date);
  }
  return Date(year, month, day);
}
 */

