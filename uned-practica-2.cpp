/*
 * Rombos concéntricos
 * Práctica nº 2 de la asignatura "Introducción a la programación" de la UNED.
 *
 * MIT License
 * Copyright (c) 2020 Salva Ruiz http://salvaruiz.me
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <stdio.h>

char get_character(const int position) {
	char car;

	switch(position) {
		case 0:
			car = '@';
			break;
		case 1:
		case 3:
			car = '.';
			break;
		case 2:
			car = 'o';
			break;
	}

	return car;
}

void print_line(const int line, const int width) {
	int position = 0;

	for (int blank = 0; blank < width - line - 1; blank++) {
		printf(" ");
	}

	for (int column = width - line; column < width; column++) {
		printf("%c", get_character(position));

		if (position == 3) {
			position = 0;
		} else {
			position++;
		}
	}

	for (int column = width - line; column < width; column++) {
		printf("%c", get_character(position));

		if (position == 0) {
			position = 3;
		} else {
			position--;
		}
	}

	printf("@\n");
}

int main() {
	int width;

	printf("Rhombus side size? ");
	scanf("%d", &width);

	if (width > 0 && width <= 20) {
		printf("\n");

		for (int line = 0; line < width; line++) {
			print_line(line, width);
		}

		for (int line = 2; line < width + 1; line++) {
			print_line(width - line, width);
		}
	}
}

