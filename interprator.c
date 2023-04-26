#include "shell.h"

/**
 * main - command line interprattor
 *
 * Return: void
 */
int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	pid_t pid;
	int status;

	while (1)
	{
		printf("$ ");
		fgets(command, MAX_COMMAND_LENGTH, stdin);
		if (feof(stdin))
			break;
		command[strcspn(command, " ")] = '\0';
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			exceclp(command, command, (char *) NULL);
			perror("execlp");
			exit(EXIT_FAILURE);
		}
		else
		{
			waitpid(pid, &status, 0);
		}
	}
	return (0);
}
