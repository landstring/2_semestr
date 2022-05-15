#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

void normalizeCycle(vector<int> &cycle) {
	vector<int>::iterator minimum = min_element(cycle.begin(), cycle.end());

	for (vector<int>::iterator it = cycle.begin(); it != minimum; it++) {
		cycle.push_back(*cycle.begin());
		cycle.erase(cycle.begin());
	}

	if (*(cycle.end()-1) < *(cycle.begin()+1))
		for (int i = 1; i < 1+(cycle.size()-1)/2; i++)
			swap(cycle[i], cycle[cycle.size()-i]);
}

void printCycle(vector<int> &pr, int start, int end, vector<vector<int>> &cycles) {
	vector<int> fst = {start}, snd = {end}, tmp;
	int cur;

	cur = start;
	while (pr[cur] != -1) {
		cur = pr[cur];
		fst.push_back(cur);
	}
	
	cur = end;
	while (pr[cur] != -1) {
		cur = pr[cur];
		snd.push_back(cur);
	}

	int last = -1;

	while (fst.back() == snd.back()) {
		last = fst.back();
		fst.pop_back();
		snd.pop_back();
	}

	for (int i = fst.size()-1; i >= 0; i--) tmp.push_back(fst[i]);
	tmp.push_back(last);
	for (int i = 0; i < snd.size(); i++) tmp.push_back(snd[i]);

	normalizeCycle(tmp);
	cycles.push_back(tmp);
}

void searchCycles(vector<vector<int>> &Gr, vector<bool> &used, vector<int> &pr, int x, vector<vector<int>> &cycles) {
	used[x] = true;
	for (int i = 0; i < Gr[x].size(); i++) {
		if (pr[Gr[x][i]] != x && !used[Gr[x][i]]) {
			pr[Gr[x][i]] = x;
			searchCycles(Gr, used, pr, Gr[x][i], cycles);
		}
		else if (pr[Gr[x][i]] != x && pr[x] != Gr[x][i]) {
			printCycle(pr, Gr[x][i], x, cycles);
		}
	}
}

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

	vector<bool> used;
	for (int i = 0; i < N; i++) {
		used.push_back(false);
	}

	vector<int> pr;
	for (int i = 0; i < N * N; i++) {
		pr.push_back(-1);
	}
	vector<vector<int>> cycles;
	searchCycles(Gr, used, pr, 0, cycles);

	cycles.erase(unique(cycles.begin(), cycles.end()), cycles.end());
	for (int i = 0; i < cycles.size(); i++) {
		for (int j = 0; j < cycles[i].size(); j++) {
			cout << cycles[i][j] << ' ';
		}
		cout << endl;
	}
}