#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian"); 
    vector<int> v;
    int el;
    int n;
    cout << "Введите кол-во элементов: ";
    cin >> n;
    cout << endl;

    for (int i = 0; i < n; i++) { //заполнение вектора целыми числами
        cout << "v[" << i << "] = ";
        cin >> el;
        v.push_back(el);
    }

    int a, b;
    cout << "Введите интервал [a, b] через пробел: ";
    cin >> a >> b;
    cout << endl;

    int x;
    cout << "Введите значение Х: ";
    cin >> x;
    cout << endl;
    if (a > b) {
        cout << "Введён неверный промежуток!";
    }
    else {
        reverse(v.begin(), v.end());
        cout << "Вывод в обратном порядке: " << endl;
        for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++) {
            cout << *iter << ' ';
        }
        cout << endl;

        for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++) { //замена элементов, попавших в [a, b] на X
            if (a <= *iter and *iter <= b) {
                *iter = x;
            }
        }

        cout << "Вывод в обратном порядке с заменой: " << endl;
        for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++) {
            cout << *iter << ' ';
        }
        cout << endl;

        sort(v.begin(), v.end());

        cout << "Вывод с сортировкой полученного массива: " << endl;
        for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++) {
            cout << *iter << ' ';
        }
        cout << endl;

        int element, position;
        cout << "Введите элемент и позицию, на которую нужно вставить, через пробел: ";
        cin >> element >> position;
        cout << endl;

        auto iter_insert = v.cbegin();
        v.insert(iter_insert + position, element);

        cout << "Вывод массива после вставки: " << endl;
        for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++) {
            cout << *iter << ' ';
        }
        cout << endl;

        sort(v.begin(), v.end()); //сортировка для unique 
        
        vector<int>::iterator iter = unique(v.begin(), v.end()); 
        v.erase(iter, v.end());
        cout << "Вывод массива после удаления повторяющихся элементов: " << endl;
        for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++) {
            cout << *iter << " ";
        }
    } 
}

