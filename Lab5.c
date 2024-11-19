//To display directory content using readdir;

#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<time.h>
#include<string.h>
#include<dirent.h>

int main(int argc, char* argv[]) {
    DIR *dir = opendir(argv[1]);
    if (dir == NULL) {
        printf("No Such Directory Found:\n");
        exit(0);
    }
    struct dirent *entry = readdir(dir);
    while (entry != NULL) {
        printf("%s \n", entry->d_name);
        entry = readdir(dir);
    }
    closedir(dir);
    return 0;
}