ll K, lim;
ll a[N], b[N], c[N];
ll A[N], B[N];

void OR(ll *F, ll op) {
    for (ll o = 2; o <= lim; o <<= 1) {
        for (ll i = 0, k = o >> 1; i < lim; i += o) {
            for (ll j = 0; j < k; j++) {
                F[i + j + k] = (F[i + j + k] + F[i + j] * op + p) % p;
            }
        }
    }
}

void AND(ll *F, ll op) {
    for (ll o = 2; o <= lim; o <<= 1) {
        for (ll i = 0, k = o >> 1; i < lim; i += o) {
            for (ll j = 0; j < k; j++) {
                F[i + j] = (F[i + j] + F[i + j + k] * op + p) % p;
            }
        }
    }
}

void XOR(ll *F, ll op) {
    for (ll o = 2; o <= lim; o <<= 1) {
        for (ll i = 0, k = o >> 1; i < lim; i += o) {
            for (ll j = 0; j < k; j++) {
                ll X = F[i + j], Y = F[i + j + k];
                F[i + j] = (X + Y) * (op == 1 ? 1 : inv2) % p;
                F[i + j + k] = (X - Y + p) * (op == 1 ? 1 : inv2) % p;
            }
        }
    }
}

void FWT(ll *H, ll *F, ll *G) {
    for (int i = 0; i < lim; i++) A[i] = F[i], B[i] = G[i];
    OR(A, 1);
    OR(B, 1);
    for (int i = 0; i < lim; i++) A[i] = A[i] * B[i] % p;
    OR(A, -1);
    for (int i = 0; i < lim; i++) H[i] = A[i];
}

int main() {
    K = read();
    lim = 1 << K;
    for (ll i = 0; i < lim; i++) a[i] = read();
    for (ll i = 0; i < lim; i++) b[i] = read();
    FWT(c, a, b);
    for (ll i = 0; i < lim; i++) cout << c[i] << " ";
    return 0;
}