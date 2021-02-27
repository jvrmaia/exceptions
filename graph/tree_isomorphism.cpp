struct Node {
    vector<Node *> child;
};
bool otreeIsomorphism(Node *n, Node *m) {
    if (n->child.size() != m->child.size()) return false;
    REP(i, n->child.size())
        if (!otreeIsomorphism(n->child[i], m->child[i])) return false;
    return true;
}

///////////////////////////////////

struct Node {
    vector<Node *> child;
    vector<int> code;
};
void code(Node *n) {
    int size = 1;
    vector< pair<vector<int>, int> > codes;
    REP(i, n->child.size()) {
        code(n->child[i]);
        codes.push_back( make_pair(n->child[i]->code, i) );
        size += codes[i].first[0];
    }
    sort(codes.rbegin(), codes.rend()); // !reverse
    n->code.push_back(size);
    for (int i = 0; i < n->child.size(); ++i) {
        swap(n->child[i], n->child[ codes[i].second ]);
        n->code.insert(n->code.end(),
                codes[i].first.begin(), codes[i].first.end());
    }
}
bool utreeIsomorphism(Node *n, Node *m) {
    code(n); code(m); return n->code == m->code;
}

