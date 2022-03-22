#include <iostream>
using namespace std; 

struct queue {
    int value; 
    queue* next;
};

void push(queue*& h, queue*& t, int value) {
    queue* r = new queue; 
    r->value = value;
    r->next = NULL;
    if (!h && !t) {
        h = t = r;
    }
    else {
        t->next = r;
        t = r;
    }
}

int pop(queue*& h, queue*& t) {
    queue* r = h;
    int data = h->value;
    h = h->next;
    if (!h) {
        t = NULL;
    }
    delete r;
    return data;
}

int max(queue*& h, queue*& t) {
    queue* head1 = NULL;
    queue* tail1 = NULL;
    int max_el = h->value;
    int el;
    while (h || t) {
        el = pop(h, t);
        if (el > max_el) {
            max_el = el;
        }
        push(head1, tail1, el);
    }
    h = head1;
    t = tail1;
    return max_el;
}

int min(queue*& h, queue*& t) {
    queue* head1 = NULL;
    queue* tail1 = NULL;
    int min_el = h->value;
    int el;
    while (h || t) {
        el = pop(h, t);
        if (el < min_el) {
            min_el = el;
        }
        push(head1, tail1, el);
    }
    h = head1;
    t = tail1;
    return min_el;
}

void task(queue*& h, queue*& t, int max_el, int min_el) {
    queue* head1 = NULL; 
    queue* tail1 = NULL;

    while (h || t) {
        int el = pop(h, t);
        if (el == max_el) {
            push(head1, tail1, min_el);
        }
        push(head1, tail1, el);
    }
    h = head1;
    t = tail1;
}

int main()
{
    queue* head = NULL;
    queue* tail = NULL;
    int n; //кол-во элементов 
    cout << "Enter n: ";
    cin >> n;
    cout << endl; 
    int input; //переменная для ввода
    for (int i = 0; i < n; i++) {
        cin >> input;
        push(head, tail, input);
    }

    int max_el = max(head, tail);
    int min_el = min(head, tail);
    task(head, tail, max_el, min_el);

    while (head || tail) {
        cout << pop(head, tail) << ' ';
    }   
}

