//https://linux.die.net/HOWTO/SCSI-Generic-HOWTO/open.html
//https://linux.die.net/man/3/stdout
//https://linux.die.net/man/2/read
//https://linux.die.net/man/2/write

#include <fcntl.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void filecopy(int ifd, int ofd);
static void error(char *fmt, ...); // can be used to generate error message

int main(int argc, char *argv[]) {

    int fp;
    int ofp;

    if(argc == 1)  // no args; copy standard input
        filecopy(STDIN_FILENO, STDOUT_FILENO);

    else
        while (--argc > 0)
            if ((fp = open(*++argv, O_RDONLY)) == -1)
            {
               error("cathw: can't open %s\n", *argv);
            }
            else
            {
                filecopy(fp, ofp);
                close(fp);
            }
    return 0;
}

void filecopy(int ifd, int ofd) {
    ssize_t c;
    char buf [1000];
    while ((c = read(ifd, buf, sizeof(buf))) != 0)
        write(ofd, buf, c);
}

// no modification needed
void error(char *fmt, ...) {
    va_list args;

    va_start(args, fmt);
    fprintf(stderr, "error: ");
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");
    va_end(args);
    exit(1);
}

