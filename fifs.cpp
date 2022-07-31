#include<iostream>
#include<vector>

#include<algorithm>

using namespace std;

int main() {

	int n;
	cout << "Enter number of processes: ";
	cin >> n;

	vector < pair<int, int> > task(n);
	cout << "Enter brust times and arrival time: " << endl;
	for (int i = 0; i < n; i++) {
		int a, b;
		cout << "----Task " << i + 1 << "----" << endl;
		cout << "Arrival Time: ";
		cin >> a;
		cout << "Brust Time: ";
		cin >> b;
		task[i] = {a, b};
	}
	sort(task.begin(), task.end());

	int gantt[n + 1];
	gantt[0] = 0;

	for (int i = 1; i <= n; i++) {
		gantt[i] = gantt[i - 1] + task[i - 1].second;
	}

	int turnarount_time = 0, waiting_time = 0;

	for (int i = 0; i < n; i++) {
		int processT = (gantt[i + 1] - task[i].first);
		turnarount_time += processT;
		waiting_time += processT - task[i].second;
	}

	cout << "Avarage Tournarount Time: " << turnarount_time / n << endl;
	cout << "Avarage Waiting Time: " << waiting_time / n << endl;

}