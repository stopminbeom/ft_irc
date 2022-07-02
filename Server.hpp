#ifndef SERVER_HPP
#define SERVER_HPP

#include <string>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <iostream>

class Server {
	private:
		int	port;
		std::string	password;
		Server();
	public:
};

#endif