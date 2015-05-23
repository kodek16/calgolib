#include <stdio.h>
#include <stdlib.h>

#include "io"
#include "errors"

#ifdef CAL_THREAD_SAFE_IO
#define gc getchar
#define pc putchar
#else
#define gc getchar_unlocked
#define pc putchar_unlocked
#endif

template <typename SignedDecimal>
void read_signed_decimal(SignedDecimal& x) {
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
		cal::error("Input error: signed number not found.");
	}

	x = 0;
	
	do {
		x = (x << 1) + (x << 3);
		x += c - '0';
		c = gc();	
	} while (c >= '0' && c <= '9');

	if (negate) {
		x = -x;
	}
}

template <typename UnsignedDecimal>
void read_unsigned_decimal(UnsignedDecimal& x) {
	int c = gc();
	while (c == ' ' || c == '\t' || c == '\n') {
		c = gc();
	}

	if (c < '0' || c > '9') {
		cal::error("Input error: unsigned number not found.");
	}

	x = 0;
	
	do {
		x = (x << 1) + (x << 3);
		x += c - '0';
		c = gc();	
	} while (c >= '0' && c <= '9');
}

template <> void cal::read<short> (short& x) { read_signed_decimal(x); }
template <> void cal::read<int> (int& x) { read_signed_decimal(x); }
template <> void cal::read<long> (long& x) { read_signed_decimal(x); }
template <> void cal::read<long long> (long long& x) { read_signed_decimal(x); }

template <> void cal::read<unsigned short> (unsigned short& x) { read_unsigned_decimal(x); }
template <> void cal::read<unsigned int> (unsigned int& x) { read_unsigned_decimal(x); }
template <> void cal::read<unsigned long> (unsigned long& x) { read_unsigned_decimal(x); }
template <> void cal::read<unsigned long long> (unsigned long long& x) { read_unsigned_decimal(x); }

template <typename Float>
void read_float(Float& x) {
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
		cal::error("Input error: signed number not found.");
	}

	x = 0.0;

	do {
		x *= 10;
		x += c - '0';
		c = gc();
	} while (c >= '0' && c <= '9');

	if (c == '.') {
		Float divider = 10;

		c = gc();
		while (c >= '0' && c <= '9') {
			x += (c - '0') / divider;
			divider *= 10;
			c = gc();
		}
	}
}

template <> void cal::read<float> (float& x) { read_float(x); }
template <> void cal::read<double> (double& x) { read_float(x); }
template <> void cal::read<long double> (long double& x) { read_float(x); }

template <>
void cal::read<char> (char& c) {
	int ic = gc();
	while (c == ' ' || c == '\t' || c == '\n') {
		ic = gc();
	}

	if (ic == EOF) {
		cal::error("Input error: end of file reached.");
	} else {
		c = (char) ic;
	}
}

template <>
void cal::read<std::string> (std::string& s) {
	int c = gc();
	while (c == ' ' || c == '\t' || c == '\n') {
		c = gc();
	}

	if (c == EOF) {
		cal::error("Input error: end of file reached.");
	}

	do {
		s += c;
		c = gc();
	} while (c != ' ' && c != '\t' && c != '\n' && c != EOF);
}

template <typename First, typename... Rest>
void cal::read(First& first, Rest&... rest) {
	read(first);
	read(rest...);
}

template <typename Decimal>
void write_decimal(Decimal x, int max_len) {
	if (x == 0) {
		pc('0');
	} else {
		if (x < 0) {
			pc('-');
			x = -x;
		}

		char *num = (char *) malloc(max_len + 1);
		int i = 0;
		while (x) {
			num[i++] = '0' + (x % 10);
			x /= 10;
		}

		for (int j = i - 1; j >= 0; j--) {
			pc(num[i]);
		}

		free(num);
	}
}

template <> void cal::write<short> (short x) { write_decimal(x, 6); }
template <> void cal::write<int> (int x) { write_decimal(x, 11); }
template <> void cal::write<long> (long x) { write_decimal(x, 20); }
template <> void cal::write<long long> (long long x) { write_decimal(x, 20); }

template <> void cal::write<unsigned short> (unsigned short x) { write_decimal(x, 6); }
template <> void cal::write<unsigned int> (unsigned int x) { write_decimal(x, 11); }
template <> void cal::write<unsigned long> (unsigned long x) { write_decimal(x, 20); }
template <> void cal::write<unsigned long long> (unsigned long long x) { write_decimal(x, 20); }

template <> void cal::write<float> (float f) { printf("%.8f", f); }
template <> void cal::write<double> (double f) { printf("%.15f", f); }
template <> void cal::write<long double> (long double f) { printf("%.15Lf", f); }

template <> void cal::write<char> (char c) {
	pc(c);
}

template <> void cal::write<std::string> (std::string s) {
	for (const char *str = s.c_str(); *str; str++) {
		pc(*str);
	}
}

template <typename First, typename... Rest>
void cal::write(First first, Rest... rest) {
	write(first);
	write(rest...);
}

void cal::file_io(std::string name) {
	freopen((name + ".in").c_str(), "r", stdin);
	freopen((name + ".out").c_str(), "w", stdout);
}

void cal::file_io(std::string infile, std::string outfile) {
	freopen(infile.c_str(), "r", stdin);
	freopen(outfile.c_str(), "w", stdout);
}