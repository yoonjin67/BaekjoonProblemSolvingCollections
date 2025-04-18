#include<stdio.h>

int main() {
	int n,m,i;
	scanf("%d %d", &n,&m);
	int basket[n];
	for(i=1;i<=n;i++) {
		basket[i-1]=i;
	}
	for(i=0;i<m;i++) {
		int v,w;
		scanf("%d %d", &v, &w);
		if(v==w) continue;
		while(v<w) {
		    basket[v-1]^=basket[w-1];
		    basket[w-1]^=basket[v-1];
		    basket[v-1]^=basket[w-1];
		    v++;
		    w--;
		}
	}
	for (int i=0;i<n;i++) {
		if(i!=n-1) printf("%d ", basket[i]); else printf("%d", basket[i]);
	}
	return 0;
}
