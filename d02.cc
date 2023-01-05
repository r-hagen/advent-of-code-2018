#include "bits/stdc++.h"

using namespace std;

#define		       int long long int
#define		       double long double
#define si             set <int>
#define vi             vector <int>
#define mii            map <int, int>
#define endl	       "\n"
#define sz(x)          ((int) x.size())
#define all(p)         p.begin(), p.end()
#define que_max        priority_queue <int>
#define que_min        priority_queue <int, vi, greater<int>>
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
#define print(a)       for(auto x : a) cout << x << " "; cout << endl
#define print1(a)      for(auto x : a) cout << x.F << " " << x.S << endl
#define print2(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { 
  cout << name << " : " << arg1 << endl; 
}

template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr (names + 1, ',');
  cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}


void solve() {
  int exactly2 = 0;
  int exactly3 = 0;
  bool foundTwo = false;
  bool foundThree = false;
  string id; 
  vector<string> boxids;

  while (cin >> id) {
    boxids.push_back(id);

    map<char, int> counter;
    for (auto c : id) counter[c] += 1;

    foundTwo = foundThree = false;

    for (auto p : counter) {
      if (!foundTwo && p.second == 2) {
	exactly2++;
	foundTwo = true;
      }
      else if (!foundThree && p.second == 3) {
	exactly3++;
	foundThree = true;
      }
    }
  }
  cout << "Part 1: " << exactly2 * exactly3 << endl;

  int minDiff = 1000000;
  vi minIndices;
  string minId;

  for (auto id1 : boxids) {
    for (auto id2 : boxids) {
      if (id1 == id2) continue;
      vi ii;

      for (int i=0; i < id1.length(); i++) {
	if (id1[i] == id2[i]) continue;
	ii.push_back(i);
      }

      if (sz(ii) < minDiff) {
	minDiff = sz(ii);
	minIndices = ii;
	minId = id1;
      }
    }
  }

  cout << "Part 2: ";
  for (int i=0; i < minId.length(); i++) {
    if (find(all(minIndices), i) == minIndices.end()) {
      cout << minId[i];
    }
  }
  cout << endl;
}


int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("d02.in", "r", stdin);

  clock_t z = clock();

  int t = 1;
  // cin >> t;
  while (t--) solve();

  cerr << "Run Time: " << ((double)(clock() - z) / CLOCKS_PER_SEC);

  return 0;
}

