/* #include <zephyr/kernel.h> */

#include <stdio.h>
#include <stdlib.h>
#include <dds/ddsrt/environ.h>

#include "throughput_config.h"

int throughput_pub(int argc, char **argv);
int throughput_sub(int argc, char **argv);

char **environ = (char*[]) {
  (char*)&cdds_xml_config,
  NULL
};

void main(void)
{
    int ret;
    printf("CycloneDDS Throughput (%s)\n", CONFIG_BOARD);
#if BUILD_THROUGHPUT_PUB
    char *args[] = { "ThroughputPublisher" };
    ret = throughput_pub(sizeof(args)/sizeof(args[0]), args);
#else
    char *args[] = { "ThroughputSubscriber" };
    ret = throughput_sub(sizeof(args)/sizeof(args[0]), args);
#endif
    printf("Done (ret=%d)\n", ret);
    return;
}
