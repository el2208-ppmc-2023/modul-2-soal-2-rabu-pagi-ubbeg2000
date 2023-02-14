/** EL2208 Praktikum Pemecahan Masalah dengan C 2022/2023
 *   Modul               : 
 *   Hari dan Tanggal    :
 *   Nama (NIM)          :
 *   Nama File           : main.c
 *   Deskripsi           :
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readFile(FILE *fp) {
    float x = 0;
    float y = 0;
    char command[20], temp[20], validate[6];  
    float value;
    char prevCommand[20] = "";

    while (fscanf(fp, "%s", temp) != EOF) {
        sscanf(temp, "%[^,],%[^,],%f", validate, command, &value);
        if (strcmp(validate, "gukguk") == 0) {
            if (strcmp(command, "move") == 0) {
            y += value;
            }
            else if (strcmp(command, "moverl") == 0) {
                x += value;
                strcpy(prevCommand, "moverl");//checking untuk obstacle ketika command sebelumnya moverl
            }
            else if (strcmp(command, "obstacle") == 0) {
                if (strcmp(prevCommand, "moverl") == 0) {
                    y += 1;
                    x += 1;
                    y -= 1;
                } else { // masuk kondisi else ketika moverl tidak command sebelumnya
                    x += 1;
                    y += 1;
                    x -= 1;
                }
            }
            else if (strcmp(command, "stop") == 0) {
                printf("Posisi akhir: (%0.2f, %0.2f)\n", x, y);
                break;
            }
        } else {
            continue;
        }
        
    }
}

int main() {
    FILE *fp;
    char namaFile[128];

    printf("Masukkan nama file: ");
    scanf("%s",namaFile);

    fp = fopen(namaFile, "r");

    if (fp == NULL) {
        printf("File tidak ditemukan! \n");
        return 1;
    }
    readFile(fp);
    fclose(fp);
    return 0;
}
