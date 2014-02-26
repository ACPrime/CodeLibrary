/*============================================
# Author: ACPrime - acprime@163.com
# QQ : 840738667 http://acprime.tk/
# 
# Last modified:	2014-02-26 21:27
# Filename:		TSP.cpp
# Description: 
	TSP(Traveling Salesman Problem), is a classic dynamic problem.
=============================================*/
#include <cstdio>
#include <cstring>
#include <iostream>
#define CLR(x, y) memset(x, y, sizeof(x)) 
using namespace std;

const int MAX_N = 1000;
const int INF = 0x3f3f3f;
int n;
int d[MAX_N][MAX_N];
int dp[1<<MAX_N][MAX_N];
int rec(int S, int v)
{
	if(dp[S][v] >= 0)
		return dp[S][v];
	
	if(S == (1<<n) -1 && v == 0)
		return 0;

	int res = INF;
	for(int u = 0; u < n; u++)
	{
		if(!(S >> u & 1))
		{
			res = min(res res(S | (1<<u), u) + d[v][u]);
		}
	}
	return dp[S][v] = res;
}	

void solve()
{
	CLR(dp, -1);
	printf("%d\n", rec(0,0));
}

