#include<iostream>
#include<vector>

#include<algorithm>
#include<climits>
using namespace std;

struct process {
	int arrival_time, brust_time, end;
};

int main() {

	int n;
	cout << "Enter number of processes: ";
	cin >> n;

	vector < process > task(n);
	cout << "Enter brust times and arrival time: " << endl;
	for (int i = 0; i < n; i++) {
		int a, b;
		cout << "----Task " << i + 1 << "----" << endl;
		cout << "Arrival Time: ";
		cin >> a;
		cout << "Brust Time: ";
		cin >> b;
		task[i].arrival_time = a;
		task[i].brust_time = b;
		task[i].end = 1;
	}

	int gantt[n + 1];
	gantt[0] = 0;
	int turnarount_time = 0, waiting_time = 0;

	for (int i = 1; i <= n; i++) {
		int pid;
		int p = INT_MAX;
		for (int j = 0; j < n; ++j)
		{
			if (task[j].end and task[j].arrival_time <= gantt[i - 1]) {
				if (p > task[j].brust_time) {
					pid = j;
					p = task[j].brust_time;
				}
			}
		}
		task[pid].end = 0;

		gantt[i] = gantt[i - 1] + task[pid].brust_time;

		int processT = (gantt[i] - task[pid].arrival_time);
		turnarount_time += processT;
		waiting_time += processT - task[pid].brust_time;
	}



	cout << "Average Turnarount Time: " << (float)turnarount_time / n << endl;
	cout << "Average Waiting Time: " << (float)waiting_time / n << endl;

}