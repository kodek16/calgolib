#include "calgolib"

using namespace cal;

int main() {
	file_io("input.txt", "output.txt");

	f80 f;

	read(f);
	write(f / 2);
}