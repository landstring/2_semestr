#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
	int N, M; //кол-во вершин и рёбер
	cout << "Enter N, M: ";
	cin >> N >> M; //ввод кол-ва рёбер и вершин
	int x, y; //две вершины 
	vector<vector<int>> Gr;
	Gr.resize(N);
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		if (x < N && y < N) {
			Gr[x].push_back(y);
			Gr[y].push_back(x);
		}
	}
	for (int i = 0; i < Gr.size(); i++) {
		sort(Gr[i].begin(), Gr[i].end());
		Gr[i].erase(unique(Gr[i].begin(), Gr[i].end()), Gr[i].end());
	}
	
	int a, b; //вершины
	cout << "Enter A, B: "; cin >> a >> b;
	Gr[a].push_back(b);
	Gr[b].push_back(a);
	sort(Gr[a].begin(), Gr[a].end());
	Gr[a].erase(unique(Gr[a].begin(), Gr[a].end()), Gr[a].end());
	sort(Gr[b].begin(), Gr[b].end());
	Gr[b].erase(unique(Gr[b].begin(), Gr[b].end()), Gr[b].end());

	for (int i = 0; i < Gr.size(); i++) {
		for (int j = 0; j < Gr[i].size(); j++) {
			cout << Gr[i][j] << ' ';
		}
		cout << endl;
	}
}