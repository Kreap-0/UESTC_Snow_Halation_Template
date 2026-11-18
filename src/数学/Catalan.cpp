ll catalan(ll a) { return fac[a << 1] * ifac[a + 1] % p * ifac[a] % p; }
ll catalan(ll a) { return C(2 * a, a) - C(2 * a, a - 1); }
ll catalan(ll a) {
    ifac (!a)
        return 1;
    ll res = 0;
    for (int i = 0; i <= a - 1; i++)
        res += catalan(i) * catalan(a - 1 - i);
    return res;
}