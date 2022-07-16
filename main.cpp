#include "Server.hpp"

using std::cout;
using std::endl;
using std::cerr;

int main(int argc, char **argv) {
	if (argc =! 3) {
		cerr << "[Error] bad arguments" << endl;
		return 1;
	}
	for (int i = 0; argv[1][i]; i++) {
		if (!isdigit(argv[1][i])) {
			cerr << "[Error] invalid character in port" << endl;
			return 1;
		}
	}
	Server server(atoi(argv[1]), argv[2]);

	if (server.setup())
		return 1;
	server.run();
}