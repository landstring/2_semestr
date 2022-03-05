#include <iostream>
#include <list>
#include<list>
#include <algorithm>
using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian"); 

    list<int> v1;
    int n1;
    cout << "Введите кол-во элементов 1 последовательности: ";
    cin >> n1;
    cout << endl;

    int el; //переменная для ввода

    for (int i = 0; i < n1; i++) { //заполнение списка целыми числами
        cout << "v1[" << i << "] = ";
        cin >> el;
        v1.push_back(el);
    }

    list<int> v2;
    int n2;
    cout << "Введите кол-во элементов 2 последовательности: ";
    cin >> n2;
    cout << endl;

    for (int i = 0; i < n2; i++) { //заполнение списка целыми числами
        cout << "v2[" << i << "] = ";
        cin >> el;
        v2.push_back(el);
    }

    //удаление из 1 списка элементов, встречающихся во 2
    int erase_count = 0; //счётчик повторений

    for (list<int>::iterator iter2 = v2.begin(); iter2 != v2.end(); iter2++) {
        v1.remove(*iter2);      
    }



    for (list<int>::iterator iter1 = v1.begin(); iter1 != v1.end(); iter1++) {
        cout << *iter1 << ' ';
    }
    cout << endl;

    for (list<int>::iterator iter2 = v2.begin(); iter2 != v2.end(); iter2++) {
        cout << *iter2 << ' ';
    }
    cout << endl;

    int x;
    cout << "Введите x: ";
    cin >> x;

    int element;
    
    for (list<int>::iterator iter2 = v2.begin(); iter2 != v2.end(); iter2++) {
        if (*iter2 % x == 0) {
            cout << "Введите элемент: ";
            cin >> element;
            if (iter2 != v2.end()) {
                iter2++;
                v2.emplace(iter2, element);
                iter2--;
            }
            else {
                v2.push_back(element);
            }
            
        }
    }

    for (list<int>::iterator iter1 = v1.begin(); iter1 != v1.end(); iter1++) {
        cout << *iter1 << ' ';
    }
    cout << endl;

    for (list<int>::iterator iter2 = v2.begin(); iter2 != v2.end(); iter2++) {
        cout << *iter2 << ' ';
    }
    cout << endl;

    v1.sort();
    v2.sort();

    for (list<int>::iterator iter1 = v1.begin(); iter1 != v1.end(); iter1++) {
        cout << *iter1 << ' ';
    }
    cout << endl;

    for (list<int>::iterator iter2 = v2.begin(); iter2 != v2.end(); iter2++) {
        cout << *iter2 << ' ';
    }

    cout << endl;

    v1.merge(v2); //объединение

    for (list<int>::iterator iter1 = v1.begin(); iter1 != v1.end(); iter1++) {
        cout << *iter1 << ' ';
    }
    cout << endl;
}

