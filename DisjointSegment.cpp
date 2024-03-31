#include<iostream>
#include<algorithm>

using namespace std;

struct segment {
    int a, b;
};
segment s[100002];
bool cmp(segment &s1, segment &s2){
    return s1.b < s2.b;
}
int main(){
    int n; cin >> n;
    for(int i = 0;  i < n; i++) cin >> s[i].a >> s[i].b;
    sort(s, s+n, cmp);
    int last = s[0].b; 
    int ans = 1;
    for(int i =1; i < n; i++){
        if(last < s[i].a){
            ans++;
            last = s[i].b;
        }
    }
    cout << ans << endl;
    return 0;
}
