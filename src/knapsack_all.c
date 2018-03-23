/*
 * knapsack_all.c
 *
 * Copyright 2018 Consuella Moore <cmoore4os@github.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 *
 */


#include <stdio.h>

int main(int argc, char **argv)
{
    int MAX_SIZE = 1000;
    int total_cost = 100;
    FILE *fp;
    int cost[MAX_SIZE];
    int value[MAX_SIZE];
    int line[64];

    if (argc == 1)
    {
        printf("Usage of knapsack: ./knapsack [filename] [optional: threshold]\n");
        exit(1);
    }

    if (argc == 2)
    {
        total_cost = 100;
        fp = fopen(argv[1], "r");
        if (fp == 0)
        {
            printf("open file failed\n");
            exit(1);
        }
        int line_count = 0;
        while (fgets(line, 64, fp) != NULL)
        {
            sscanf(line, "%*d %d %d", &cost[line_count], &value[line_count]);
            line_count++;
        }
        fclose(fp);
    }

	return 0;
}

