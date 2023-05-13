#include <stdio.h>
// #include <stdbool.h>

typedef struct {
    int msize, used, hole;
} Memory;
   
typedef struct {
    int psize, alloc;
} Process;

int main()
{
    Memory mem[10];
    Process proc[10];
    int i, j, n_proc, n_mem;
   
    printf("Enter the number of memory locations : ");
    scanf("%d",&n_mem);
   
    printf("\n");
    for (i=0; i<n_mem;i++)
    {
        printf("Enter the partition size (in kB) for memory location %d : ", i+1);
        scanf("%d",&mem[i].msize);
        mem[i].used = 0;
    }
    printf("\n");
    printf("Enter the number of processes : ");
    scanf("%d",&n_proc);
    for (i=0; i<n_proc;i++)
    {
        printf("Enter the size (in kB) of process %d : ", i+1);
        scanf("%d",&proc[i].psize);
        proc[i].alloc = -1;
    }
    printf("\n");
    // bool check;
    for (i=0; i<n_proc; i++)
    {
        // check = false;
        int index=-1;
        for (j=0;j<n_mem; j++)
        {
            if (mem[j].msize >= proc[i].psize && !mem[j].used)
            {
                if (index == -1 || mem[index].msize > mem[j].msize)
                {
                    index = j;
                    // check = true;
                }
            }
        }
        if (index != -1)
        {
            mem[index].used = 1;
            proc[i].alloc = index;
        }
        if (proc[i].alloc !=-1)
            mem[index].hole = mem[index].msize - proc[i].psize;
        
    }
   
    printf("\n");
    for (i=0; i<n_proc;i++)
    {
        if (proc[i].alloc ==-1)
            printf("Process %d has not been allocated any memory\n", i+1);
        else
        {
            printf("Process %d has been allocated partition No. %d\n", i+1, proc[i].alloc+1);
            printf("A hole of %dkB has been generated \n", mem[proc[i].alloc].hole);
        }
        printf("\n");
    }
    return 0;
}
