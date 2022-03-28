#include <iostream>
using namespace std; 

struct stack
{
    string value;
    stack* next;
};

void push(stack* &head, string str) {
    stack* el = new stack;
    el->value = str;
    el->next = head;
    head = el;
}

string pop(stack*& head) {
    string value = head->value;
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

void task(stack*& h, char l) {
    stack* head1 = NULL;
    while (h) {
        if (h->value[h->value.size() - 1] != l) {
            push(head1, pop(h));
        }
        else {
            pop(h);
        }
    }
    h = head1;
}

int main()
{
    stack* h = NULL;
    char liter; 
    cout << "Enter the simbol: ";
    cin >> liter; 
    cout << endl;
    cout << "Enter the words. If you want to stop typing, press 0 and enter." << endl;
    string input;

    while (input != "0") { //Ввод данных 
        cin >> input; 
        if (input != "0") {
            push(h, input);
        }
    }

    task(h, liter); //задание

    while (h) {
        cout << pop(h) << ' '; 
    }
}

