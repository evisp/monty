#include "monty.h"

int number;

void _push(stack_t **top, __attribute__ ((unused)) unsigned int line)
{
  stack_t *new = malloc(sizeof(stack_t));

  if (new == NULL)
    malloc_error();

  new->n = number;
  new->prev = NULL;

  if (*top == NULL)
    {
      new->next = NULL;
      *top = new;
    }
  else
    {
      new->next = *top;
      (*top)->prev = new;
      *top = new;
    }
}

void _pall(stack_t **top, __attribute__((unused)) unsigned int line)
{
  stack_t *tmp = *top;
  
  while (tmp != NULL)
    {
      printf("%d\n", tmp->n);
      tmp = tmp->next;
    }
}


void _pint(stack_t **top, __attribute__((unused)) unsigned int line)
{
  /* stack_t *tmp = *top; */

  if (*top != NULL)
    printf("%d\n", (*top)->n);
  else
    pint_error(line);
}

void _pop(stack_t **top, __attribute__((unused)) unsigned int line)
{
  stack_t *tmp = *top;

  if (*top == NULL)
    pop_error(line);

  tmp = tmp->next;
  free(*top);
  *top = tmp;
}

void _free(stack_t *top)
{
  stack_t *tmp;

  if (top == NULL)
    return;

  while (top != NULL)
    {
      tmp = top;
      top = top->next;
      free(tmp);
    }
  free(top);
}
