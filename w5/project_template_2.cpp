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
        year = new_year;
        month = new_month;
        day = new_day;
        verify_date(year, month, day);
    }

    Date(const string& str_date) {
        int y;
        int m;
        int d;
        string error;
        istringstream input(str_date);

        if (!(input >> y)) {
        error = "Wrong date format: " + str_date;
          throw runtime_error(error);
        }
        if (input.peek() != '-') {
          error = "Wrong date format: " + str_date;
          throw runtime_error(error);
        }
        input.ignore(1);
        if (!(input >> m)) {
          error = "Wrong date format: " + str_date;
          throw runtime_error(error);
        }
        if (input.peek() != '-') {
          error = "Wrong date format: " + str_date;
          throw runtime_error(error);
        }
        input.ignore(1);
        if (!(input >> d)) {
          error = "Wrong date format: " + str_date;
          throw runtime_error(error);
        }
        if (!(input.peek() == EOF)) {
            error = "Wrong date format: " + str_date;
            throw runtime_error(error);
        }
        year = y;
        month = m;
        day = d;
        verify_date(year, month, day);
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

    void verify_date(int year, int month, int day) {
        string error;

        if (month < 1 || month > 12) {
            error = "Month value is invalid: " + to_string(month);
            throw runtime_error(error);
        }
        else if (day < 1 || day > 31) {
            error = "Day value is invalid: " + to_string(day);
            throw runtime_error(error);
        }
    }

    int year;
    int month;
    int day;
};

istream& operator>>(istream& stream, Date& new_date) {

  string str_date;
  stream >> str_date;
    string error;
      new_date = Date(str_date);
    return stream;
}


ostream& operator << (ostream& stream, const Date& new_date) {
    stream << setw(4) << setfill('0') << new_date.GetYear() << '-' << setw(2)
         << new_date.GetMonth() << '-' << setw(2) << new_date.GetDay();
    return stream;
}


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
  
/*
 void Print() const {
      for (const auto& [date, events] : d_base) {
          cout << date << ' ';
          for (size_t i = 0; i < events.size(); ++i) {
              cout << events[i];
              if (i + 1 < events.size()) {
                  cout << ' ';
              }
          }
          cout << endl;
      }
  }
*/
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
#if 0
  { 
    try {
      auto date =  Date("2016-05-10");
      cout << "test 1 OK " << date << endl;
    } catch(runtime_error& e) {
      cout << e.what() << endl;
    }
    try {
      auto date =  Date("0-10-05");
      cout << "test 2 OK " << date << endl;
    } catch(runtime_error& e) {
      cout << e.what() << endl;
    }
    try {
      auto date = Date("2016-13-05");
      cout << "test 3 OK " << date << endl;
    } catch(runtime_error& e) {
      cout << e.what() << endl;
    }
    try {
      auto date = Date("2016-12-32");
      cout << "test 4 OK " << date << endl;
    } catch(runtime_error& e) {
      cout << e.what() << endl;
    }
    try {
      auto date = Date("2016--4-32");
      cout << "test 5 OK " << date << endl;
    } catch(runtime_error& e) {
      cout << e.what() << endl;
    }
    try {
      auto date = Date("2016----13-32");
      cout << "test 6 OK " << date << endl;
    } catch(runtime_error& e) {
      cout << e.what() << endl;
    }
    try {
      auto date = Date("2016-13-uuu32");
      cout  << "test 7 OK " << date << endl;
    } catch(runtime_error& e) {
      cout << e.what() << endl;
    }
    try {
      auto date = Date("23eef344gt65");
      cout  << "test 8 OK " << date << endl;
    } catch(runtime_error& e) {
      cout << e.what() << endl;
    }
    try {
      stringstream ss("1--1-0");
      auto date = Date("1970-1-1");
      ss >> date;
    } catch(runtime_error& e) {
      cout << e.what() << endl;
    }
    try {
      stringstream ss("1965-4-31");
      auto date = Date("1970-1-1");
      ss >> date;
      cout << date << endl;
    } catch(runtime_error& e) {
      cout << e.what() << endl;
    }
  }
    cout << "===============\n";
  {
    try {  
      db.AddEvent({"1990-06-21"},"Birthday");
      db.AddEvent({"1997-09-1"},"School");
      db.AddEvent({"1997-09-1"},"End-of-summer");
      db.AddEvent({"2001-01-1"},"Millenium");
      db.AddEvent({"2001-01-1"},"New-Year");
      db.AddEvent({"2001-01-1"},"New-Year");
      db.AddEvent({"2007-07-1"},"SchoolEnd");
      db.Print();
      db.AddEvent({"2007-07-1"},"UniversityExams");
      db.DeleteEvent({"2007-07-1"},"UniversityExams");
      db.DeleteEvent({"2007-07-1"},"First-Girlfriend");
      db.DeleteDate({"2001-01-1"});

      auto events = db.Find({"2005-12-21"});
      for(const string& event : events) {
        cout << event << endl;
      }
      for(const string& event : db.Find({"1997-09-01"})) {
        cout << event << endl;
      }
    } catch(exception& e) {
      cout << e.what() << endl;
    }

  
  }

#endif
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


