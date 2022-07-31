#include<iostream>
#include<vector>

#include<algorithm>
#include<climits>
using namespace std;

struct process {
	int arrival_time, brust_time, end, need;
};

bool cmp(process a, process b) {
	return a.arrival_time < b.arrival_time;
}

int main() {

	int n, tq;
	cout << "Enter number of processes: ";
	cin >> n;
	cout << "Enter time quantum: ";
	cin >> tq;
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
		task[i].need = b;
		task[i].end = 1;
	}
	sort(task.begin(), task.end(), cmp);
	int turnarount_time = 0, waiting_time = 0, curr_time = 0;
	int end = 0;

	while (end < n) {
		for (int i = 0; i < n; i++ ) {
			if (task[i].end and task[i].arrival_time <= curr_time) {
				if (task[i].need > tq) {
					curr_time += tq;
					task[i].need -= tq;
				} else {
					curr_time += task[i].need;
					task[i].end = 0;
					end++;
					int processT = curr_time - task[i].arrival_time;
					turnarount_time += processT ;
					waiting_time += processT - task[i].brust_time;
					task[i].need = 0;
				}

			}
		}
	}



	cout << "Avarage Tournarount Time: " << (float)turnarount_time / n << endl;
	cout << "Avarage Waiting Time: " << (float)waiting_time / n << endl;

}