#include"monty.h"

int number;

int main(int argc, char **argv)
{
  ssize_t line_size;
  FILE *fp;
  char *buf = NULL, *token = NULL; /*, command[1024]; */
  size_t len = 0;
  unsigned int line_counter = 1;
  stack_t *top = NULL;

  if (argc != 2)
    error_arguments();

  fp = fopen(argv[1], "r");
  if (fp == NULL)
    open_error(argv);

  while( (line_size = getline(&buf, &len, fp)) != -1)
    {
      token = strtok(buf, "\n\t\r ");
      if (*token == '\0')
	continue;
      
      /* strcpy(command, token); */

      /*

      if (is_comment(token, line_counter) == 1)
	continue;
      */
      
      if (strcmp(token, "push") == 0)
	{
	  token = strtok(NULL, "\n\t\r ");
	  /*
	  if (token == NULL || is_number(token) == -1)
	    not_int_err(line_counter);
	  */
	  number = atoi(token);

	  _push(&top, line_counter);
	}
      else if (strcmp(token, "pall") == 0)
	_pall(&top, line_counter);
      else if (strcmp(token, "pop") == 0)
	_pop(&top, line_counter);
      else if (strcmp(token, "pint") == 0)
	_pint(&top, line_counter);
      else if (strcmp(token, "add") == 0)
	_add(&top, line_counter);
      else if (strcmp(token, "sub") == 0)
	_sub(&top, line_counter);
      else if (strcmp(token, "mul") == 0)
	_mul(&top, line_counter);
      else if (strcmp(token, "div") == 0)
	_div(&top, line_counter);
      else
	printf("No known function");

      line_counter++;
    }
  fclose(fp);

  if (buf != NULL)
    free(buf);

  _free(top);
  
  return (0);
}
