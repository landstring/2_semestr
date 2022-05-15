#include <iostream>
using namespace std; 

struct stack
{
    int value;
    stack* next;
};

void push(stack* &head, int num) {
    stack* el = new stack;
    el->value = num;
    el->next = head;
    head = el;
}

int pop(stack*& head) {
    int value = head->value;
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

int max(stack*& h) {
    stack* head1 = NULL;
    int max = h->value; 
    while (h) {
        int l = pop(h);
        push(head1, l);
        if (l > max) {
            max = l;
        }
    }
    h = head1;
    return max;
}

void task(stack*& h, int max) {
    stack* head1 = NULL; 
    while (h) {
        if (h->value == max) {
            pop(h);
        }
        else {
            push(head1, pop(h));
        }
    }
    h = head1;
}

int main()
{
    stack* h = NULL;
    int n; //кол-во элементов
    int input; //ввод данных
    cout << "Enter n: ";
    cin >> n; 
    cout << endl;
    while (n > 0) {
        cin >> input;
        push(h, input);
        n--;
    }

    int m = max(h);
    task(h, m);
    reverse(h);

    while (h) {
        cout << pop(h) << ' '; 
    }
}

