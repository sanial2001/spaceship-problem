
#include<bits/stdc++.h>
#include<iostream>
#define ll long long int
#define f(i, a, b) 		for(ll i = a ; i < b ; i++)
using namespace std;

double dp[1000];

void solve(double l[], ll n)
{
	if (n == 0)                                         //base case
	{
		dp[n] = l[n]+l[n+1]/2;
		return;
	}

	dp[n] = l[n] + l[n+1] / 2 + l[n-1] / 2;             //time reqd is being stored in the array
	solve(l, n - 1);                                    //recursion used to calculate each step
}

int main() {

	freopen("input.txt", "r", stdin);                   //input.txt predent int he local file and using it to read the contents
	freopen("output.txt", "w", stdout);                 //output.txt to store the final answer


	ll n;                                               //l1 is a macro already defined
	double l[n];                                        //l and array of size n to  store the contents of the array

	cin >> n;
	f(i, 0, n)                                          //input the contents if the input.txt
	cin >> l[i];                                        //storing in the array

	if (n == 1)
		cout << l[0];
	else if (n == 0)
		cout << "0";
	else
	{
		dp[n-1] = l[n-1] + l[n - 2] / 2;                //using the methodolgy to store the time required in each case
		solve(l, n - 2);

		double ans = 0;

		f(i, 0, n)
		ans+=dp[i];


		printf("%.1lf", ans);                           //final answer
	}

	return 0;
}
