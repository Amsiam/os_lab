#include <iostream>
using namespace std;

int main()
{

	int n, m, i, j, k;
	cout << "Enter number of processes: ";
	cin >> n;
	cout << "Enter number of resource: ";
	cin >> m;
	int alloc[n][m] ;

	cout << "Enter alloced resource: " << endl;
	for (int i = 0; i < n; i++) {

		cout << "resource for process " << i + 1 << ": ";
		for (int j = 0; j < m; j++) {
			cin >> alloc[i][j];
		}
	}
	int need[n][m];
	cout << "Enter Requested resource: " << endl;
	for (int i = 0; i < n; i++) {

		cout << "Requested resource for process " << i + 1 << ": ";
		for (int j = 0; j < m; j++) {
			cin >> need[i][j];
		}
	}

	int avail[m];
	cout << "Enter available resource: " << endl;
	for (int i = 0; i < m; i++) {

		cin >> avail[i];
	}

	int f[n], ans[n], ind = 0;
	for (k = 0; k < n; k++) {
		f[k] = 0;
	}
	int y = 0;
	for (k = 0; k < n; k++) {
		for (i = 0; i < n; i++) {
			if (f[i] == 0) {

				int flag = 0;
				for (j = 0; j < m; j++) {
					if (need[i][j] > avail[j]) {
						flag = 1;
						break;
					}
				}

				if (flag == 0) {
					ans[ind++] = i;
					for (y = 0; y < m; y++)
						avail[y] += alloc[i][y];
					f[i] = 1;
				}
			}
		}
	}

	int flag = 1;

	for (int i = 0; i < n; i++)
	{
		if (f[i] == 0)
		{
			flag = 0;
			cout << "Deadlock occurs.";
			break;
		}
	}

	if (flag == 1)
	{
		cout << "Following is the SAFE Sequence" << endl;
		for (i = 0; i < n - 1; i++)
			cout << " P" << ans[i] << " ->";
		cout << " P" << ans[n - 1] << endl;
	}

	return (0);
}
