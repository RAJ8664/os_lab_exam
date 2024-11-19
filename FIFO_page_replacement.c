#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<unistd.h>
#include<sys/wait.h>

int main() {
    printf("Enter the Number of Pages:\n");
    int n; scanf("%d", &n);
    printf("Enter the page Numbers:\n");
    int page[n];
    for (int i = 0; i < n; i++) scanf("%d", &page[i]);
    
    printf("Enter the Number of Frames : \n");
    int num_frames; scanf("%d", &num_frames);
    int frames[num_frames];
    for (int i = 0; i < num_frames; i++) frames[i] = -1;
    int current_frame_ind = 0, page_faults = 0;

    for (int i = 0; i < n; i++) {
        int current_page = page[i];
        int flag = 0;
        //check if the current_page in the frame;
        for (int j = 0; j < num_frames; j++) {
            if (frames[j] == current_page) flag = 1;
        }
        if (flag == 0) {
            //not present;
            page_faults++;
            if (current_frame_ind == num_frames) current_frame_ind = 0;
            frames[current_frame_ind++] = current_page;
        }
    }
    printf("Total Page Faults : %d\n", page_faults);
    return 0;
}