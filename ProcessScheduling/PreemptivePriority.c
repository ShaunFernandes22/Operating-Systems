#include <stdio.h>
#include <stdbool.h>

// preemptive priority
typedef struct {
    int pid, art, brt, pr, start, ct, rt, tat, wt; 
} Process;


int main() {
    Process proc[10];
    int i, n, total_tat=0, total_wt=0;
    printf("Enter the number of processes : ");
    scanf("%d",&n);

    for (i = 0; i<n; i++)
    {
        printf("Enter the arrival and burst time and Priority of Process %d : ",i+1);
        scanf("%d %d %d",&proc[i].art,&proc[i].brt,&proc[i].pr);
        proc[i].pid = i+1;
    }
    
    for (i=0; i<n; i++)
        proc[i].rt = proc[i].brt;
    
    int t = 0, high_pr = -1, complete = 0, index;
    bool inQ = false;

    while (complete != n)
    {
        for (i=0; i<n; i++)
        {
            if (proc[i].art <= t && proc[i].pr > high_pr && proc[i].rt > 0)
            {
                index = i;
                high_pr = proc[i].pr;
                inQ = true;
            }
        }
            if (proc[index].brt == proc[index].rt){
                proc[index].start = t;
            }
            if (inQ == false) {
                t++;
                continue;
            }    
            
            proc[index].rt--;
            t++;
            
            if (proc[index].rt == 0)
            {
                proc[index].ct = t;
                high_pr = -1;
                complete++;
                inQ = false;
            }    
    }
    
    for (i =0;i<n;i++)    
    {
        proc[i].tat = proc[i].ct - proc[i].art;
        proc[i].wt = proc[i].tat - proc[i].brt;
        total_tat += proc[i].tat;
        total_wt += proc[i].wt;
    }
    printf("PID \t ARR \t BRR \t PRI \t CT \t TAT \t WT \n");
    for (i =0;i<n;i++)    
    {
        printf(" %d \t\t %d \t\t %d \t\t %d \t\t%d\t\t%d\t\t%d\n",proc[i].pid, proc[i].art, proc[i].brt, proc[i].pr, proc[i].ct, proc[i].tat, proc[i].wt);
    }
    printf("\n");
    for(int i=0; i<n; i++){
        printf("%d....P%d....%d\n",proc[i].start, proc[i].pid ,proc[i].ct);
    }
    printf("The average turnaround time is %.2f \n",total_tat/(float)n);
    printf("The average waiting time is %.2f \n",total_wt/(float)n);
    
    return 0;
}
