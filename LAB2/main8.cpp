#include <iostream>
#include "List.h"

using namespace std;

int main() {
    List list;
    int n;
    while (true) {
        cin >> n;
        if (n == -1) {
            break;
        } else if (n == 0) {
            double x;
            cin >> x;
            list.add(x);
        } else if (n == 1) {
            double x;
            cin >> x;
            list.removeFirst(x);
        } else if (n == 2) {
            double x;
            cin >> x;
            list.removeAll(x);
        } else if (n == 3) {
            int x;
            double y;
            cin >> x >> y;
            list.replace(x, y);
        }
    }
    list.print();
    return 0;
}