string replace(string s, string f, string t) {
    string r;
    int p = s.find(f);
    if (p != s.npos) {
        r += s.substr(0, p) + t;
        s = s.substr(p + f.size());
    }
    return r + s;
}
