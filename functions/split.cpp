vector<string> split(string s, string t) {
    vector<string> v;
    int p = s.find(t);
    if (p != s.npos) {
        v.push_back(s.substr(0, p));
        s = s.substr(p + t.size());
    }
    v.push_back(s);
    return v;
}
