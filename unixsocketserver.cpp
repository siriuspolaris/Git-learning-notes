#include <iostream>
#include <sys/un.h>
#include <sys/socket.h>
#include <unistd.h>
#include <cstring>

using namespace std;

int main()
{
	struct sockaddr_un addr;
	int sfd, cfd;
	ssize_t numRead;
	char buf[10];
	pid_t pid;

	cout << "server" << endl;
	sfd = socket(AF_UNIX, SOCK_STREAM, 0);
	if (sfd == -1)
	{
		cout << "server: " << "socket failed" << endl;
		return -1;
	}

	memset(&addr, 0, sizeof(struct sockaddr_un));
	memset(buf, 0, sizeof(buf));
	addr.sun_family = AF_UNIX;
	addr.sun_path[1] = 's';
	addr.sun_path[2] = 'i';
	addr.sun_path[3] = 'p';
	addr.sun_path[4] = 'c';
//	strncpy(&addr.sun_path[1], "sipc", ((sizeof(addr.sun_path) -1) >= 5) ? 5 : sizeof(addr.sun_path));

	if (bind(sfd, (struct sockaddr *)&addr, sizeof(struct sockaddr_un)) == -1)
	{
		cout << "server: " << "bind failed" << endl;
		return -1;
	}

	if (listen(sfd, 1) == -1)
	{
		cout << "server: " << "listen failed" << endl;
		return -1;
	}

	while (1)
	{
		cfd = accept(sfd, NULL, NULL);
		if (cfd == -1)
		{
			cout << "server: " << "accept failed" << endl;
			return -1;
		}

		cout << "server: " << "accept new connect" << endl;
 
//		while ((numRead = read(cfd, buf, 10)) > 0)
		while ((numRead = read(cfd, &pid, sizeof(pid))) > 0)
		{
			cout << "server: recv " << numRead << " bytes " << "clientpid:" << pid/*buf*/ << endl;
		}

		if (numRead == 0)
		{
			cout << "server: " << "client is closed" << endl;
		}
		else
		{
			cout << "server: " << "errno: " << errno << endl;
		}
	}
}

