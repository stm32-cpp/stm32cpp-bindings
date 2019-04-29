#ifndef STM32CPP_I2C_H
#define STM32CPP_I2C_H

#include <cstdint>

namespace stm32cpp {
  enum class I2CMode {
    Fast,
    Standard
  };

  class I2C {
  public:
    explicit I2C(uint8_t number);
    void initGPIO();

    void enable();
    void disable();
    void setClockFrequency(uint8_t frequency);
    void setMode(I2CMode mode);
    void setCCR(uint16_t freq);
    void setTrise(uint16_t trise);
    void setAck(bool enabled) const;
    void setDMA(bool enabled);
    void setOwn7bitSlaveAddress(uint8_t address);

    bool isBusy() const;
    bool isMaster() const;

    void sendStartAck() const;
    void sendStop() const;
    void sendStartRead(uint8_t address) const;
    void sendStartWrite(uint8_t address) const;
    void sendByte(uint8_t byte) const;
    uint8_t readByte() const;

    void transfer7(uint8_t addr, uint8_t *w, uint16_t wn, uint8_t *r, uint16_t rn) const;
  private:
    uint32_t m_port;
  };
}


#endif //STM32CPP_I2C_H
