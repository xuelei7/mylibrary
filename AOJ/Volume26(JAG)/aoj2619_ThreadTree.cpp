// Nathan O. Davis has been running an electronic bulletin board system named JAG-channel. He is now having hard time to add a new feature there --- threaded view.

// Like many other bulletin board systems, JAG-channel is thread-based. Here a thread (also called a topic) refers to a single conversation with a collection of posts. Each post can be an opening post, which initiates a new thread, or a reply to a previous post in an existing thread.

// Threaded view is a tree-like view that reflects the logical reply structure among the posts: each post forms a node of the tree and contains its replies as its subnodes in the chronological order (i.e. older replies precede newer ones). Note that a post along with its direct and indirect replies forms a subtree as a whole.

// Let us take an example. Suppose: a user made an opening post with a message hoge; another user replied to it with fuga; yet another user also replied to the opening post with piyo; someone else replied to the second post (i.e. fuga”) with foobar; and the fifth user replied to the same post with jagjag. The tree of this thread would look like:

// hoge
// ├─fuga
// │　├─foobar
// │　└─jagjag
// └─piyo
// For easier implementation, Nathan is thinking of a simpler format: the depth of each post from the opening post is represented by dots. Each reply gets one more dot than its parent post. The tree of the above thread would then look like:

// hoge
// .fuga
// ..foobar
// ..jagjag
// .piyo
// Your task in this problem is to help Nathan by writing a program that prints a tree in the Nathan's format for the given posts in a single thread.

// Input
// Input contains a single dataset in the following format:

// n
// k1
// M1
// k2
// M2
// :
// :
// kn
// Mn
// The first line contains an integer n (1≤n≤1,000), which is the number of posts in the thread. Then 2n lines follow. Each post is represented by two lines: the first line contains an integer ki (k1=0, 1≤ki<i for 2≤i≤n) and indicates the i-th post is a reply to the ki-th post; the second line contains a string Mi and represents the message of the i-th post. k1 is always 0, which means the first post is not replying to any other post, i.e. it is an opening post.

// Each message contains 1 to 50 characters, consisting of uppercase, lowercase, and numeric letters.

// Output
// Print the given n messages as specified in the problem statement.

#include <bits/stdc++.h>
using namespace std;

vector<int> G[1010];
string str[1010];

void dfs(int id, int lv) {
    for (int i = 0; i < lv; i++) {
        cout << ".";
    }
    cout << str[id] << endl;
    for (int i = 0; i < G[id].size(); i++) {
        dfs(G[id][i],lv+1);
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int id;
        cin >> id >> str[i];
        id--;
        if (id < 0) continue;
        G[id].push_back(i);
    }
    dfs(0,0);
    return 0;
}