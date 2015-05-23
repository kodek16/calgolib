#include "io"

using namespace cal;

int main() {
	file_io("input.txt", "output.txt");

	long double f;

	read(f);
	write(f / 2);
}