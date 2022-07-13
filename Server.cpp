#include "Server.hpp"

using std::cout;
using std::endl;
using std::cerr;

Server::Server(int _port, std::string pw): port(_port), password(pw) {}

Server::~Server()
{
}

int	Server::setup() {
	if (server_socket = socket(AF_INET, SOCK_STREAM, 0) == -1) {
		cerr << "[Error] Can't make server socket" << endl;
		return 1;
	}
	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(port);
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
		cerr << "[Error] Can't bind server socket" << endl;
		return 1;
	}
	if (listen(server_socket, SOMAXCONN) == -1) {
		cerr << "[Error] Can't listen server socket" << endl;
		return 1;
	}
	return 0;
}

int	Server::run() {
	
}