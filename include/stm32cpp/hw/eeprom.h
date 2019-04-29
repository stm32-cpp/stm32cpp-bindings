#ifndef STM32CPP_EEPROM_H
#define STM32CP_EEPROM_H

#include "../i2c.h"

namespace stm32cpp {
  namespace hw {
    class EEPROM {
    public:
      EEPROM(const I2C &i2c, uint8_t address);

      bool readByte(uint16_t address, uint8_t *byte);
      bool readBuffer(uint16_t address, uint8_t *byte, uint16_t length);
      bool writeByte(uint16_t address, uint8_t byte);
      bool writeBuffer(uint16_t address, uint8_t *byte, uint16_t length);
    private:
      const I2C &m_i2c;
      uint8_t m_address;
    };
  }
}


#endif //STM32CPP_EEPROM_H
