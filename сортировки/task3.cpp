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

vector <people> LSD_sort(vector <people>& l) {
	int k = 0; //максимальный разр€д
	vector<int> vec; //вектор дл€ подсчЄта максимального разр€да
	for (int i = 0; i < l.size(); i++) {
		vec.push_back(l[i].Salary);
	}
	vector<int>::iterator m = max_element(vec.begin(), vec.end());
	int m_value = *m;
	while (m_value > 0) {
		m_value /= 10;
		k++;
	}

	for (int i = 0; i < k; i++) {
		vector < vector < people >> b(10);
		for (int j = 0; j < l.size(); j++) {
			b[l[j].Salary / (int) pow(10, i) % 10].push_back(l[j]);
		}
		l.clear();
		for (int j = 0; j < 10; j++) {
			for (int z = 0; z < b[j].size(); z++) {
				l.push_back(b[j][z]);
			}
		}
	}
	return l;
}

int main()
{
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

	v = LSD_sort(v);

	ofstream fout; //объект вывода данных
	fout.open("output.txt");
	if (fout.is_open())
	{
		for (int i = 0; i < v.size(); i++) {
			fout << v[i].Surname << " " << v[i].DateOfBirth.dd << '.' << v[i].DateOfBirth.mm << '.' << v[i].DateOfBirth.yy << ' ' << v[i].Position << ' ' << v[i].exp << ' ' << v[i].Salary << endl;
		}
	}	
	fout.close();

}
