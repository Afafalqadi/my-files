#include <iostream> 
#include <iomanip> 
#include <vector> 
#include <algorithm>
#include <queue> 
 using namespace std;

struct Process { 
int id; 
int arrivalTime; 
int burstTime; 
int remainingTime; 
int waitingTime; 
int turnaroundTime;
 int priority; 
 };

void printTable(const vector<Process>& processes) {
 double totalWaiting = 0, totalTurnaround = 0; 
 cout << "\nProcess Table:\n"; 
 cout << "ID\tArrival\tBurst\tWaiting\tTurnaround\n"; 
 for (const auto& p : processes)//name vector 
 {
  cout << p.id << "\t" << p.arrivalTime << "\t" << p.burstTime << "\t" << p.waitingTime << "\t" << p.turnaroundTime << "\n";
   totalWaiting += p.waitingTime;
    totalTurnaround += p.turnaroundTime;
	 } 
	 cout << fixed << setprecision(2); 
	 cout << "\nAverage Waiting Time: " << totalWaiting / processes.size() << "\n"; 
	 cout << "Average Turnaround Time: " << totalTurnaround / processes.size() << "\n"; 
	 }

void fcfs(vector<Process> processes) {
 int currentTime = 0;
 
  sort(processes.begin(), processes.end(), [](Process a, Process b) {
   return a.arrivalTime < b.arrivalTime; 
   });
   
    for (auto& p : processes) {
	 if (currentTime < p.arrivalTime)
	 
	 currentTime = p.arrivalTime; 
	 p.waitingTime = currentTime - p.arrivalTime;
	  currentTime += p.burstTime;
	   p.turnaroundTime = p.waitingTime + p.burstTime; 
	  } 
	  printTable(processes); 
	  }
	  
	  
	  

void sjf(vector<Process> processes) { 
int time = 0, completed = 0;
 vector<bool> done(processes.size(), false);
 
  while (completed < processes.size()) { 
  int idx = -1; 
  int minBT = 1e9;
   for (int i = 0; i < processes.size(); i++) { 
   
   if (!done[i] && processes[i].arrivalTime <= time && processes[i].burstTime < minBT) {
    minBT = processes[i].burstTime; 
	idx = i; 
	} 
	} 
	
	if (idx != -1) { 
	processes[idx].waitingTime = time - processes[idx].arrivalTime; 
	time += processes[idx].burstTime; 
	processes[idx].turnaroundTime = time - processes[idx].arrivalTime;
	 done[idx] = true; 
	 completed++;
	  } 
	else { time++; } }
	 printTable(processes); }



void priorityScheduling(vector<Process> processes) {
 int time = 0, completed = 0;
  vector<bool> done(processes.size(), false);
  
   while (completed < processes.size()) { 
   int idx = -1, highest = 1e9;
    for (int i = 0; i < processes.size(); i++) { 
    
	if (!done[i] && processes[i].arrivalTime <= time && processes[i].priority < highest) {
	 highest = processes[i].priority;
	  idx = i; 
	  } }
	  if (idx != -1) { 
	  processes[idx].waitingTime = time - processes[idx].arrivalTime;
	   time += processes[idx].burstTime; 
	   processes[idx].turnaroundTime = time - processes[idx].arrivalTime; 
	   done[idx] = true;
	    completed++;
	   
	    } else { time++; } 
		} printTable(processes); }



void roundRobin(vector<Process> processes, int quantum){
 queue<int> q; //create queue to add index 
 int time = 0, completed = 0;
 
  for (int i = 0; i < processes.size(); i++) {
   processes[i].remainingTime = processes[i].burstTime; 
   } 
   vector<bool> inQueue(processes.size(), false);

while (completed < processes.size()) {
    for (int i = 0; i < processes.size(); i++) {
        if (!inQueue[i] && processes[i].arrivalTime <= time) {
            q.push(i);
            inQueue[i] = true;
        }
    }

    if (!q.empty()) {
        int i = q.front();
		 q.pop();
        int execTime = min(quantum, processes[i].remainingTime);
        time += execTime;
        processes[i].remainingTime -= execTime;

//to check from new prosses
        for (int j = 0; j < processes.size(); j++) {
            if (!inQueue[j] && processes[j].arrivalTime <= time) {
                q.push(j);
                inQueue[j] = true;
            }
        }

        if (processes[i].remainingTime > 0) {
            q.push(i);
        } else 
		{
            processes[i].turnaroundTime = time - processes[i].arrivalTime;
            processes[i].waitingTime = processes[i].turnaroundTime - processes[i].burstTime;
            completed++;
        }
    } else {
        time++;
    }
}
printTable(processes);

}


int main() { 
int n; 
cout << "Enter the number of processes: ";
 cin >> n;

vector<Process> processes(n), original(n);
for (int i = 0; i < n; i++) {
    processes[i].id = i + 1;
    cout << "\nProcess " << i + 1 << ":\n";
    cout << "Arrival Time: ";
    cin >> processes[i].arrivalTime;
    cout << "Burst Time: ";
    cin >> processes[i].burstTime;
    cout << "Priority (lower = higher priority): ";
    cin >> processes[i].priority;
    original[i] = processes[i];
}

int choice;
do {
    cout << "\nChoose Scheduling Algorithm:\n";
    cout << "1. FCFS\n2. SJF\n3. Priority\n4. Round Robin\n0. Exit\nYour choice: ";
    cin >> choice;

    processes = original;

    switch (choice) {
        case 1: fcfs(processes); break;
        case 2: sjf(processes); break;
        case 3: priorityScheduling(processes); break;
        case 4:
            int quantum;
            cout << "Enter Quantum Time: ";
            cin >> quantum;
            roundRobin(processes, quantum);
            break;
        case 0:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
    }
} while (choice != 0);

return 0;

}
