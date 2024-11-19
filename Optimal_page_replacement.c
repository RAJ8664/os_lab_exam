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

    for (int i = 0; i < n; i++) {
        int current_page = page[i];
        //check if the current_page is in the frame;
        int flag = 0;
        for (int j = 0; j < num_frames; j++) {
            if (frames[j] == current_page) flag = 1;
        }
        if (flag == 0) {
            //if not in the frame && current_frame_ind == num_frames meanining the frame is full then -->;
            //need to remove the one whose demand in future in at last out of all the frames[j];
            //how to do that ?
            page_faults++;
            if (current_frame_ind == num_frames) {
                int temp[1000]; //assuming the values for page[i] is atmost 1000;
                int found_ind = -1;
                for (int j = 0; j < 1000; j++) temp[j] = 100000;
                for (int j = 0; j < num_frames; j++) {
                    //for this frames[j] find its latest position of demand in future starting from i + 1;
                    for (int k = i + 1; k < n; k++) {
                        if (page[k] == frames[j]) {
                            temp[frames[j]] = k;
                            break;
                        }
                    }
                }
                //now find the index of one which needs to be removed;
                //whose index is maximum will be removed;
                int current_maxi_ind = -2;
                for (int j = 0; j < num_frames; j++) {
                    if (temp[frames[j]] > current_maxi_ind) {
                        current_maxi_ind = temp[frames[j]];
                        found_ind = j;
                    }
                }
                frames[found_ind] = current_page;
            }
            else frames[current_frame_ind++] = current_page;
        } 
    }
    printf("Total Page Faults :%d\n", page_faults);
    return 0;
}