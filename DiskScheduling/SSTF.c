#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, index, least, diff, n_tracks, rw_head, n_reqs, total_tr=0, complete=0;
    int req[100], visited[100], movement[100];
    printf("Enter the number of tracks : ");
    scanf("%d",&n_tracks);
    printf("Enter the number of requests : ");
    scanf("%d",&n_reqs);
    for (i=0; i<n_reqs; i++) {
        printf("Enter the request track %d : ",i+1);
        scanf("%d",&req[i]);
        visited[i] = 0;
    }
    printf("Enter the read write head : ");
    scanf("%d",&rw_head);
    printf("The track movements are : \n");
    printf("%d -->",rw_head);
    while (complete < n_reqs) {
        least = 5000;
        for (j=0; j<n_reqs; j++) {
            diff = abs(rw_head - req[j]);
            if (diff < least && visited[j] == 0) {
                index = j;
                least = diff;
            }
        }
        total_tr += least;
        visited[index] = 1;
        rw_head = req[index];
        movement[complete] = req[index];
        complete++;
        // if (complete < n_reqs - 1)
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
