/*******************************************************************************
 * Copyright (c) 2020 Wim Jongman and others
 *
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

/**
 * This sketch reads the analog value on the input pin and then
 * communicates the value through fResolution bits binary flashing of the leds on the
 * fOutputTrue and fOutputFalse ports. fResolution is usually 10 bits.
 *
 * You can use it to calculate the upper and lower values of an analog input device like
 * a potentiometer or photo resistor.
 *
 * Example:
 *
 * value of analog read is 69 which is 0001000101 in fResolution (10) bits binary
 *
 * First we get 5 flashes indicating that we start a new sequence:
 *
 * 0 - True led is off False led is on for fShowResultsDelay ms then a 150 ms all leds off
 * 0 - True led is off False led is on for fShowResultsDelay ms then a 150 ms all leds off
 * 0 - True led is off False led is on for fShowResultsDelay ms then a 150 ms all leds off
 * 1 - True led is on False led is off for fShowResultsDelay ms then a 150 ms all leds off
 * 0 - True led is off False led is on for fShowResultsDelay ms then a 150 ms all leds off
 * 0 - True led is off False led is on for fShowResultsDelay ms then a 150 ms all leds off
 * 0 - True led is off False led is on for fShowResultsDelay ms then a 150 ms all leds off
 * 1 - True led is on False led is off for fShowResultsDelay ms then a 150 ms all leds off
 * 0 - True led is off False led is on for fShowResultsDelay ms then a 150 ms all leds off
 * 1 - True led is on False led is off for fShowResultsDelay ms then a 150 ms all leds off
 *
 * Write down the bits and then calculate the decimal value.
 *
 */

int fOutputTrue = 0;
int fOutputFalse = 1;
int fShowResultsDelay = 600;
int fInput = 3;
int fResolution = 10; // 10 bits: 0 to 1023

void setup() {
	pinMode(fOutputTrue, OUTPUT);
	pinMode(fOutputFalse, OUTPUT);
	pinMode(fInput, INPUT);
	test();
}

/**
 * Test 5 bits off 5 bits on
 */
void test(){
	newSequence();
	signal(0, 5);
	delay(100);
	newSequence();
	signal(1023, 5);
	delay(100);
}

void loop() {
	newSequence();
	delay(1000);
	signal(analogRead(fInput), fResolution);
}

/**
 * Flash the leds 3 times to indicate a new sequence.
 */
void newSequence() {
	for (int i = 0; i < 3; i++) {
		delay(100);
		digitalWrite(fOutputFalse, HIGH);
		digitalWrite(fOutputTrue, HIGH);
		delay(100);
		digitalWrite(fOutputFalse, LOW);
		digitalWrite(fOutputTrue, LOW);
	}
}

/**
 * Signals the passed "pValue" as "pResolution" bit binary through the True and False pins, MSB first.
 */
void signal(int pValue, int pResolution) {
	int mask =  power(2, pResolution-1);

	for (int i = 0; i < pResolution; i++) {
		if ((pValue & mask) == 0) {
			digitalWrite(fOutputTrue, LOW);
			digitalWrite(fOutputFalse, HIGH);
		} else {
			digitalWrite(fOutputTrue, HIGH);
			digitalWrite(fOutputFalse, LOW);
		}
		showResultsDelay();
		mask = mask / 2;
	}
}

int power(int pBase, int pExponent){
	int result = 1;
	for(int i = 0; i< pExponent; i++){
		result = result * pBase;
	}
	return result;
}

/**
 * Shows the results for fShowResultsDelay ms then turns the leds off and waits another 150ms.
 */
void showResultsDelay() {
	delay(fShowResultsDelay);
	digitalWrite(fOutputTrue, LOW);
	digitalWrite(fOutputFalse, LOW);
	delay(150);
}
