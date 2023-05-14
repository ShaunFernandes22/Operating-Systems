import java.util.Scanner;

class Bankers
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int m, n;
        System.out.print("Enter number of resources: ");
        m = sc.nextInt();
        System.out.print("Enter number of processes: ");
        n = sc.nextInt();

        int resource[] = new int[m];
        int max[][] = new int[n][m];
        int allocation[][] = new int[n][m];
        int need[][] = new int[n][m];
        int work[] = new int[m];
        int finish[] = new int[n];
        int tot[] = new int[m];

        int i, j;
        for(i = 0; i < m; i++)
        {
            System.out.print("Enter number of instances of resource "+(i+1)+": ");
            resource[i] = sc.nextInt();
            tot[i] = 0;
        }
        for(i = 0; i < n; i++)
        {
            System.out.println("Maximum and Allocated resources for Process "+(i+1));
            for(j = 0; j < m; j++)
            {
                System.out.print("Max for resource "+(j+1)+": ");
                max[i][j] = sc.nextInt();
                System.out.print("Allocation for resource "+(j+1)+": ");
                allocation[i][j] = sc.nextInt();
                tot[j] += allocation[i][j];
                need[i][j] = max[i][j] - allocation[i][j];
            }
            finish[i] = 0;
        }

        System.out.print("\nInstances of resources available:\n");
        for(i = 0; i < m; i++)
        {
            work[i] = resource[i] - tot[i];
            System.out.print("R"+(i+1)+": "+work[i]+"\t");
        }
        System.out.print("\nInstances of resources needed by Processes:\n");
        for(i = 0; i < m; i++)
        System.out.print("\tR"+(i+1));
        for(i = 0; i < n; i++)
        {
            System.out.print("\nP"+(i+1));
            for(j = 0; j < m; j++)
                System.out.print("\t"+need[i][j]);
        }
        System.out.println();
        int total = 0, check = 0, k;
        boolean flag = false;
        int safe[] = new int[n];
        for( k=0; k<n; k++)
        {
            for(i = 0; i < n; i++)
            {
                for(j = 0; j < m; j++)
                {
                    if(need[i][j] > work[j])
                        check++;
                }
                if(check == 0 && finish[i] == 0)
                {
                    for(j = 0; j < m; j++)
                        work[j] += allocation[i][j];
                    finish[i] = 1;
                    safe[total] = i+1;
                    total++;
                }
                check = 0;
                if(total == n)
                {
                    flag = true;
                    break;
                }
            }
        }
        if (flag) {
            System.out.print("\n\nThe safe sequence is");
            for(i = 0; i < n-1; i++)
                System.out.print("\tP"+safe[i]+" -->");
                System.out.print("\tP"+safe[i]);
            
            System.out.println();
        }
        else
            System.out.println("No safe sequence found.");
    }
}
