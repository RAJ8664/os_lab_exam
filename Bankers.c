#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<unistd.h>

int main() {
    printf("Enter the Number of Processes: \n");
    int n; scanf("%d", &n);
    printf("Enter the Number of Resources: \n");
    int m; scanf("%d", &m);

    printf("Enter the allocated value of each processes for each resources:\n");
    int alloc[n][m], maxi[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) scanf("%d", &alloc[i][j]);
    }
    printf("Enter the Maximum value of each processes for each resources:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) scanf("%d", &maxi[i][j]);
    }

    printf("Enter the available values for each resources:\n");
    int avail[m];
    for (int i = 0; i < m; i++) scanf("%d", &avail[i]);

    int res[n], f[n];
    for (int i = 0; i < n; i++) {
        res[i] = 0;
        f[i] = 0;
    }
    int need[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) need[i][j] = maxi[i][j] - alloc[i][j];
    }

    int ind = 0;
    for (int x = 0; x < n; x++) {
        for (int i = 0; i < n; i++) {
            if (f[i] == 0) {
                int flag = 1;
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) {
                        flag = 0;
                        break;
                    }
                }
                if (flag == 1) {
                    res[ind++] = i;
                    for (int j = 0; j < m; j++) avail[j] += alloc[i][j];
                    f[i] = 1;
                }
            }
        }
    }
    int flag = 1;
    for (int i = 0; i < n; i++) {
        if (f[i] == 0) {
            flag = 0;
            break;
        }
    }
    if (flag == 0) {
        printf("The Following System in not Safe:\n");
        return 0;
    }
    printf("The Following System in Safe:\n");
    printf("Sequence Order : ");
    for (int i = 0; i < n - 1; i++) {
        printf("P%d->", res[i]);
    }
    printf("P%d\n", res[n - 1]);
    return 0;
}


