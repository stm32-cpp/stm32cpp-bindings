
#include <stm32cpp/hw/eeprom.h>

#include "../../include/stm32cpp/hw/eeprom.h"

namespace stm32cpp {
  namespace hw {
    EEPROM::EEPROM(const I2C &i2c, uint8_t address):
      m_i2c(i2c),
      m_address(address)
    {

    }

    bool EEPROM::readByte(uint16_t address, uint8_t *byte) {
      m_i2c.sendStartWrite(m_address);

      if (!m_i2c.isBusy()) {
        return false;
      }

      m_i2c.sendByte((uint8_t)(address >> 8));
      m_i2c.sendByte((uint8_t)(address & 0xff));

      m_i2c.sendStartRead(m_address);

      if (!m_i2c.isBusy()) {
        return false;
      }

      *byte = m_i2c.readByte();
      m_i2c.sendStop();

      return true;
    }

    bool EEPROM::readBuffer(uint16_t address, uint8_t *byte, uint16_t length) {
      m_i2c.sendStartWrite(m_address);

      if (!m_i2c.isBusy()) {
        return false;
      }

      m_i2c.sendByte((uint8_t)(address >> 8));
      m_i2c.sendByte((uint8_t)(address & 0xff));

      m_i2c.sendStartRead(m_address);

      if (!m_i2c.isBusy()) {
        return false;
      }

      m_i2c.setAck(true);
      while (length > 0) {
        *byte = m_i2c.readByte();

        length--;
        byte++;

        if (length == 1) {
          m_i2c.setAck(false);
        }
      }

      m_i2c.sendStop();

      return true;
    }

    bool EEPROM::writeByte(uint16_t address, uint8_t byte) {
      m_i2c.sendStartWrite(m_address);

      if (!m_i2c.isBusy()) {
        return false;
      }

      m_i2c.sendByte((uint8_t)(address >> 8));
      m_i2c.sendByte((uint8_t)(address & 0xff));

      m_i2c.sendByte(byte);
      m_i2c.sendStop();

      return true;
    }

    bool EEPROM::writeBuffer(uint16_t address, uint8_t *byte, uint16_t length) {
      m_i2c.sendStartWrite(m_address);

      if (!m_i2c.isBusy()) {
        return false;
      }

      m_i2c.setAck(true);

      m_i2c.sendByte((uint8_t)(address >> 8));
      m_i2c.sendByte((uint8_t)(address & 0xff));

      while (length > 0) {
        m_i2c.sendByte(*byte);

        length--;
        byte++;
      }

      m_i2c.sendStop();

      return true;
    }
  }
}
