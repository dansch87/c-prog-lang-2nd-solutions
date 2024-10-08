#include <stdio.h>
#include <stdarg.h>


void minprintf(char *fmt, ...);


int main(void) {
    minprintf("%d, %d\n", 1, 2);
    minprintf("%c\n", 'a');
    return 0;
}

void minprintf(char *fmt, ...) {
    va_list ap;
    char *p, *sval;
    int ival;
    double dval;

    // make ap point to 1st unnamed arg
    va_start(ap, fmt);
    for (p = fmt; *p; p++) {
        if (*p != '%') {
            putchar(*p);
            continue;
        }

        // look one character ahead
        switch(*++p) {
            case 'd':
                ival = va_arg(ap, int);
                printf("%d", ival);
                break;
            case 'f':
                dval = va_arg(ap, double);
                printf("%f", dval);
                break;
            case 's':
                for (sval = va_arg(ap, char *); *sval; sval++) {
                    putchar(*sval);
                }
                break;
            case 'c':
                ival = va_arg(ap, int);
                printf("%c", ival);
                break;
            default:
                putchar(*p);
                break;
        }
    }
    va_end(ap);
}





