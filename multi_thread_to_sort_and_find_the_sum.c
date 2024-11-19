#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<pthread.h>
#include<sys/wait.h>
#include<unistd.h>

int arr[] = {5, 4, 1, 2, 3};
int n = sizeof(arr) / sizeof(arr[0]);
pthread_mutex_t mutex;

void *sort_array(void *arg) {
    pthread_mutex_lock(&mutex);
    printf("Sorting the array:\n");
    pthread_mutex_unlock(&mutex);
    for (int i = 0; i < n; i++) {
        int mini = arr[i];
        int ind = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < mini) {
                mini = arr[j];
                ind = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[ind];
        arr[ind] = temp;
    }
    pthread_mutex_lock(&mutex);
    printf("Sorted Array\n");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    pthread_mutex_unlock(&mutex);
}


void *find_sum(void *arg) {
    pthread_mutex_lock(&mutex);
    printf("Computing the sum:\n");
    pthread_mutex_unlock(&mutex);
    
    int sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];

    pthread_mutex_lock(&mutex);
    printf("Sum of array is : %d\n", sum);
    pthread_mutex_unlock(&mutex);
}

int main() {
    pthread_t thread1, thread2;
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&thread1, NULL, sort_array, NULL);
    pthread_create(&thread2, NULL, find_sum, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    pthread_mutex_destroy(&mutex);
    return 0;

}

//Note : To Compile use --> gcc -pthread name_of_file.c -o any name;
//       To Run ./name you have given in place of any name;