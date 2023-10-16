#include <util/delay.h>
#include<avr/io.h>
#include "lcd.h"
#include "keypad.h"
#include "common_macros.h"
#include "std_types.h"
int main() {
	int x[2];
	x[0] = 0;
	x[1] = 0;
	char op;
	uint8 s = 0;
	uint8 y = 0;
	LCD_init();
	LCD_displayString("Abdo ki cala");
	_delay_ms(300);
	LCD_clearScreen();

	LCD_displayString("simple calc");
	_delay_ms(300);
	LCD_clearScreen();
	uint8 temp = 0;
	while (1) {
		temp = KEYPAD_getPressedKey();
		if (temp >= 0 && temp < 10) {
			x[s] = x[s] * 10 + temp;
			LCD_intgerToString(temp);
			_delay_ms(300);

		} else {
			if (temp == '+' || temp == '*' || temp == '-' || temp == '/') {
				op = temp;
				LCD_displayCharacter(op);
				_delay_ms(300);
				s++;
			}
			if (temp == '=') {
				LCD_displayCharacter('=');
				switch (op) {
				case '+':

					LCD_moveCursor(1, 0);
					LCD_intgerToString(x[0] + x[1]);
					_delay_ms(300);

					break;

				case '-':
					LCD_moveCursor(1, 0);
					LCD_intgerToString(x[0] - x[1]);
					_delay_ms(300);

					break;

				case '*':
					LCD_moveCursor(1, 0);
					LCD_intgerToString(x[0] * x[1]);
					_delay_ms(300);

					break;

				case '/':
					LCD_moveCursor(1, 0);
					LCD_intgerToString(x[0] / x[1]);
					_delay_ms(300);
					break;

				}

			}
			if (temp == 'c') {
				LCD_clearScreen();
				x[0] = x[1] = s = 0;

			}
		}

//		else if (KEYPAD_getPressedKey() == 13) {
//			LCD_clearScreen();
//		}
//		for (unsigned char var = 0; var < 10; ++var) {
//
//			x[var] = KEYPAD_getPressedKey();
//			if ((x[var] == '+' || x[var] == '-' || x[var] == '*'
//					|| x[var] == '/')
//					&& (x[--var] == '+' || x[--var] == '-' || x[--var] == '*'
//							|| x[--var] == '/')) {
//				LCD_displayString("error");
//				LCD_clearScreen();
//			}
//
//		}
//		uint8 s = 0;
//		uint8 w = 0;
//		uint8 m;
//		uint8 d;
//		for (unsigned char var = 0; var < 10; ++var) {
//			if (x[var] == '*') {
//				m = var;
//				s = x[--m] * x[m++];
//				s = x[--m];
//				x[var] = x[++var];
//				x[++var] = x[var + 2];
//			} else if (x[var] == '/') {
//				d = var;
//				w = x[--d] / x[d++];
//				x[--d] = w;
//				x[var] = x[++var];
//				x[++var] = x[var + 2];
//			}
//
//		}
//		for (unsigned char var = 0; var < 10; ++var) {
//
//			switch (x[var]) {
//			case '+':
//				s = x[--var] + x[var++];
//				break;
//			case '-':
//				s = x[--var] - x[var++];
//				break;
//			}
//		}
//	}

	}

}
