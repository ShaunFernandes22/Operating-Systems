#include <stdio.h>

int main() {
    int i, j=0, k, n_frames, n_pages, hit_count=0, fault_count=0;
    int pg_stream[50], frames[50];
    printf("Enter the number of frames in main memory : ");
    scanf("%d",&n_frames);
    printf("Enter the number of pages in stream : ");
    scanf("%d",&n_pages);
    printf("Enter the stream : \n");
    for (i = 0; i < n_pages; i++)
    {
        scanf("%d",&pg_stream[i]);
    }
    char check = 'F';
    float hit_ratio, miss_ratio;
    for (k=0; k<n_frames; k++)
        frames[k] = -1;

    printf("Page Stream : \n");
    for (i=0; i<n_pages; i++) {
        check = 'F';
        for (k=0; k<n_frames; k++) {
            if (pg_stream[i] == frames[k]) {
                check = 'H';
                hit_count++;
            }
        }
        if (j<n_frames && check != 'H') {
            frames[j] = pg_stream[i];
            j++;
            fault_count++;
        }
        else if (j >= n_frames && check != 'H') {
            j=0;
            frames[j] = pg_stream[i];
            j++;
            fault_count++;
        }
        printf("%d \t\t\t",pg_stream[i]);
        for (k=0; k<n_frames; k++) {
            if (frames[k] != -1) {
                printf("%d\t",frames[k]);
            }
            else 
                printf("\t");    
        }
        printf("%c\n",check);
    }
    
    hit_ratio = hit_count/(float)n_pages;
    miss_ratio = fault_count/(float)n_pages;

    printf("The total number of hits are %d \n",hit_count);
    printf("The total number of faults are %d \n",fault_count);
    printf("The hit ratio is %.2f \n",hit_ratio);
    printf("The miss ratio is %.2f \n",miss_ratio);

    return 0;
}
