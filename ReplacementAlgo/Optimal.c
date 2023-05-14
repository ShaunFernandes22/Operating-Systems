#include <stdio.h>

int main() {
    int i, j, k, n_frames, n_pages, hit_count=0, fault_count=0;
    int frames[10], pg_stream[50];
    printf("Enter the number of frames : ");
    scanf("%d",&n_frames);
    printf("Enter the number of pages to be executed : ");
    scanf("%d",&n_pages);
    printf("Enter the page stream : \n");
    for (i=0; i<n_pages; i++)
        scanf("%d",&pg_stream[i]);
        
    for (i=0; i<n_frames; i++) {
        frames[i] = -1;
    }
    int next_occurrence, farthest, index;
    char check = 'F';
    
    printf("Page Stream : \n");
    for (i=0; i<n_pages; i++) {
        check ='F';
        for (j=0; j<n_frames; j++) {
            if (frames[j] == pg_stream[i]) {
                check = 'H';
                hit_count++;
                break;
            }
        }
        if (check != 'H') {
            index = -1;
            farthest = 0;
            
            for (j=0; j<n_frames; j++) {
                next_occurrence = -1;
                for (k=i+1; k<n_pages; k++) {
                    if (frames[j] == pg_stream[k]) {
                        next_occurrence = k;
                        break;
                    }
                }
                if (next_occurrence == -1) {
                    index = j;
                    break;
                }
                if (next_occurrence > farthest) {
                    farthest = next_occurrence;
                    index = j;
                }
            }
            frames[index] = pg_stream[i];
            fault_count++;
        }
        printf("%d \t\t", pg_stream[i]);
        for (k=0; k<n_frames; k++) {
            if (frames[k] != -1) {
                printf("%d\t",frames[k]);
            }
            else {
                printf("\t");
            }
        }
        printf("%c \n",check);
    }
    float hit_ratio, miss_ratio;
    hit_ratio = hit_count/(float)n_pages;
    miss_ratio = fault_count/(float)n_pages;

    printf("The total number of hits are %d \n",hit_count);
    printf("The total number of faults are %d \n",fault_count);
    printf("The hit ratio is %.2f \n",hit_ratio);
    printf("The miss ratio is %.2f \n",miss_ratio);

    return 0;
}
