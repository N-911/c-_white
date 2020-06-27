#include <iostream>
#include <numeric>
#include <fstream>
#include <sstream>

using namespace std;


class Rational {
public:
    Rational() {
        numerator1 = 0;
        denominator1 = 1;
    }

    Rational(int numerator, int denominator) {
        if (denominator < 0 && numerator > 0) {
            numerator1 = -numerator;
            denominator1 = abs(denominator);
        }
        else if (denominator < 0 && numerator < 0){
            numerator1 = abs(numerator);
            denominator1 = abs(denominator);
        }
        else if (numerator == 0) {
            numerator1 = 0;
            denominator1 = 1;
        }
        else {
            numerator1 = numerator;
            denominator1 = abs(denominator);
        }
    }


    int Numerator() const {
        int temp = gcd(numerator1, denominator1);
        return numerator1 / temp;
    }

    int Denominator() const {
        int temp = gcd(numerator1, denominator1);
        return  denominator1 / temp;
    }

private:
    int numerator1;
    int denominator1;
};

bool operator==(const Rational& lhs, const Rational& rhs) {
    if ((lhs.Numerator() == rhs.Numerator()) && (lhs.Denominator() == rhs.Denominator())) {
        return true;
    }
    else {
        return false;
    }
}

Rational operator+(const Rational& lhs, const Rational& rhs) {
    int temp = lcm(lhs.Denominator(), rhs.Denominator());
    return Rational((lhs.Numerator() * (temp / lhs.Denominator())) +
                    (rhs.Numerator() * (temp / rhs.Denominator())), temp);
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
    int temp = lcm(lhs.Denominator(), rhs.Denominator());
    return Rational((lhs.Numerator() * (temp / lhs.Denominator())) -
                    (rhs.Numerator() * (temp / rhs.Denominator())), temp);
}
Rational operator*(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator());
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator());
}

ostream& operator<<(ostream& stream, const Rational& rational) {
    stream << rational.Numerator() << '/' << rational.Denominator();
    return stream;
}


istream& operator>>(istream& stream, Rational& rational) {
    int n = 0;
    int d = 0;

    if (stream) {
        stream >> n;
    }
    else {
        return stream;
    }
    stream.ignore(1);
    if (stream) {
        stream >> d;
    }
    else {
        return stream;
    }
    rational = Rational(n, d);
    return stream;
}

int main() {


    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }


    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 3;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 4;
        }
    }

    cout << "OK" << endl;
    return 0;
}
