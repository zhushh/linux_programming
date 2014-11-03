#include <sys/types.h>
#include <dirent.h>
#include "ourhdr.h"
#include "new_err.h"

/*
 * #include <sys/types.h>
 * #include <dirent.h>
 *
 * DIR * opendir(const char *pathname);
 * struct dirent * readdir(DIR * dp);
 * int closedir(DIR * dp);
 *
 */
int main(int argc, char * argv[]) {
    DIR *dp;
    struct dirent *dirp;

    if (argc != 2)
        err_quit("a single argument (the directory name) is required");
    if ( (dp = opendir(argv[1])) == NULL )
        err_sys("can't open %s\n", argv[1]);
    while ( (dirp = readdir(dp)) != NULL )
        printf("%s\n", dirp->d_name);
    closedir(dp);
    exit(0);
}

