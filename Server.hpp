#ifndef SERVER_HPP
#define SERVER_HPP

#include <string>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <iostream>
#include <stdlib.h>

class Server {
	private:
		int	port;
		int	server_socket;
		std::string	password;
		struct sockaddr_in server_addr;

	public:
		Server(int _port, std::string pw);
		~Server();
		int setup();
		int run();
};

#endif