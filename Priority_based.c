#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<string.h>
#include<limits.h>
#include<unistd.h>
#include<dirent.h>

//first process the one having lesser priority number;

typedef struct {
    int pid, bt, p;
}Tuple;


int custom_sort(const void* a, const void* b) {
    Tuple* first = (Tuple*)a;
    Tuple* second = (Tuple*)b;
    return first->p - second->p;
}


void compute_waiting_time(int wt[], int n, Tuple* res) {
    for (int i = 1; i < n; i++) wt[i] = wt[i - 1] + res[i - 1].bt;
}

int main() {
    printf("Enter the Number of Processes:\n");
    int n; scanf("%d", &n);
    int bt[n];
    printf("Enter burst time of %d Processes:\n", n);
    for (int i = 0; i < n; i++) scanf("%d", &bt[i]);
    printf("Enter the priority of %d Processes:\n", n);
    int p[n];
    for (int i = 0; i < n; i++) scanf("%d", &p[i]);

    Tuple* res = (Tuple*)(malloc)(n * sizeof(Tuple));
    for (int i = 0; i < n; i++) {
        res[i].pid = i;
        res[i].bt = bt[i];
        res[i].p = p[i];
    }

    qsort(res, n, sizeof(Tuple), custom_sort);

    int wt[n], tat[n];  
    for (int i = 0; i < n; i++) {
        wt[i] = 0; tat[i] = 0;
    }
    compute_waiting_time(wt, n, res);
    for (int i = 0; i < n; i++) tat[i] = wt[i] + res[i].bt;

    float average_waiting_time = 0.0, average_turn_around_time = 0.0;
    for (int i = 0; i < n; i++) {
        average_turn_around_time += tat[i];
        average_waiting_time += wt[i];
    }

    printf("PID WT TAT\n");
    for (int i = 0; i < n; i++) {
        printf("%d %d %d\n", res[i].pid, wt[i], tat[i]);
    }

    average_turn_around_time /= n * 1.0;
    average_waiting_time /= n * 1.0;
    printf("Average Waiting Time -> %f\n", average_waiting_time);
    printf("Average Turn Around Time --> %f\n", average_turn_around_time);
    return 0;
}