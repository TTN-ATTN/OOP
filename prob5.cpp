#include <iostream>
using namespace std;

/**
 * Date structure with day, month, year.
 */
struct Date {
    int day = 1;
    int month = 1;
    int year = 2000;
};

/**
 * Checks if a year is a leap year.
 * Input: year - integer
 * Output: true if the year is a leap year, false otherwise
 */
bool leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

/**
 * Returns the number of days in a given month of a given year.
 * Input: month, year - integers
 * Output: number of days in the month
 */
int num_day_month(int month, int year) {
    if (month == 2) {
        return leap_year(year) ? 29 : 28;
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    return 31;
}

/**
 * Encodes the Date to the number of days since 01/01/0001.
 * Input: Date object
 * Output: number of days since 01/01/0001
 */
int encode_to_days(const Date& date) {
    int days = 0;
    for (int y = 1; y < date.year; ++y) {
        days += leap_year(y) ? 366 : 365;
    }
    for (int m = 1; m < date.month; ++m) {
        days += num_day_month(m, date.year);
    }
    days += date.day - 1;
    return days;
}

/**
 * Decodes the number of days since 01/01/0001 to a Date.
 * Input: days - integer, date - Date object
 * Output: None
 */
void decode_to_date(int days, Date& date) {
    date.year = 1;

    int day_num;
    while (true) {
        day_num = leap_year(date.year) ? 366 : 365;
        if (days < day_num) {
            break;
        }
        days -= day_num;
        ++date.year;
    }

    date.month = 1;
    while (true) {
        int num_days_in_month = num_day_month(date.month, date.year);
        if (days < num_days_in_month) {
            break;
        }
        days -= num_days_in_month;
        ++date.month;
    }

    date.day = days + 1;
}

/**
 * Formats a number to a string with leading zero if less than 10.
 * Input: n - integer
 * Output: formatted string
 */
string format(int n) {
    return n < 10 ? "0" : "";
}

/**
 * Prints the date in the format dd/mm/yyyy.
 * Input: date - Date object
 * Output: Displays the date
 */
void print(const Date& date) {
    cout << format(date.day) << date.day << "/" << format(date.month) << date.month << "/" << date.year << endl;
}

/**
 * Finds the date of yesterday.
 * Input: date - Date object
 * Output: Date object for yesterday
 */
Date yesterday(const Date& date) {
    int days = encode_to_days(date) - 1;
    Date yesterday;
    decode_to_date(days, yesterday);
    return yesterday;
}

/**
 * Finds the date of tomorrow.
 * Input: date - Date object
 * Output: Date object for tomorrow
 */
Date tomorrow(const Date& date) {
    int days = encode_to_days(date) + 1;
    Date tomorrow;
    decode_to_date(days, tomorrow);
    return tomorrow;
}

/**
 * Calculates the day number in the year.
 * Input: date - Date object
 * Output: day number in the year
 */
int day_in_year(const Date& date) {
    int days = 0;
    for (int m = 1; m < date.month; ++m) {
        days += num_day_month(m, date.year);
    }
    days += date.day;
    return days;
}

/**
 * Checks if the given date is invalid.
 * Input: day, month, year - integers
 * Output: true if the date is invalid, false otherwise
 */
bool invalid(int day, int month, int year) {
    if (day < 1 || month < 1 || month > 12 || year < 1) {
        return true;
    }
    if (month == 2) {
        return day > (leap_year(year) ? 29 : 28);
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return day > 30;
    }
    return day > 31;
}

/**
 * Reads input date from the user.
 * Input: None
 * Output: Date object
 */
Date input() {
    int day, month, year;

    cout << "Enter day: ";
    cin >> day;
    cout << "Enter month: ";
    cin >> month;
    cout << "Enter year: ";
    cin >> year;

    while(invalid(day, month, year)) {
        cout << "Invalid date! Please enter again." << endl;
        cout << "Enter day: ";
        cin >> day;
        cout << "Enter month: ";
        cin >> month;
        cout << "Enter year: ";
        cin >> year;
    }

    Date date;
    date.day = day;
    date.month = month;
    date.year = year;
    return date;
}

int main() {
    const Date date = input();
    cout << "Today: ";
    print(date);

    cout << "Yesterday: ";
    print(yesterday(date));

    cout << "Tomorrow: ";
    print(tomorrow(date));

    cout << "Day in year: " << day_in_year(date) << endl;

    return 0;
}