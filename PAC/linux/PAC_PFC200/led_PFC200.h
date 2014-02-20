/// @file led_PFC200.h
/// @brief ������ �� ������������ ����������� � �� Linux PAC PFC200.
///
/// @author  ������ ������� ���������.
///
/// @par �������� �������� �������������:
/// @c DEBUG    - ���������� c ������� ���������� ���������� � �������.@n@n
///
/// @par ������� ������:
/// @$Rev: 220 $.\n
/// @$Author: id $.\n
/// @$Date:: 2011-02-15 16:58:56#$.

#ifndef LED_PFC200_H
#define LED_PFC200_H

#include "led.h"
//-----------------------------------------------------------------------------
/// @brief ������ � �������� ������������.

class led_PFC200 : public led
    {
public:

    led_PFC200();

    virtual ~led_PFC200();

    void on( LEDS_NAMES led, COLOUR led_color );

    void off( LEDS_NAMES led );
    };
//-----------------------------------------------------------------------------
#endif // LED_PFC200_H
