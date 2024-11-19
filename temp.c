int main(int argc, char* argv[]) {
    struct stat current_file;
    if (stat(argv[1], &current_file) == -1) {
        perror("File not found");
        exit(0);
    }

    //file informations;

    //
}