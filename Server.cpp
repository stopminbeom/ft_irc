#include "Server.hpp"

using std::cout;
using std::endl;
using std::cerr;

Server::Server(int _port, std::string pw): port(_port), password(pw) {}

Server::~Server() {
	for (int i = 0; i < POLL_NUM; ++i) {
		if (poll_arr[i].fd != -1) {
			close(poll_arr[i].fd);
		}
	}
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
	poll_arr[0].fd = server_socket;
	poll_arr[0].events = POLLIN;
	poll_arr[0].revents = 0;

	for (int i = 1; i < POLL_NUM; i++)
		poll_arr[i].fd = -1;

	return 0;
}

int	Server::run() {
	while (1) {
		if (poll(poll_arr, POLL_NUM, -1)) {
			if (poll_arr[0].revents == POLLIN) {
				bzero(&client_addr, sizeof(client_addr));
				int client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addrsize);

				for (int i = 1; i < POLL_NUM; i++) {
					if (poll_arr[i].fd == -1) {
						poll_arr[i].fd = client_socket;
						poll_arr[i].events = POLLIN;
						poll_arr[i].revents = 0;
						break;
					}
				}
			}

			for (int i = 1; i < POLL_NUM; i++) {
				if (poll_arr[i].revents == POLLIN) {
					// recv 함수 부분
				}
			}
		}
	}
}