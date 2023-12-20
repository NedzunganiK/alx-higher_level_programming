#include <Python.h>
#include <stdio.h>

void print_python_list(PyObject *p) {
    if (!PyList_Check(p)) {
        fprintf(stderr, "[ERROR] Invalid List Object\n");
        return;
    }

    Py_ssize_t size = PyList_Size(p);
    Py_ssize_t allocated = ((PyListObject *)p)->allocated;

    printf("[*] Python list info\n");
    printf("[*] Size of the Python List = %zd\n", size);
    printf("[*] Allocated = %zd\n", allocated);

    for (Py_ssize_t i = 0; i < size; ++i) {
        printf("Element %zd: ", i);

        PyObject *element = PyList_GetItem(p, i);

        if (PyBytes_Check(element)) {
            // Print Python bytes info
            printf("[.] bytes object info\n");

            if (!PyBytes_Check(element)) {
                fprintf(stderr, "  [ERROR] Invalid Bytes Object\n");
                continue;
            }

            Py_ssize_t bytes_size = PyBytes_Size(element);
            char *bytes_str = PyBytes_AsString(element);

            printf("  size: %zd\n", bytes_size);
            printf("  trying string: %s\n", bytes_str);

            printf("  first 10 bytes: ");
            for (Py_ssize_t j = 0; j < bytes_size && j < 10; ++j) {
                printf("%02x ", bytes_str[j] & 0xff);
            }
            printf("\n");
        } else if (PyFloat_Check(element)) {
            // Print Python float info
            printf("[.] float object info\n");

            if (!PyFloat_Check(element)) {
                fprintf(stderr, "  [ERROR] Invalid Float Object\n");
                continue;
            }

            double value = PyFloat_AsDouble(element);
            printf("  value: %f\n", value);
        } else {
            printf("%s\n", Py_TYPE(element)->tp_name);
        }
    }
}

void print_python_bytes(PyObject *p) {
    if (!PyBytes_Check(p)) {
        fprintf(stderr, "[ERROR] Invalid Bytes Object\n");
        return;
    }

    printf("[.] bytes object info\n");

    Py_ssize_t size = PyBytes_Size(p);
    char *str = PyBytes_AsString(p);

    printf("  size: %zd\n", size);
    printf("  trying string: %s\n", str);

    printf("  first 10 bytes: ");
    for (Py_ssize_t i = 0; i < size && i < 10; ++i) {
        printf("%02x ", str[i] & 0xff);
    }
    printf("\n");
}

void print_python_float(PyObject *p) {
    if (!PyFloat_Check(p)) {
        fprintf(stderr, "[ERROR] Invalid Float Object\n");
        return;
    }

    printf("[.] float object info\n");

    double value = PyFloat_AsDouble(p);
    printf("  value: %f\n", value);
}

