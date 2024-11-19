#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<dirent.h>
#include<string.h>
#include<unistd.h>

//bt --> burst time;
//ct --> completion time;
//wt --> waiting time -- > w[i] = wt[i - 1] + bt[i - 1];
//tat --> turn around time --> tat[i] = w[i] + b[i];

int main() {
    printf("Enter the Number of Processes:\n");
    int n; scanf("%d", &n);
    
    int bt[n];
    printf("Enter the burst time of %d Processes:\n", n);
    for (int i = 0; i < n; i++) scanf("%d", &bt[i]);

    int wt[n], tat[n];
    for (int i = 0; i < n; i++) {
        wt[i] = 0;
        tat[i] = 0;
    }
    for (int i = 1; i < n; i++) wt[i] = wt[i - 1] + bt[i - 1];
    for (int i = 0; i < n; i++) tat[i] = wt[i] + bt[i];

    printf("WT TAT\n");
    for (int i = 0; i < n; i++) {
        printf("%d %d\n", wt[i], tat[i]);
    }

    float average_waiting_time = 0.0, average_turn_around_time = 0.0;
    for (int i = 0; i < n; i++) {
        average_turn_around_time += tat[i];
        average_waiting_time += wt[i];
    }

    average_turn_around_time /= n * 1.0;
    average_waiting_time /= n * 1.0;
    printf("Average Waiting Time -- > %f\n", average_waiting_time);
    printf("Average Turn Around Time -- > %f\n", average_turn_around_time);

    return 0;
}