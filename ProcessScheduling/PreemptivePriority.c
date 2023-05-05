#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int art, brt, pr, start; 
} Process;

int tat[10], wt[10], rt[10], ct[10];

int main() {
    Process proc[10];
    int i, n, total_tat=0, total_wt=0;
    printf("Enter the number of processes : ");
    scanf("%d",&n);

    for (i = 0; i<n; i++)
    {
        printf("Enter the arrival and burst time and Priority of Process %d : ",i+1);
        scanf("%d %d %d",&proc[i].art,&proc[i].brt,&proc[i].pr);
    }
    
    for (i=0; i<n; i++)
    rt[i] = proc[i].brt;
    
    int t = 0, high_pr = -1, complete = 0, index;
    bool inQ = false;

    while (complete != n)
    {
        for (i=0; i<n; i++)
        {
            if (proc[i].art <= t && proc[i].pr > high_pr && rt[i] > 0)
            {
                index = i;
                high_pr = proc[i].pr;
                inQ = true;
            }
        }
            if (proc[i].brt == rt[i])
            {
                proc[i].start = t;
            }
        
            if (inQ == false)
            {
                t++;
                continue;
            }    
            
            rt[index]--;
            t++;
            
            if (rt[index] == 0)
            {
                complete++;
                ct[index] = t;
                inQ = false;
                high_pr = -1;
            }    
    }
    
    for (i =0;i<n;i++)    
    {
        tat[i] = ct[i] - proc[i].art;
        wt[i] = tat[i] - proc[i].brt;
        total_tat += tat[i];
        total_wt += wt[i];
    }
    printf("PID \t ARR \t BRR \t PRI \t CT \t TAT \t WT \n");
    for (i =0;i<n;i++)    
    {
        printf(" %d \t\t %d \t\t %d \t\t %d \t\t%d\t\t%d\t\t%d\n", i+1, proc[i].art, proc[i].brt, proc[i].pr, ct[i], tat[i], wt[i]);
    }
    for(int i=0; i<n; i++){
        printf("%d....P%d....%d\n", proc[i].start, i+1,ct[i]);
    }
    printf("The average turnaround time is %f \n",total_tat/(float)n);
    printf("The average waiting time is %f \n",total_wt/(float)n);
    
    return 0;
}
