// Segment Tree Simulation - query Max

#include<iostream>
#include<climits>
#include<algorithm>
#include<cmath>

using namespace std;

// struct SegmentTree {
//     int id;
//     int left,right;
//     int maxVal;
//     SegmentTree(int nodeId, int l, int r) : id(nodeId), left(l), right(r), maxVal(0) {}
// };

// vector<SegmentTree> st;
// int n;

int getMaxFromNode(int id, int left, int right, int start, int end, int *st){
    if(start > right || end < left) return INT_MIN;
    if(start <= left && end >= right)
        return st[id];
    int mid = (left+right)/2;
    int LC = 2*id ;
    int RC = 2*id + 1;
    int maxLeft = getMaxFromNode(LC,left,mid,start,end,st);
    int maxRight = getMaxFromNode(RC,mid+1,right,start,end,st);
    return max(maxLeft,maxRight);
}

void updateFromNode(int id, int left, int right, int index, int value, int arr[], int *st){
    if(left > right) return;
    if(index < left || index > right) return;
    if(left == right){
        arr[index] = value;
        st[id] = value;
        return;
    }
    else {
        int LC = 2*id;
        int RC = 2*id + 1;
        int mid = (left + right)/2;
        updateFromNode(LC,left,mid,index,value,arr,st);
        updateFromNode(RC,mid+1,right,index,value,arr,st);
        st[id] = max(st[LC], st[RC]);
    }
}

void buildSegmentTree(int id, int left, int right, int *st, int arr[]){
    if (left == right) {
        st[id] = arr[left];
        return;
    }
    int mid = (left + right) / 2;
    int LC = 2*id ;
    int RC = 2*id + 1;
    buildSegmentTree(LC, left, mid, st, arr);
    buildSegmentTree(RC, mid + 1, right, st, arr);
    st[id] = max(st[LC], st[RC]);
}

int *constructST(int arr[], int n){
    int x = (int)(ceil(log2(n)));
	int max_size = 2 * (int)pow(2, x) - 1;
	int* st = new int[max_size];
	buildSegmentTree(1, 0, n - 1, st, arr);
	return st;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int arr[n];
    for(int i = 1; i <= n; i++) cin >> arr[i];
    int *st = constructST(arr,n);
    int q; cin >> q;
    while(q--){
        string queryChoose;
        cin >> queryChoose;
        if(queryChoose == "get-max"){
            int i,j; cin >> i >> j;
            cout << getMaxFromNode(1,0,n-1,i,j,st) << endl;
        }
        if(queryChoose == "update"){
            int k,v; cin >> k >> v;
            updateFromNode(1,0,n-1,k,v,arr,st);
        }
    }
    return 0;
}
