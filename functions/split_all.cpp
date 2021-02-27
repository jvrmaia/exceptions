vector<string> splitAll(string s, string t) {
    vector<string> v;
    for (int p = 0; (p = s.find(t)) != s.npos; ) {
        v.push_back(s.substr(0, p));
        s = s.substr(p + t.size());
    }
    v.push_back(s);
    return v;
}
