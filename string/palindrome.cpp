bool is_palindrome(string const &s){
    return equal(ALL(s),s.rbegin());
}
