#include <stdio.h>
#define MAX 20

typedef struct {
    int pid, at, bt, start, ct, rt, tat, wt, in_q;
} Process;

// Queue control ----
int front = -1, rear = -1;
int c_queue[MAX];

void enqueue(int process) {
    if (rear == -1) {
        front = 0;
        rear = 0;
        c_queue[rear] = process;
    }
    else if (front == (rear + 1)%MAX) {
        printf("Queue is full.\n");
    }
    else{
        rear = (rear+1) % MAX;
        c_queue[rear] = process;
    }
}

int dequeue() {
    int process;
    if (front == -1) {
        printf("Queue empty.\n");
        process = -1;
    }
    else if (front == rear) {
        process = c_queue[front];
        front = -1;
        rear = -1;
    }
    else {
        process = c_queue[front];
        front = (front+1)%MAX;
    }
    return process;
}

int isEmpty() {
    if (front==-1 && rear ==-1)
        return 1;
    else 
        return 0;
}
// ----

int main() {
    Process proc[10];
    Process temp;
    int i, n, j, t_qu;
    float total_tat = 0, total_wt = 0;
    printf("Enter the number of processes : ");
    scanf("%d",&n);
    printf("Enter the time quantum : ");
    scanf("%d",&t_qu);
    
    for (i=0; i<n; i++) {
        printf("Enter arrival time, burst time of process %d : ",i+1);
        scanf("%d %d", &proc[i].at, &proc[i].bt);
        proc[i].pid = i+1;
        proc[i].in_q = 0;
        proc[i].rt = proc[i].bt;
    }
    
    // insertion sort acc to arrival time
    for (i=1; i<n; i++) {
        temp = proc[i];
        j = i - 1;
        while (j>=0 && proc[j].at > temp.at) {
            proc[j+1] = proc[j];
            j--;
        }
        proc[j+1] = temp;
    }
    
    int complete = 0, index, t=0;
    
    t = proc[0].at;
    enqueue(0);
    
    while (complete < n) {
        index = -1; // resetting index everytime handles if a process is not in queue

        if (!isEmpty()) {
            index = dequeue(); // q front is processed
    
            proc[index].in_q = 1; // prevents being selected in for loop below 

            if (proc[index].bt == proc[index].rt) {
                proc[index].start = t;
            }
            if (proc[index].rt <= t_qu) {
                t += proc[index].rt;
                proc[index].rt = 0;
                proc[index].ct = t;
                complete++;
            }
            else {
                t += t_qu;
                proc[index].rt -= t_qu;
            }
        }
        // we search for new processes that have not yet arrived
        for (i=0; i<n; i++) {
            if (proc[i].rt > 0 && !proc[i].in_q && proc[i].at <= t) {
                enqueue(i);
                proc[i].in_q = 1;
            }
        }
        // index is queued behind again only after processes till time - t have arrived
        if (index != -1 && proc[index].rt > 0) {
            enqueue(index);
            proc[index].in_q = 1;
        }
        // if queue is empty we increment time
        if (isEmpty()) {
            t++;
        }
        
    }    
    
    for (i=0; i<n; i++) {
        proc[i].tat = proc[i].ct - proc[i].at;
        proc[i].wt = proc[i].tat - proc[i].bt;
        
        total_tat += proc[i].tat;
        total_wt += proc[i].wt;
    }
    
    printf("PID\tART\tBRT\tCT\tTAT\tWT\n");
    for (i=0; i<n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",proc[i].pid, proc[i].at, proc[i].bt,  proc[i].ct, proc[i].tat, proc[i].wt);
            
    }
    printf("Average Turnaround Time : %.2f \n",total_tat/n);
    printf("Average Waiting Time : %.2f \n",total_wt/n);
    
    return 0;
}
