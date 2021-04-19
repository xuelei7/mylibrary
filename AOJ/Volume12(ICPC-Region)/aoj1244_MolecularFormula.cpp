// Problem E: Molecular Formula
// Your mission in this problem is to write a computer program that manipulates molecular for- mulae in virtual chemistry. As in real chemistry, each molecular formula represents a molecule consisting of one or more atoms. However, it may not have chemical reality.

// The following are the definitions of atomic symbols and molecular formulae you should consider.

// An atom in a molecule is represented by an atomic symbol, which is either a single capital letter or a capital letter followed by a small letter. For instance H and He are atomic symbols.
// A molecular formula is a non-empty sequence of atomic symbols. For instance, HHHeHHHe is a molecular formula, and represents a molecule consisting of four H’s and two He’s.
// For convenience, a repetition of the same sub-formula  where n is an integer between 2 and 99 inclusive, can be abbreviated to (X)n. Parentheses can be omitted if X is an atomic symbol. For instance, HHHeHHHe is also written as H2HeH2He, (HHHe)2, (H2He)2, or even ((H)2He)2.
// The set of all molecular formulae can be viewed as a formal language. Summarizing the above description, the syntax of molecular formulae is defined as follows.


// Each atom in our virtual chemistry has its own atomic weight. Given the weights of atoms, your program should calculate the weight of a molecule represented by a molecular formula. The molecular weight is defined by the sum of the weights of the constituent atoms. For instance, assuming that the atomic weights of the atoms whose symbols are H and He are 1 and 4, respectively, the total weight of a molecule represented by (H2He)2 is 12.

// Input
// The input consists of two parts. The first part, the Atomic Table, is composed of a number of lines, each line including an atomic symbol, one or more spaces, and its atomic weight which is a positive integer no more than 1000. No two lines include the same atomic symbol.

// The first part ends with a line containing only the string END OF FIRST PART.

// The second part of the input is a sequence of lines. Each line is a molecular formula, not exceeding 80 characters, and contains no spaces. A molecule contains at most 105 atoms. Some atomic symbols in a molecular formula may not appear in the Atomic Table.

// The sequence is followed by a line containing a single zero, indicating the end of the input.

// Output
// The output is a sequence of lines, one for each line of the second part of the input. Each line contains either an integer, the molecular weight for a given molecular formula in the correspond- ing input line if all its atomic symbols appear in the Atomic Table, or UNKNOWN otherwise. No extra characters are allowed.

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (int)(a); (i) < (int)(b); (i)++)
#define rrep(i, a, b) for (int i = (int)(b) - 1; (i) >= (int)(a); (i)--)
#define all(v) v.begin(), v.end()

typedef long long ll;
template <class T> using V = vector<T>;
template <class T> using VV = vector<V<T>>;

/* 提出時これをコメントアウトする */
// #define LOCAL true

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl
#else
#define dbg(x) true
#endif

map<string,int> table;
int pos;
string s;
bool unknown;

int Number() {
#ifdef LOCAL
    cerr << "Num " << pos << " " << s[pos] << endl;
#endif
    int ret = 0;
    if (s[pos] >= '1' && s[pos] <= '9') {
        ret = s[pos] - '0';
        pos++;
    }
    if (s[pos] >= '0' && s[pos] <= '9') {
        ret *= 10;
        ret += s[pos] - '0';
        pos++;
    }
    if (ret == 0) return 1;
    return ret;
}

int Atom() {
#ifdef LOCAL
    cerr << "Atm " << pos << " ";
#endif
    string ret = "";
    ret += s[pos];
    pos++;
    if (s[pos] >= 'a' && s[pos] <= 'z') {
        ret += s[pos++];
    }
#ifdef LOCAL
    cerr << ret << endl;
#endif
    if (!table.count(ret)) {
        unknown = 1;
        return -1;
    }
    dbg(table[ret]);
    return table[ret];
}

int Molecule() {
#ifdef LOCAL
    cerr << "Mol " << pos << " " << s[pos] << endl;
#endif
    int ret = 0;
    while (pos < s.size() && s[pos] != ')') {
        if (s[pos] == '(') {
            pos++;
            int mole = Molecule();
            pos++;
            ret += mole * Number();
        } else {
            ret += Atom() * Number();
        }
        if (ret < 0) return -1;
    }
    dbg(ret);
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    while (getline(cin,s)) {

        // make map
        table.clear();
        do {
            stringstream ss(s);
            string atom;
            int weight;
            ss >> atom;
            if (atom == "END_OF_FIRST_PART") break;
            ss >> weight;
            table[atom] = weight;
            dbg(atom);
        } while (getline(cin,s));

        dbg("part 1");
        
        // quests
        while (getline(cin,s)) {
            string mole;
            stringstream ss(s);
            ss >> mole;
            s = mole;
            if (s == "0") break;
            dbg(s);
            pos = 0;
            unknown = 0;
            int ret = Molecule();
            if (unknown) cout << "UNKNOWN" << endl;
            else cout << ret << endl;
        }

        dbg("part 2");
    }

    return 0;
}