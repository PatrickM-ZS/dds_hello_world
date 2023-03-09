/****************************************************************

  Generated by Eclipse Cyclone DDS IDL to C Translator
  File name: /home/patrickm/zephyrproject/zephyr/samples/cdds_linux/examples/throughput/Throughput.c
  Source: /home/patrickm/zephyrproject/zephyr/samples/dds_hello_world/cyclonedds/examples/throughput/Throughput.idl
  Cyclone DDS: V0.11.0

*****************************************************************/
#include "Throughput.h"

static const uint32_t ThroughputModule_DataType_ops [] =
{
  /* DataType */
  DDS_OP_ADR | DDS_OP_TYPE_8BY, offsetof (ThroughputModule_DataType, count),
  DDS_OP_ADR | DDS_OP_TYPE_SEQ | DDS_OP_SUBTYPE_1BY, offsetof (ThroughputModule_DataType, payload),
  DDS_OP_RTS
};

/* Type Information:
  [MINIMAL 46578b8e1954ec8f55c18e8a5800] (#deps: 0)
  [COMPLETE 74baedc00c9d1184e9ac93db73bc] (#deps: 0)
*/
#define TYPE_INFO_CDR_ThroughputModule_DataType (unsigned char []){ \
  0x60, 0x00, 0x00, 0x00, 0x01, 0x10, 0x00, 0x40, 0x28, 0x00, 0x00, 0x00, 0x24, 0x00, 0x00, 0x00, \
  0x14, 0x00, 0x00, 0x00, 0xf1, 0x46, 0x57, 0x8b, 0x8e, 0x19, 0x54, 0xec, 0x8f, 0x55, 0xc1, 0x8e, \
  0x8a, 0x58, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, \
  0x00, 0x00, 0x00, 0x00, 0x02, 0x10, 0x00, 0x40, 0x28, 0x00, 0x00, 0x00, 0x24, 0x00, 0x00, 0x00, \
  0x14, 0x00, 0x00, 0x00, 0xf2, 0x74, 0xba, 0xed, 0xc0, 0x0c, 0x9d, 0x11, 0x84, 0xe9, 0xac, 0x93, \
  0xdb, 0x73, 0xbc, 0x00, 0x6e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, \
  0x00, 0x00, 0x00, 0x00\
}
#define TYPE_INFO_CDR_SZ_ThroughputModule_DataType 100u
#define TYPE_MAP_CDR_ThroughputModule_DataType (unsigned char []){ \
  0x50, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0xf1, 0x46, 0x57, 0x8b, 0x8e, 0x19, 0x54, 0xec, \
  0x8f, 0x55, 0xc1, 0x8e, 0x8a, 0x58, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0xf1, 0x51, 0x01, 0x00, \
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, \
  0x0b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x08, 0xe2, 0x94, 0x2a, 0x04, 0x00, \
  0x10, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x80, 0xf3, 0x01, 0x00, 0x00, 0x02, \
  0x32, 0x1c, 0x3c, 0xf4, 0x82, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0xf2, 0x74, 0xba, 0xed, \
  0xc0, 0x0c, 0x9d, 0x11, 0x84, 0xe9, 0xac, 0x93, 0xdb, 0x73, 0xbc, 0x00, 0x6a, 0x00, 0x00, 0x00, \
  0xf2, 0x51, 0x01, 0x00, 0x23, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1b, 0x00, 0x00, 0x00, \
  0x54, 0x68, 0x72, 0x6f, 0x75, 0x67, 0x68, 0x70, 0x75, 0x74, 0x4d, 0x6f, 0x64, 0x75, 0x6c, 0x65, \
  0x3a, 0x3a, 0x44, 0x61, 0x74, 0x61, 0x54, 0x79, 0x70, 0x65, 0x00, 0x00, 0x3a, 0x00, 0x00, 0x00, \
  0x02, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x08, 0x00, \
  0x06, 0x00, 0x00, 0x00, 0x63, 0x6f, 0x75, 0x6e, 0x74, 0x00, 0x00, 0x00, 0x1a, 0x00, 0x00, 0x00, \
  0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x80, 0xf3, 0x01, 0x00, 0x00, 0x02, 0x08, 0x00, 0x00, 0x00, \
  0x70, 0x61, 0x79, 0x6c, 0x6f, 0x61, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00, 0x22, 0x00, 0x00, 0x00, \
  0x01, 0x00, 0x00, 0x00, 0xf2, 0x74, 0xba, 0xed, 0xc0, 0x0c, 0x9d, 0x11, 0x84, 0xe9, 0xac, 0x93, \
  0xdb, 0x73, 0xbc, 0xf1, 0x46, 0x57, 0x8b, 0x8e, 0x19, 0x54, 0xec, 0x8f, 0x55, 0xc1, 0x8e, 0x8a, \
  0x58, 0x00\
}
#define TYPE_MAP_CDR_SZ_ThroughputModule_DataType 258u
const dds_topic_descriptor_t ThroughputModule_DataType_desc =
{
  .m_size = sizeof (ThroughputModule_DataType),
  .m_align = dds_alignof (ThroughputModule_DataType),
  .m_flagset = DDS_TOPIC_XTYPES_METADATA,
  .m_nkeys = 0u,
  .m_typename = "ThroughputModule::DataType",
  .m_keys = NULL,
  .m_nops = 3,
  .m_ops = ThroughputModule_DataType_ops,
  .m_meta = "",
  .type_information = { .data = TYPE_INFO_CDR_ThroughputModule_DataType, .sz = TYPE_INFO_CDR_SZ_ThroughputModule_DataType },
  .type_mapping = { .data = TYPE_MAP_CDR_ThroughputModule_DataType, .sz = TYPE_MAP_CDR_SZ_ThroughputModule_DataType }
};

