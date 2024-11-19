#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdbool.h>
#include<time.h>
#include<string.h>
#include<sys/wait.h>
#include<dirent.h>
#include<sys/stat.h>
#include<limits.h>

//shortest job remaining first;
void compute_waiting_time(int at[], int bt[], int wt[], int n) {
    int cbt[n];
    for (int i = 0; i < n; i++) cbt[i] = bt[i];
    int current_time = 0;
    while (true) {
        bool flag = true;
        for (int i = 0; i < n; i++) {
            if (cbt[i] > 0) flag = false;
        }
        if (flag == true) break;
        int current_mini = INT_MAX;
        int ind = -1;
        for (int i = 0; i < n; i++) {
            if (at[i] <= current_time && cbt[i] != 0) {
                if (current_mini > cbt[i]) {
                    current_mini = cbt[i];
                    ind = i;
                }
            }
        }
        if (ind == -1) {
            current_time++;
            continue;
        }
        cbt[ind]--;
        if (cbt[ind] == 0) {
            wt[ind] = current_time + 1 - bt[ind] - at[ind];
            if (wt[ind] < 0) wt[ind] = 0;
        }
        current_time++;
    } 
}


int main() {
    printf("Enter the Number of Processes:\n");
    int n; scanf("%d", &n);

    int at[n], bt[n];
    printf("Enter the arrival time for %d Processes:\n", n);
    for (int i = 0; i < n; i++) scanf("%d", &at[i]);
    printf("Enter the burst time for %d Processes:\n", n);
    for (int i = 0; i < n; i++) scanf("%d", &bt[i]);

    int wt[n], tat[n];
    for (int i = 0; i < n; i++) {
        wt[i] = 0; tat[i] = 0;
    }

    compute_waiting_time(at, bt, wt, n);
    for (int i = 0; i < n; i++) tat[i] = wt[i] + bt[i];

    float average_waiting_time = 0.0, average_turn_around_time = 0.0;
    for (int i = 0; i < n; i++) {
        average_waiting_time += wt[i];
        average_turn_around_time += tat[i];
    }

    printf("AT WT TAT\n");
    for (int i = 0; i < n; i++) {
        printf("%d %d %d\n", at[i], wt[i], tat[i]);
    }

    average_waiting_time /= n * 1.0;
    average_turn_around_time /= n * 1.0;
    printf("Average Waiting Time --> %f\n", average_waiting_time);
    printf("Average Turn Around Time --> %f\n", average_turn_around_time);

    return 0;
}