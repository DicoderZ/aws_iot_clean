#include "buzzer.h"
#include "driver/gpio.h"
#include "driver/ledc.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <stdlib.h>  // For generating random numbers

#define BUZZER_GPIO GPIO_NUM_0
#define BUZZER_CHANNEL LEDC_CHANNEL_0
#define BUZZER_FREQ_HZ 2000
#define BUZZER_RESOLUTION LEDC_TIMER_8_BIT
#define BUZZER_CONTROL_GPIO GPIO_NUM_10

void buzzer_init()
{
    // Initialization code remains the same
    gpio_pad_select_gpio(BUZZER_CONTROL_GPIO);
    gpio_set_direction(BUZZER_CONTROL_GPIO, GPIO_MODE_OUTPUT);
}

void buzzer_play_tone()
{
    // Turn on the control GPIO
    gpio_set_level(BUZZER_CONTROL_GPIO, 1);

    // Play the tone
    ledc_timer_config_t ledc_timer = {
        .duty_resolution = BUZZER_RESOLUTION,
        .freq_hz = BUZZER_FREQ_HZ,
        .speed_mode = LEDC_LOW_SPEED_MODE,
        .timer_num = LEDC_TIMER_0
    };
    ledc_timer_config(&ledc_timer);
    
    ledc_channel_config_t ledc_channel = {
        .channel = BUZZER_CHANNEL,
        .duty = 128,
        .gpio_num = BUZZER_GPIO,
        .speed_mode = LEDC_LOW_SPEED_MODE,
        .timer_sel = LEDC_TIMER_0
    };
    ledc_channel_config(&ledc_channel);

    // Play the tone for 1 second
    vTaskDelay(pdMS_TO_TICKS(200));

    // Turn off the control GPIO
    gpio_set_level(BUZZER_CONTROL_GPIO, 0);
}


void buzzer_play_heartbeat()
{
    // Turn on the control GPIO
    gpio_set_level(BUZZER_CONTROL_GPIO, 1);

    // Play the tone resembling a single heartbeat
    ledc_timer_config_t ledc_timer = {
        .duty_resolution = BUZZER_RESOLUTION,
        .freq_hz = BUZZER_FREQ_HZ,
        .speed_mode = LEDC_LOW_SPEED_MODE,
        .timer_num = LEDC_TIMER_0
    };
    ledc_timer_config(&ledc_timer);

    ledc_channel_config_t ledc_channel = {
        .channel = BUZZER_CHANNEL,
        .duty = 128,
        .gpio_num = BUZZER_GPIO,
        .speed_mode = LEDC_LOW_SPEED_MODE,
        .timer_sel = LEDC_TIMER_0
    };
    ledc_channel_config(&ledc_channel);

    // Play the low-pitch beat
    ledc_set_duty(ledc_channel.speed_mode, ledc_channel.channel, 0);
    ledc_update_duty(ledc_channel.speed_mode, ledc_channel.channel);
    vTaskDelay(pdMS_TO_TICKS(50));

    // Play the higher-pitch beat
    ledc_set_duty(ledc_channel.speed_mode, ledc_channel.channel, 128);
    ledc_update_duty(ledc_channel.speed_mode, ledc_channel.channel);
    vTaskDelay(pdMS_TO_TICKS(50));

    // Turn off the control GPIO
    gpio_set_level(BUZZER_CONTROL_GPIO, 0);
}

void buzzer_play_progress()
{
    // Turn on the control GPIO
    gpio_set_level(BUZZER_CONTROL_GPIO, 1);

    // Play the tone resembling a single heartbeat
    ledc_timer_config_t ledc_timer = {
        .duty_resolution = BUZZER_RESOLUTION,
        .freq_hz = BUZZER_FREQ_HZ,
        .speed_mode = LEDC_LOW_SPEED_MODE,
        .timer_num = LEDC_TIMER_0
    };
    ledc_timer_config(&ledc_timer);

    ledc_channel_config_t ledc_channel = {
        .channel = BUZZER_CHANNEL,
        .duty = 128,
        .gpio_num = BUZZER_GPIO,
        .speed_mode = LEDC_LOW_SPEED_MODE,
        .timer_sel = LEDC_TIMER_0
    };
    ledc_channel_config(&ledc_channel);

    // Play the low-pitch beat
    ledc_set_duty(ledc_channel.speed_mode, ledc_channel.channel, 0);
    ledc_update_duty(ledc_channel.speed_mode, ledc_channel.channel);
    vTaskDelay(pdMS_TO_TICKS(75));

    // Play the higher-pitch beat
    ledc_set_duty(ledc_channel.speed_mode, ledc_channel.channel, 64);
    ledc_update_duty(ledc_channel.speed_mode, ledc_channel.channel);
    vTaskDelay(pdMS_TO_TICKS(75));

    // Play the higher-pitch beat
    ledc_set_duty(ledc_channel.speed_mode, ledc_channel.channel, 128);
    ledc_update_duty(ledc_channel.speed_mode, ledc_channel.channel);
    vTaskDelay(pdMS_TO_TICKS(75));

    // Play the higher-pitch beat
    ledc_set_duty(ledc_channel.speed_mode, ledc_channel.channel, 192);
    ledc_update_duty(ledc_channel.speed_mode, ledc_channel.channel);
    vTaskDelay(pdMS_TO_TICKS(75));
    // Turn off the control GPIO
    gpio_set_level(BUZZER_CONTROL_GPIO, 0);
}