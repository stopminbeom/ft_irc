#ifndef SERVER_HPP
# define SERVER_HPP

# include <string>
# include <sys/socket.h>
# include <arpa/inet.h>
# include <iostream>
# include <stdlib.h>
# include <poll.h>
# include <unistd.h>

# define POLL_NUM	100

class Server {
	private:
		int	port;
		int	server_socket;
		std::string	password;
		struct sockaddr_in	server_addr, client_addr;
		struct pollfd	poll_arr[POLL_NUM];
		socklen_t	addrsize;

	public:
		Server(int _port, std::string pw);
		~Server();
		int setup();
		int run();
};

#endif