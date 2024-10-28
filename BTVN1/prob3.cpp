#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Reads a list of fractions from the user.
 *
 * Prompts the user to enter the number of fractions, then for each fraction,
 * prompts for the numerator and denominator. Ensures the denominator is not zero.
 *
 * @return A vector of pairs, where each pair represents a fraction (numerator, denominator).
 */
vector<pair<int, int>> input() {
    int n;
    cout << "Number of fractions: ";
    cin >> n;
    vector<pair<int, int>> fractions(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cout << "\nNumerator of fraction " << i + 1 << ": ";
        cin >> a;
        cout << "Denominator of fraction " << i + 1 << ": ";
        cin >> b;
        while (b == 0) {
            cout << "Denominator cannot be zero! Try different denominator: ";
            cin >> b;
        }
        fractions[i] = {a, b};
    }
    return fractions;
}

/**
 * @brief Prints a fraction in the form "numerator/denominator".
 *
 * If the denominator is negative, the signs of both the numerator and denominator
 * are inverted to keep the denominator positive.
 *
 * @param p A pair representing a fraction (numerator, denominator).
 */
void print(pair<int, int> p) {
    if (p.second < 0) {
        p.first = -p.first;
        p.second = -p.second;
    }
    cout << p.first << "/" << p.second << endl;
}

/**
 * @brief Reduces a fraction to its simplest form.
 *
 * Uses the greatest common divisor (GCD) to reduce the fraction.
 *
 * @param num The numerator of the fraction.
 * @param den The denominator of the fraction.
 * @return A pair representing the reduced fraction (numerator, denominator).
 */
pair<int, int> reduce(int num, int den) {
    int gcd = __gcd(num, den);
    return {num / gcd, den / gcd};
}

/**
 * @brief Solves for a combination of fractions that multiply to a target fraction.
 *
 * Recursively tries different combinations of fractions to find a product that matches
 * the target fraction.
 *
 * @param fractions The list of fractions to consider.
 * @param idx The current index in the list of fractions.
 * @param num The current numerator of the product.
 * @param den The current denominator of the product.
 * @param target_num The target numerator.
 * @param target_den The target denominator.
 * @param result The list of fractions that form the product.
 * @return True if a combination is found, false otherwise.
 */
bool solve(vector<pair<int, int>>& fractions, int idx, int num, int den, int target_num, int target_den, vector<pair<int, int>>& result) {
    auto [reduced_num, reduced_den] = reduce(num, den);
    auto [reduced_tnum, reduced_tden] = reduce(target_num, target_den);

    if (reduced_num == reduced_tnum && reduced_den == reduced_tden) {
        return true;
    }

    if (idx == fractions.size()) {
        return false;
    }

    for (int i = idx; i < fractions.size(); i++) {
        int new_num = num * fractions[i].first;
        int new_den = den * fractions[i].second;

        result.push_back(fractions[i]);

        if (solve(fractions, i + 1, new_num, new_den, target_num, target_den, result)) {
            return true;
        }

        result.pop_back();
    }
    return false;
}

int main() {
    vector<pair<int, int>> fractions = input();
    int target_num, target_den;
    cout << "\nEnter target numerator: ";
    cin >> target_num;
    cout << "Enter target denominator: ";
    cin >> target_den;
    while (target_den == 0) {
        cout << "Denominator cannot be zero! Try different denominator: ";
        cin >> target_den;
    }

    vector<pair<int, int>> result;
    if (solve(fractions, 0, 1, 1, target_num, target_den, result)) {
        sort(result.begin(), result.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.first * b.second < b.first * a.second;
        });
        cout << "Result: " << endl;
        for (auto& frac : result) {
            print(frac);
        }
    } else {
        cout << "Not found!" << endl;
    }

    return 0;
}