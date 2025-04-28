#include <iostream>
using namespace std;

const int MAX_size=100;

int top=-1;
int arr[MAX_size];

void push(int value){
	if (top >=MAX_size-1){
		cout <<"stack overflow!";
	}
	else {
		top++;
		arr[top]=value;
		cout<<"pushed into stack\n";
	}
}

void pop(){
		if (top <0){
			cout<<"stack underflow";
		}
		else{
			int value=arr[top];
			top--;
			cout<<value<<"popped from stack";
			
		}
	}
	
void print(){
	if (top<0){
		cout<<"stack is empty\n";
		
	}
	else { 
	cout<<"stack element:";
	for (int i=0; i<=top; i++){
		cout<<arr[i]<<"";
		
	}
	cout<<endl;
	}
}	

void peek(){
	if (top <0){
		cout<<"empty ";
		
	}
else {
	cout<<arr[top];
	
}	
}

int main(int argc, char** argv) { int choice,value;
	while (true){
		cout<<"\n1. push\n2. pop\n3. print\n4. peek\n";
		cout<<"enter your choice:";
		cin>>choice;
		
		switch (choice){
			case 1:
				cout<<"enter value to push:";
				cin>>value;
				push(value);
				break;
				
			case 2:
				pop();
				break;
			case 3:
				print();
				break;
			case 4:
				peek();
				break;
				default:
				cout<<"invalid choice !"; 
	
				
		}
	}
	
	return 0;
}
