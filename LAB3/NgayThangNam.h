#ifndef NGAYTHANGNAM_H
#define NGAYTHANGNAM_H
#include <bits/stdc++.h>
using namespace std;

/**
 * \class NgayThangNam
 * \brief A class to represent a date with day, month, and year.
 */
class NgayThangNam {
private:
    int iNgay;
    int iThang;
    int iNam;

    /**
     * \brief Checks if a year is a leap year.
     * \param year The year to check
     * \return True if leap year, otherwise false
     */
    bool is_leap_year(int year) const;

    /**
     * \brief Gets the number of days in a given month of a given year.
     * \param month The month
     * \param year The year
     * \return Number of days in the month
     */
    int days_in_month(int month, int year) const;

public:
    /**
     * \brief Default constructor initializing date to 01/01/0001.
     */
    NgayThangNam();

    /**
     * \brief Parameterized constructor to initialize date.
     * \param nam Year
     * \param thang Month
     * \param ngay Day
     */
    NgayThangNam(int nam, int thang, int ngay);

    /**
     * \brief Converts the date to the total number of days since 01/01/0001.
     * \return Total number of days
     */
    int date_to_days() const;

    /**
     * \brief Converts the total number of days since 01/01/0001 to a date.
     * \param total_days Total number of days
     */
    void days_to_date(int total_days);

    /**
     * \brief Adds a number of days to the date.
     * \param ngay Number of days to add
     * \return A new NgayThangNam object representing the new date
     */
    NgayThangNam operator +(int ngay) const;

    /**
     * \brief Subtracts a number of days from the date.
     * \param ngay Number of days to subtract
     * \return A new NgayThangNam object representing the new date
     */
    NgayThangNam operator -(int ngay) const;

    /**
     * \brief Calculates the difference in days between two dates.
     * \param nt Another NgayThangNam object
     * \return Number of days between the two dates
     */
    int operator -(const NgayThangNam& nt) const;

    /**
     * \brief Prefix increment operator.
     * \return Reference to the incremented NgayThangNam object
     */
    NgayThangNam& operator ++();

    /**
     * \brief Prefix decrement operator.
     * \return Reference to the decremented NgayThangNam object
     */
    NgayThangNam& operator --();

    /**
     * \brief Checks if two NgayThangNam objects are equal.
     * \param nt Another NgayThangNam object
     * \return True if equal, otherwise false
     */
    bool operator ==(const NgayThangNam& nt) const;

    /**
     * \brief Checks if two NgayThangNam objects are not equal.
     * \param nt Another NgayThangNam object
     * \return True if not equal, otherwise false
     */
    bool operator !=(const NgayThangNam& nt) const;

    /**
     * \brief Checks if this NgayThangNam object is greater than or equal to another.
     * \param nt Another NgayThangNam object
     * \return True if greater than or equal, otherwise false
     */
    bool operator >=(const NgayThangNam& nt) const;

    /**
     * \brief Checks if this NgayThangNam object is less than or equal to another.
     * \param nt Another NgayThangNam object
     * \return True if less than or equal, otherwise false
     */
    bool operator <=(const NgayThangNam& nt) const;

    /**
     * \brief Checks if this NgayThangNam object is greater than another.
     * \param nt Another NgayThangNam object
     * \return True if greater, otherwise false
     */
    bool operator >(const NgayThangNam& nt) const;

    /**
     * \brief Checks if this NgayThangNam object is less than another.
     * \param nt Another NgayThangNam object
     * \return True if less, otherwise false
     */
    bool operator <(const NgayThangNam& nt) const;

    /**
     * \brief Input stream operator to read NgayThangNam object.
     * \param is Input stream
     * \param nt NgayThangNam object to read into
     * \return Reference to the input stream
     */
    friend istream& operator >>(istream& is, NgayThangNam& nt);

    /**
     * \brief Output stream operator to write NgayThangNam object.
     * \param os Output stream
     * \param nt NgayThangNam object to write
     * \return Reference to the output stream
     */
    friend ostream& operator <<(ostream& os, const NgayThangNam& nt);
};

#endif // NGAYTHANGNAM_H