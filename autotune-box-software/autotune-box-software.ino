#include "driver/i2s.h"
#include "arduinoFFT.h"

// Pin definitions
// Display
const uint8_t DIG1_A = GPIO_NUM_19;
const uint8_t DIG1_B = GPIO_NUM_21;
const uint8_t DIG1_C = GPIO_NUM_18;
const uint8_t DIG1_D = GPIO_NUM_5;
const uint8_t DIG1_E = GPIO_NUM_17;
const uint8_t DIG1_F = GPIO_NUM_4;
const uint8_t DIG2_B = GPIO_NUM_21;
const uint8_t DP1 = GPIO_NUM_22;

// Record button
const uint8_t RECORD = GPIO_NUM_26;

// MIC
const uint8_t AUDIO_IN = GPIO_NUM_26;
const uint8_t AUDIO_SCK = GPIO_NUM_27;
const uint8_t AUDIO_WS = GPIO_NUM_14;

// Mic out
const uint8_t AUDIO_OUT = GPIO_NUM_25;

// I2S Port
const i2s_port_t I2S_PORT = I2S_NUM_1;

// FFT Params
const uint16_t SAMPLE_FREQUENCY = 32000;

void setup() {
  Serial.begin(115200);
  esp_err_t err;

  i2s_config_t i2s_config = {
    .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_RX),
    .sample_rate = 20000,
    .bits_per_sample = I2S_BITS_PER_SAMPLE_32BIT,
    .channel_format = I2S_CHANNEL_FMT_ONLY_LEFT,
    .communication_format = i2s_comm_format_t(I2S_COMM_FORMAT_I2S),
    .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1,
    .dma_buf_count = 4,
    .dma_buf_len = 1024,
    .use_apll = false,
    .tx_desc_auto_clear = false,
    .fixed_mclk = 0};

  // The pin config as per the setup
  const i2s_pin_config_t pin_config = {
      .bck_io_num = AUDIO_SCK,   // Serial Clock (SCK)
      .ws_io_num = AUDIO_WS,    // Word Select (WS)
      .data_out_num = I2S_PIN_NO_CHANGE, // not used (only for speakers)
      .data_in_num = AUDIO_IN   // Serial Data (SD)
  };

  // Configuring the I2S driver and pins.
  // This function must be called before any I2S driver read/write operations.
  err = i2s_driver_install(I2S_PORT, &i2s_config, 0, NULL);
  if (err != ESP_OK) {
    Serial.printf("Failed installing driver: %d\n", err);
    while (true);
  }
  err = i2s_set_pin(I2S_PORT, &pin_config);
  if (err != ESP_OK) {
    Serial.printf("Failed setting pin: %d\n", err);
    while (true);
  }
  Serial.println("I2S driver installed.");
}

void loop() {
  // put your main code here, to run repeatedly:
  bool record_state = digitalRead(RECORD);
  if (record_state){
    // Record many data

    // FFT data in set windows

    // Set all data in window to frequency of window

    // Send data to speaker
  }

}
