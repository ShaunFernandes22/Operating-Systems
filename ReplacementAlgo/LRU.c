#include <stdio.h>

int main() {
    int i, j=0, k, n_frames, n_pages, hit_count=0, fault_count=0;
    int frames[10], flag[10], pg_stream[50];
    printf("Enter the number of frames : ");
    scanf("%d",&n_frames);
    printf("Enter the number of pages to be executed : ");
    scanf("%d",&n_pages);
    printf("Enter the page stream : \n");
    for (i=0; i<n_pages; i++)
        scanf("%d",&pg_stream[i]);
    for (i=0; i<n_frames; i++) {
        frames[i] = -1;
        flag[i] = 0;
    }
    
    int c = 0, min, lru = 0;
    char check = 'F';
    
    printf("Page Stream : \n");
    for (i=0; i<n_pages; i++) {
        min = 1000;
        
        for (k=0; k<n_frames; k++) {
            if (flag[k] < min) {
                min = flag[k];
                lru = k;
            }
        }

        for (k=0; k<n_frames; k++) {
            if (frames[k] == pg_stream[i]) {
                check = 'H';
                c++;
                flag[k] = c;
                hit_count++;
            }
        }
        if (j < n_frames && check != 'H') {
            frames[j] = pg_stream[i];
            c++;
            flag[j] = c;
            j++;
            fault_count++;
        }
        else if (j>= n_frames && check != 'H') {
            frames[lru] = pg_stream[i];
            c++;
            flag[lru] = c;
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
        check = 'F';
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
