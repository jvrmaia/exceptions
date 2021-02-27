string replaceAll(string s, string f, string t) {
    string r;
    for (int p = 0; (p = s.find(f)) != s.npos; ) {
        r += s.substr(0, p) + t;
        s = s.substr(p + f.size());
    }
    return r + s;
}
