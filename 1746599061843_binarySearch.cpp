#include <iostream>
using namespace std;

int binarySearch(int arr[],int size, int target){
	int low=0;
	int high=size-1;
	
	cout<<endl <<"target : "<< target<<endl;
	while (low <= high){
		int mid=low+(high-low)/2;
		
		if (arr[mid]==target){
			cout<<"the elemnt :"<<arr[mid];
			return mid;
		}
		else if(arr[mid]<target){
			low=mid+1;
		}
		else {
			high=mid-1;
		}
		
	} 
	return -1;	
}


int main() {
	int arr[]={1,2,3,5,10,12,14,15};
	int size=sizeof(arr)/sizeof(arr[0]);
//	cout<<size;
	int target=1;
	
	int index=binarySearch(arr,size,target);
	
	 if (index!=-1){
	 	cout<<"found the"<<target<<"  in:"<<index<<endl;
	 }
	 else {
	 	cout <<"the element"<<target<<" not found"<<endl;
	 }
	
	
	return 0;
	
	
	
}
