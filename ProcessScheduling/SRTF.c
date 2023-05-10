#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int pid, art, brt, tat, wt, ct, start, rt; 
} Process;

int main() {
    Process proc[10];
    int i, n;
    float total_tat=0, total_wt=0;
    printf("Enter the number of processes : ");
    scanf("%d",&n);

    for (i = 0; i<n; i++)
    {
        printf("Enter the id, arrival and burst time of process : ");
        scanf("%d %d %d",&proc[i].pid,&proc[i].art,&proc[i].brt);
    }
    
    for (i=0; i<n; i++)
        proc[i].rt = proc[i].brt; // remaining time

    bool check = false; // about whether process is available for processing
    
    int complete=0, t = 0, shortest;
	int minm = 1000;
    while (complete < n) {
		for (int j = 0; j < n; j++) {
       //picking process having min burst time and which has already arrived and is not completed
			if ((proc[j].art <= t) && (proc[j].brt < minm) && (proc[j].rt>0)) {
				minm = proc[j].brt;
				shortest = j;
				check = true;
			}
		}
		
        //continues time incrementation if no process currently in queue
		if (check == false) {
			t++;
			continue;
		}
		
		if (proc[shortest].rt == proc[shortest].brt) 
	        proc[shortest].start = t;
        
        proc[shortest].rt--;
        t++;
        
        minm = proc[shortest].rt;
        
        if (minm == 0) 
            minm = 1000; // reset so that new process would satisfy if above
        
        if (proc[shortest].rt == 0) {
            proc[shortest].ct = t;
            check = false; // reset as we need to find a process again
            complete++; // a process done
        }
	}
    // calculating turnaround = completion - arrival,  waiting = turnaround - burst
     for (i =0; i<n; i++)   
    {    
        proc[i].tat = proc[i].ct - proc[i].art;
        proc[i].wt = proc[i].tat - proc[i].brt;

        total_tat += proc[i].tat;
        total_wt += proc[i].wt;
    }
    
    printf("PID \t ART \t BRT \t CT \t TAT \t WT \n");
    for (i =0;i<n;i++)    
    {
        printf(" %d \t\t %d \t\t %d \t\t%d\t\t%d\t\t%d\n",proc[i].pid, proc[i].art, proc[i].brt, proc[i].ct, proc[i].tat, proc[i].wt);
    }
    
    printf("The average turnaround time is %.2f \n",total_tat/(float)n);
    printf("The average waiting time is %.2f \n",total_wt/(float)n);
    
    printf("\nGANTT CHART :\n");
    // printf("PID\tSTART\tCOMPLETION\n");
    for (i=0; i<n; i++) {
        printf("%d---P%d---%d\n", proc[i].start, proc[i].pid, proc[i].ct);
    }
    return 0;
}
