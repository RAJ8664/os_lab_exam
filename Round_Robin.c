#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<string.h>
#include<time.h>
#include<dirent.h>
#include<stdbool.h>

//assuming all the process will arrive at time t = 0;
void compute_waiting_time(int wt[], int bt[], int n, int quantum) {
    int current_time = 0;
    int cbt[n]; //copy of burst time;
    for (int i = 0; i < n; i++) cbt[i] = bt[i];
    while (true) {
        bool flag = true;
        for (int i = 0; i < n; i++) {
            if (cbt[i] > 0) {
                flag = false;
            }
        }
        if (flag == true) break;
        for (int i = 0; i < n; i++) {
            if (cbt[i] > 0) {
                if (cbt[i] > quantum) {
                    cbt[i] -= quantum;
                    current_time += quantum;
                }
                else {
                    current_time += cbt[i];
                    cbt[i] = 0;
                    wt[i] = current_time - bt[i];
                }
            }
        }
    }
}


int main() {
    printf("Enter the Number of Processes:\n");
    int n; scanf("%d", &n);
    int bt[n];
    printf("Enter the burst time of %d Processes:\n", n);
    for (int i = 0; i < n; i++) scanf("%d", &bt[i]);

    printf("Enthe the time quantum:\n");
    int quantum; scanf("%d", &quantum);

    int wt[n], tat[n];
    compute_waiting_time(wt, bt, n, quantum);
    for (int i = 0; i < n; i++) tat[i] = wt[i] + bt[i];

    float average_waiting_time = 0.0, average_turn_around_time = 0.0;
    for (int i = 0; i < n; i++) {
        average_turn_around_time += tat[i];
        average_waiting_time += wt[i];
    }

    average_turn_around_time /= n * 1.0;
    average_waiting_time /= n * 1.0;
    printf("Average Waiting Time --> %f\n", average_waiting_time);
    printf("Average Turn Around Time --> %f\n", average_turn_around_time);

    return 0;
}