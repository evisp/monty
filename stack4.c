#include "monty.h"

void _pstr(stack_t **top, __attribute__((unused)) unsigned int line)
{
	stack_t *tmp;
	int ascii_num;

	if (*top == NULL)
	{
		putchar('\n');
		return;
	}
	tmp = *top;
	while (tmp != NULL)
	{
		ascii_num = tmp->n;

		if (ascii_num <= 0 || ascii_num > 127)
			break;
		putchar(ascii_num);
		tmp = tmp->next;
	}
	putchar('\n');
}
