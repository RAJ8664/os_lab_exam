//To display file status using stat system call.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<time.h>

int main(int argc, char* argv[]) {
    struct stat current_file;
    if (stat(argv[1], &current_file) == -1) {
        perror("File Not Found:\n");
        exit(EXIT_FAILURE);
    }

    printf("File Information:\n");
    printf("File : %s\n", argv[1]);
    printf("File UID : %d\n", current_file.st_uid);
    printf("File GID : %d\n", current_file.st_gid);
    printf("File Block Size : %ld\n", current_file.st_blksize);
    printf("Number of blocks : %ld\n", current_file.st_blocks);
    printf("Number of nlink :%ld\n", current_file.st_nlink);
    printf("File size : %ld\n", current_file.st_size);

    printf("File Information Regarding time:\n");
    printf("Last access time : %s\n", ctime(&current_file.st_atime));
    printf("Last Modifictaion time : %s\n", ctime(&current_file.st_mtime));
    printf("Last access change time : %s\n", ctime(&current_file.st_ctime));

    printf("File Permissions:\n");
    printf((current_file.st_mode & S_IRUSR) ? "r" : "-");
    printf((current_file.st_mode & S_IWUSR) ? "w" : "-");
    printf((current_file.st_mode & S_IXUSR) ? "x" : "-");

    printf((current_file.st_mode & S_IRGRP) ? "r" : "-");
    printf((current_file.st_mode & S_IWGRP) ? "w" : "-");
    printf((current_file.st_mode & S_IXUSR) ? "x" : "-");
 
    printf((current_file.st_mode & S_IROTH) ? "r" : "-");
    printf((current_file.st_mode & S_IWOTH) ? "w" : "-");
    printf((current_file.st_mode & S_IXOTH) ? "x" : "-");
    return 0;
}