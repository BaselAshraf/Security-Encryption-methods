#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

void main(){

	long long M,N;
	long long addative=0;
	long long multiplicative=0;
	long long T1=0, T2=0, T3=0;
	string Error;
	
	cin >> M >> N;

	if (M>N){
		addative=M-N;
		
	}
	else if (M<N){
		addative= ((M-N)%M) + M;
		
	}
	long long A1=1, A2=0, A3=M, B1=0, B2=1, B3=N, Q=0;


	while (B3!=0){
		if (B3==1)
		{
			if ((B2%M)<0)
				multiplicative=(B2%M)+M;
			else {multiplicative=(B2%M);}

			break;
		}
		Q=A3/B3;
		T1=A1-Q*B1;
		T2=A2-Q*B2;
		T3=A3-Q*B3;
		A1=B1;
		A2=B2;
		A3=B3;
		B1=T1;
		B2=T2;
		B3=T3;
	}

	if (B3==0)
	{
		Error="IMPOSSIBLE";
		cout << Error << endl;
		return;
	}

	cout << addative << " " << multiplicative << endl;
}