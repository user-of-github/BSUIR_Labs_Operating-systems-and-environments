#include "./shared.hpp"


void handle_client_query(const int client_socket);

const std::string execute_command(const std::string &command);

int main()
{
	const auto server_socket{socket(AF_INET, SOCK_STREAM, 0)}; // Create server socket
	if (server_socket == 0)
		throw std::runtime_error("[Server] Error: Server socket creation failed");


	// Set socket options
	auto options{1};
	const auto set_socket_options_result{setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &options, sizeof(options))};
	if (set_socket_options_result != 0)
		throw std::runtime_error("[Server] Error: Socket options can not be set");


	// Bind server socket to port
	sockaddr_in server_address{};
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = INADDR_ANY;
	server_address.sin_port = htons(kPort);


	//bind()  assigns  the address  specified  by  addr  to the socket referred to by the file descriptor sockfd
	const auto bind_result{bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address))};
	if (bind_result < 0)
		throw std::runtime_error("[Server] Error: bind failed");


	// Start listening for incoming connections
	if (listen(server_socket, kMaxClients) < 0)
		throw std::runtime_error("[Server] Error: listen failed");

	std::vector<std::thread> threads{};

	// Accept incoming connections and start new threads for each client
	int client_socket{};
	sockaddr_in client_address{};
	const auto addr_len{sizeof(server_address)};
	while ((client_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t * ) & addr_len)))
	{
		std::cout << "[Server] New client connected" << '\n';
		threads.emplace_back(std::thread(handle_client_query, client_socket));
	}

	// Join all threads
	for (auto &thread : threads)
		thread.join();

	return 0;
}

void handle_client_query(int client_socket)
{
	while (true)
	{
		char buffer[kBufferSize];
		const auto buffer_length{recv(client_socket, buffer, kBufferSize, 0)};

		if (buffer_length <= 0)
			break;

		std::string received_command{buffer};
		received_command.resize(buffer_length);

		std::cout << "[Server] Received message: " << received_command << '\n';
		const auto executing_response{execute_command(received_command)};

		send(client_socket, executing_response.c_str(), kBufferSize, 0);
	}

	close(client_socket);
}

const std::string execute_command(const std::string &command)
{
	char buffer[kBufferSize]{};
	std::string result{};

	const auto pipe{popen(command.c_str(), "r")};

	if (!pipe)
		throw std::runtime_error("[Server] Error: popen() failed");

	try
	{
		while (fgets(buffer, sizeof buffer, pipe) != NULL)
			result += std::string{buffer};
	}
	catch (std::exception &exception)
	{
		pclose(pipe);
		throw std::runtime_error(exception.what());
	}

	pclose(pipe);

	return result;
}