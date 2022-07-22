#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

#define MAX_LINE 80 /* The maximum length command */

			 /*
			 * After reading user input, the steps are:
			 * (1) fork a child process using fork()
			 * (2) the child process will invoke execvp()
		     * (3) if command included &, parent will invoke wait()
             */

int main(void)
{
	char *args[MAX_LINE/2 + 1]; /* command line arguments */
	char line[MAX_LINE]; /* get command line */
	char *token; /* piece of input string */
	const char *delim = " "; /* param for strtok */
	int i = 0;
	int j;
	int status;
	int exit_code;
	int should_run = 1; /* flag to determine when to exit program */
	
	while (should_run) {
		printf("osh>");
		fflush(stdout);

		fgets(line, MAX_LINE, stdin); /* read input from command line */
		size_t len = strlen(line);
		if (line[len -1] == '\n'){ /* if input is new line */
			line[len - 1] = '\0';
		}
		if (strcmp(line, "exit") == 0) { /* checking exit keyword */
			break;
		}
		pid_t pid, wait_pid;
		pid = fork(); /* start fork */
		
		switch(pid) /* handle child/parent processes */
		{
		case -1:
			perror("fork failed... exiting");
			exit(0);
		case 0: /* child process */
			token = strtok(line, delim); /* tokenize first command */
			while (token != NULL) {
				args[i] = token;
				token = strtok(NULL, delim); /* tokenize again to get rest of commands */
				i++; 
			}
			args[i] = NULL; /* set last to NULL */
			execvp(args[0], args); 
		default: /* parent process */
			if (line[strlen(line) - 1] == '&') { /* checking & condition */
				printf("wait command\n");
				for (; j < i; j++) {
					sleep(1);
				}
				wait_pid = wait(&status);
				printf("Child has finished: PID = %d\n", wait_pid);
				if (WIFEXITED(status)) {
					printf("Child exited with code %d\n", WEXITSTATUS(status));
				}
				else {
					printf("Child terminated abnormally\n");
				}
			}
			exit(exit_code);
		}
	}
	return 0;
}