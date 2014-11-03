#include <sys/types.h>
#include <sys/stat.h>
#include "new_err.h"
#include <stdio.h>

/*
 * int stat(const char * file_name, struct stat *buf);
 * int fstat(int filedes, struct stat *buf);
 * int lstat(const char * file_name, struct stat *buf);
 */
int main(int argc, char * argv[]) {
    int     i;
    struct stat buf;
    char    *ptr;

    for (i = 1; i < argc; ++i) {
        printf("%s: ", argv[i]);
        if (lstat(argv[i], &buf) < 0) {
            err_ret("lstat error");
            continue;
        }

        if      (S_ISREG(buf.st_mode))  ptr = "regular";
        else if (S_ISDIR(buf.st_mode))  ptr = "directory";
        else if (S_ISCHR(buf.st_mode))  ptr = "character special";
        else if (S_ISBLK(buf.st_mode))  ptr = "block special";
        else if (S_ISFIFO(buf.st_mode)) ptr = "fifo";
    #ifdef S_ISLNK
        else if (S_ISLNK(buf.st_mode))  ptr = "symbolic link";
    #endif
    #ifdef S_ISSOCK
        else if (S_ISSOCK(buf.st_mode)) ptr = "socket";
    #endif
        else                ptr = "** unknow mode **";
        printf("%s\n", ptr);
    }
    return 0;
}

