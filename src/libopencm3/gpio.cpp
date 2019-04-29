#include "../../include/stm32cpp/gpio.h"

#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/exti.h>

#if defined(STM32F1)
#include <libopencm3/stm32/f1/nvic.h>
#elif defined(STM32F2)
#include <libopencm3/stm32/f2/nvic.h>
#elif defined(STM32F4)
#include <libopencm3/stm32/f4/nvic.h>
#endif

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
      case 4:
        m_port = GPIOD;
        break;
      case 5:
        m_port = GPIOE;
        break;
    }
    m_pin = (uint16_t)((uint32_t)pin & 0xffff);
  }

  GPIO::GPIO(Pin pin, PullMode pullMode):
    GPIO(pin)
  {
    setInput(pullMode);
  }

  GPIO::GPIO(Pin pin, OutputMode outputMode, PullMode pullMode, OutputSpeed speed):
    GPIO(pin)
  {
    setOutput(outputMode, pullMode, speed);
  }

  GPIO::GPIO(Pin pin, AFMode afMode, OutputMode outputMode, PullMode pullMode, OutputSpeed speed):
    GPIO(pin)
  {
    setAlternateFunction(afMode, outputMode, pullMode, speed);
  }

  void GPIO::setInput(PullMode pullMode) {
#if defined(STM32F1)
    uint8_t cnf;
    uint8_t odr;
    switch (pullMode) {
      case PullMode::NoPull:
        cnf = GPIO_CNF_INPUT_FLOAT;
        odr = 0;
        break;
      case PullMode::PullUp:
        cnf = GPIO_CNF_INPUT_PULL_UPDOWN;
        odr = 0;
        break;
      case PullMode::PullDown:
        cnf = GPIO_CNF_INPUT_PULL_UPDOWN;
        odr = 1;
        break;
    }
    gpio_set_mode(m_port, GPIO_MODE_INPUT, cnf, m_pin);
    if (odr) {
      GPIO_ODR(m_port) |= 1u << m_pin;
    }
    else {
      GPIO_ODR(m_port) &= ~(1u << m_pin);
    }


#elif defined(STM32F4)
    gpio_mode_setup(m_port, (uint8_t)PortMode::Input, (uint8_t)pullMode, m_pin);
#endif
  }

  void GPIO::setOutput(OutputMode outputMode, PullMode pullMode, OutputSpeed speed) {
#if defined(STM32F1)
    uint8_t mode = (uint8_t)speed;
    uint8_t cnf;
    switch (outputMode) {
      case OutputMode::OpenDrain:
        cnf = GPIO_CNF_OUTPUT_OPENDRAIN;
        break;
      case OutputMode::PushPull:
        cnf = GPIO_CNF_OUTPUT_PUSHPULL;
        break;
    }

    gpio_set_mode(m_port, mode, cnf, m_pin);
#elif defined(STM32F4)
    gpio_mode_setup(m_port, (uint8_t)PortMode::Output, (uint8_t)pullMode, m_pin);
    gpio_set_output_options(m_port, (uint8_t)outputMode, (uint8_t)speed, m_pin);
#endif
  }

  void GPIO::setAlternateFunction(AFMode afMode, OutputMode outputMode, PullMode pullMode, OutputSpeed speed) {
#if defined(STM32F1)
    uint8_t mode = (uint8_t)speed;
    uint8_t cnf;
    switch (outputMode) {
      case OutputMode::OpenDrain:
        cnf = GPIO_CNF_OUTPUT_ALTFN_OPENDRAIN;
        break;
      case OutputMode::PushPull:
        cnf = GPIO_CNF_OUTPUT_ALTFN_PUSHPULL;
        break;
    }

    gpio_set_mode(m_port, mode, cnf, m_pin);

#elif defined(STM32F4)
    gpio_mode_setup(m_port, (uint8_t)PortMode::AlternateFunction, (uint8_t)pullMode, m_pin);
    gpio_set_output_options(m_port, (uint8_t)outputMode, (uint8_t)speed, m_pin);
    gpio_set_af(m_port, (uint8_t)afMode, m_pin);
#endif
  }

  void GPIO::clear() {
    gpio_clear(m_port, m_pin);
  }

  void GPIO::set() {
    gpio_set(m_port, m_pin);
  }

  void GPIO::toggle() {
    gpio_toggle(m_port, m_pin);
  }

  void GPIO::setEXTI_IRQ(EXTITrigger trigger, uint8_t nvic)
  {
    exti_trigger_type extiTriggerType;
    switch (trigger) {
      case EXTITrigger::Rising:
        extiTriggerType = EXTI_TRIGGER_RISING;
        break;
      case EXTITrigger::Falling:
        extiTriggerType = EXTI_TRIGGER_FALLING;
        break;
      case EXTITrigger::Both:
        extiTriggerType = EXTI_TRIGGER_BOTH;
        break;
    }

    nvic_enable_irq(nvic);
    exti_select_source(m_pin, m_port);
    exti_set_trigger(m_pin, extiTriggerType);
    exti_enable_request(m_pin);
  }

  void GPIO::clearEXTIPendingBit()
  {
    exti_reset_request(m_pin);
  }
}
