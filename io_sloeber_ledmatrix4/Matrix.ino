/*******************************************************************************
 * Copyright (c) 2020 Wim Jongman and others
 * This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License 2.0
 * which accompanies this distribution, and is available at
 * https://www.eclipse.org/legal/epl-2.0/
 *
 * SPDX-License-Identifier: EPL-2.0
 *
 * Contributors:
 * - Wim Jongman (wim.jongman@remainsoftware.com)  - initial API and implementation
 *******************************************************************************/

#include "LedControl.h"

/*******************************************************************************
 * This is a 4 segment led matrix ATtiny example
 *******************************************************************************/

const int DIN_PIN = 1;
const int CS_PIN = 2;
const int CLK_PIN = 3;
const int DISPLAYS = 4;

LedControl ledControl = LedControl(DIN_PIN, CLK_PIN, CS_PIN, DISPLAYS);

unsigned long delayTime = 150;  // Delay between Frames

/*******************************************************************************
 * The alphabet in upper and lowercase
 *******************************************************************************/
const byte CA[] = {
B00000000,
B00111100,
B01100110,
B01100110,
B01111110,
B01100110,
B01100110,
B01100110 };

const byte CB[] = {
B00000000,
B01111100,
B01100110,
B01100110,
B01111100,
B01100110,
B01100110,
B01111100 };

const byte CC[] = {
B00000000,
B00111100,
B01100110,
B01100000,
B01100000,
B01100000,
B01100110,
B00111100 };

const byte CD[] = {
B00000000,
B01111100,
B01100110,
B01100110,
B01100110,
B01100110,
B01100110,
B01111100 };

const byte CE[] = {
B00000000,
B01111110,
B01100000,
B01100000,
B01111100,
B01100000,
B01100000,
B01111110 };

const byte CF[] = {
B00000000,
B01111110,
B01100000,
B01100000,
B01111100,
B01100000,
B01100000,
B01100000 };

const byte CG[] = {
B00000000,
B00111100,
B01100110,
B01100000,
B01100000,
B01101110,
B01100110,
B00111100 };

const byte CH[] = {
B00000000,
B01100110,
B01100110,
B01100110,
B01111110,
B01100110,
B01100110,
B01100110 };

const byte CI[] = {
B00000000,
B00111100,
B00011000,
B00011000,
B00011000,
B00011000,
B00011000,
B00111100 };

const byte CJ[] = {
B00000000,
B00011110,
B00001100,
B00001100,
B00001100,
B01101100,
B01101100,
B00111000 };

const byte CK[] = {
B00000000,
B01100110,
B01101100,
B01111000,
B01110000,
B01111000,
B01101100,
B01100110 };

const byte CL[] = {
B00000000,
B01100000,
B01100000,
B01100000,
B01100000,
B01100000,
B01100000,
B01111110 };

const byte CM[] = {
B00000000,
B01100011,
B01110111,
B01111111,
B01101011,
B01100011,
B01100011,
B01100011 };

const byte CN[] = {
B00000000,
B01100011,
B01110011,
B01111011,
B01101111,
B01100111,
B01100011,
B01100011 };

const byte CO[] = {
B00000000,
B00111100,
B01100110,
B01100110,
B01100110,
B01100110,
B01100110,
B00111100 };

const byte CP[] = {
B00000000,
B01111100,
B01100110,
B01100110,
B01100110,
B01111100,
B01100000,
B01100000 };

const byte CQ[] = {
B00000000,
B00111100,
B01100110,
B01100110,
B01100110,
B01101110,
B00111100,
B00000110 };

const byte CR[] = {
B00000000,
B01111100,
B01100110,
B01100110,
B01111100,
B01111000,
B01101100,
B01100110 };

const byte CS[] = {
B00000000,
B00111100,
B01100110,
B01100000,
B00111100,
B00000110,
B01100110,
B00111100 };

const byte CT[] = {
B00000000,
B01111110,
B01011010,
B00011000,
B00011000,
B00011000,
B00011000,
B00011000 };

const byte CU[] = {
B00000000,
B01100110,
B01100110,
B01100110,
B01100110,
B01100110,
B01100110,
B00111110 };

const byte CV[] = {
B00000000,
B01100110,
B01100110,
B01100110,
B01100110,
B01100110,
B00111100,
B00011000 };

const byte CW[] = {
B00000000,
B01100011,
B01100011,
B01100011,
B01101011,
B01111111,
B01110111,
B01100011 };

const byte CX[] = {
B00000000,
B01100011,
B01100011,
B00110110,
B00011100,
B00110110,
B01100011,
B01100011 };

const byte CY[] = {
B00000000,
B01100110,
B01100110,
B01100110,
B00111100,
B00011000,
B00011000,
B00011000 };

const byte CZ[] = {
B00000000,
B01111110,
B00000110,
B00001100,
B00011000,
B00110000,
B01100000,
B01111110 };

const byte SPC[] = {
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000 };

const byte LA[] = {
B00000000,
B00000000,
B00000000,
B00111100,
B00000110,
B00111110,
B01100110,
B00111110 };

const byte LB[] = {
B00000000,
B01100000,
B01100000,
B01100000,
B01111100,
B01100110,
B01100110,
B01111100 };

const byte LC[] = {
B00000000,
B00000000,
B00000000,
B00111100,
B01100110,
B01100000,
B01100110,
B00111100 };

const byte LD[] = {
B00000000,
B00000110,
B00000110,
B00000110,
B00111110,
B01100110,
B01100110,
B00111110 };

const byte LE[] = {
B00000000,
B00000000,
B00000000,
B00111100,
B01100110,
B01111110,
B01100000,
B00111100 };

const byte LF[] = {
B00000000,
B00011100,
B00110110,
B00110000,
B00110000,
B01111100,
B00110000,
B00110000 };

const byte LG[] = {
B00000000,
B00000000,
B00111110,
B01100110,
B01100110,
B00111110,
B00000110,
B00111100 };

const byte LH[] = {
B00000000,
B01100000,
B01100000,
B01100000,
B01111100,
B01100110,
B01100110,
B01100110 };

const byte LI[] = {
B00000000,
B00000000,
B00011000,
B00000000,
B00011000,
B00011000,
B00011000,
B00111100 };

const byte LJ[] = {
B00000000,
B00001100,
B00000000,
B00001100,
B00001100,
B01101100,
B01101100,
B00111000 };

const byte LK[] = {
B00000000,
B01100000,
B01100000,
B01100110,
B01101100,
B01111000,
B01101100,
B01100110 };

const byte LL[] = {
B00000000,
B00011000,
B00011000,
B00011000,
B00011000,
B00011000,
B00011000,
B00011000 };

const byte LM[] = {
B00000000,
B00000000,
B00000000,
B01100011,
B01110111,
B01111111,
B01101011,
B01101011 };

const byte LN[] = {
B00000000,
B00000000,
B00000000,
B01111100,
B01111110,
B01100110,
B01100110,
B01100110 };

const byte LO[] = {
B00000000,
B00000000,
B00000000,
B00111100,
B01100110,
B01100110,
B01100110,
B00111100 };

const byte LP[] = {
B00000000,
B00000000,
B01111100,
B01100110,
B01100110,
B01111100,
B01100000,
B01100000 };

const byte LQ[] = {
B00000000,
B00000000,
B00111100,
B01101100,
B01101100,
B00111100,
B00001101,
B00001111 };

const byte LR[] = {
B00000000,
B00000000,
B00000000,
B01111100,
B01100110,
B01100110,
B01100000,
B01100000 };

const byte LS[] = {
B00000000,
B00000000,
B00000000,
B00111110,
B01000000,
B00111100,
B00000010,
B01111100 };

const byte LT[] = {
B00000000,
B00000000,
B00011000,
B00011000,
B01111110,
B00011000,
B00011000,
B00011000 };

const byte LU[] = {
B00000000,
B00000000,
B00000000,
B01100110,
B01100110,
B01100110,
B01100110,
B00111110 };

const byte LV[] = {
B00000000,
B00000000,
B00000000,
B00000000,
B01100110,
B01100110,
B00111100,
B00011000 };

const byte LW[] = {
B00000000,
B00000000,
B00000000,
B01100011,
B01101011,
B01101011,
B01101011,
B00111110 };

const byte LX[] = {
B00000000,
B00000000,
B00000000,
B01100110,
B00111100,
B00011000,
B00111100,
B01100110 };

const byte LY[] = {
B00000000,
B00000000,
B00000000,
B01100110,
B01100110,
B00111110,
B00000110,
B00111100 };

const byte LZ[] = {
B00000000,
B00000000,
B00000000,
B00111100,
B00001100,
B00011000,
B00110000,
B00111100 };


// Initialise the matrices
void setup() {
	for (int d = 0; d < DISPLAYS; d++) {
		ledControl.shutdown(d, false);
	}
	for (int d = 0; d < DISPLAYS; d++) {
		ledControl.setIntensity(d, 1);
	}
	for (int d = 0; d < DISPLAYS; d++) {
		ledControl.clearDisplay(d);
	}
}

void loop() {
	printName(CH,LE,LL,LO); // Helo
	printName(CS,CL,CB,CR); // SLBR
}

void printName(const byte *l1, const byte *l2, const byte *l3, const byte *l4){
	displayImage(3, l1);
	delay(500);

	displayImage(2, l2);
	delay(500);

	displayImage(1, l3);
	delay(500);

	displayImage(0, l4);
	delay(500);

	ledControl.clearDisplay(3);
	delay(100);
	ledControl.clearDisplay(2);
	delay(100);
	ledControl.clearDisplay(1);
	delay(100);
	ledControl.clearDisplay(0);
	delay(100);

}

// Displays the image on the matrix.
void displayImage(int pDsp, const byte *pImg) {
	for (int i = 0; i < 8; i++) {
		ledControl.setColumn(pDsp, i, flip(pImg[i]));
	}
}

// Flips the image.
byte flip(byte v){
	unsigned int r = v; // r will be reversed bits of v; first get LSB of v
	int s = sizeof(v) * 8 - 1; // extra shift needed at end

	for (v >>= 1; v; v >>= 1)
	{
	  r <<= 1;
	  r |= v & 1;
	  s--;
	}
	r <<= s; // shift when v's highest bits are zero
	return r;
}
