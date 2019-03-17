//
//  linkedlist.h
//  hellocpp
//
//  Created by mike oshea on 3/7/19.
//  Copyright © 2019 Future Trends. All rights reserved.
//

#ifndef linkedlist_h
#define linkedlist_h

#include <iostream>
#include <sstream>

struct Node {
    unsigned value;
    Node *next;
    Node() : value(0), next(nullptr) {}
};

class LinkedList {
    friend std::ostream& operator<<(std::ostream& os,const LinkedList& rval);
    Node head;
    int count;
public:
    void push(int);
    int pop();
    std::string toString() const;
    int size() const { return count; }
    ~LinkedList() {
        while (count > 0) {
            pop();
        }
    }
};

void LinkedList::push(int v) {
    Node *n = new Node;
    n->value = v;
    n->next = head.next;
    head.next = n;
    count += 1;
}

int LinkedList::pop() {
    int topVal = -1;
    if (head.next != nullptr) {
        Node *curr = head.next;
        topVal = curr->value;
        head.next = curr->next;
        delete curr;
        count -= 1;
    }
    return topVal;
}

std::string LinkedList::toString() const {
    std::stringstream ss;
    ss << "[";
    Node *curr = head.next;
    while (curr != nullptr) {
        ss << curr->value << ((curr->next != nullptr) ? "," : "");
        curr = curr->next;
    }
    ss << "]";
    return ss.str();
}

std::ostream& operator<<(std::ostream& os,const LinkedList& rval) {
    os << rval.toString();
    return os;
}

#endif /* linkedlist_h */
