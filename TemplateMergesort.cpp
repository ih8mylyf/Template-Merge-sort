#include <iostream>
#include <cassert>

using namespace std;

template <class T>
void msort(T a[], T x[], int s, int e) {
	if(e-s > 1){
		int m = (s+(e-1))/2;
		msort(a, x, s, m+1);
		msort(a, x, m+1, e);
		int j = s;
		int c = m+1;
		int t = s;
	    	while(j < m+1 && c < e){
			if(a[j] >= a[c]) x[t++] = a[c++];
			else x[t++] = a[j++];
	   	 }
	   	 while(j < m+1) x[t++] = a[j++];
	    	while(c < e) x[t++] = a[c++];
	    	for(int q=s; q < e; q++) a[q] = x[q];
	}
}

template <class T>
void mergesort(T a[], int n) {
	T *x = new T[n];
	msort(a, x, 0, n);
	delete []x;
}

template <class T>
bool sorted(T a[], int n) {
	for (int x = 0; x < n-1; x++)
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
	double f []={-12.4, -12.3, 12.4, 12.3, 27.89, 0, 5, 6.7, 3.14};
	mergesort<double>(f, 9);
	assert (sorted (f,9));
	float g [] = {1.1, 4, -9, 90.67, 1.5, -67.5, 0, 90.67, 1.3, 1.1};
	mergesort <float>(g, 10);
	assert (sorted (g, 10));
  
	cout << "All tests passed." << endl;    
}
