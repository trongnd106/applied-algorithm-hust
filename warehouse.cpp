// accepted 5/5

#include <bits/stdc++.h>

using namespace std;

struct node{
    int a, t;
    node *next;
    node(int a1, int t1, node *n){
        a = a1;
        t = t1;
        next = n;
    }
};

node *s[1001];

int main(){
    int n, T, D, a[1001], t[1001], mx = 0;
    cin >> n >> T >> D;
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &t[i]);
        s[i] = new node(a[i], T - t[i], 0);
    }
    
    for(int i = 2; i <= n; ++i){
        int opt[T] = {};
        for(int j = 1; j <= D && j < i; ++j){
            node *temp = s[i - j];
            while(temp){
                int tt = temp->t - t[i], at = temp->a + a[i];
                if(tt >= 0 && opt[tt] <= at){
                    opt[tt] = at;
                    s[i] = new node(at, tt, s[i]);
                    mx = max(s[i]->a, mx);
                }
                temp = temp->next;
            }
        }
    }
    cout << mx;
}
