struct PMA {
    PMA *next[0x100]; // next[0] is for fail
    vector<int> accept;
    PMA() { fill(next, next+0x100, (PMA*)0); }
};
PMA *buildPMA(char *p[], int size) {
    PMA *root = new PMA;
    for (int i = 0; i < size; ++i) { // make trie
        PMA *t = root;
        for (int j = 0; p[i][j]; ++j) {
            char c = p[i][j];
            if (t->next[c] == NULL) t->next[c] = new PMA;
            t = t->next[c];
        }
        t->accept.push_back(i);
    }
    queue<PMA*> Q; // make failure link using bfs
    for (int c = 'a'; c <= 'z'; ++c) {
        if (root->next[c]) {
            root->next[c]->next[0] = root;
            Q.push(root->next[c]);
        } else root->next[c] = root;
    }
    while (!Q.empty()) {
        PMA *t = Q.front(); Q.pop();
        for (int c = 'a'; c <= 'z'; ++c) {
            if (t->next[c]) {
                Q.push(t->next[c]);
                PMA *r = t->next[0];
                while (!r->next[c]) r = r->next[0];
                t->next[c]->next[0] = r->next[c];
            }
        }
    }
    return root;
}
int match(char *t, PMA *v, int *result) {
    int n = strlen(t);
    int count = 0;
    for (int i = 0; i < n; ++i) {
        char c = t[i];
        while (!v->next[c]) v = v->next[0];
        v = v->next[c];
        for (int j = 0; j < v->accept.size(); ++j)
            result[v->accept[j]]++;
    }
}
