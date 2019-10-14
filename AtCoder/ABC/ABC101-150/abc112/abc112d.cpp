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

vector<long long> calc_divisors(long long n, const map<long long, int> &prime_factor) {
  vector<long long> divisors(1, 1);
  for (auto it : prime_factor) {
    long long p; int k;
    tie(p, k) = it;
    int size = divisors.size();
    for (int i = 0; i < k; ++i) {
      for (int j = 0; j < size; ++j) divisors.push_back(divisors[i*size+j] * p);
    }
  }
  sort(divisors.begin(), divisors.end());
  return divisors;
}

int main() {
  int n, m; cin>>n>>m;
  auto primes = sieve_of_eratosthenes();
  auto prime_factors = prime_factorize(m, primes);
  auto divisors = calc_divisors(n, prime_factors);

  int ans = 1;
  rep(i, divisors.size()) if (m/n >= divisors[i]) ans = divisors[i];
  print(ans);

  return 0;
}