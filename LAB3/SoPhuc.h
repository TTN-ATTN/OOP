#ifndef SOPHUC_H
#define SOPHUC_H
#include <bits/stdc++.h>
class SoPhuc {
private:
    double dThuc;
    double dAo;

public:
    /**
     * Default constructor initializing the complex number to 0 + 0i.
     */
    SoPhuc();

    /**
     * Constructor initializing the complex number to the given real and imaginary parts.
     * @param thuc Real part of the complex number.
     * @param ao Imaginary part of the complex number.
     */
    SoPhuc(double thuc, double ao);

    /**
     * Overloaded addition operator for complex numbers.
     * @param sp Another complex number to add.
     * @return The sum of the two complex numbers.
     */
    SoPhuc operator +(const SoPhuc& sp) const;

    /**
     * Overloaded subtraction operator for complex numbers.
     * @param sp Another complex number to subtract.
     * @return The difference of the two complex numbers.
     */
    SoPhuc operator -(const SoPhuc& sp) const;

    /**
     * Overloaded multiplication operator for complex numbers.
     * @param sp Another complex number to multiply.
     * @return The product of the two complex numbers.
     */
    SoPhuc operator *(const SoPhuc& sp) const;

    /**
     * Overloaded division operator for complex numbers.
     * @param sp Another complex number to divide.
     * @return The quotient of the two complex numbers.
     * @throws std::invalid_argument if the divisor is zero.
     */
    SoPhuc operator /(const SoPhuc& sp) const;

    /**
     * Overloaded equality operator for complex numbers.
     * @param sp Another complex number to compare.
     * @return True if the two complex numbers are equal, false otherwise.
     */
    bool operator ==(const SoPhuc& sp) const;

    /**
     * Overloaded inequality operator for complex numbers.
     * @param sp Another complex number to compare.
     * @return True if the two complex numbers are not equal, false otherwise.
     */
    bool operator !=(const SoPhuc& sp) const;

/**
     * Overloaded input operator for complex numbers.
     * @param is Input stream.
     * @param sp Complex number to input.
     * @return Reference to the input stream.
     */
    friend std::istream& operator >>(std::istream& is, SoPhuc& sp);

 /**
     * Overloaded output operator for complex numbers.
     * @param os Output stream.
     * @param sp Complex number to output.
     * @return Reference to the output stream.
     */
    friend std::ostream& operator <<(std::ostream& os, const SoPhuc& sp);
};

#endif // SOPHUC_H