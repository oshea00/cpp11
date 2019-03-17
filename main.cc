//
//  main.cpp
//  hellocpp
//
//  Created by mike oshea on 3/4/19.
//  Copyright © 2019 Future Trends. All rights reserved.
//

#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <list>
#include <forward_list>
#include <string>
#include <fstream>
#include <cctype>
#include <algorithm>
#include <numeric>
#include "linkedlist.h"
#include "animal.h"

#define DELIM(s,v,d) ((s!=v.cend()-1) ? d : "")

using namespace std;

void test();
void testGetFile(int argc, char *argv[]);
void getFile(string,vector<string>&);
void ostringstreamPlay();
void containers();
void chopstring();
void testparens();
bool parensmatch(string);
bool matched(char,char);
void stringalgos();
int replacetoken(string &temp, const string &tok, const string &with);
void algorithms();
void dumpints(vector<int>&);
void dumpstrs(vector<string>&);
void dumpaints(int **a, int len);
bool isShorter(const string &s1, const string &s2);
void animalplay();

template <typename T>
void dump(T &col) {
    cout << "[";
    for (auto i = col.cbegin(); i != col.cend(); ++i) {
        cout << *i << DELIM(i,col,",");
    }
    cout << "]";
    cout << endl;
}

int main(int argc, char *argv[]) {
    test();
    testGetFile(argc, argv);
    ostringstreamPlay();
    containers();
    chopstring();
    testparens();
    stringalgos();
    algorithms();
    animalplay();
    cout << "All done!\n";
    return 0;
}

void testparens() {
    if (parensmatch("[]{}({[]})")) {
        cout << "Well Formed!" << endl;
    } else {
        cout << "Not!" << endl;
    }
}

void ostringstreamPlay() {
    ostringstream formatted;
    vector<string> strings{"mike","jim","steve"};
    for (auto name : strings) {
        name[0] = toupper(name[0]);
        formatted << name << " ";
    }
    cout << formatted.str() << endl;
}

void testGetFile(int argc, char *argv[]) {
    vector<string> lines;
    if (argc > 1) {
        getFile(argv[1],lines);
        for (auto line : lines) {
            cout << line << endl;
        }
    }
}

void getFile(string fileName, vector<string> &lines) {
    int lineCount=0;
    string line;
    cout << "File: " << fileName << endl;
    ifstream in(fileName);
    if (in) {
        while (getline(in,line)) {
            lines.push_back(line);
            lineCount++;
        }
        in.close();
        cout << "[Lines: " << lineCount << "]" << endl;
    } else {
        cout << "Error opening: " << fileName << endl;
    }
}

void test() {
    LinkedList a;
    a.push(10);
    a.push(20);
    a.push(15);
    a.push(2);
    cout << a << " Length = " << a.size() << endl;
    a.pop();
    cout << a << " Length = " << a.size() << endl;
}

void containers() {
    // Vectors
    ostringstream line;
    vector<int> ints {1,2,3,4,5,6,7,8,9,10};
    // linked list (double linked)
    list<int> copyints(ints.begin()+2,ints.end());
    // linked list (single)
    forward_list<int> singlelink(copyints.begin(),copyints.end());
    vector<int> revlist;
    vector<int> subs {4,5,6};
    vector<int> copylist;
    copylist.assign(copyints.begin(),copyints.end());
    // reverse iterator
    dump(copylist);
    reverse_copy(copylist.begin(), copylist.end(),back_inserter(revlist));
    dump(revlist);
    cout << line.str();
    // deque
    deque<string> facecards{"King","Queen","Jack"};
    while (!facecards.empty()) {
        cout << facecards.back() << endl;
        facecards.pop_back();
    }
    cout << endl;
    while (!singlelink.empty()) {
        cout << singlelink.front() << " ";
        singlelink.pop_front();
    }
    cout << endl;
    // insert
    ints.insert(ints.begin()+2,subs.begin(),subs.end());
    dump(ints);
}

void chopstring() {
    string src = "Hello World";
    for (auto i : src) {
        cout << i;
    }
    cout << endl;
    cout << src.substr(6,100) << endl; // smart count
}

bool matched(char s, char e) {
    if (s=='(' and e == ')')
        return true;
    if (s=='[' and e == ']')
        return true;
    if (s=='{' and e == '}')
        return true;
    return false;
}

bool parensmatch(string e) {
    stack<char> d;
    for (auto c : e) {
        if (c == '{' || c == '[' || c == '(')
            d.push(c);
        if (c == '}' || c == ']' || c == ')') {
            if (!d.empty()) {
                auto m = d.top();
                d.pop();
                if (!matched(m, c))
                    return false;
            } else {
                return false;
            }
        }
    }
    if (d.empty())
        return true;
    return false;
}

int replacetoken(string &temp, const string &tok, const string &with) {
    int count = 0;
    string::size_type i = 0, toklen(tok.size()), withlen(with.size());
    while ((i = temp.find(tok,i)) != string::npos) {
        temp.replace(i, toklen, with);
        ++count;
        i += withlen;
    }
    return count;
}

void stringalgos() {
    string temp("My name is @boo. People call me @boo. My friends call me @booier.");
    int count = replacetoken(temp, "@boo", "MICHAEL");
    cout << "Found " << count << " times." << endl;
    cout << temp << endl;
    
}

void dump(int a[], int len) {
    cout << "[";
    for (int i = 0; i<len; i++) {
        cout << a[i] << ((i<len-1) ? "," : "");
    }
    cout << "]";
    cout << endl;
}

void algorithms() {
    vector<int> ints{1,1,2,3,5,8,13,21,54};
    list<double> dbls{3.141,2.372,1.141,42};
    vector<string> str = {"hello","there","good","fellow"};
    cout << accumulate(dbls.cbegin(),dbls.cend(),0.00) << endl; // sum doubles
    cout << accumulate(dbls.cbegin(),dbls.cend(),0) << endl; // sum as int
    cout << accumulate(str.cbegin(),str.cend(),string("")) << endl;
    int a1[] = {0,1,2,3,4,5,6,7,8,9};
    int a2[sizeof(a1)/sizeof(*a1)];
    
    copy(begin(a1),end(a1),a2);
    dump(a2,sizeof(a2)/sizeof(*a2));
    dump(ints);
    dump(str);
    vector<int> repl;
    replace_copy(ints.cbegin(),ints.cend(),back_inserter(repl),1,100);
    dump(repl);
    replace(repl.begin(),repl.end(),100,42);
    dump(repl);
    
    // sorting, removing dupes
    sort(repl.begin(),repl.end());
    dump(repl);
    auto end_unique = unique(repl.begin(), repl.end());
    repl.erase(end_unique,repl.end());
    dump(repl);
    
    // custom sorting with predicate function
    sort(str.begin(),str.end(), isShorter);
    dump(str);
    
    // custom sorting using lambda
    sort(str.begin(), str.end(), [] (const string &a, const string &b) {
        return a.size() > b.size();
    });
    dump(str);
    
    // search for first word of length 4
    int len(4);
    auto found = find_if(str.begin(), str.end(), [len] (const string &in) {
        return in.size() == len;
    });
    cout << *found << endl;
    
    // for-each
    len = 5;
    for_each(str.begin(), str.end(), [len](const string& in){
        if (in.size() == len) {
            cout << in << " ";
        }
    });
    cout << endl;
}

bool isShorter(const string &s1, const string &s2) {
    return s1.size() < s2.size();
}
void animalplay() {
    vector<shared_ptr<Animal>> animals = {
        make_shared<Animal>(),
        make_shared<Dog>(),
        make_shared<BigDog>(),
        make_shared<BigDog>("ARRGHH! WOOF!")
    };
    cout << "Dogs are animals:" << endl;
    for (auto a : animals) {
        a->says();
    }
    Animal animal = *animals[2];
    animal.says();
    cout << "Animals created: " << Animal::animals_created << endl;
}
