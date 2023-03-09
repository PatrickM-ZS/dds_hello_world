/* #include <zephyr/kernel.h> */

#include <stdio.h>
#include <stdlib.h>
#include <dds/ddsrt/environ.h>

#include "roundtrip_config.h"

int roundtrip_ping(int argc, char **argv);
int roundtrip_pong(int argc, char **argv);

char **environ = (char*[]) {
  (char*)&cdds_xml_config,
  NULL
};

void main(void)
{
    int ret;
    printf("CycloneDDS Roundtrip (%s)\n", CONFIG_BOARD);
#if BUILD_ROUNDTRIP_PING
    char *args[] = { "RoundtripPing", "0", "0", "0" };
    ret = roundtrip_ping(sizeof(args)/sizeof(args[0]), args);
#else
    char *args[] = { "RoundtripPong" };
    ret = roundtrip_pong(sizeof(args)/sizeof(args[0]), args);
#endif
    printf("Done (ret=%d)\n", ret);
    return;
}
