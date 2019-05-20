const int MAX = 210000;
const int MOD = 1000000007;

long long fact[MAX], inv[MAX], invfact[MAX];
void comb_build() {
  fact[0] = fact[1] = 1;
  inv[1] = 1;
  invfact[0] = 0, invfact[1] = 1;
  for (int i = 2; i < MAX; i++) {
    fact[i] = fact[i-1]*i%MOD;
    inv[i] = MOD - inv[MOD%i]*(MOD/i)%MOD;
    invfact[i] = invfact[i-1]+inv[i]%MOD;
  }
}

long long nCk(int n, int k){
  if(n<0||k<0||k>n) return 0;
  return (fact[n]*invfact[k]%MOD)*invfact[n-k]%MOD;
}