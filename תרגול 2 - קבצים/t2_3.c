//This example show how to switch between printout to file instead to screen And vice versa
//commandline: ./a.out screen.txt

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv) 
{ 
	int pid, status; 
	int newfd; /* new file descriptor */ 
	int screen_fd; //temp location to hold keyboard address
	if (argc != 2) 
	{ 
		fprintf(stderr, "usage: %s output_file\n", argv[0]); 
		exit(1); 
	} 
	if ((newfd = open(argv[1], O_CREAT|O_TRUNC|O_WRONLY, 0644)) < 0) 
	{ 
		perror(argv[1]); /* open failed */ 
		exit(1); 
	} 
	printf("This printout No. 0 goes to the standard output (screen).\n"); 
	printf("Now the standard output will go to \"%s\" file.\n", 	argv[1]); 
	/* this new file will become the standard output */
	/*standard output is file descriptor 1, so we use dup2 */ 
	/* to copy the new file descriptor onto file descriptor 1 */ 
	/* dup2 will close the current standard output */ 
	screen_fd=dup(1);//Store keyboard address to the first empty fd (the first empty ID will be keep in screen_fd.
	dup2(newfd, 1); 
	printf("This printout No. 1 goes to the file.\n"); 
	dup2(screen_fd, 1); //Switch back from file address to screen address
	printf("This printout No. 2 goes back to screen instead to the file.\n"); 
	dup2(newfd, 1); 
	printf("This printout No. 3 goes to the file.\n"); 
	exit(0); 
	//Please notice when the process exit all fd closed 
}
