#include "./shared.hpp"


void handle_client(int client_socket)
{
	char buffer[1024];
	int buffer_len;
	while ((buffer_len = recv(client_socket, buffer, 1024, 0)) > 0)
	{
		buffer[buffer_len] = '\0';
		std::cout << "Received message: " << buffer << std::endl;
		send(client_socket, buffer, buffer_len, 0);
	}
	close(client_socket);
}

int main()
{
	int server_socket, client_socket;
	sockaddr_in server_address {};
	sockaddr_in client_address {};
	auto options {1};
	const auto addrlen {sizeof(server_address)};

	std::vector<std::thread> threads {};

	// Create server socket
	if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0)
	{
		perror("socket failed");
		exit(EXIT_FAILURE);
	}

	// Set socket options
	if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &options, sizeof(options)))
	{
		perror("setsockopt");
		exit(EXIT_FAILURE);
	}

	// Bind server socket to port
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = INADDR_ANY;
	server_address.sin_port = htons(kPort);
	if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}

	// Start listening for incoming connections
	if (listen(server_socket, kMaxClients) < 0)
	{
		perror("listen");
		exit(EXIT_FAILURE);
	}

	// Accept incoming connections and start new threads for each client
	while ((client_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t * ) & addrlen)))
	{
		std::cout << "New client connected" << std::endl;
		threads.emplace_back(std::thread(handle_client, client_socket));
	}

	// Join all threads
	for (auto &thread : threads)
	{
		thread.join();
	}
}