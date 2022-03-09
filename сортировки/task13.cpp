#include <iostream>
#include <vector>
#include <Windows.h>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

struct date { //дата 
	int dd, mm, yy;
};

struct people {
	string Surname; //фамили€
	string Position; //должность 
	date DateOfBirth; //дата рождени€ 
	int exp; //стаж работы
	int Salary; //зарплата
};

vector<people> coctail_sort(vector<people> l) {
	int first = -1;
	int last = l.size() - 1;
	bool swap_flag = true;
	while (swap_flag) {
		swap_flag = false;
		first++;
		for (int j = first; j < last; j++) {
			if (l[j].DateOfBirth.yy > l[j + 1].DateOfBirth.yy ||
			l[j].DateOfBirth.yy == l[j + 1].DateOfBirth.yy && l[j].DateOfBirth.mm > l[j + 1].DateOfBirth.mm ||
			l[j].DateOfBirth.yy == l[j + 1].DateOfBirth.yy && l[j].DateOfBirth.mm == l[j + 1].DateOfBirth.mm && l[j].DateOfBirth.dd > l[j + 1].DateOfBirth.dd) {
				people change = l[j];
				l[j] = l[j + 1];
				l[j + 1] = change;
				swap_flag = true;
			}
		}

		if (swap_flag) {
			swap_flag = false;
			last--;
			for (int j = last; j >= first; j--) {
				if (l[j].DateOfBirth.yy > l[j + 1].DateOfBirth.yy ||
					(l[j].DateOfBirth.yy == l[j + 1].DateOfBirth.yy && l[j].DateOfBirth.mm > l[j + 1].DateOfBirth.mm) ||
					(l[j].DateOfBirth.yy == l[j + 1].DateOfBirth.yy && l[j].DateOfBirth.mm == l[j + 1].DateOfBirth.mm && l[j].DateOfBirth.dd > l[j + 1].DateOfBirth.dd)) {
					people change = l[j];
					l[j] = l[j + 1];
					l[j + 1] = change;
					swap_flag = true;
				}
			}
		}
	}
	return l;
}


int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);

	vector <people> v; //список сотрудников 
	people temp; //текущий сотрудник 
	string line; //текуща€ строка докуммента 
	string data; //текуща€ строка докуммента дл€ вывода данных
	string text; //переменна€ дл€ хранени€ строк 
	ifstream fin("input.txt"); //поток ввода текстовый документ 

	if (fin.is_open())
	{
		while (getline(fin, line))
		{
			int j = 0;
			data = line;
			while (j != data.size()) {
				temp.Surname = "";
				while (data[j] != ';') { //сохранение фамилии в temp
					temp.Surname += data[j];
					j++;
				}
				j++;

				temp.Position = "";
				while (data[j] != ';') { //сохранение должности в temp 
					temp.Position += data[j];
					j++;
				}
				j++;

				text = "";
				while (data[j] != '.') { //число мес€ца 
					text += data[j];
					j++;
				}
				j++;
				temp.DateOfBirth.dd = stoi(text);

				text = "";
				while (data[j] != '.') { //мес€ц 
					text += data[j];
					j++;
				}
				j++;
				temp.DateOfBirth.mm = stoi(text);

				text = "";
				while (data[j] != ';') { //год 
					text += data[j];
					j++;
				}
				j++;
				temp.DateOfBirth.yy = stoi(text);

				text = "";
				while (data[j] != ';') { //стаж работы 
					text += data[j];
					j++;
				}
				j++;
				temp.exp = stoi(text);

				text = "";
				while (data[j] != ';') { //«ѕ
					text += data[j];
					j++;
				}
				j++;
				temp.Salary = stoi(text);
				v.push_back(temp);
			}
		}
	}
	fin.close();

	v = coctail_sort(v);

	ofstream fout; //объект вывода данных
	fout.open("output.txt");
	if (fout.is_open())
	{
		for (int i = 0; i < v.size(); i++) {
			fout << v[i].Surname << ';';
			fout << v[i].Position << ';';
			if (v[i].DateOfBirth.dd < 10) {
				fout << '0';
			}
			fout << v[i].DateOfBirth.dd << '.';
			if (v[i].DateOfBirth.mm < 10) {
				fout << '0';
			}
			fout << v[i].DateOfBirth.mm << '.';
			fout << v[i].DateOfBirth.yy << ';' << v[i].exp << ';' << v[i].Salary << ';' << endl;
		}
		fout.close();
	}
}
