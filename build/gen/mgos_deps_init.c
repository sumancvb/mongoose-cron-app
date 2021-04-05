/* This file is auto-generated by mos build, do not edit! */

#include <stdbool.h>
#include <stdio.h>

#include "common/cs_dbg.h"

#include "mgos_app.h"


extern bool mgos_mongoose_init(void);
extern bool mgos_vfs_common_init(void);
extern bool mgos_vfs_dev_part_init(void);
extern bool mgos_vfs_fs_lfs_init(void);
extern bool mgos_vfs_fs_spiffs_init(void);
extern bool mgos_core_init(void);
extern bool mgos_mqtt_init(void);
extern bool mgos_shadow_init(void);
extern bool mgos_aws_init(void);
extern bool mgos_location_init(void);
extern bool mgos_sntp_init(void);
extern bool mgos_cron_init(void);
extern bool mgos_mbedtls_init(void);
extern bool mgos_rpc_common_init(void);
extern bool mgos_rpc_service_config_init(void);
extern bool mgos_rpc_service_fs_init(void);
extern bool mgos_rpc_uart_init(void);
extern bool mgos_wifi_init(void);

#ifndef MGOS_LIB_INFO_VERSION
struct mgos_lib_info {
  const char *name;
  const char *version;
  bool (*init)(void);
};
#endif

const struct mgos_lib_info mgos_libs_info[] = {

    // "mongoose". deps: [ ]
    {.name = "mongoose", .version = "6.18", .init = mgos_mongoose_init},

    // "vfs-common". deps: [ ]
    {.name = "vfs-common", .version = "1.0", .init = mgos_vfs_common_init},

    // "vfs-dev-part". deps: [ "vfs-common" ]
    {.name = "vfs-dev-part", .version = "1.0", .init = mgos_vfs_dev_part_init},

    // "vfs-fs-lfs". deps: [ "vfs-common" ]
    {.name = "vfs-fs-lfs", .version = "2.2.0", .init = mgos_vfs_fs_lfs_init},

    // "vfs-fs-spiffs". deps: [ "vfs-common" ]
    {.name = "vfs-fs-spiffs", .version = "1.0", .init = mgos_vfs_fs_spiffs_init},

    // "core". deps: [ "mongoose" "vfs-common" "vfs-dev-part" "vfs-fs-lfs" "vfs-fs-spiffs" ]
    {.name = "core", .version = "1.0", .init = mgos_core_init},

    // "mqtt". deps: [ "core" ]
    {.name = "mqtt", .version = "1.0", .init = mgos_mqtt_init},

    // "shadow". deps: [ "core" ]
    {.name = "shadow", .version = "1.0", .init = mgos_shadow_init},

    // "aws". deps: [ "ca-bundle" "core" "mqtt" "shadow" ]
    {.name = "aws", .version = "1.0", .init = mgos_aws_init},

    // "location". deps: [ "core" ]
    {.name = "location", .version = "1.0", .init = mgos_location_init},

    // "sntp". deps: [ "core" ]
    {.name = "sntp", .version = "1.0", .init = mgos_sntp_init},

    // "cron". deps: [ "core" "location" "sntp" ]
    {.name = "cron", .version = "1.0", .init = mgos_cron_init},

    // "mbedtls". deps: [ ]
    {.name = "mbedtls", .version = "2.16.6-cesanta1", .init = mgos_mbedtls_init},

    // "rpc-common". deps: [ "core" "mongoose" ]
    {.name = "rpc-common", .version = "1.0", .init = mgos_rpc_common_init},

    // "rpc-service-config". deps: [ "core" "rpc-common" ]
    {.name = "rpc-service-config", .version = "1.0", .init = mgos_rpc_service_config_init},

    // "rpc-service-fs". deps: [ "core" "rpc-common" "vfs-common" ]
    {.name = "rpc-service-fs", .version = "1.0", .init = mgos_rpc_service_fs_init},

    // "rpc-uart". deps: [ "core" "rpc-common" ]
    {.name = "rpc-uart", .version = "1.0", .init = mgos_rpc_uart_init},

    // "wifi". deps: [ "core" ]
    {.name = "wifi", .version = "1.0", .init = mgos_wifi_init},

    // Last entry.
    {.name = NULL},
};

bool mgos_deps_init(void) {
  for (const struct mgos_lib_info *l = mgos_libs_info; l->name != NULL; l++) {
    LOG(LL_DEBUG, ("Init %s %s...", l->name, l->version));
    if (!l->init()) {
      LOG(LL_ERROR, ("%s init failed", l->name));
      return false;
    }
  }
  return true;
}