#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>
#include <endian.h>

int main(int argc, char **argv)
{
	uint16_t a;
	uint32_t b;
	uint16_t a_net;
	uint32_t b_net;
	uint16_t a_be;
	uint32_t b_be;

	a = 0xeffa;
	b = 0xeffabedc;
	printf("a: %x\n", a);
	printf("b: %x\n", b);

	printf("Default byte ordering: \n");
	printf("a : %x%x\n", ((uint8_t *)&a)[0], ((uint8_t *)&a)[1]);

	printf("b : %x%x%x%x\n", ((uint8_t *)&b)[0], ((uint8_t *)&b)[1],
	       ((uint8_t *)&b)[2], ((uint8_t *)&b)[3]);

	printf("After byte ordering(hton()): \n");
	a_net = htons(a);
	printf("a : %x%x\n", ((uint8_t *)&a_net)[0], ((uint8_t *)&a_net)[1]);

	b_net = htonl(b);
	printf("b : %x%x%x%x\n", ((uint8_t *)&b_net)[0], ((uint8_t *)&b_net)[1],
	       ((uint8_t *)&b_net)[2], ((uint8_t *)&b_net)[3]);

	printf("After byte ordering(htobe()): \n");
	a_be = htobe16(a);
	printf("a : %x%x\n", ((uint8_t *)&a_be)[0], ((uint8_t *)&a_be)[1]);

	b_be = htobe32(b);
	printf("b : %x%x%x%x\n", ((uint8_t *)&b_be)[0], ((uint8_t *)&b_be)[1],
	       ((uint8_t *)&b_be)[2], ((uint8_t *)&b_be)[3]);
	return 0;
}
