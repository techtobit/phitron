#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, q;
	cin >> n >> q;
	int a[n];
	for (size_t i = 0; i < n; i++)
	// time complixity O(n)
	{
		cin >> a[i];
	}

	sort(a, a + n);

	while (q--)
	// time complixity O(q)
	{
		int x;
		cin >> x;
		int l = 0;
		int r = n - 1;
		bool flag = false;

		//Binary Search
		while (l <= r)
		{
			int mid_index = (l + r) / 2;
			if (a[mid_index] == x)
			{
				flag = true;
				break;
			}
			else if (x > a[mid_index])
			{
				// dan pase e same jabe
				l = mid_index + 1;
			}
			else
			{
				// bame pecon er dike jabe
				r = mid_index - 1;
			}
		}

		if (flag == true)
		{
			cout << "found" << endl;
		}
		else
			cout << "not found" << endl;
	}

	return 0;
}