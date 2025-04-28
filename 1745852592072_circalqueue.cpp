#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

const int max_size=5;
int queue[max_size];
int front=-1;
int rear=-1;

bool isfull(){
	return ((rear+1)%max_size==front);
}

bool isempty(){
	return front==-1;
}

void enqueue(){
	if (isfull()){
		cout<<"Queue is full, cannot add more element"<<endl;
		return;
	}
	if (isempty()){
		front=0;
	}
	rear=(rear+1)%max_size;
    cin>>queue[rear];
	cout<<"element added to the queue"<<endl;
	
}

void dequeue(){
	if (isempty()){
		cout<<"queue is empty cannot remove element\n";
		return;
	}
	int element =queue[front];
	cout<<"element"<<element<<"removed from the queue\n";
	
	if (front==rear){
		front=rear=-1;
	}else 
	{
		front=(front+1)%max_size;
	}
}

int getfront(){
	if (isempty()){
		cout<<"queue is empty\n";		return -1;
	}
	return queue[front];
}

void displayqueue(){
	if (isempty()){
		cout<<"queue is empty\n";
		return ;
	}
	cout <<"queue elements:";
	int i=front;
	
	while(true){
		cout<<queue[i]<<"";
		if(i==rear) break;
		i=(i+1)%max_size;
	}
	cout<<endl;
}

int main(int argc, char** argv) {
	
	  int choice;
 
   while (true){
   	cout<<"\n1. enqueu \n2. dequeue \n3. displayqueue \n ";
		cout<<"enter your choice:";
		cin>>choice;
		
		switch (choice){
			case 1:
				cout<<"enter the value:";
				enqueue();
				break;
			case 2:
				cout<<" the value that deleted:";
				dequeue();
				break;	
				
			case 3:
				displayqueue();
				break;
				
			default:
				cout<<"invalid choice !"; 
	
				
		}
	}
	
	
	
	
	
	
//	enqueue(10);
//	enqueue(20);
//	enqueue(30);
//	enqueue(40);
//	enqueue(50);
	
//	displayqueue();
//	dequeue();
//	enqueue(60);
//	
//	displayqueue();
//	cout<<"front element in the queue:"<<getfront()<<endl;
	return 0;
}
