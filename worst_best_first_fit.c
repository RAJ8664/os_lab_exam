#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void display(int page[], int n, int allocation[]) {
    for (int i = 0; i < n; i++) {
        if (allocation[i] != -1) {
            printf("allocated page for %d is %d\n", page[i], allocation[i] + 1);
        }
        else printf("Not Allocated\n");
    }
}

void first_fit(int page[], int n, int frames[], int m) {
    //n = numebers of pages, m = number of frames;
    int vis[m];
    int allocation[n];
    for (int i = 0; i < n; i++) allocation[i] = -1;
    for (int i = 0; i < m; i++) vis[i] = 0;
    for (int i = 0; i < n; i++) {
        int current_page = page[i];
        for (int j = 0; j < m; j++) {
            if (vis[j] == 0 && frames[j] >= current_page) {
                allocation[i] = j;
                vis[j] = 1;
                break;
            }
        }
    }
    display(page, n, allocation);
}

void worst_fit(int page[], int n, int frames[], int m) {
    int vis[m];
    for (int i = 0; i < m; i++) vis[i] = 0;
    int allocation[n];
    for (int i = 0; i < n; i++) allocation[i] = -1;
    for (int i = 0; i < n; i++) {
        int current_page = page[i];
        int maxi = -1, ind = -1;
        for (int j = 0; j < m; j++) {
            if (vis[j] == 0 && frames[j] > maxi) {
                maxi = frames[j];
                ind = j;
            }
        }
        if (maxi >= current_page) {
            allocation[i] = ind;
            vis[ind] = 1;
        }
    }
    display(page, n, allocation);
}

void best_fit(int page[], int n, int frames[], int m) {
    int vis[m];
    for (int i = 0; i < m; i++) vis[i] = 0;
    int allocation[n];
    for (int i = 0; i < n; i++) allocation[i] = -1;
    for (int i = 0; i < n; i++) {
        int current_page = page[i];
        int mini = 100000, ind = -1;
        for (int j = 0; j < m; j++) {
            if (vis[j] == 0 && frames[j] >= current_page && frames[j] < mini) {
                mini = frames[j];
                ind = j;
            }
        }
        if (ind == -1) continue;
        if (mini >= current_page) {
            allocation[i] = ind;
            vis[ind] = 1; 
        }
    }
    display(page, n, allocation);
}



int main() {
    printf("Enter the Number of pages:\n");
    int n; scanf("%d", &n);
    int page[n];
    printf("Enter the pages size for %d pages\n", n);
    for (int i = 0; i < n; i++) scanf("%d", &page[i]);
    printf("Enter the frames size:\n");
    int frames_size; scanf("%d", &frames_size);
    int frames[frames_size];
    printf("Enter the frames values for %d frames\n", frames_size);
    for (int i = 0; i < frames_size; i++) scanf("%d", &frames[i]);
    
    //first_fit(page, n, frames, frames_size);
    //worst_fit(page, n, frames, frames_size);
    best_fit(page, n, frames, frames_size);
    return 0;
}