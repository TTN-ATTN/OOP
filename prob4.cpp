#include <bits/stdc++.h>
using namespace std;

const float pi = M_PI;

/**
 * Calculate sine of an angle using the series expansion formula.
 * Input: double x - angle in radians.
 * Output: double - sine of the angle x.
 */
long double Sin(long double x) {
    long double res = x;
    long double t = x;
    int n = 1;

    while (fabs(t) > 0.00001) {
        t *= -x * x / ((2 * n) * (2 * n + 1));
        res += t;
        ++n;
    }

    return res;
}

int main() {
    long double x;
    cout << "Enter angle in radians: ";
    cin >> x;
    long double reduced_x = fmod(abs(x), 2 * pi);
    long double res = Sin(reduced_x);
    cout << "Sin(" << x << ") = " << ((x > 0) ? res : -res) << endl;
    return 0;
}