#include <stdio.h>
#include <sys/fcntl.h>
#include <sys/types.h>
#include <errno.h>
#include <stdlib.h>
#include <dirent.h>
#define SIZE 10 

main(int argc , char argv) 
{
	int fdin;           /* input file descriptor */ 
	int fdout;          /* out   file descriptor */ 
	char *buf[SIZE+1]; /* input (output) buffer */
	int readAmt;          /* how many chars were actually red */ 
	int writeAmt;          /* how many chars were actually written */
	DIR* dir;
	struct dirent* myDirent;

	dir = opendir("/home/shani/Dropbox/Operating Systems/Tirgul/T3");
	myDirent = readdir(dir);
	printf("d_ino: %d\n", (int)myDirent->d_ino);
	printf("d_off: %d\n", (int)myDirent->d_off);
	printf("d_reclen: %d\n", (unsigned int)myDirent->d_reclen);
	printf("d_type: %d\n", (unsigned int)myDirent->d_type);
	printf("d_name: %s\n\n", myDirent->d_name);


	myDirent = readdir(dir);
	printf("d_ino: %d\n", (int)myDirent->d_ino);
	printf("d_off: %d\n", (int)myDirent->d_off);
	printf("d_reclen: %d\n", (unsigned int)myDirent->d_reclen);
	printf("d_type: %d\n", (unsigned int)myDirent->d_type);
	printf("d_name: %s\n\n", myDirent->d_name);


	myDirent = readdir(dir);
	printf("d_ino: %d\n", (int)myDirent->d_ino);
	printf("d_off: %d\n", (int)myDirent->d_off);
	printf("d_reclen: %d\n", (unsigned int)myDirent->d_reclen);
	printf("d_type: %d\n", (unsigned int)myDirent->d_type);
	printf("d_name: %s\n\n", myDirent->d_name);

	myDirent = readdir(dir);
	printf("d_ino: %d\n", (int)myDirent->d_ino);
	printf("d_off: %d\n", (int)myDirent->d_off);
	printf("d_reclen: %d\n", (unsigned int)myDirent->d_reclen);
	printf("d_type: %d\n", (unsigned int)myDirent->d_type);
	printf("d_name: %s\n\n", myDirent->d_name);

	myDirent = readdir(dir);
	printf("d_ino: %d\n", (int)myDirent->d_ino);
	printf("d_off: %d\n", (int)myDirent->d_off);
	printf("d_reclen: %d\n", (unsigned int)myDirent->d_reclen);
	printf("d_type: %d\n", (unsigned int)myDirent->d_type);
	printf("d_name: %s\n\n", myDirent->d_name);

	myDirent = readdir(dir);
	printf("d_ino: %d\n", (int)myDirent->d_ino);
	printf("d_off: %d\n", (int)myDirent->d_off);
	printf("d_reclen: %d\n", (unsigned int)myDirent->d_reclen);
	printf("d_type: %d\n", (unsigned int)myDirent->d_type);
	printf("d_name: %s\n\n", myDirent->d_name);

	myDirent = readdir(dir);
	printf("d_ino: %d\n", (int)myDirent->d_ino);
	printf("d_off: %d\n", (int)myDirent->d_off);
	printf("d_reclen: %d\n", (unsigned int)myDirent->d_reclen);
	printf("d_type: %d\n", (unsigned int)myDirent->d_type);
	printf("d_name: %s\n\n", myDirent->d_name);

	myDirent = readdir(dir);
	printf("d_ino: %d\n", (int)myDirent->d_ino);
	printf("d_off: %d\n", (int)myDirent->d_off);
	printf("d_reclen: %d\n", (unsigned int)myDirent->d_reclen);
	printf("d_type: %d\n", (unsigned int)myDirent->d_type);
	printf("d_name: %s\n\n", myDirent->d_name);

	myDirent = readdir(dir);
	printf("d_ino: %d\n", (int)myDirent->d_ino);
	printf("d_off: %d\n", (int)myDirent->d_off);
	printf("d_reclen: %d\n", (unsigned int)myDirent->d_reclen);
	printf("d_type: %d\n", (unsigned int)myDirent->d_type);
	printf("d_name: %s\n\n", myDirent->d_name);

	myDirent = readdir(dir);
	printf("d_ino: %d\n", (int)myDirent->d_ino);
	printf("d_off: %d\n", (int)myDirent->d_off);
	printf("d_reclen: %d\n", (unsigned int)myDirent->d_reclen);
	printf("d_type: %d\n", (unsigned int)myDirent->d_type);
	printf("d_name: %s\n\n", myDirent->d_name);

	myDirent = readdir(dir);
	printf("d_ino: %d\n", (int)myDirent->d_ino);
	printf("d_off: %d\n", (int)myDirent->d_off);
	printf("d_reclen: %d\n", (unsigned int)myDirent->d_reclen);
	printf("d_type: %d\n", (unsigned int)myDirent->d_type);
	printf("d_name: %s\n\n", myDirent->d_name);

	myDirent = readdir(dir);
	printf("d_ino: %d\n", (int)myDirent->d_ino);
	printf("d_off: %d\n", (int)myDirent->d_off);
	printf("d_reclen: %d\n", (unsigned int)myDirent->d_reclen);
	printf("d_type: %d\n", (unsigned int)myDirent->d_type);
	printf("d_name: %s\n\n", myDirent->d_name);

	myDirent = readdir(dir);
	printf("d_ino: %d\n", (int)myDirent->d_ino);
	printf("d_off: %d\n", (int)myDirent->d_off);
	printf("d_reclen: %d\n", (unsigned int)myDirent->d_reclen);
	printf("d_type: %d\n", (unsigned int)myDirent->d_type);
	printf("d_name: %s\n\n", myDirent->d_name);

	myDirent = readdir(dir);
	printf("d_ino: %d\n", (int)myDirent->d_ino);
	printf("d_off: %d\n", (int)myDirent->d_off);
	printf("d_reclen: %d\n", (unsigned int)myDirent->d_reclen);
	printf("d_type: %d\n", (unsigned int)myDirent->d_type);
	printf("d_name: %s\n\n", myDirent->d_name);


	closedir(dir);		/* free allocated structures */
}

