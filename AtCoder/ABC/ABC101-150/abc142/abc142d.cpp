#include <bits/stdc++.h>
using namespace std;
#define REP(i,b,e) for(int i=(b);i<(e);++i)
#define RREP(i,b,e) for(int i=(b)-1;i>=e;--i)
#define rep(i,e) for(int i=0;i<(e);++i)

constexpr int MOD = 1000000007;
constexpr int INF = 1LL << 30;
constexpr long long LLINF = 1LL << 60;
constexpr double EPS = 1e-9;

struct Initializer {
  Initializer() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(15) << boolalpha;
  }
} initializer;

template<typename T>
istream &operator>>(istream &is, vector<T> &vec) {
  for (T &x : vec) is >> x;
  return is;
}

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
  os << "[";
  for (auto it = vec.begin(); it != vec.end(); ++it) {
    if (it != vec.begin()) os << ", ";
    os << *it;
  }
  return os << "]";
}

template<typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &pa) {
  return os << "(" << pa.first << ", " << pa.second << ")";
}

template<typename T>
ostream &operator<<(ostream &os, const set<T> &se) {
  os << "{";
  for (auto it = se.begin(); it != se.end(); ++it) {
    if (it != se.begin()) os << ", ";
    os << *it;
  }
  return os << "}";
}

template<typename T, typename U>
ostream &operator<<(ostream &os, const map<T, U> &ma) {
  os << "{";
  for (auto it = ma.begin(); it != ma.end(); ++it) {
    if (it != ma.begin()) os << ", ";
    os << it->first << ": " << it->second;
  }
  return os << "}";
}

inline void print(void) { cout<<'\n'; }
template<class T> inline void print(const T &x) { cout<<x<<'\n'; }
template<class T, class... U> inline void print(const T &x, const U&... y) { cout<<x<<" "; print(y...); }
#define dump(...) cout<<#__VA_ARGS__<<": [L_"<<__LINE__<<"]"<<'\n'; print(__VA_ARGS__);cout<<'\n';

template<class T, class U>inline bool chmax(T &a, const U &b) { if(a<b){ a=b; return 1; } return 0; }
template<class T, class U>inline bool chmin(T &a, const U &b) { if(b<a){ a=b; return 1; } return 0; }

// naive check O(sqrt(N))
inline bool is_prime(long long x) {
  if (x <= 1) return false;
  for (long long i = 2; i*i <= x; ++i) if (x % i == 0) return false;
  return true;
}

/**
 * @brief Sieve of Eratosthenes
 * @note List primes O(NloglogN)
 */
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

/**
 * @brief Prime Factorization
 * @note prime table up to sqrt(N) is enough to factorize.
 * @note O(sqrt(N))
 */
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

/**
 * @brief List divisors
 */
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

template<typename T>
T gcd(T a, T b) {
  while (a) {
    b %= a;
    swap(a, b);
  }
  return b;
}

/**
 * @note Be careful of overflow
 */
template<typename T>
T lcm(T a, T b) {
  T ret = a / gcd(a, b) * b;
  if (b <= numeric_limits<T>::max() / (a / gcd(a, b))) return ret;
  else return numeric_limits<T>::max();
}

int main() {
  long long a, b; cin>>a>>b;
  //print(a, b);
  auto primes = sieve_of_eratosthenes(2000000);
  auto prime_factor_a = prime_factorize(a, primes);
  auto prime_factor_b = prime_factorize(b, primes);
  auto divisors_a = calc_divisors(a, prime_factor_a);
  auto divisors_b = calc_divisors(b, prime_factor_b);
  //print(divisors_a);
  //print(divisors_b);

  vector<long long> common;
  int i = 0, j = 0;
  while (i < divisors_a.size() && j < divisors_b.size()) {
    if (divisors_a[i] == divisors_b[j]) {
      common.push_back(divisors_a[i]);
      ++i; ++j;
    } else if (divisors_a[i] < divisors_b[j]) {
      ++i;
    } else {
      ++j;
    }
  }
  //print(common);
  long long ans = 1;
  rep(i, common.size()) if (is_prime(common[i])) ++ans;
  print(ans);

  return 0;
}
