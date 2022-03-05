#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian"); 
    vector<int> v;
    int x;
    int n;
    cout << "Введите кол-во элементов: ";
    cin >> n;
    cout << endl;

    for (int i = 0; i < n; i++) { //заполнение вектора целыми числами
        cout << "v[" << i << "] = ";
        cin >> x;
        v.push_back(x);
    }

    vector<int>::iterator it = min_element(v.begin(), v.end());

    int Min = *it;
    it = remove(v.begin(), v.end(), Min); //сохраняем конец нового вектора
    v.erase(it, v.end()); //удаляем лишние (минимальные) элементы

    for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++){
        cout << *iter;
        cout << endl;
    }
    
}

