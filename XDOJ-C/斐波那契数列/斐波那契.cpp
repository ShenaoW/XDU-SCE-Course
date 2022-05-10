int fib(int n)
{
	int f[40],i;
	f[0]=7;
	f[1]=11;
	for(i=2;i<=n;i++)
	f[i]=f[i-1]+f[i-2];
	return f[n];
}
