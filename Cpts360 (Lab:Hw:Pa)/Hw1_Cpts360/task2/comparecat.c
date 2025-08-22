//https://linux.die.net/HOWTO/SCSI-Generic-HOWTO/open.html
//https://linux.die.net/man/3/stdout
//https://linux.die.net/man/2/read
//https://linux.die.net/man/2/write

// you need to include -lrt flag (i.e., real-time libraries or librt)
// to compile this code

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>	/* for uint64 definition */
#include <time.h>	/* for clock_gettime */
#include <fcntl.h>
#include <stdarg.h>
#include <unistd.h>

#define BILLION 1000000000L

static void filecopy(int ifd, int ofd);
static void error(char *fmt, ...); // can be used to generate error message
void filecopy_cat(FILE *, FILE *);

void filecopy(int ifd, int ofd) {
    ssize_t c;
    char buf [1000];
    while ((c = read(ifd, buf, sizeof(buf))) != 0)
        write(ofd, buf, c);
}

void filecopy_cat(FILE *ifp, FILE *ofp)
{
    int c;

    while ((c = getc(ifp)) != EOF)
        putc(c, ofp);
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

int main_cathw(int argc, char *argv[]) {
    // your implementation for cat using system call
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

int main_cat(int argc, char *argv[])
{
    FILE *fp;

    if(argc == 1)  // no args; copy standard input
        filecopy_cat(stdin, stdout);
    else
        while (--argc > 0)
            if ((fp = fopen(*++argv, "r")) == NULL)
            {
                printf("cat: can't open %s\n", *argv);
                return 1;
            }
            else
            {
                filecopy_cat(fp, stdout);
                fclose(fp);
            }
    return 0;
}

int main(int argc, char **argv) {
    uint64_t diff;
    uint64_t diff_cat;
    struct timespec start, end;
    struct timespec start_cat, end_cat;
    int i;

    // measure time
    clock_gettime(CLOCK_MONOTONIC, &start);	// mark start time
    main_cathw(argc, argv);	// call cathw routine
    clock_gettime(CLOCK_MONOTONIC, &end);	// mark the end time

    // measure time
    clock_gettime(CLOCK_MONOTONIC, &start_cat);	// mark start time
    main_cat(argc, argv);	// call cat routine
    clock_gettime(CLOCK_MONOTONIC, &end_cat);	// mark the end time

    // calculate difference
    diff = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
    printf("Run time of cathw = %llu nanoseconds\n", (long long unsigned int) diff);

    // calculate difference
    diff_cat = BILLION * (end_cat.tv_sec - start_cat.tv_sec) + end_cat.tv_nsec - start_cat.tv_nsec;
    printf("Run time of cat = %llu nanoseconds\n", (long long unsigned int) diff_cat);

    return 0;
}