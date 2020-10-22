#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
	pid_t pid;
	int status;

	/* if fork error return minus value */
	if((pid = fork()) < 0)
		perror("fork error");

	/* child process execute execl() function and ls command */
	else if(pid == 0)
	{
		execl("/bin/ls", "ls", (char *)0);
		perror("execl error");
	}

	/*
	   parent process displays the string
	   "execl() function execution"
	   after execl() function executing the ls command
	*/
	else
	{
		/* parent process wait until child dies */
		if(wait(&status) != pid)
			perror("wait error");

		printf("execl() function execution\n");
	}

	exit(EXIT_SUCCESS);
}
