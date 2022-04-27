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

void task(queue*& h, queue*& t) {
    queue* head_pos = NULL;
    queue* tail_pos = NULL;
    queue* head_neg = NULL;
    queue* tail_neg = NULL;

    while (h || t) {
        int num = pop(h, t);
        if (num >= 0) {
            push(head_pos, tail_pos, num);
        }
        else {
            push(head_neg, tail_neg, num);
        }
    }
    while (head_neg || tail_neg) {
        push(h, t, pop(head_neg, tail_neg));
    }
    while (head_pos || tail_pos) {
        push(h, t, pop(head_pos, tail_pos));
    }
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

    task(head, tail);

    while (head || tail) {
        cout << pop(head, tail) << ' ';
    }   
}

