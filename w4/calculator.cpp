#include <iostream>
#include <exception>
#include <stdexcept>
#include <numeric>

using namespace std;

class Rational {
public:
    Rational() {
        numerator = 0;
        denominator = 1;
    };
    Rational(int n, int d) {
        int temp = gcd(n, d);
        if (d == 0) {
            throw invalid_argument("Invalid argument");
        }
        numerator = n / temp;
        denominator = d /temp;
        if (d < 0) {
            numerator = -n;
            denominator = -d;
        }
    }

    int Numerator() const {
        return numerator;
    }

    int Denominator() const {
        return  denominator;
    }

private:
    int numerator;
    int denominator;
};

bool operator==(const Rational& lhs, const Rational& rhs) {
    return (lhs.Numerator() == rhs.Numerator()) && (lhs.Denominator() == rhs.Denominator());
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
    return {lhs.Numerator() * rhs.Numerator(),
            lhs.Denominator() * rhs.Denominator()};
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
    if (rhs.Numerator() == 0) {
        throw domain_error("Division by zero");
    }
    return {lhs.Numerator() * rhs.Denominator(),
            lhs.Denominator() * rhs.Numerator()};
}

ostream& operator<<(ostream& stream, const Rational& rational) {
    stream << rational.Numerator() << '/' << rational.Denominator();
    return stream;
}

istream& operator>>(istream& stream, Rational& rational) {
    int n = 0;
    int d = 0;
    char delim;

    if (stream) {
        stream >> n >> delim >> d;
        if (stream && delim == '/') {
            rational = Rational(n, d);
        }
    }
    return stream;
}

int main() {
    try {
        char operation;
        Rational l, r;
        cin >> l;
        cin.ignore(1);
        cin >> operation;
        cin.ignore(1);
        cin >> r;
        if (operation == '+') {
            cout << (l + r);
        } else if (operation == '-') {
            cout << (l -r);
        } else if (operation == '*') {
            cout << (l * r);
        } else if (operation == '/') {
            cout << (l / r);
        }
    } catch (exception& ex)  {
        cout << ex.what();
    }
    return 0;
}

