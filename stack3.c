#include "monty.h"

void _mod(stack_t **top, unsigned int line)
{
	stack_t *tmp;

	if (*top == NULL || (*top)->next ==  NULL)
		mod_error(line);

	if ((*top)->n == 0)
		div_error2(line);

	tmp = (*top)->next;
	tmp->n = (tmp->n) % (*top)->n;
	_pop(top, line);
}

void _rotl(stack_t **top, __attribute__((unused)) unsigned int line)
{
	stack_t *new_top, *tmp, *new_last;

	if (*top == NULL || (*top != NULL && (*top)->next == NULL))
		return;

	new_last = *top;
	tmp = *top;

	while (tmp->next)
		tmp = tmp->next;

	new_top = (*top)->next;
	new_last->next = NULL;
	new_last->prev = tmp;
	tmp->next = new_last;
	new_top->prev = NULL;
	*top = new_top;
}

void _rotr(stack_t **top, __attribute__((unused)) unsigned int line)
{
	stack_t *tmp;

	if (*top == NULL || (*top != NULL && (*top)->next == NULL))
		return;
	tmp = *top;
	while (tmp->next)
		tmp = tmp->next;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	tmp->next = *top;
	(*top)->prev = tmp;
	*top = tmp;
}

void _nop(stack_t **top, unsigned int line)
{
	(void) top;
	(void) line;
}

void _pchar(stack_t **top, unsigned int line)
{
	int ascii_num;

	if (*top == NULL)
		pchar_error2(line);

	ascii_num = (*top)->n;

	if (ascii_num < 0 || ascii_num > 127)
		pchar_error(line);
	putchar(ascii_num);
	putchar('\n');
}
