#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define RREP(i,b,e) for(int i=(b)-1;i>=e;--i)
#define rep(i,e) for(int i=0;i<(e);++i)

inline void print(void) { cout<<'\n'; }
template<class T> inline void print(const T &x) { cout<<x<<'\n'; }
template<class T, class... U> inline void print(const T &x, const U&... y) { cout<<x<<" "; print(y...); }

vector<int> sieve_of_eratosthenes(int n = 200010) {
  vector<bool> is_prime(n+1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 0; i <= n; ++i) if (is_prime[i]) {
    for (int j = i+i; j <= n; j+=i) is_prime[j] = false;
  }
  vector<int> primes;
  for (int i = 2; i <= n; ++i) if (is_prime[i]) primes.push_back(i);
  return primes;
}

map<long long, int> prime_factorize(long long n, const vector<int> &primes) {
  map<long long, int> prime_factor;
  for (int p : primes) {
    if (n < (long long) p * p) break;
    while (n % p == 0) {
      prime_factor[p] += 1;
      n /= p;
    }
  }
  if (n != 1) prime_factor[n] += 1;
  return prime_factor;
}

int main() {
  int n; cin>>n;
  auto primes = sieve_of_eratosthenes();

  vector<int> fac(110, 0);
  REP(i, 1, n+1) {
    auto pf = prime_factorize(i, primes);
    for (auto x: pf) fac[x.first] += x.second;
  }

  int ans = 0;
  if (fac[2] >= 74) ++ans;
  rep(i, 110) rep(j, 110) {
    if (i == j) continue;
    if (fac[i] >= 24 and fac[j] >= 2) ++ans;
    if (fac[i] >= 14 and fac[j] >= 4) ++ans;
  }
  rep(i, 110) rep(j, 110) rep(k, 110) {
    if (i <= j or j == k or k == i) continue;
    if (fac[i] >= 4 and fac[j] >= 4 and fac[k] >= 2) ++ans;
  }
  print(ans);

  return 0;
}