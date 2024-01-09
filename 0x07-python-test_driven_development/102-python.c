#define PY_SSIZE_T_CLEAN
#include <Python.h>

void print_python_string(PyObject *p) {
    if (!PyUnicode_Check(p)) {
        PyErr_Print();
        fprintf(stderr, "[ERROR] Invalid String Object\n");
        return;
    }

    Py_ssize_t length = PyUnicode_GET_LENGTH(p);
    const char *value = PyUnicode_AsUTF8(p);

    printf("[.] string object info\n");
    printf("  type: %s\n", PyUnicode_IS_COMPACT_ASCII(p) ? "compact ascii" : "compact unicode object");
    printf("  length: %zd\n", length);
    printf("  value: %s\n", value);

    if (!PyUnicode_IS_COMPACT_ASCII(p)) {
        printf("  [Unicode Info]\n");
        printf("    is_ascii: %d\n", PyUnicode_IS_ASCII(p));
        printf("    is_compact: %d\n", PyUnicode_IS_COMPACT(p));
        printf("    is_utf_8: %d\n", PyUnicode_IS_UTF8(p));
    }
}

int main(void) {
    Py_Initialize();

    Py_Finalize();
    return 0;
}

