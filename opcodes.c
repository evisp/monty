#include "monty.h"

void (*get_op_code(char *token, unsigned int line)) (stack_t **, unsigned int)
{
  int i;
	instruction_t operation[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"nop", _nop},
		{"add", _add},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{NULL, NULL}
	};
	for (i = 0; operation[i].opcode != NULL; i++)
	{
		if (strcmp(token, operation[i].opcode) == 0)
		{
			return (operation[i].f);
		}
	}
	invalidInstruction_error(token, line);
	return (NULL);
}
