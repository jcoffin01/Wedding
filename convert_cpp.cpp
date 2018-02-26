#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

int main(int argc, char **argv) {
	using namespace std::literals;
	using namespace std::chrono;

	if (argc != 2) {
		std::cerr << "Usage: convert <filename>\n";
		return EXIT_FAILURE;
	}

	std::ifstream in(argv[1]);
	std::ofstream out(argv[1] + ".out"s);

	auto start = high_resolution_clock::now();

	char ch;
	while (in.get(ch))
	{
		out.put(ch);
		if (ch == ',')
			out.put('\n');
	}
	auto finish = high_resolution_clock::now();

	std::cout << "Time: " << duration_cast<milliseconds>(finish - start).count() << "\n";
}
