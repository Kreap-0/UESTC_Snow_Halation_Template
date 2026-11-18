
void modify_path(int u, int v) {
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]])
            swap(u, v);
        l = in[top[u]], r = in[u];
        modify(1, 1, n);
        u = fa[top[u]];
    }
    if (dep[u] > dep[v])
        swap(u, v);
    l = in[u], r = in[v], modify(1, 1, n);
}

int query_path(int u, int v) {
    int ret = 0;
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]])
            swap(u, v);
        l = in[top[u]], r = in[u];
        ret = (ret + query(1, 1, n)) % Mod;
        u = fa[top[u]];
    }
    if (dep[u] > dep[v])
        swap(u, v);
    l = in[u], r = in[v];
    return (ret + query(1, 1, n)) % Mod;
}