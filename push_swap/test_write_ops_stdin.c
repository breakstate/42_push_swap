#include <unistd.h>

int main()
{
	write(1, "pa\npb\npc\n", 9);
	return (0);
}
