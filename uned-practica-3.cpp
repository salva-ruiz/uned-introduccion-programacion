/*
 * Calendario perpétuo.
 * Práctica nº 3 de la asignatura "Introducción a la programación" de la UNED.
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
#include <stdlib.h>
#include <math.h>

int days_in_a_month(const int year, const int month) {
	int days;

	if (month == 2) {
		if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
			days = 29;
		} else {
			days = 28;
		}
	} else {
		switch(month) {
			case 4:
			case 6:
			case 9:
			case 11:
				days = 30;
				break;
			default:
				days = 31;
		}
	}

	return days;
}

int first_day_of_month(int year, int month) {
	int century;
	int day;

	if (month == 1 || month == 2) {
		month = month + 12;
		year--;
	}

	century = year / 100;
	year = year % 100;
	day = (13 * (month - 2) - 1) / 5+ year / 4 + century / 4 + 1
		+ year - 2 * century;

	if (day < 0) {
		day = day + 7 * ceil(abs(day) / 7.0);
	}

	day = day % 7;

	if (day == 0) {
		day = 6;
	} else {
		day--;
	}

	return day;
}

void print_separator(const int column) {
	switch(column) {
		case 4:
			printf(" | ");
			break;
		case 6:
			printf("\n");
			break;
		default:
			printf("  ");
	}
}

void print_month(const int year, const int month) {
	const int first_day = first_day_of_month(year, month);
	const int last_day  = days_in_a_month(year, month);
	int column = 0;

	switch(month) {
		case  1: printf("ENERO     "); break;
		case  2: printf("FEBRERO   "); break;
		case  3: printf("MARZO     "); break;
		case  4: printf("ABRIL     "); break;
		case  5: printf("MAYO      "); break;
		case  6: printf("JUNIO     "); break;
		case  7: printf("JULIO     "); break;
		case  8: printf("AGOSTO    "); break;
		case  9: printf("SEPTIEMBRE"); break;
		case 10: printf("OCTUBRE   "); break;
		case 11: printf("NOVIEMBRE "); break;
		case 12: printf("DICIEMBRE "); break;
	}

	printf("             %d\n", year);
	printf("===========================\n");
	printf("LU  MA  MI  JU  VI | SA  DO\n");
	printf("===========================\n");

	for (int day = 0; day < first_day; day++) {
		printf(" .");
		print_separator(column);
		column++;
	}

	for (int day = 1; day <= last_day; day++) {
		printf("%2d", day);
		print_separator(column);
		column++;
		if (column > 6) {
			column = 0;
		}
	}

	if (column > 0) {
		for (int day = column; day < 7; day++) {
			printf(" .");
			print_separator(column);
			column++;
		}
	}
}

int main() {
	int year;
	int month;

	printf("Month (1..12)? ");
	scanf("%d", &month);
	printf("Year (1601..3000)? ");
	scanf("%d", &year);

	if (year >= 1601 && year <= 3000 && month >= 1 && month <= 12) {
		printf("\n");
		print_month(year, month);
	}
}
