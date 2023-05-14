#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, diff, n_tracks, rw_head, n_reqs, total_tr=0;
    int req[100], movement[100];
    printf("Enter the number of tracks : ");
    scanf("%d",&n_tracks);
    printf("Enter the number of requests : ");
    scanf("%d",&n_reqs);
    for (i=0; i<n_reqs; i++) {
        printf("Enter the request track %d : ",i+1);
        scanf("%d",&req[i]);
    }
    printf("Enter the read write head : ");
    scanf("%d",&rw_head);
    printf("The track movements are : \n");
    printf("%d -->",rw_head);
    for (i=0; i<n_reqs; i++) {
        
        diff = abs(rw_head - req[i]);
        total_tr += diff;
        movement[i] = req[i];
        rw_head = req[i];
        // if (i < n_reqs - 1)
        //     printf("\t%d -->",req[index]);
        // else 
        //     printf("\t%d", req[index]);
    }
    for (i=0; i<n_reqs; i++) {
        if (i < n_reqs - 1)
            printf("\t%d -->",movement[i]);
        else 
            printf("\t%d", movement[i]);
    }
    
    printf("\nThe total track movement is %d \n", total_tr);
}
