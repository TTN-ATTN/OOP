#include<bits/stdc++.h>
using namespace std;


/** Get input for the vector
 * Input: integer n - size of the vector
 * Output: a vector - vector of integers
 */
vector<int>input(int n) {
    vector<int> input(n);
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        input[i] = t;
    }
    return input;
}

/** Storing the starting indexes of the appearance of vector A in vector B.
 * Input: vector A, vector B
 * Output: vector indexes - starting indexes of appearance
 */
vector<int> count_appearance(const vector<int>&a, const vector<int>&b) {
    vector<int> indexes;
    int sub_end = a.size();
    for(int i = 0 ; i < b.size() ; i++) {
        if(b[i] == a[0]) {
            bool found = true;
            if(sub_end > 1)
                for(int j = 1; j < sub_end; j++) {
                    if(b[i+j] != a[j]) {
                        found = false;
                        break;
                    }
                }
            if(found) {
                indexes.push_back(i);
            }
        }
    }
    return indexes;
}

int main() {
    int n1, n2;
    cout << "Size of array A and B, respectively:  ";
    cin >> n1 >> n2;
    vector<int>a = input(n1);
    vector<int>b = input(n2);

    vector<int> indexes = count_appearance(a,b);
    cout << "Number of appearance: " << indexes.size() << endl;
    cout << "Starting indexes:  ";
    for(const int index: indexes)
        cout << index << " ";

    return 0;
}