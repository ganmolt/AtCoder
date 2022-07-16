struct COM{
    Int n, mod;
    vector<Int> fac,finv,inv;

    COM(Int n, Int m): n(n), mod(m){
        fac.resize(n+1);
        finv.resize(n+1);
        inv.resize(n+1);
        COMinit();
    }
    // テーブルを作る前処理
    void COMinit() {
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1] = 1;
        for (int i = 2; i <= n; i++){
            fac[i] = fac[i-1] * i % mod;
            inv[i] = mod - inv[mod%i] * (mod / i) % mod;
            finv[i] = finv[i-1] * inv[i] % mod;
        }
    }

    // 二項係数計算
    Int nCk(int n, int k){
        if (n < k) return 0;
        if (n < 0 || k < 0) return 0;
        return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
    }
};