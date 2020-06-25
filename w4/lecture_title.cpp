#include <iostream>
#include <string>

using namespace std;


struct Specialization {
    string value;
    explicit Specialization(const  string& spec) {
        value = spec;
    }
};

struct Course {
    string value;
    explicit Course(const string& course) {
        value = course;
    }
};

struct Week {
    string value;
    explicit  Week(const string& week) {
        value = week;
    }
};

struct LectureTitle {
    LectureTitle(Specialization new_sp, Course new_course, Week new_week) {
        specialization = new_sp.value;
        course = new_course.value;
        week = new_week.value;
    }

    string specialization;
    string course;
    string week;
};

