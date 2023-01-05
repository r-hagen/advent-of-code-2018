#include "bits/stdc++.h"
#include <regex>

using namespace std;

#define int	       long long int
#define F              first
#define S              second
#define pb             push_back
#define si             set <int>
#define vi             vector <int>
#define pii            pair <int, int>
#define vpi            vector <pii>
#define vpp            vector <pair<int, pii>>
#define mii            map <int, int>
#define mpi            map <pii, int>
#define spi            set <pii>
#define endl	       "\n"
#define sz(x)          ((int) x.size())
#define all(p)         p.begin(), p.end()
#define double	       long double
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
  mpi G;
  map<int, vi> C;

  while (!cin.eof()) {
    string S;
    getline(cin, S);
    if (sz(S) == 0) break;

    istringstream iss(S);
    string word;

    int idx = 0;
    int id;
    int ex;
    int ey;
    int w;
    int h;
    while (getline(iss, word, ' ')) {
      if (idx == 0) {
	id = stoll(word.substr(1, word.size()));
      } else if (idx == 2) {
	int sep = word.find(",");
	ex = stoll(word.substr(0, sep));
	ey = stoll(word.substr(sep+1, word.length()-sep));
      } else if (idx == 3) {
	int sep = word.find("x");
	w = stoll(word.substr(0, sep));
	h = stoll(word.substr(sep+1, word.length()-sep));
      }
      idx++;
    }

    for (auto y = ey; y < ey+h; y++) {
      for (auto x = ex; x < ex+w; x++) {
	pii xy = make_pair(x, y);
	G[xy] += 1;
      }
    }
    C[id] = vi{ex, w, ey, h};
  }

  int p1 = 0;
  for (auto p : G) {
    if (p.second >= 2) p1++;
  }

  cout << "Part 1: " << p1 << endl;

  for (auto p : C) {
    int ex = p.second[0];
    int w = p.second[1];
    int ey = p.second[2];
    int h = p.second[3];

    bool intact = true;

    for (auto y = ey; y < ey+h; y++) {
      for (auto x = ex; x < ex+w; x++) {
	pii xy = make_pair(x, y);
	if (G[xy] > 1) {
	  intact = false;
	}
      }
    }

    if (intact) {
      cout << "Part 2: " << p.first << endl;
      break;
    }
  }
}


int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("d03.in", "r", stdin);

  clock_t z = clock();

  int t = 1;
  // cin >> t;
  while (t--) solve();

  cerr << "Run Time: " << ((double)(clock() - z) / CLOCKS_PER_SEC);

  return 0;
}

