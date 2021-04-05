#include "mgos.h"
#include "mgos_cron.h"

#define LED_PIN 2

static void cron_job_1_cb(void *user_data, mgos_cron_id_t id) {

  mgos_gpio_toggle(LED_PIN);

  time_t now = time(0);
  struct tm *tm = localtime(&now);

  char t[32];
  strftime(t, sizeof(t), "%T", tm);

  LOG(LL_INFO,
      ("Uptime: %.2lf, time: %s", mgos_uptime(), t));

  (void) user_data;
  (void) id;
}


enum mgos_app_init_result mgos_app_init(void) {
  mgos_gpio_setup_output(LED_PIN, 0);

  /*
   * Add a cron job at every 6:50:01 UTC everyday
   */
  mgos_cron_add("1 50 6 * * *", cron_job_1_cb, NULL);
  return MGOS_APP_INIT_SUCCESS;
}
