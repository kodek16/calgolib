#include <stdio.h>

#include "io.h"
//#include <ext/errors>

#ifdef EXT_THREAD_SAFE_IO
#define gc getchar
#else
#define gc getchar_unlocked
#endif

template <>
void ext::read<int> (int& x) {
	int c = gc();
	while (c == ' ' || c == '\t' || c == '\n') {
		c = gc();
	}

	bool negate = false;
	if (c == '-') {
		negate = true;
		c = gc();
	}

	if (c < '0' || c > '9') {
		//ext::error("Input error: number not found.");
	}

	x = 0;
	
	do {
		x *= 10;
		x += c - '0';
		c = gc();	
	} while (c >= '0' && c <= '9');

	if (negate) {
		x = -x;
	}
}

template <typename First, typename... Rest>
void ext::read(First& first, Rest&... rest) {
	read(first);
	read(rest...);
}