#include "../../include/stm32cpp/gpio.h"

#include <libopencm3/stm32/gpio.h>

namespace stm32cpp {

  GPIO::GPIO(Pin pin) {
    auto port = (uint8_t)((uint32_t)pin >> 16);
    switch (port) {
      case 1:
        m_port = GPIOA;
        break;
      case 2:
        m_port = GPIOB;
        break;
      case 3:
        m_port = GPIOC;
        break;
    }
    m_pin = (uint16_t)((uint32_t)pin & 0xffff);
  }

  GPIO::GPIO(Pin pin, InputMode mode):
    GPIO(pin)
  {
    setInput(mode);
  }

  GPIO::GPIO(Pin pin, OutputMode mode, OutputSpeed speed):
    GPIO(pin)
  {
    setOutput(mode, speed);
  }

  void GPIO::setInput(InputMode mode) {
    gpio_set_mode(m_port, GPIO_MODE_INPUT, (uint8_t)mode, m_pin);
  }

  void GPIO::setOutput(OutputMode mode, OutputSpeed speed) {
    gpio_set_mode(m_port, (uint8_t)speed, (uint8_t)mode, m_pin);
  }
}
