long long sum(int *a, int n) {
    register long long i; 
	register long long ans = 0;
    for(i=0;i<n;i++)
        ans+=a[i];
	return ans;
}
