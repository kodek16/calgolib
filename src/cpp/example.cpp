#include "calgolib"

using namespace cal;

int main() {
	mod_int<> x;
	long long lx = 0;
	for (int i = 1; i <= 10000; i++) {
		x += sqr(i);
		lx += sqr(i);
	}

	writeln(lx, ' ', x);
}