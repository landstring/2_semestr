#include <iostream>
#include <Windows.h>
#include <ctype.h>
#include<set>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    set <string> stack; //очередь
    set <string> question; //слова вопросительных предложений 
    set <string> narration; //слова повествовательных предложений 
    set <string> exclamation; //слова восклицательных предложений 

    string text; //текст 

    string word = ""; //текущее слово

    cout << "Введите текст: " << endl;
    getline(cin, text);

    for (int i = 0; i < text.length(); i++) {
        if (text[i] == ' ' and (text[i - 1] == ':' or text[i - 1] == ',' or text[i - 1] == '-' or text[i - 1] == '?' or text[i - 1] == '!' or text[i - 1] == '.')) {

        }
        else if (text[i] == ',' or text[i] == ' '){
            stack.insert(word);
            word = "";
        }       
        else if (text[i] == '-') {
            i++;
        }
        else if (text[i] == '!') {
            stack.insert(word);
            word = "";
            for (auto &item : stack) {
                exclamation.insert(item);
            }
            stack = {};
        }
        else if (text[i] == '?') {
            stack.insert(word);
            word = "";
            for (auto &item : stack) {
                question.insert(item);
            }
            stack = {};
        }
        else if (text[i] == '.') {
            stack.insert(word);
            word = "";
            for (auto &item : stack) {
                narration.insert(item);
            }
            stack = {};
        }
        else {
            word += (char)tolower(text[i]);
        }
    }
    int c = 0;
    for (auto &item : narration) {
        if (question.find(item) == question.end() and exclamation.find(item) == exclamation.end()) {
            cout << item << " ";
            c++;
        }
    }
    cout << endl << "Количество: " << c << endl;
}
