#include <iostream>
using namespace std;

struct node {
    int value; 
    node* prev, * next;
};

class List {
public: 
    node* head, * tail;
    int length;

    List() { // конструктор 
        head = tail = NULL;
        length = 0;
    }

    ~List() { // деструктор 
        while (head->next != NULL) {
            node* p = head; 
            head = head->next;
            head->prev = NULL;
            delete p;
        }
        head->next = NULL;
        head->prev = NULL;
        head->value = NULL;
    }

    void push_back(int x) { // добавление в конец
        node* r = new node;
        r->value = x;
        r->next = NULL;
        if (!head && !tail) {
            r->prev = NULL;
            head = r;
        }
        else {
            tail->next = r;
            r->prev = tail;
        }
        tail = r;
        length++;
    }
    
    void print() {// вывод всего списка
        node* p = head;
        cout << "[";
        while (p) {
            cout << p->value << ", ";
            p = p->next;
        }
        cout << "]" << endl;
    }

    node* find(int x) { // поиск элемента по значению
        node* p = head;
        while (p) {
            if (p->value == x) {
                break;
            }
            p = p->next;
        }
        return p;
    }

    void insert_after(node* r, int y){ // вставка после элемента 
        node* p = new node;
        p->value = y;
        if (r == tail) {
            p->next = NULL; 
            p->prev = r;
            r->next = p;
            tail = p;  
        }
        else {
            r->next->prev = p;
            p->next = r->next;
            p->prev = r;
            r->next = p;
        }
        length++;
    }

    int del_element(node* r) {
        if (r == head && r == tail) {
            head = tail = NULL;
        }
        else if (head == r) {
            head = head->next;
            head->prev = NULL;
        }
        else if (r == tail) {
            tail = tail->prev;
            tail->next = NULL;
        }
        else {
            r->next->prev = r->prev;
            r->prev->next = r->next;
        }
        int result;
        result = r->value;
        delete r;
        length--;
        return result;
    }

    int max() {
        int result = head->value;
        node* p = head;
        while (p) {
            if (p->value > result) {
                result = p->value;
            }
            p = p->next;
        }
        return result; 
    }
};

int average(List& l, node* r) {
    r = r->next;
    int sum = 0; 
    int num = 0;
    while (r) {
        sum += r->value;
        num++;
        r = r->next;
    }
    return sum / num;
}

int main()
{
    int n;
    cout << "Enter num elem's: ";
    cin >> n;
    int input; 

    List* list = new List;
    while (n > 0) {
        cin >> input;
        list->push_back(input);
        n--;
    }
    
    node* p = list->head;
    while (p->next) {    
        if (p->value < average(*list, p)) {
            list->del_element(p);
            p = list->head;
        }
        else {
            p = p->next;
        }
    }

    list->print();
    cout << list->length;

    delete list;
}

