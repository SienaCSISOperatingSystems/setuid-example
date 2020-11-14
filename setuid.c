/*
  Small program to demonstrate getuid, geteuid, getgid and setuid/gid bits

  Jim Teresco
  Williams College
  Computer Science 432, Fall 2005
  Updated Fall 2006
  Updated Spring 2008, Mount Holyoke College, CS 322
  Updated Fall 2020, Siena College, CSIS 330
 */

#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[]) {
  FILE *fp;
  uid_t uid;

  if (argc < 3) {
    fprintf(stderr, "Usage: %s filename uid\n", argv[0]);
    return 1;
  }

  uid = atoi(argv[2]);

  printf("Running as uid=%d, euid=%d, gid=%d, egid=%d\n",
	 getuid(), geteuid(), getgid(), getegid());
  fp = fopen(argv[1], "r");
  if (!fp) {
    perror("fopen");
  }
  else {
    printf("Successfully opened file %s for reading\n", argv[1]);
    fclose(fp);
  }

  printf("Attempting to set effective uid to %d\n", uid);

  if (setuid(uid) == -1) {
    perror("setuid");
  }
  else {
    printf("Successfully set uid\n");
  }

  printf("Running as uid=%d, euid=%d, gid=%d, egid=%d\n",
	 getuid(), geteuid(), getgid(), getegid());

  fp = fopen(argv[1], "r");
  if (!fp) {
    perror("fopen");
  }
  else {
    printf("Successfully opened file %s for reading\n", argv[1]);
    fclose(fp);
  }

  return 0;
}

