#include<bits/stdc++.h>
using namespace std;

/**
 * @brief Reads a list of fractions from the user.
 *
 * Prompts the user to enter the number of fractions, then for each fraction,
 * prompts for the numerator and denominator. Ensures the denominator is not zero.
 *
 * @return A vector of pairs, where each pair represents a fraction (numerator, denominator).
 */
vector<pair<int,int>> input() {
    int n;
    cout << "Number of fractions: ";
    cin >> n;
    vector<pair<int,int>> fractions(n);
    for(int i=0; i<n; i++) {
        int a, b;
        cout <<"\nNumerator of fraction " << i + 1 << ": ";
        cin >> a;
        cout << "Denominator of fraction " << i + 1 << ": ";
        cin >>  b;
        while(b == 0) {
            cout << "Denominator cannot be zero! Try different denominator: ";
            cin >> b;
        }
        fractions[i] = {a ,b};
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
void print(pair<int,int> p) {
    if(p.second < 0) {
        p.first = -p.first;
        p.second = -p.second;
    }
    cout << p.first << "/" << p.second << endl;
}

int main() {
    vector<pair<int,int>> fractions = input();
    sort(fractions.begin(), fractions.end(), [](pair<int,int>&a, pair<int,int>&b) {
        int num = a.first * b.second - b.first * a.second;
        int den = a.second * b.second;
        return num * den < 0;
    });

    cout << "Smallest fraction: ";
    print(fractions[0]);
    cout << "Largest fraction: ";
    print(fractions[fractions.size() - 1]);
    return 0;
}