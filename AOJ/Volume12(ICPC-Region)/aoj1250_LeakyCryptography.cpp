// Problem C: Leaky Cryptography
// The ACM ICPC judges are very careful about not leaking their problems, and all communications are encrypted. However, one does sometimes make mistakes, like using too weak an encryption scheme. Here is an example of that.

// The encryption chosen was very simple: encrypt each chunk of the input by flipping some bits according to a shared key. To provide reasonable security, the size of both chunk and key is 32 bits.

// That is, suppose the input was a sequence of m 32-bit integers.

// N1 N2 N3 ... Nm

// After encoding with the key K it becomes the following sequence of m 32-bit integers.

// (N1 ∧ K) (N2 ∧ K) (N3 ∧ K) ... (Nm ∧ K)

// where (a ∧ b) is the bitwise exclusive or of a and b.

// Exclusive or is the logical operator which is 1 when only one of its operands is 1, and 0 otherwise. Here is its definition for 1-bit integers.

//      0 ⊕ 0 = 0      0 ⊕ 1 = 1
//      1 ⊕ 0 = 1      1 ⊕ 1 =0
// As you can see, it is identical to addition modulo 2. For two 32-bit integers a and b, their bitwise exclusive or a ∧ b is defined as follows, using their binary representations, composed of 0's and 1's.

// a ∧ b = a31 ... a1a0 ∧ b31 ... b1b0 = c31 ... c1c0

// where

// ci = ai ⊕ bi (i = 0, 1, ... , 31).

// For instance, using binary notation, 11010110 ∧ 01010101 = 10100011, or using hexadecimal,

// d6 ∧ 55 = a3.
// Since this kind of encryption is notoriously weak to statistical attacks, the message has to be compressed in advance, so that it has no statistical regularity. We suppose that N1 N2 ... Nm is already in compressed form.

// However, the trouble is that the compression algorithm itself introduces some form of regularity: after every 8 integers of compressed data, it inserts a checksum, the sum of these integers. That is, in the above input, N9 = ∑8i=1 Ni = N1 + ... + N8, where additions are modulo 232.

// Luckily, you could intercept a communication between the judges. Maybe it contains a problem for the finals!

// As you are very clever, you have certainly seen that you can easily find the lowest bit of the key, denoted by K0. On the one hand, if K0 = 1, then after encoding, the lowest bit of ∑8i=1 Ni ∧ K is unchanged, as K0 is added an even number of times, but the lowest bit of N9 ∧ K is changed, so they shall differ. On the other hand, if K0 = 0, then after encoding, the lowest bit of ∑8i=1 Ni ∧ K shall still be identical to the lowest bit of N9 ∧ K, as they do not change. For instance, if the lowest bits after encoding are 1 1 1 1 1 1 1 1 1 then K0 must be 1, but if they are 1 1 1 1 1 1 1 0 1 then K0 must be 0.

// So far, so good. Can you do better?

// You should find the key used for encoding.

// Input
// The input starts with a line containing only a positive integer S, indicating the number of datasets in the input. S is no more than 1000.

// It is followed by S datasets. Each dataset is composed of nine 32-bit integers corresponding to the first nine chunks of a communication. They are written in hexadecimal notation, using digits ‘0’ to ‘9’ and lowercase letters ‘a’ to ‘f’, and with no leading zeros. They are separated by a space or a newline. Each dataset is ended by a newline.

// Output
// For each dataset you should output the key used for encoding. Each key shall appear alone on its line, and be written in hexadecimal notation, using digits ‘0’ to ‘9’ and lowercase letters ‘a’ to ‘f’, and with no leading zeros.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll toll(string s){
    ll num = 0;
    for (int i = 0; i < s.size(); i++) {
        int k;
        if (s[i] >= '0' && s[i] <= '9') {
            k = s[i] - '0';
        } else {
            k = s[i] - 'a' + 10;
        }
        num = num * 16 + k;
    }
    // cout << "toll " << s << " " << bitset<32>(num) << endl;
    return num;
}
string tos(ll k) {
    if (k == 0) return "0";
    string s = "";
    // cout << "tos " << k;
    while (k > 0) {
        int kk = k % 16;
        k /= 16;
        if (kk < 10) s = (char)(kk+'0') + s;
        else s = (char)(kk-10+'a') + s;
    }
    // cout << " " << s << endl;
    return s;
}
int n;
string s[10];
ll num[10];
void solve() {
    ll key = 0;
    for (int i = 0; i < 9; i++) {
        cin >> s[i];
        num[i] = toll(s[i]);
    }
    for (ll i = 0; i < 32; i++) {
        ll sum = 0;
        for (int j = 0; j < 8; j++) {
            sum += num[j]^key;
        }
        // cout << sum << endl;
        bool cover = ((sum>>i) & 1) != ((num[8]>>i) & 1);
        // cout << i << " " << cover << endl;
        if (cover) key += (1LL<<i);
    }
    // cout << "key " << key << endl;
    cout << tos(key) << endl;
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        solve();
    }
}