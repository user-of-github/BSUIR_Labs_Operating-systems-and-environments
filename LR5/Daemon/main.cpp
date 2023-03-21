#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <cstdlib>
#include <unistd.h>


int main()
{
	FILE *fp{nullptr};

	const pid_t process_id{fork()};

	if (process_id < 0) {
		std::cout << "Problem occurred" << '\n';
		perror(reinterpret_cast<const char *>(process_id));
		exit(1);
	}

	if (process_id > 0) {
		std::cout << "It's parent process" << '\n';
		exit(0);
	}

	umask(0); // make newly created fs items readable, writable

	const pid_t session_id{setsid()};

	if (session_id < 0) {
		exit(1);
	}

	return 0;
}
