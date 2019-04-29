#ifndef STM32CPP_GPIO_H
#define STM32CPP_GPIO_H

#include <cstdint>

#define GPIO_ENUM_PIN(port, pin) (((uint8_t)port << 16) | (1 << pin))

namespace stm32cpp {
  enum class Port: uint8_t {
    A = 1,
    B = 2,
    C = 3
  };

  enum class Pin: uint32_t {
    PA0 = GPIO_ENUM_PIN(Port::A, 0),
    PA1 = GPIO_ENUM_PIN(Port::A, 1),
    PA2 = GPIO_ENUM_PIN(Port::A, 2),
    PA3 = GPIO_ENUM_PIN(Port::A, 3),
    PA4 = GPIO_ENUM_PIN(Port::A, 4),
    PA5 = GPIO_ENUM_PIN(Port::A, 5),
    PA6 = GPIO_ENUM_PIN(Port::A, 6),
    PA7 = GPIO_ENUM_PIN(Port::A, 7),
    PA8 = GPIO_ENUM_PIN(Port::A, 8),
    PA9 = GPIO_ENUM_PIN(Port::A, 9),
    PA10 = GPIO_ENUM_PIN(Port::A, 10),
    PA11 = GPIO_ENUM_PIN(Port::A, 11),
    PA12 = GPIO_ENUM_PIN(Port::A, 12),
    PA13 = GPIO_ENUM_PIN(Port::A, 13),
    PA14 = GPIO_ENUM_PIN(Port::A, 14),
    PA15 = GPIO_ENUM_PIN(Port::A, 15),

    PB0 = GPIO_ENUM_PIN(Port::B, 0),
    PB1 = GPIO_ENUM_PIN(Port::B, 1),
    PB2 = GPIO_ENUM_PIN(Port::B, 2),
    PB3 = GPIO_ENUM_PIN(Port::B, 3),
    PB4 = GPIO_ENUM_PIN(Port::B, 4),
    PB5 = GPIO_ENUM_PIN(Port::B, 5),
    PB6 = GPIO_ENUM_PIN(Port::B, 6),
    PB7 = GPIO_ENUM_PIN(Port::B, 7),
    PB8 = GPIO_ENUM_PIN(Port::B, 8),
    PB9 = GPIO_ENUM_PIN(Port::B, 9),
    PB10 = GPIO_ENUM_PIN(Port::B, 10),
    PB11 = GPIO_ENUM_PIN(Port::B, 11),
    PB12 = GPIO_ENUM_PIN(Port::B, 12),
    PB13 = GPIO_ENUM_PIN(Port::B, 13),
    PB14 = GPIO_ENUM_PIN(Port::B, 14),
    PB15 = GPIO_ENUM_PIN(Port::B, 15),

    PC0 = GPIO_ENUM_PIN(Port::C, 0),
    PC1 = GPIO_ENUM_PIN(Port::C, 1),
    PC2 = GPIO_ENUM_PIN(Port::C, 2),
    PC3 = GPIO_ENUM_PIN(Port::C, 3),
    PC4 = GPIO_ENUM_PIN(Port::C, 4),
    PC5 = GPIO_ENUM_PIN(Port::C, 5),
    PC6 = GPIO_ENUM_PIN(Port::C, 6),
    PC7 = GPIO_ENUM_PIN(Port::C, 7),
    PC8 = GPIO_ENUM_PIN(Port::C, 8),
    PC9 = GPIO_ENUM_PIN(Port::C, 9),
    PC10 = GPIO_ENUM_PIN(Port::C, 10),
    PC11 = GPIO_ENUM_PIN(Port::C, 11),
    PC12 = GPIO_ENUM_PIN(Port::C, 12),
    PC13 = GPIO_ENUM_PIN(Port::C, 13),
    PC14 = GPIO_ENUM_PIN(Port::C, 14),
    PC15 = GPIO_ENUM_PIN(Port::C, 15),

#if defined(STM32F1)
    I2C1_SCL = PB6,
    I2C1_SDA = PB7,
    I2C2_SCL = PB10,
    I2C2_SDA = PB11,
#endif
  };

  enum class InputMode: uint8_t {
    Analog = 0x00,      // GPIO_CNF_INPUT_ANALOG
    Float = 0x01,       // GPIO_CNF_INPUT_FLOAT
    PullUpDown = 0x02,  // GPIO_CNF_INPUT_PULL_UPDOWN
  };

  enum class OutputMode: uint8_t {
    /** Digital Output Pushpull */
    PushPull = 0x00,    // GPIO_CNF_OUTPUT_PUSHPULL
    OpenDrain = 0x01,   // GPIO_CNF_OUTPUT_OPENDRAIN,
    AF_PushPull = 0x02, // GPIO_CNF_OUTPUT_ALTFN_PUSHPULL
    AF_OpenDrain = 0x03 // GPIO_CNF_OUTPUT_ALTFN_OPENDRAIN
  };

  enum class OutputSpeed {
    Speed10mhz = 0x01,  // GPIO_MODE_OUTPUT_10_MHZ
    Speed2mhz = 0x02,   // GPIO_MODE_OUTPUT_2_MHZ
    Speed50mhz = 0x03   // GPIO_MODE_OUTPUT_2_MHZ
  };

  class GPIO {
  public:
    GPIO(Pin pin);
    GPIO(Pin pin, InputMode mode);
    GPIO(Pin pin, OutputMode mode, OutputSpeed speed);

    void setInput(InputMode mode);
    void setOutput(OutputMode mode, OutputSpeed speed);
  private:
    uint32_t m_port;
    uint16_t m_pin;
  };
}


#endif //STM32CPP_GPIO_H
