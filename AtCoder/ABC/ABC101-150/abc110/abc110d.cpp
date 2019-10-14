#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define RREP(i,b,e) for(int i=(b)-1;i>=e;--i)
#define rep(i,e) for(int i=0;i<(e);++i)

constexpr int MOD = 1000000007;

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

struct RuntimeModComb {
private:
  unsigned int N;
  long long MOD;

public:
  vector<long long> fac;
  vector<long long> inv;
  vector<long long> ifac;

  RuntimeModComb(unsigned int N, long long MOD) : N(N), MOD(MOD), fac(), inv(), ifac() {
    fac.resize(N), inv.resize(N), ifac.resize(N);
    fac[0] = fac[1] = inv[1] = ifac[0] = ifac[1] = 1;
    for (size_t i = 2; i <= N; ++i) {
      fac[i] = fac[i-1] * i % MOD;
      inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
      ifac[i] = ifac[i-1] * inv[i] % MOD;
    }
  }
  long long comb(unsigned int n, unsigned int k) const {
    if (n < 0 || k < 0 || k > n) return 0;
    return (fac[n] * ifac[k] % MOD) * ifac[n-k] % MOD;
  }
};

int main() {
  int n, m; cin>>n>>m;
  auto primes = sieve_of_eratosthenes();
  auto prime_factor = prime_factorize(m, primes);

  RuntimeModComb mc(200010, MOD);
  long long ans = 1;
  for (auto x: prime_factor) {
    ans = (ans * mc.comb(x.second + n - 1, x.second)) % MOD;
  }
  print(ans);

  return 0;
}