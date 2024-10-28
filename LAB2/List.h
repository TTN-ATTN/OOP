#ifndef LIST_H
#define LIST_H

struct Node {
    double data;
    Node* next;

    Node(double data) : data(data), next(nullptr) {}
};

class List {
private:
    Node* head;

public:
    List();
    ~List();

    void add(double x);
    void removeFirst(double x);
    void removeAll(double x);
    void replace(int index, double y);
    void print() const;
};

#endif // LIST_H