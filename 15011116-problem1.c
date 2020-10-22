#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	pid_t pid;
	int status;

	/* fork error */
	if((pid = fork()) < 0)
			perror("error in fork()\n");

	/* child process */
	else if(pid == 0)
		printf("Child PID is %d, Parent PID is %d.\n", getpid(), getppid());
	
	/* parent process */
	else
	{
		/* parent wait until child dies */
		if(wait(&status) != pid)
			perror("wait error");

		printf("Parent PID is %d\n", getpid());
	}

	exit(EXIT_SUCCESS);
}
