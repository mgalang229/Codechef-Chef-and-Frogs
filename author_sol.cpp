#include <bits/stdc++.h>

using namespace std;

const int maxn = 100000;

struct Frog {
	int id;
	int x;
} frogs[maxn];

bool byX(const Frog &a, const Frog &b) {
	return a.x < b.x;
}

int comp[maxn];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k, p;
	cin >> n >> k >> p;
	for (int i = 0; i < n; i++) {
		// store the original index of the current element (frog)
		frogs[i].id = i;
		// input the x-coordinate of the current elements (frog)
		cin >> frogs[i].x;
	}
	// sort the ordering of th elements (coordinates of the frog) while still
	// maintaing the original index
	sort(frogs, frogs + n, byX);
	for (int i = 0; i < n; i++) {
		// set 'j' to the index of the next element
		int j = i + 1;
		// set the value to the index that can reach the current element
		comp[frogs[i].id] = i;
		// run a while-loop until the current element cannot reach a certain element
		while (j < n && frogs[j].x <= frogs[j - 1].x + k) {
			// set the value to the index that reach the current element
			comp[frogs[j].id] = i;
			// increment 'j'
			j++;
		}
		// set 'i' to 'j' - 1 (to remove the extra increment from while-loop or reset
		// 'i' to its initial value
		i = j - 1;
	}
	for (int i = 0; i < p; i++) {
		int a, b;
		cin >> a >> b;
		// check if the two elements with index 'a' and 'b' have the same value (or
		// the index/position that can reach them)
		cout << (comp[a - 1] == comp[b - 1] ? "Yes" : "No") << '\n';
	}
	return 0;
}
