#include <iostream>
#include <Windows.h>
#include <ctype.h>
#include<set>
#include <map>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    string line;
    string text;

    ifstream fin("text.txt");

    if (fin.is_open())
    {
        while (getline(fin, line))
        {
            text = line;
        }
    }
    fin.close();

    cout << text << endl;
    

    map<string, int> dict;
    
    string s = "";
    int num;
    for (int i = 0; i < text.size(); i++) {
        if (text[i] == ' ') {    
            bool flag = false;
            for (int j = 0; j < s.size(); j++) {
                if (not isdigit(s[j])) {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                ++dict[s];
            }
            s = "";
        }
        else {
            s += text[i];
        }
    }
    bool flag = false;
    for (int j = 0; j < s.size(); j++) {
        if (not isdigit(s[j])) {
            flag = true;
            break;
        }
    }
    if (flag) {
        ++dict[s];
    }
    s = "";

    multimap<int, string, greater<int>> res;

    for (auto& pair : dict)
        res.emplace(pair.second, pair.first);

    int count = 0;
    int k;
    cout << "Введите количество: ";
    cin >> k;

    for (auto word = res.begin(); count < k && word != res.end(); ++count, ++word)
        cout << word->second << " " << word->first << endl;
}
