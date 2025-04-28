#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
 //int n,i,o;
//int sum=0;
//	cout<<"enter how many number you want";
//	cin>>n;
//	for(i=1; i<=n; i++){
//		cout<<"the number";+
//		
//		cin>>o;
//			if(i%2!=0){
//		sum=o+sum;
//	
//	}
//
//																														
//	}
//        cout<<"sum="<<sum;
    int o=0;
	int x,i;
	int a[10 ]={1,2,3,4,5,6};

      cout<<"enter the number";
      cin>>x;
	
	for(i=0;i<10;i++){
		if(x==a[i]){
		o=1;
			cout<<i;
		}
	}
	
	 if (o==0) {
			cout<<"not found";
		}
		
	
	return 0;
}
