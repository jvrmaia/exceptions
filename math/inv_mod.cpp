// invMod
//   requisits: extgcd
//   x a == 1 (mod n
int invMod(Int a, Int m) {
    Int x, y;
    if (extgcd(a, m, x, y) == 1) return (x + m) % m;
    else                         return 0; // unsolvable
}
