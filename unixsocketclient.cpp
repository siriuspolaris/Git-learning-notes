#include <iostream>
#include <sys/un.h>
#include <sys/socket.h>
#include <unistd.h>
#include <cstring>

using namespace std;

int main()
{
	struct sockaddr_un addr;
	int sfd;
	ssize_t numRead;
	pid_t pid = getpid();

	cout << "client" << " pid: " << pid << endl;
	sfd = socket(AF_UNIX, SOCK_STREAM, 0);
	if (sfd == -1)
	{
		cout << "client: " << "socket failed" << endl;
	}

	memset(&addr, 0, sizeof(struct sockaddr_un));
	addr.sun_family = AF_UNIX;
	addr.sun_path[1] = 's';
	addr.sun_path[2] = 'i';
	addr.sun_path[3] = 'p';
	addr.sun_path[4] = 'c';
//	strncpy(&addr.sun_path[1], "sipc", ((sizeof(addr.sun_path) -1) >= 5) ? 5 : sizeof(addr.sun_path));

	if (connect(sfd, (struct sockaddr *)&addr, sizeof(struct sockaddr_un)) == -1)
	{
		cout << "client: " << "connect failed" << endl;
	}

//	if (write(sfd, buf, 4) != 4)
	if (write(sfd, &pid, sizeof(pid)) != 4)
	{
		cout << "client: " << "write failed" << endl;
	}
	else
	{
		cout << "client: " << "write 4 byte" << endl;
	}

	sleep(100);
}

