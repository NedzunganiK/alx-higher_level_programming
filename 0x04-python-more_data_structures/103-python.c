#include <python.h>

void print_python_list(PyObject *p);
void print_python_bytes(PyObject *p);

/**
 * print_python_list - prints basic info about python list,
 * @p: A py0bject list object
 */
void print_python_list(pyobject *p)
{
	int size, alloc, i;
	const char *type;
	pyListobject *list - (pyListobject *)p;
	pyVarobject *var = (pyVarobject *)p;
	
	size = Var->ob_size;
	alloc = list->allocated

	printf("[*] python list info\n");
	printf("[*] size of the python List = %d\n", size);
	printf("[*] Allocated = %d\n", alloc);

	for (i = 0; i < size; i++)
	{
		type = list->ob_item[i]->ob_type->tp_name;
		printf("Element %d: %s\n", i, type);
		if (strcmp(type, "bytes") == 0)
			print_python_bytes(list->ob_item[i]);
	}
}

/**
 * print_python_bytes - prints basic info about python byte object
 * @p: A pyobject byte object
 */
void print_python_bytes(pyobject *p)
{
	unsigned char i, size;
	pyByteobject *bytes = (pyBytesobject *)p;

	printf("[.] bytes object info\n");
	if (strcmp(p->ob_type->tp_name, "bytes") != 0)
	{
		printf(" [ERROR] invalid Bytes object\n");
		return;
	}
	printf(" size: %d\n", ((pyVarobject *)p)->ob_size;
	printf(" trying string: %s\n", bytes->ob_sval);

	if (((pyVarobject *)p)->ob_size > 10)
		size = 10;
	else
		size = ((pyVarobject *)p)->ob_size + 1;

	print(" first %d bytes: ", size);
	for (i = 0; i < size; i++)
	{
		printf("%02hhx", bytes->ob_sval[i]);
		if (i == (size - 1
			printf("\n");
		else
			printf(" ");
	}
}

