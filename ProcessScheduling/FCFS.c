#include <stdio.h>

typedef struct {
    int pid, at, bt, st, ct, tat, wt;
} Process;

int main() {
    Process proc[10];
    int i, n;
    float tat_total=0, wt_total=0;
    printf("Enter the number of processes : ");
    scanf("%d",&n);
    for (i=0; i<n; i++) {
        printf("Enter arrival time of process %d : ",i+1);
        scanf("%d",&proc[i].at);
        printf("Enter burst time of process %d : ",i+1);
        scanf("%d",&proc[i].bt);
        proc[i].pid = i+1;
        printf("\n");
    }
    
    int j;
    Process temp;
    for (i=1; i<n; i++) {
        temp = proc[i];
        j = i-1;
        while (j>=0 && proc[j].at > temp.at) {
            proc[j+1] = proc[j];
            j--;
        }
        proc[j+1] = temp;
    }
    
    int current_time=0;
    for (i=0; i<n; i++) {
        current_time = current_time > proc[i].at? current_time : proc[i].at;
        
        proc[i].st = current_time;
        proc[i].ct = current_time + proc[i].bt;
        current_time = proc[i].ct;
    }
    for (i=0; i<n; i++) {
        proc[i].tat = proc[i].ct - proc[i].at;
        proc[i].wt = proc[i].tat - proc[i].bt;
        tat_total += proc[i].tat;
        wt_total += proc[i].wt;
    }
    printf("PID\t ARR_T\t BR_T\t COMP_T\t TURN_T\t WAIT_T\n");
    for (i=0; i<n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",proc[i].pid, proc[i].at, proc[i].bt, proc[i].ct, proc[i].tat, proc[i].wt);
    }
    
    printf("Average Turnaround Time = %.2f\n",tat_total/n);
    printf("Average Waiting Time = %.2f\n",wt_total/n);
    
    printf("---GANTT CHART---\n");
    for (i=0; i<n; i++) {
        printf("%d-----P%d-----%d\n",proc[i].st, proc[i].pid, proc[i].ct);
    }
}
