#include <iostream>
#include "io.h"

int main() {
	int x;
	ext::read(x);
	std::cout << "read: " << x << std::endl;
}