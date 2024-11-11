#ifndef THOIGIAN_H
#define THOIGIAN_H

#include <iostream>

class ThoiGian {
private:
    int iGio;
    int iPhut;
    int iGiay;

public:
    /**
     * \brief Default constructor initializing time to 00:00:00.
     */
    ThoiGian();

    /**
     * \brief Parameterized constructor to initialize time.
     * \param h Hours
     * \param m Minutes
     * \param s Seconds
     */
    ThoiGian(int h, int m, int s);

    /**
     * \brief Adds two ThoiGian objects.
     * \param tg Another ThoiGian object
     * \return A new ThoiGian object representing the sum
     */
    ThoiGian operator +(const ThoiGian& tg) const;

    /**
     * \brief Subtracts one ThoiGian object from another.
     * \param tg Another ThoiGian object
     * \return A new ThoiGian object representing the difference
     */
    ThoiGian operator -(const ThoiGian& tg) const;

    /**
     * \brief Adds seconds to the ThoiGian object.
     * \param seconds Number of seconds to add
     * \return A new ThoiGian object representing the new time
     */
    ThoiGian operator +(int seconds) const;

    /**
     * \brief Subtracts seconds from the ThoiGian object.
     * \param seconds Number of seconds to subtract
     * \return A new ThoiGian object representing the new time
     */
    ThoiGian operator -(int seconds) const;

    /**
     * \brief Checks if two ThoiGian objects are equal.
     * \param tg Another ThoiGian object
     * \return True if equal, otherwise false
     */
    bool operator ==(const ThoiGian& tg) const;

    /**
     * \brief Checks if two ThoiGian objects are not equal.
     * \param tg Another ThoiGian object
     * \return True if not equal, otherwise false
     */
    bool operator !=(const ThoiGian& tg) const;

    /**
     * \brief Checks if this ThoiGian object is greater than another.
     * \param tg Another ThoiGian object
     * \return True if greater, otherwise false
     */
    bool operator >(const ThoiGian& tg) const;

    /**
     * \brief Checks if this ThoiGian object is greater than or equal to another.
     * \param tg Another ThoiGian object
     * \return True if greater than or equal, otherwise false
     */
    bool operator >=(const ThoiGian& tg) const;

    /**
     * \brief Checks if this ThoiGian object is less than another.
     * \param tg Another ThoiGian object
     * \return True if less, otherwise false
     */
    bool operator <(const ThoiGian& tg) const;

    /**
     * \brief Checks if this ThoiGian object is less than or equal to another.
     * \param tg Another ThoiGian object
     * \return True if less than or equal, otherwise false
     */
    bool operator <=(const ThoiGian& tg) const;

    /**
     * \brief Prefix increment operator.
     * \return Reference to the incremented ThoiGian object
     */
    ThoiGian& operator ++();

    /**
     * \brief Postfix increment operator.
     * \return A copy of the ThoiGian object before increment
     */
    ThoiGian operator ++(int);

    /**
     * \brief Prefix decrement operator.
     * \return Reference to the decremented ThoiGian object
     */
    ThoiGian& operator --();

    /**
     * \brief Postfix decrement operator.
     * \return A copy of the ThoiGian object before decrement
     */
    ThoiGian operator --(int);

    /**
     * \brief Input stream operator to read ThoiGian object.
     * \param is Input stream
     * \param tg ThoiGian object to read into
     * \return Reference to the input stream
     */
    friend std::istream& operator >>(std::istream& is, ThoiGian& tg);

    /**
     * \brief Output stream operator to write ThoiGian object.
     * \param os Output stream
     * \param tg ThoiGian object to write
     * \return Reference to the output stream
     */
    friend std::ostream& operator <<(std::ostream& os, const ThoiGian& tg);
};

#endif // THOIGIAN_H