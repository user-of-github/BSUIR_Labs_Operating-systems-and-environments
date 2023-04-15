#ifndef CLIENT_SERVER_USERS_INTERACTION__SHARED_HPP_
#define CLIENT_SERVER_USERS_INTERACTION__SHARED_HPP_


#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <vector>
#include <thread>

const auto kPort {8080};
const auto kMaxClients {4};
const auto kIpAddress {"127.0.0.1"};
const auto kBufferSize {1024};

#endif //CLIENT_SERVER_USERS_INTERACTION__SHARED_HPP_
