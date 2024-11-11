#ifndef PHANSO_H
#define PHANSO_H
#include <bits/stdc++.h>

class PhanSo {
private:
    int iTu;
    int iMau;

public:
    /**
     * Default constructor initializing the fraction to 0/1.
     */
    PhanSo();

    /**
     * Constructor initializing the fraction to the given numerator and denominator.
     * @param Tu Numerator of the fraction.
     * @param Mau Denominator of the fraction.
     * @throws std::invalid_argument if the denominator is zero.
     */
    PhanSo(int Tu, int Mau);

    /**
     * Reduces the fraction to its simplest form.
     */
    void rut_gon();

    /**
     * Overloaded addition operator for fractions.
     * @param ps Another fraction to add.
     * @return The sum of the two fractions.
     */
    PhanSo operator +(PhanSo ps);

    /**
     * Overloaded subtraction operator for fractions.
     * @param ps Another fraction to subtract.
     * @return The difference of the two fractions.
     */
    PhanSo operator -(PhanSo ps);

    /**
     * Overloaded multiplication operator for fractions.
     * @param ps Another fraction to multiply.
     * @return The product of the two fractions.
     */
    PhanSo operator *(PhanSo ps);

    /**
     * Overloaded division operator for fractions.
     * @param ps Another fraction to divide.
     * @return The quotient of the two fractions.
     * @throws std::invalid_argument if the numerator of the divisor is zero.
     */
    PhanSo operator /(PhanSo ps);

    /**
     * Overloaded equality operator for fractions.
     * @param ps Another fraction to compare.
     * @return True if the two fractions are equal, false otherwise.
     */
    bool operator ==(PhanSo ps);

    /**
     * Overloaded inequality operator for fractions.
     * @param ps Another fraction to compare.
     * @return True if the two fractions are not equal, false otherwise.
     */
    bool operator !=(PhanSo ps);

    /**
     * Overloaded greater than operator for fractions.
     * @param ps Another fraction to compare.
     * @return True if this fraction is greater than the other, false otherwise.
     */
    bool operator >(PhanSo ps);

    /**
     * Overloaded greater than or equal to operator for fractions.
     * @param ps Another fraction to compare.
     * @return True if this fraction is greater than or equal to the other, false otherwise.
     */
    bool operator >=(PhanSo ps);

    /**
     * Overloaded less than operator for fractions.
     * @param ps Another fraction to compare.
     * @return True if this fraction is less than the other, false otherwise.
     */
    bool operator <(PhanSo ps);

    /**
     * Overloaded less than or equal to operator for fractions.
     * @param ps Another fraction to compare.
     * @return True if this fraction is less than or equal to the other, false otherwise.
     */
    bool operator <=(PhanSo ps);

     /**
     * Overloaded input operator to read a fraction from the input stream.
     * @param is Input stream.
     * @param ps Fraction to read.
     * @return Reference to the input stream.
     */
    friend std::istream& operator >>(std::istream &is, PhanSo &ps);

     /**
     * Overloaded output operator to write a fraction to the output stream.
     * @param os Output stream.
     * @param ps Fraction to write.
     * @return Reference to the output stream.
     */
    friend std::ostream& operator <<(std::ostream &os, PhanSo &ps);
};

#endif // PHANSO_H