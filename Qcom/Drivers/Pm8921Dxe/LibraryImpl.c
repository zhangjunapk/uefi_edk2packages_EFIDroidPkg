#include <Base.h>

#include <Library/LKEnvLib.h>
#include <Library/QcomSsbiLib.h>
#include <Library/QcomPm8921Lib.h>

#include "pm8921_p.h"

QCOM_PM8921_PROTOCOL *gPM8921 = NULL;

STATIC pm8921_dev_t pmic = {0};
STATIC QCOM_PM8921_PROTOCOL mInternalPM8921 = {
  pm8921_gpio_config,
  pm8921_gpio_config_array,
  pm8921_boot_done,
  pm8921_ldo_set_voltage,
  pm8921_config_reset_pwr_off,
  pm8921_gpio_get,
  pm8921_pwrkey_status,
  pm8921_config_led_current,
  pm8921_config_drv_keypad,
  pm8921_low_voltage_switch_enable,
  pm8921_mpp_set_digital_output,
  pm8921_rtc_alarm_disable,
  pm89xx_bat_alarm_set,
  pm89xx_bat_alarm_status,
  pm89xx_vbus_status,
  pm89xx_ldo_set_voltage,
  pm8921_HDMI_Switch,
};

RETURN_STATUS
EFIAPI
Pm8921ImplLibInitialize (
  VOID
  )
{
  gPM8921 = &mInternalPM8921;

  // Initialize PMIC driver
  pmic.read = (pm8921_read_func) gSSBI->pa1_ssbi2_read_bytes;
  pmic.write = (pm8921_write_func) gSSBI->pa1_ssbi2_write_bytes;
  pm8921_init(&pmic);

  return RETURN_SUCCESS;
}
