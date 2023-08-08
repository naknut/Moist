/*
 * Copyright (c) 2021 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

#include "app_task.h"

#include <zephyr/logging/log.h>

#include <inttypes.h>
#include <stddef.h>
#include <stdint.h>

#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/adc.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include <zephyr/sys/util.h>

LOG_MODULE_REGISTER(app, CONFIG_CHIP_APP_LOG_LEVEL);

int main()
{
	// int err2;
	// uint32_t count = 0;
	// uint16_t buf;
	// struct adc_sequence sequence = {
	// 	.buffer = &buf,
	// 	/* buffer size in bytes, not number of samples */
	// 	.buffer_size = sizeof(buf),
	// };

	// /* Configure channels individually prior to sampling. */
	// for (size_t i = 0U; i < ARRAY_SIZE(adc_channels); i++) {
	// 	if (!device_is_ready(adc_channels[i].dev)) {
	// 		printk("ADC controller device %s not ready\n", adc_channels[i].dev->name);
	// 		return 0;
	// 	}

	// 	err2 = adc_channel_setup_dt(&adc_channels[i]);
	// 	if (err2 < 0) {
	// 		printk("Could not setup channel #%d (%d)\n", i, err2);
	// 		return 0;
	// 	}
	// }

	// while (1) {
	// 	printk("ADC reading[%u]:\n", count++);
	// 	for (size_t i = 0U; i < ARRAY_SIZE(adc_channels); i++) {
	// 		int32_t val_mv;

	// 		printk("- %s, channel %d: ",
	// 		       adc_channels[i].dev->name,
	// 		       adc_channels[i].channel_id);

	// 		(void)adc_sequence_init_dt(&adc_channels[i], &sequence);

	// 		err2 = adc_read(adc_channels[i].dev, &sequence);
	// 		if (err2 < 0) {
	// 			printk("Could not read (%d)\n", err2);
	// 			continue;
	// 		}

	// 		/*
	// 		 * If using differential mode, the 16 bit value
	// 		 * in the ADC sample buffer should be a signed 2's
	// 		 * complement value.
	// 		 */
	// 		if (adc_channels[i].channel_cfg.differential) {
	// 			val_mv = (int32_t)((int16_t)buf);
	// 		} else {
	// 			val_mv = (int32_t)buf;
	// 		}
	// 		printk("%"PRId32, val_mv);
	// 		err2 = adc_raw_to_millivolts_dt(&adc_channels[i],
	// 					       &val_mv);
	// 		/* conversion to mV may not be supported, skip if not */
	// 		if (err2 < 0) {
	// 			printk(" (value in mV not available)\n");
	// 		} else {
	// 			printk(" = %"PRId32" mV\n", val_mv);
	// 		}
	// 	}

	// 	k_sleep(K_MSEC(1000));
	// }

	CHIP_ERROR err = AppTask::Instance().StartApp();

	LOG_ERR("Exited with code %" CHIP_ERROR_FORMAT, err.Format());
	return err == CHIP_NO_ERROR ? EXIT_SUCCESS : EXIT_FAILURE;
}
