#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
using namespace std;

vector<int>first_func(vector<int> v) {
    nth_element(v.begin(), v.begin() + 5, v.end());
    return v;
}

list<int>second_func(list<int> l) {
    rotate(l.begin(), max_element(l.begin(), l.end()), l.end());
    return l;
}

vector<int>third_func(vector<int> v) {
    make_heap(v.begin(), v.end());
    return v;
}

int fourth_func(list<int> l1, list<int> l2) {
    int s = 0;
    list<int>::iterator iter1 = l1.begin();
    list<int>::iterator iter2 = l2.begin();
    while (iter1 != l1.end()){
        s += *iter1 * *iter2;
        iter1++;
        iter2++;
    }

    return s;
}

int fiveth_func(string str) {
    set<char> s(begin(str), end(str));
    return s.size();
}

int main()
{

    //Задача 1
    vector<int> v = { 1, 2, 10, 6, 10, 8, 3, 5, 7, 14 };
    cout << "Task 1: " << endl;
    cout << "Initial vector: ";
    for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++) {
        cout << *iter << ' ';
    }
    cout << endl;

    v = first_func(v);

    cout << "Changed vector: ";

    for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++) {
        cout << *iter << ' ';
    }
    cout << endl;

    //Задача 2
    list<int> l = { 1, 6, 4, 10, 4, 5, 15, 14, 15, 10 };
    cout << "Task 2: " << endl;
    cout << "Initial list: ";
    for (list<int>::iterator iter = l.begin(); iter != l.end(); iter++) {
        cout << *iter << ' ';
    }
    cout << endl;

    l = second_func(l);

    cout << "Changed list: ";

    for (list<int>::iterator iter = l.begin(); iter != l.end(); iter++) {
        cout << *iter << ' ';
    }
    cout << endl;
    
    //Задача 3
    vector<int> v1 = { 1, 2, 10, 6, 10, 8, 3, 5, 7, 14 };
    cout << "Task 3: " << endl;
    cout << "Initial vector: ";
    for (vector<int>::iterator iter = v1.begin(); iter != v1.end(); iter++) {
        cout << *iter << ' ';
    }
    cout << endl;

    v1 = third_func(v1);

    cout << "Changed list: ";

    for (vector<int>::iterator iter = v1.begin(); iter != v1.end(); iter++) {
        cout << *iter << ' ';
    }
    cout << endl;

    //Задание 4
    list<int> l1 = { 1, 6, 11, 24, 7, 5, -15, -100, 15, 25 };
    list<int> l2 = { 5, 2, 0, 1, 4, 2, 4, 2, 3, 12};

    cout << "Task 4: " << endl;

    cout << "Initial list1: ";
    for (list<int>::iterator iter = l1.begin(); iter != l1.end(); iter++) {
        cout << *iter << ' ';
    }
    cout << endl;

    cout << "Initial list2: ";
    for (list<int>::iterator iter = l2.begin(); iter != l2.end(); iter++) {
        cout << *iter << ' ';
    }
    cout << endl;

    int s = fourth_func(l1, l2);

    cout << "Answer: " << s << endl;

    cout << "Task 5: " << endl;
    string str = "qwertyqweqweqwetttt";
    cout << "Initial string: " << str << endl;

    cout << "Answer: " << fiveth_func(str);
}

