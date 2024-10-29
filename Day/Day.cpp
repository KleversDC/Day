#include <iostream>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

    bool isLeapYear(int year) const {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    int daysInMonth(int month, int year) const {
        if (month == 2) {
            return isLeapYear(year) ? 29 : 28;
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11) {
            return 30;
        }
        else {
            return 31;
        }
    }

public:
    Date(int d = 1, int m = 1, int y = 2000) : day(d), month(m), year(y) {}

    void addDay() {
        day++;
        if (day > daysInMonth(month, year)) {
            day = 1;
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        }
    }

    Date& operator++() {
        addDay();
        return *this;
    }

    Date operator++(int) {
        Date temp = *this;
        addDay();
        return temp;
    }

    Date& operator--() {
        day--;
        if (day < 1) {
            month--;
            if (month < 1) {
                month = 12;
                year--;
            }
            day = daysInMonth(month, year);
        }
        return *this;
    }

    Date operator--(int) {
        Date temp = *this;
        --(*this);
        return temp;
    }

    bool operator==(const Date& other) const {
        return day == other.day && month == other.month && year == other.year;
    }

    bool operator!=(const Date& other) const {
        return !(*this == other);
    }

    bool operator>(const Date& other) const {
        if (year > other.year) return true;
        if (year == other.year && month > other.month) return true;
        return year == other.year && month == other.month && day > other.day;
    }

    bool operator<(const Date& other) const {
        return !(*this > other) && *this != other;
    }

    Date& operator=(const Date& other) {
        if (this != &other) {
            day = other.day;
            month = other.month;
            year = other.year;
        }
        return *this;
    }

    Date& operator+=(int days) {
        for (int i = 0; i < days; i++) {
            addDay();
        }
        return *this;
    }

    Date& operator-=(int days) {
        for (int i = 0; i < days; i++) {
            --(*this);
        }
        return *this;
    }

    void operator()(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
    }

    friend ostream& operator<<(ostream& os, const Date& date) {
        os << date.day << "/" << date.month << "/" << date.year;
        return os;
    }

    friend istream& operator>>(istream& is, Date& date) {
        cout << "Enter day: ";
        is >> date.day;
        cout << "Enter month: ";
        is >> date.month;
        cout << "Enter year: ";
        is >> date.year;
        return is;
    }
};

int main() {
    Date date1(28, 2, 2020);
    Date date2;

    cout << "Initial date1: " << date1 << endl;
    ++date1;
    cout << "After increment: " << date1 << endl;

    date1 += 5;
    cout << "After adding 5 days: " << date1 << endl;

    date2(15, 8, 2022);

}
