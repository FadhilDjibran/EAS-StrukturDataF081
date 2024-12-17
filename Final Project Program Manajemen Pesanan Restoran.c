#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct Pesanan {
    int id;
    char makanan[50];
    char minuman[50];
    char pemesan[50];
    int kasirId;
    int trayId;
    char status[20]; 
    struct Pesanan* next;
} Pesanan;

typedef struct Queue {
    Pesanan* front;
    Pesanan* rear;
    int count;  
} Queue;

typedef struct Stack {
    int trayId;
    struct Stack* next;
    int count;  
} Stack;

typedef struct Kasir {
    int id;
    char nama[50];
    struct Kasir* next;
} Kasir;

Kasir* createKasir() {
    const char* namaKasir[] = {"Fadhil", "Antony", "Riky", "Achmad Zaki", "Lovina"};
    int jumlahKasir = sizeof(namaKasir) / sizeof(namaKasir[0]);

    Kasir* head = NULL;
    Kasir* prev = NULL;

    for (int i = 0; i < jumlahKasir; i++) {
        Kasir* newKasir = (Kasir*)malloc(sizeof(Kasir));
        newKasir->id = i + 1;
        strcpy(newKasir->nama, namaKasir[i]);
        newKasir->next = NULL;

        if (head == NULL) {
            head = newKasir;
            prev = newKasir;
        } else {
            prev->next = newKasir;
            prev = newKasir;
        }
    }

    prev->next = head;
    return head;
}

void push(Stack** stack, int trayId) {
    Stack* newStack = (Stack*)malloc(sizeof(Stack));
    newStack->trayId = trayId;
    newStack->next = *stack;
    
    if (*stack == NULL) {
        newStack->count = 1;  
    } else {
        newStack->count = (*stack)->count + 1;  
    }
    
    *stack = newStack;
    printf("Tray nomor %d ditambahkan ke stack. Total tray: %d\n", trayId, newStack->count);
}

int pop(Stack** stack) {
    if (*stack == NULL) {
        printf("Stack kosong.\n");
        return -1;
    }

    int trayId = (*stack)->trayId;
    Stack* temp = *stack;
    *stack = (*stack)->next;

    if (*stack) {
    	if (temp->count > 1) {
        	(*stack)->count = temp->count - 1;
    	} else {
        	(*stack)->count = 0;
    	}
	}
    
    free(temp);
    return trayId;
}

int main() {
    Queue pesananQueue = {NULL, NULL, 0};  
    Stack* piringStack = NULL;
    Kasir* shiftKasir = createKasir(); 
    Kasir* kasirAktif = shiftKasir;

    for (int i = 10; i >= 1; i--) {
        push(&piringStack, i);
    }

    int pilihan;
    do {
        system("cls");
        printf("Program Manajemen Pesanan Restoran\n");
        printf("EAS Struktur Data F081 Kelompok 2\n");
        printf("Restoran buka jam 07.00 - 12.00\n");
        printf("Kasir Aktif: %s\n", kasirAktif->nama);
        printf("0. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilihan);
        
        system("cls");
        switch (pilihan) {
            case 0: {
            	    printf("Berhasil keluar dari program manajemen pesanan restoran.\n");
                getchar();
                break;
            }
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
                break;
    	}
    } while (pilihan != 0);

    return 0;
}
