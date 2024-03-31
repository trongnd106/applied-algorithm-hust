// add 2 big integers
#include<iostream>
#include<cstring>

using namespace std;
string a,b;

void standard(string a, string b){
    while(a.length() < b.length()) 
        a = "0" + a;
    while(a.length() > b.length()) 
        b = "0" + b;
}

string Sum(string a, string b){
    string result = "";
    int miss = 0;
    for(int i = a.length() - 1; i >= 0; --i){
        result = (char)(((a[i] - '0') + (b[i] - '0') + miss)%10 + '0') + result;
        miss = ((a[i] - '0') + (b[i] - '0'))/10;
    }
    if (miss > 0)
        result = '1' + result;
    return result;
}

int main(){
    cin >> a >> b;
    standard(a,b);
    cout << Sum(a,b);
    return 0;
}
