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

int jam = 7; 
int menit = 0;
int pesananCounter = 1; 

void updateWaktu(int durasi) {
    menit += durasi;
    if (menit >= 60) {
        menit -= 60;
        jam++;
    }
    if (jam >= 12 && menit > 0) {
        printf("Restoran sudah tutup!\n");
        getch();
        exit(0);
    }
}

void printWaktu() {
    printf("Waktu sekarang: %02d:%02d\n", jam, menit);
}

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

void enqueue(Queue* queue, char* makanan, char* minuman, char* pemesan, int kasirId, int trayId) {
    Pesanan* newPesanan = (Pesanan*)malloc(sizeof(Pesanan));
    newPesanan->id = pesananCounter++;
    strcpy(newPesanan->makanan, makanan);
    strcpy(newPesanan->minuman, minuman);
    strcpy(newPesanan->pemesan, pemesan);
    newPesanan->kasirId = kasirId;
    newPesanan->trayId = trayId;
    strcpy(newPesanan->status, "Dipesan");
    newPesanan->next = NULL;

    if (queue->rear == NULL) {
        queue->front = queue->rear = newPesanan;
        queue->count = 1;
    } else {
        queue->rear->next = newPesanan;
        queue->rear = newPesanan;
        queue->count++;
    }
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
        printWaktu();
        printf("Kasir Aktif: %s\n", kasirAktif->nama);
        printf("0. Keluar\n");
        printf("1. Tambah Pesanan ke Antrian\n");
        printf("Pilih: ");
        scanf("%d", &pilihan);
        
        system("cls");
        switch (pilihan) {
            case 0: {
            	    printf("Berhasil keluar dari program manajemen pesanan restoran.\n");
                getchar();
                break;
            }
            case 1: {
                char makanan[50], minuman[50], pemesan[50];
                fflush(stdin);
                printf("Masukkan Nama Makanan: ");
				fgets(makanan, sizeof(makanan), stdin);
				makanan[strcspn(makanan, "\n")] = '\0'; 

				printf("Masukkan Nama Minuman: ");
				fgets(minuman, sizeof(minuman), stdin);
				minuman[strcspn(minuman, "\n")] = '\0'; 

				printf("Masukkan Nama Pemesan: ");
				fgets(pemesan, sizeof(pemesan), stdin);
				pemesan[strcspn(pemesan, "\n")] = '\0'; 

                int trayId = pop(&piringStack);
                if (trayId == -1) {
                    printf("Tidak ada tray yang tersedia. Mohon untuk selesaikan pesanan sebelum melakukan pesanan lagi.\n");
                } else {
                    enqueue(&pesananQueue, makanan, minuman, pemesan, kasirAktif->id, trayId);
                    printf("Pesanan berhasil ditambahkan dengan tray ID %d oleh %s.\n", trayId, kasirAktif->nama);
                    updateWaktu(15);
                    if (menit == 0) kasirAktif = kasirAktif->next;
                }
                break;
            }
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
                break;
    	}
    	if (pilihan != 0) {
            printf("\nTekan tombol apa saja untuk melanjutkan...");
            getchar();
        }
    } while (pilihan != 0);

    return 0;
}
