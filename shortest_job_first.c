#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<limits.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/wait.h>


typedef struct {
    int pid, bt;
}Pair;


int custom_sort(const void* a, const void* b) {
    Pair* first = (Pair*)a;
    Pair* second = (Pair*)b;
    return (first->bt - second->bt);
}

int main() {
    printf("Enthe the Number of Processes:\n");
    int n; scanf("%d", &n);

    printf("Enter the burst time of %d Processes:\n", n);
    int bt[n];
    for (int i = 0; i < n; i++) scanf("%d", &bt[i]);
    
    int wt[n], tat[n];
    for (int i = 0; i < n; i++) {
        wt[i] = 0; tat[i] = 0;
    }

    Pair* res = (Pair*)(malloc)(n * sizeof(Pair));
    for (int i = 0; i < n; i++) {
        res[i].pid = i;
        res[i].bt = bt[i];
    }

    qsort(res, n, sizeof(Pair), custom_sort);

    for (int i = 1; i < n; i++) wt[i] = wt[i - 1] + res[i - 1].bt;
    for (int i = 0; i < n; i++) tat[i] = wt[i] + res[i].bt;

    printf("PID   WT    TAT\n");
    for (int i = 0; i < n; i++) {
        printf("%d %d %d\n", res[i].pid, wt[i], tat[i]);
    }

    float average_waiting_time = 0.0, average_turn_around_time = 0.0;
    for (int i = 0; i < n; i++) {
        average_turn_around_time += tat[i];
        average_waiting_time += wt[i];
    }

    average_turn_around_time /= n * 1.0;
    average_waiting_time /= n * 1.0;

    printf("Average waiting time --> %f\n", average_waiting_time);
    printf("Average turn around time --> %f\n", average_turn_around_time);

    return 0;
}