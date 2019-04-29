#ifndef STM32CPP_GPIO_H
#define STM32CPP_GPIO_H

#include <cstdint>

#define GPIO_ENUM_PIN(port, pin) (((uint8_t)port << 16) | (1 << pin))

namespace stm32cpp {
  enum class Port: uint8_t {
    A = 1,
    B = 2,
    C = 3,
    D = 4,
    E = 5
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

    PD0 = GPIO_ENUM_PIN(Port::D, 0),
    PD1 = GPIO_ENUM_PIN(Port::D, 1),
    PD2 = GPIO_ENUM_PIN(Port::D, 2),
    PD3 = GPIO_ENUM_PIN(Port::D, 3),
    PD4 = GPIO_ENUM_PIN(Port::D, 4),
    PD5 = GPIO_ENUM_PIN(Port::D, 5),
    PD6 = GPIO_ENUM_PIN(Port::D, 6),
    PD7 = GPIO_ENUM_PIN(Port::D, 7),
    PD8 = GPIO_ENUM_PIN(Port::D, 8),
    PD9 = GPIO_ENUM_PIN(Port::D, 9),
    PD10 = GPIO_ENUM_PIN(Port::D, 10),
    PD11 = GPIO_ENUM_PIN(Port::D, 11),
    PD12 = GPIO_ENUM_PIN(Port::D, 12),
    PD13 = GPIO_ENUM_PIN(Port::D, 13),
    PD14 = GPIO_ENUM_PIN(Port::D, 14),
    PD15 = GPIO_ENUM_PIN(Port::D, 15),

    PE0 = GPIO_ENUM_PIN(Port::E, 0),
    PE1 = GPIO_ENUM_PIN(Port::E, 1),
    PE2 = GPIO_ENUM_PIN(Port::E, 2),
    PE3 = GPIO_ENUM_PIN(Port::E, 3),
    PE4 = GPIO_ENUM_PIN(Port::E, 4),
    PE5 = GPIO_ENUM_PIN(Port::E, 5),
    PE6 = GPIO_ENUM_PIN(Port::E, 6),
    PE7 = GPIO_ENUM_PIN(Port::E, 7),
    PE8 = GPIO_ENUM_PIN(Port::E, 8),
    PE9 = GPIO_ENUM_PIN(Port::E, 9),
    PE10 = GPIO_ENUM_PIN(Port::E, 10),
    PE11 = GPIO_ENUM_PIN(Port::E, 11),
    PE12 = GPIO_ENUM_PIN(Port::E, 12),
    PE13 = GPIO_ENUM_PIN(Port::E, 13),
    PE14 = GPIO_ENUM_PIN(Port::E, 14),
    PE15 = GPIO_ENUM_PIN(Port::E, 15),
    
#if defined(STM32F1)
    I2C1_SCL = PB6,
    I2C1_SDA = PB7,
    I2C2_SCL = PB10,
    I2C2_SDA = PB11,
#elif defined(STM32F4)
    I2C1_SCL = PB6,
    I2C1_SDA = PB7,
    I2C2_SCL = PB10,
    I2C2_SDA = PB11,
    I2C3_SCL = PA8,
    I2C3_SDA = PC9,
#endif
  };

  enum class PullMode: uint8_t {
    NoPull = 0x00,
    PullUp = 0x01,
    PullDown = 0x02
  };

  enum class OutputMode: uint8_t {
    PushPull = 0x00,
    OpenDrain = 0x01,
  };

#if defined(STM32F1)
  enum class AFMode: uint8_t {
    I2C
  };

#elif defined(STM32F4)
  enum class PortMode: uint8_t {
    Input = 0x00,
    Output = 0x01,
    AlternateFunction = 0x02,
    Analog = 0x03
  };

  enum class AFMode: uint8_t {
    AF0 = 0x00,
    AF1 = 0x01,
    AF2 = 0x02,
    AF3 = 0x03,
    AF4 = 0x04,
    AF5 = 0x05,
    AF6 = 0x06,
    AF7 = 0x07,
    AF8 = 0x08,
    AF9 = 0x09,
    AF10 = 0x0a,
    AF11 = 0x0b,
    AF12 = 0x0c,
    AF13 = 0x0d,
    AF14 = 0x0e,
    AF15 = 0x0f,

    I2C = AF4
  };
#endif

  enum class OutputSpeed {
#if defined(STM32F1)
    Speed10mhz = 0x01,  // GPIO_MODE_OUTPUT_10_MHZ
    Speed2mhz = 0x02,   // GPIO_MODE_OUTPUT_2_MHZ
    Speed50mhz = 0x03   // GPIO_MODE_OUTPUT_2_MHZ
#elif defined(STM32F4)
    Speed2mhz = 0x00,   // GPIO_OSPEED_2MHZ
    Speed25mhz = 0x01,  // GPIO_OSPEED_25MHZ
    Speed50mhz = 0x02,
    Speed100mhz = 0x03
#endif
  };

  enum class EXTITrigger {
    Rising,
    Falling,
    Both,
  };

  class GPIO {
  public:
    GPIO(Pin pin);
    GPIO(Pin pin, PullMode pullMode);
    GPIO(Pin pin, OutputMode outputMode, PullMode pullMode, OutputSpeed speed);
    GPIO(Pin pin, AFMode afMode, OutputMode outputMode, PullMode pullMode, OutputSpeed speed);

    void setInput(PullMode pullMode);
    void setOutput(OutputMode outputMode, PullMode pullMode, OutputSpeed speed);
    void setAlternateFunction(AFMode afMode, OutputMode outputMode, PullMode pullMode, OutputSpeed speed);

    void clear();
    void set();
    void toggle();

    void setEXTI_IRQ(EXTITrigger trigger, uint8_t nvic);
    void clearEXTIPendingBit();
  private:
    uint32_t m_port;
    uint16_t m_pin;
  };
}


#endif //STM32CPP_GPIO_H
