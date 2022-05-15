#include <iostream>
#include <string>
using namespace std;

struct stack
{
    char value;
    stack* next;
};

void push(stack*& head, char str) {
    stack* el = new stack;
    el->value = str;
    el->next = head;
    head = el;
}

char pop(stack*& head) {
    char value = head->value;
    stack* r = head;
    head = head->next;
    delete r;
    return value;
}

void reverse(stack*& h) {
    stack* head1 = NULL;
    while (h) {
        push(head1, pop(h));
    }
    h = head1;
}

bool correct(stack*& h, string s) {
    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] == ')') {
            push(h, s[i]);
        }
        else if (s[i] == '(') {
            if (h) {
                pop(h);
            }
            else {
                return false;
            }
        }
    }
    if (h) {
        return false;
    }
    else {
        return true;
    }
}

int main()
{
    stack* h = NULL;
    string str;
    cin >> str;

    if (correct(h, str)) {
        cout << "Correct" << endl;
    }
    else {
        cout << "Wrong" << endl;
    }
    
    while (h) {
        pop(h);
    }
}
