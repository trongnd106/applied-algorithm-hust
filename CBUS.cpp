
#include<bits/stdc++.h>

using namespace std;

int n, k, N, load, fopt, f, g;
long long cmin;
int c[23][23], visited[23*23], x[23*23];

bool UCV(int i){   // khach co the den duoc ben?
	if (i <= n){    // khach hang i len xe tai diem i
		return (!visited[i] && load < k);
	}
	else {		// khach (i-n) xuong xe tai diem i
		return (!visited[i] && visited[i-n]);
	}
}

void Try(int k){
	for(int i = 1; i <= 2*n; i++){
		if(UCV(i)){
			x[k] = i;
			if(i <= n) load++;
			else load--;
			visited[i] = 1;
			f = f + c[x[k-1]][i];
			if (k == 2*n){
				// ghi nhan ki luc
				int ftemp = f + c[x[k]][0];
				if(ftemp < fopt) fopt = ftemp;
			}
			g = f + (2*n-k+1)*cmin;
			if(g < fopt) Try(k+1);
			visited[i] = 0;
			f -= c[x[k-1]][i];
			if(i <= n) load--;
			else load++;
		}	
	}
}


int main(){
	cmin = 1e8;
	cin >> n >> k;
	int N = 2*n;
	for(int i = 0; i <= N; i++){
		for(int j = 0; j <= N; j++){
			cin >> c[i][j];
			if (i != j && cmin > c[i][j])	
				cmin = c[i][j];
		}
		visited[i] = 0;
	}
	load = 0; x[0] = 0;
	fopt = 1e8; f = 0;
	Try(1);
	cout << fopt << endl;
	return 0;
}
