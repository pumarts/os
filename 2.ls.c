#include <stdio.h>
#include <dirent.h>

int main(int argc, char **argv) {
    DIR *dp;
    struct dirent *link;
    if (argc < 2) {
        printf("usage: %s <directory>\n", argv[0]);
        return 1;
    }
    dp = opendir(argv[1]);
    if (dp == NULL) {
        perror("operation");
        return 1;
    }
    printf("Contents of the directory %s are:\n", argv[1]);
    while ((link = readdir(dp)) != NULL)
        printf("%s\n", link->d_name);
    closedir(dp);
    return 0;
}
