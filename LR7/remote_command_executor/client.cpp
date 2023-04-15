#include <string>
#include <cstring>
#include "./shared.hpp"


const std::string kExitCommand{"exit"};

int main()
{
	// Create client socket
	const auto client_socket{socket(AF_INET, SOCK_STREAM, 0)};
	if (client_socket < 0)
		throw std::runtime_error("[Client] Error: socket is not created");


	// Set server address
	sockaddr_in server_address{};
	memset(&server_address, '0', sizeof(server_address));
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(kPort);


	// Convert IPv4 and IPv6 addresses from text to binary form
	const auto convert_into_network_address_result{inet_pton(AF_INET, kIpAddress, &server_address.sin_addr)};
	if (convert_into_network_address_result <= 0)
		throw std::runtime_error("[Client] Error: Invalid address / Address not supported");


	// Connect to server
	const auto connection_result{connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address))};
	if (connection_result < 0)
		throw std::runtime_error("[Client] Error: Connection failed");

	while (true)
	{
		char buffer[kBufferSize]{};

		std::cout << "[Client] Type shell command to send to remote server (type 'exit' to finish):" << '\n';
		std::string command{};
		std::getline(std::cin, command);

		if (command == kExitCommand)
			break;

		const auto command_c_str{command.c_str()};

		// Send message to server
		send(client_socket, command_c_str, strlen(command_c_str), 0);

		// Receive response from server
		read(client_socket, buffer, kBufferSize);
		std::cout << "[Client] Received response from server: " << '\n' << buffer << '\n' << '\n';
	}

	close(client_socket);

	return 0;
}