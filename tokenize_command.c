
#include "shell.h"
/**
 * tokenize_command - Tokenizes a command string into an array of strings.
 * @command: The command string to tokenize.
 * @status: An integer representing the status of the command.
 *
 * Return: 1 on success, 0 on failure.
 */
int tokenize_command(char *command, int status)
{
	int i = 0;
	char *command_copied = _strdup(command);

	if (command_copied == NULL)
	{
		return (0);
	}

	char *token = strtok(command_copied, TOK_DE);

	while (token != NULL)
	{
		argument_vector[i] = process_token(token, status);
		if (argument_vector[i] == NULL)
		{
			free_vector(argument_vector);
			free(command_copied);
			return (0);
		}
		token = strtok(NULL, TOK_DE);
		i++;
	}
	argument_vector[i] = NULL;
	free(command_copied);
	return (1);

}