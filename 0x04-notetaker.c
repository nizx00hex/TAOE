#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include "hacking.h"

void usage(char *, char *);
void fatal(char *);
void *ec_malloc(unsigned int);

int main(int argc, char *argv[]) {
	int userid, fd;
	char *buffer, *datafile;

	buffer = (char *) ec_malloc(100);
	datafile = (char *) ec_malloc(20);
	strcpy(datafile, "/var/notes");

	if(argc < 2)
		usage(argv[0], datafile);

	strcpy(buffer, argv[1]);

	printf("[DEBUG] buffer @ %p: \'%s\'\n", buffer, buffer);
	printf("[DEBUG] datafile @ %p: \'%s\'\n", datafile, datafile);

	//open the file 
	fd = open(datafile, O_WRONLY|O_CREAT|O_APPEND, S_IRUSR|S_IWUSR);
	if(fd == -1)
		fatal("in main() while openning file");
	printf("[DEBUG] file descriptor is %d\n", fd);
	userid = getuid(); //get the current user ID.

	//write the user ID before the data
	if(write(fd, &userid, 4) == -1)
		fatal("in main() while writing userid to file");
	write(fd, "\n", 1);

	//write the note
	if(write(fd, buffer, strlen(buffer)) == -1)
		fatal("in main() while writing note to file");
	write(fd, "\n", 1); //Terminate the line using \n

	//Closing the file
	if(close(fd) == -1)
		fatal("in main() while closing file");
	printf("Notes has been saved.\n");

	free(buffer);
	free(datafile);

	buffer = "\x00";
	buffer = "\x00";
}
