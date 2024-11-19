#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

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

    int chance[100000];
    for (int i = 0; i < n; i++) {
        int current_page = page[i];
        int flag = 0;
        for (int j = 0; j < num_frames; j++) {
            if (frames[j] == current_page) flag = 1;
        }
        if (flag == 0) {
            page_faults++;
            if (current_frame_ind == num_frames) {
                //if full which one to remove;
                if (current_frame_ind == num_frames) current_frame_ind = 0;
                //current_frame_indx;
                if (chance[current_frame_ind] == 0) {
                    frames[current_frame_ind++] = current_page;
                    continue;
                }
                else {
                    int prev = current_frame_ind;
                    int found = 0;
                    for (int j = current_frame_ind; j < num_frames; j++) {
                        if (chance[frames[j]] == 0) {
                            frames[j] = current_page;
                            found = 1;
                            break;
                        }
                        else {
                            chance[frames[j]] = 0;
                        }
                    }
                    for (int j = 0; j < current_frame_ind; j++) {
                        if (chance[frames[j] == 0]) {
                            frames[j] = current_page;
                            found = 1;
                        }
                        else chance[frames[j]] = 0;
                    }
                    if (found == 0) {
                        frames[current_frame_ind] = current_page;
                    }
                    current_frame_ind = prev + 1;
                }
            }   
            else frames[current_frame_ind++] = current_page;
        }
        else {
            chance[current_page] = 1;
        }
    }
    printf("Total Page Faults :%d\n", page_faults);
    return 0;
}