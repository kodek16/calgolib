#include <stdio.h>
#include <stdlib.h>

#include "errors"

void cal::error(std::string text, int exit_code) {
	fprintf(stderr, "Runtime error in calgolib: %s\n", text.c_str());
	exit(exit_code);
}