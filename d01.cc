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
  int p1 = 0;
  int p2 = 0;
  vi freqs;
  mii seen;

  int n;
  while (cin >> n) freqs.push_back(n);

  for (auto x : freqs) p1 += x;
  cout << "Part 1: " << p1 << endl;

  int i = 0;
  while (true) {
    p2 += freqs[i];
    i = (i+1) % sz(freqs);

    if (seen.find(p2) != seen.end()) 
      break;

    seen.insert({p2, 1});
  }
  cout << "Part 2: " << p2 << endl;
}


int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("d01.in", "r", stdin);

  clock_t z = clock();

  int t = 1;
  // cin >> t;
  while (t--) solve();

  cerr << "Run Time: " << ((double)(clock() - z) / CLOCKS_PER_SEC);

  return 0;
}

