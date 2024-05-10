#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

#define MAX_LINE_LENGTH 1024

/**
 * main - Monty bytecode interpreter
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */

// Main function taking command line arguments
int main(int argc, char *argv[])
{
	// Declare a file pointer
	FILE *file;
	// Declare a character array to hold each line of the file
	char line[MAX_LINE_LENGTH];
	// Initialize line number to 1
	int line_number = 1;
	// Initialize a pointer to the stack structure to NULL
	stack_t *stack = NULL;

	// if the number of command line arguments is not 2
	if (argc != 2)
	{
		// Print usage error message
		fprintf(stderr, "USAGE: monty file\n");

		// Exit the program with a failure status
		exit(EXIT_FAILURE);
	}
	// Open the file provided as a command line argument is read mode
	file = fopen(argv[1], "r");

	// if the file cannot be opened
	if (file == NULL)
	{
		// print error message
		fprintf(stderr, "Error: can't open file %\n", argv[1]);
		// Exit the program with a failure status
		exit(EXIT_FAILURE)
	}

	// while there are lines in the file
	while (fgets(line, sizeof(line), file) != NULL)
	{
		// If the last character of the line is newline
		if (line[strlen(line) - 1] == '\n')

		// Replace the newline character with a null character
		line[strlen(line) - 1] == '\0';

		// if the line can not be parsed
		if (parse_line(line_number, &stack) == -1)
		{
			// print error message
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, line);
			// Free the memory allocated to the stack
			free_stack(*stack);
			// close the file
			fclose(file);
			// Exit the program with a failure status
			exit(EXIT_FAILURE);
		}
		// Increment the line number
		line_number++;
	}

	// Free the memory allocated to the stack
	free_stack(&stack);

	// close the file
	fclose(file);

	// Exit the program with a success status
	exit(EXIT_SUCCESS)
}
