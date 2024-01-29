#ifndef ESP32_SMARTDISPLAY_H
#define ESP32_SMARTDISPLAY_H

#include <Arduino.h>
#include <lvgl.h>

// LVGL lines buffered
#define LVGL_PIXEL_BUFFER_LINES 16

// Use last PWM_CHANNEL for backlight
#define PWM_CHANNEL_BCKL (SOC_LEDC_CHANNEL_NUM - 1)
#define PWM_FREQ_BCKL 20000
#define PWM_BITS_BCKL 8
#define PWM_MAX_BCKL ((1 << PWM_BITS_BCKL) - 1)

// Exported functions
#ifdef __cplusplus
extern "C"
{
#endif

#include <mutex>

// Mutex to access lvgl if multi-threaded
extern std::recursive_mutex lvgl_mutex;
// Initialize the display and touch
extern void smartdisplay_init();
// Set the color of the led
extern void smartdisplay_set_led_color(lv_color32_t rgb);
// Get the value of the CDS sensor
extern int smartdisplay_get_light_intensity();
// Beep with the specified frequency and duration
extern void smartdisplay_beep(unsigned int frequency, unsigned long duration);
// Set the brightness of the backlight display
extern void smartdisplay_tft_set_backlight(uint16_t duty); // 0-1023 (12 bits)
// Put the display to sleep
extern void smartdisplay_tft_sleep();
// Wake the display
extern void smartdisplay_tft_wake();

// ESP32_2432S028R
#ifdef ESP32_2432S028R
#define TFT_WIDTH 240
#define TFT_HEIGHT 320
#define ILI9431
#define ILI9431_SPI_SCLK 14
#define ILI9431_SPI_MOSI 13
#define ILI9431_SPI_MISO 12
#define ILI9341_PIN_CS 15
#define ILI9341_PIN_DC 2
#define ILI9341_SPI_FREQ 50000000
#define ILI9341_PIN_BL 21
#define ILI9341_PWM_CHANNEL_BL 12
#define ILI9341_PWM_FREQ_BL 5000
#define ILI9341_PWM_BITS_BL 8
#define ILI9341_PWM_MAX_BL ((1 << ILI9341_PWM_BITS_BL) - 1)
#define XPT2046
#define XPT2046_SPI_SCLK 25
#define XPT2046_SPI_MOSI 32
#define XPT2046_SPI_MISO 39
#define XPT2046_SPI_FREQ 2000000
#define XPT2046_PIN_INT 36
#define XPT2046_PIN_CS 33
// Calibration 240x320
#define XPT2046_MIN_X 349
#define XPT2046_MAX_X 3859
#define XPT2046_MIN_Y 247
#define XPT2046_MAX_Y 3871

extern SPIClass spi_ili9431;
extern SPIClass spi_xpt2046;
#endif
#ifdef __cplusplus
}
#endif

#endif