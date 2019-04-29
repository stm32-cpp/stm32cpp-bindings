#include "../../include/stm32cpp/i2c.h"
#include "../../include/stm32cpp/gpio.h"

#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/i2c.h>

namespace stm32cpp {

  I2C::I2C(uint8_t number) {
    switch (number) {
      case 2:
        m_port = I2C2;
        break;

#ifdef I2C3
      case 3:
        m_port = I2C3;
        break;
#endif

      default:
        m_port = I2C1;
    }
  }

  void I2C::initGPIO() {
    Pin scl_pin;
    Pin sda_pin;
    switch (m_port) {
      case I2C2:
        scl_pin = Pin::I2C2_SCL;
        sda_pin = Pin::I2C2_SDA;
        break;

      default:
        scl_pin = Pin::I2C1_SCL;
        sda_pin = Pin::I2C1_SDA;
    }

    GPIO(scl_pin, AFMode::I2C, OutputMode::OpenDrain, PullMode::NoPull, OutputSpeed::Speed2mhz);
    GPIO(sda_pin, AFMode::I2C, OutputMode::OpenDrain, PullMode::NoPull, OutputSpeed::Speed2mhz);
  }

  void I2C::enable() {
    i2c_peripheral_enable(m_port);
  }

  void I2C::disable() {
    i2c_peripheral_disable(m_port);
  }

  void I2C::setClockFrequency(uint8_t frequency) {
    i2c_set_clock_frequency(m_port, frequency);
  }

  void I2C::setMode(I2CMode mode) {
    switch (mode) {
      case I2CMode::Fast:
        i2c_set_fast_mode(m_port);
        break;
      case I2CMode::Standard:
        i2c_set_standard_mode(m_port);
        break;
    }
  }

  void I2C::setCCR(uint16_t freq) {
    i2c_set_ccr(m_port, freq);
  }

  void I2C::setTrise(uint16_t trise) {
    i2c_set_trise(m_port, trise);
  }

  void I2C::setAck(bool enabled) const {
    if (enabled) {
      i2c_enable_ack(m_port);
    }
    else {
      i2c_disable_ack(m_port);
    }
  }

  void I2C::setDMA(bool enabled) {
    if (enabled) {
      i2c_enable_dma(m_port);
    }
    else {
      i2c_disable_dma(m_port);
    }
  }

  void I2C::setOwn7bitSlaveAddress(uint8_t address) {
    i2c_set_own_7bit_slave_address(m_port, address);
  }

  void I2C::transfer7(uint8_t addr, uint8_t *w, uint16_t wn, uint8_t *r, uint16_t rn) const {
    i2c_transfer7(m_port, addr, w, wn, r, rn);
  }

  void I2C::sendStartAck() const {
    i2c_send_start(m_port);
    while ((I2C_SR1(m_port) & I2C_SR1_SB) == 0u);
  }

  void I2C::sendStop() const {
    i2c_send_stop(m_port);
  }

  void I2C::sendStartRead(uint8_t address) const {
    sendStartAck();

    i2c_send_7bit_address(m_port, address, I2C_READ);
    while ((I2C_SR1(m_port) & I2C_SR1_ADDR) == 0);
  }

  void I2C::sendStartWrite(uint8_t address) const {
    sendStartAck();

    i2c_send_7bit_address(m_port, address, I2C_WRITE);
    while ((I2C_SR1(m_port) & I2C_SR1_ADDR) == 0);
  }

  void I2C::sendByte(uint8_t byte) const {
    i2c_send_data(m_port, byte);
    while ((I2C_SR1(m_port) & I2C_SR1_TxE) == 0);
  }

  bool I2C::isBusy() const {
    return (I2C_SR2(m_port) & I2C_SR2_BUSY) != 0;
  }

  uint8_t I2C::readByte() const {
    while ((I2C_SR1(m_port) & I2C_SR1_RxNE) == 0);
    return i2c_get_data(m_port);
  }

  bool I2C::isMaster() const {
    return (I2C_SR2(m_port) & I2C_SR2_MSL) != 0;
  }

}
