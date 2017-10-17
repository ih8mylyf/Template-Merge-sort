#include <iostream>
#include <cassert>

using namespace std;

void msort(int a[], int x[], int s, int e) {
	if(e-s > 1){
		int m = (s+(e-1))/2;
		msort(a, x, s, m+1);
		msort(a, x, m+1, e);
		int j = s;
		int c = m+1;
		int t = s;
	    	while(j < m+1 && c < e){
			if(a[j]>=a[c]) x[t++] = a[c++];
			else x[t++]=a[j++];
	   	 }
	   	 while(j < m+1) x[t++] = a[j++];
	    	while(c < e) x[t++] = a[c++];
	    	for(int q=s;q < e;q++) a[q] = x[q];
	}
}

void mergesort(int a[], int n) {
	int *x = new int[n];
	msort(a, x, 0, n);
	delete []x;
}

bool sorted(int a[], int n) {
	for (int x = 0;x < n-1;x++)
		if (a[x] > a[x+1]) return false;
		return true;
}

int main(int argc, char * args[]) {
	int a[1000];
	for (int i = 0; i < 1000; ++i) a[i] = -50 + rand() % 100;
	mergesort(a, 1000);
	assert(sorted(a, 1000));
	int b[1001];
	for (int i = 0; i < 1001; ++i) b[i] = -50 + rand() % 100;
	mergesort(b, 1001);
	assert(sorted(b, 1001));
	int c[] = { 2 };
	mergesort(c, 1);
	assert(sorted(c, 1));
	int d[] = { 1, 2, 3, 4, 5 };
	mergesort(d, 5);
	assert(sorted(d, 5));
	int e [0];
	mergesort (e, 0);
	assert (sorted (e, 0));
	int f[]={10};
	mergesort (f, 0);
	assert (sorted (f, 0));
  
	cout << "All tests passed." << endl;    
}
