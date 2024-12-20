#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

// Program Manajemen Pesanan Restoran
// Kelompok 2, Beranggotakan:
// ACHMAD FATHONI (23081010017)
// LOVINA PUTRI PRATAMA (23081010018)
// RIKY HERMAWAN (23081010021)
// ACHMAD ZAKI AL AKBAR (23081010022)
// FADHIL DJIBRAN (23081010030)
// Evaluasi Akhir Semester
// Struktur Data F081

//========================================================

// Deklarasi Struct

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

//========================================================

// Deklarasi Variabel Global

int jam = 7; // Restoran mulai dari Jam 07.00
int menit = 0;
int pesananCounter = 1; 

//========================================================

// Deklarasi Judul Fungsi

void updateWaktu(int durasi);
void printWaktu();
void enqueue(Queue* queue, char* makanan, char* minuman, char* pemesan, int kasirId, int trayId);
Pesanan* dequeue(Queue* queue);
void push(Stack** stack, int trayId);
int pop(Stack** stack);
Kasir* createKasir();
void printShiftKasir(Kasir* head, Kasir* kasirAktif);

//========================================================

// Fungsi Main

int main() {
    Queue pesananQueue = {NULL, NULL, 0}; 
    Queue pesananDisajikanQueue = { NULL, NULL, 0 };
    Stack* piringStack = NULL;
    Kasir* shiftKasir = createKasir(); 
    Kasir* kasirAktif = shiftKasir;

    for (int i = 10; i >= 1; i--) {
        push(&piringStack, i);
    }
    
    system("cls");
    printf("      )  (\n");
    printf("     (   ) )\n");
    printf("      ) ( (\n");
    printf("    _______)_      Program Manajemen Pesanan Restoran\n");
    printf(" .-'---------|     EAS Struktur Data F081 Kelompok 2, Beranggotakan:\n");
    printf("( C|/\\/\\/\\/\\/|     Achmad Fathoni, Lovina Putri Pratama, Riky Hermawan, Achmad Zaki Al Akbar, Fadhil Djibran\n");
    printf(" '-./\\/\\/\\/\\/|\n");
    printf("   '_________'\n");
    printf("    '-------'\n");
    printf("\nTekan tombol apa saja untuk melanjutkan...");
    getch();

    int pilihan;
    do {
        system("cls");
        printf("Program Manajemen Pesanan Restoran\n");
        printf("EAS Struktur Data F081 Kelompok 2\n");
        printf("Restoran buka jam 07.00 - 12.00\n");
        printWaktu();
        printf("Kasir Aktif: %s\n", kasirAktif->nama);
        printf("Menu:\n");
        printf("1. Tambah Pesanan ke Antrian\n");
        printf("2. Sajikan Pesanan\n");
        printf("3. Selesaikan Pesanan\n");
        printf("4. Lihat Shift Kasir\n");
        printf("5. Cek Info Pesanan\n");
        printf("6. Cek Tray Pesanan\n");
        printf("7. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilihan);

        system("cls");
        switch (pilihan) {
            case 1: {
    			char makanan[50], minuman[50], pemesan[50];
    			int pilihan;
    			
    			do {
        		printf("Pilih Menu Makanan:\n");
        		printf("1. Ayam Goreng\n");
        		printf("2. Nasi Goreng\n");
        		printf("3. Rendang\n");
        		printf("4. Bakso\n");
        		printf("5. Soto Ayam\n");
        		printf("6. Input Nama Makanan Sendiri\n");
        		printf("Pilihan: ");
        		scanf("%d", &pilihan);

        		switch (pilihan) {
            		case 1:
                		strcpy(makanan, "Ayam Goreng");
               		 	break;
            		case 2:
                		strcpy(makanan, "Nasi Goreng");
                		break;
            		case 3:
                		strcpy(makanan, "Rendang");
                		break;
            		case 4:
                		strcpy(makanan, "Bakso");
                		break;
                	case 5:
                		strcpy(makanan, "Soto Ayam");
                		break;
                	case 6:
                		fflush(stdin);
                		printf("Masukkan Nama Makanan: ");
                		fgets(makanan, sizeof(makanan), stdin);
                		makanan[strcspn(makanan, "\n")] = '\0';
                		break;
            		default:
                		printf("Pilihan tidak valid. Silakan coba lagi.\n");
                		pilihan = 0;
						fflush(stdin);
                		break;
       				}
    			} while (pilihan == 0);

    			do {
        			printf("\nPilih Menu Minuman:\n");
        			printf("1. Es Teh\n");
        			printf("2. Kopi Hitam\n");
        			printf("3. Jus Jeruk\n");
        			printf("4. Es Campur\n");
        			printf("5. Soda\n");
        			printf("6. Input Nama Minuman Sendiri\n");
        			printf("Pilihan: ");
        			scanf("%d", &pilihan);

        			switch (pilihan) {
            			case 1:
                			strcpy(minuman, "Es Teh");
                			break;
            			case 2:
           			    	strcpy(minuman, "Kopi Hitam");
         			       	break;
         			   	case 3:
         			       	strcpy(minuman, "Jus Jeruk");
         			       	break;
       			     	case 4:
                			strcpy(minuman, "Es Campur");
                			break;
                		case 5:
                			strcpy(minuman, "Soda");
                			break;
                		case 6:
                			fflush(stdin);
                			printf("Masukkan Nama minuman: ");
                			fgets(minuman, sizeof(minuman), stdin);
                			minuman[strcspn(minuman, "\n")] = '\0'; 
                		break;
            	       default:
            	           printf("Pilihan tidak valid. Silakan coba lagi.\n");
            	           pilihan = 0;
            	           fflush(stdin);
            	           break;
        	       }
    	        } while (pilihan == 0);
 
    	    	fflush(stdin);
    	    	printf("\nMasukkan Nama Pemesan: ");
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

            case 2: {
    			if (pesananQueue.front) {
        			Pesanan* temp = pesananQueue.front;
        			printf("Pesanan di Antrian Terdepan:\n");
        			printf("ID: %d, Makanan: %s, Minuman: %s, Pemesan: %s, Tray: %d, Status: %s\n",
               			temp->id, temp->makanan, temp->minuman, temp->pemesan, temp->trayId, temp->status);
					printf("Apakah Anda ingin menyajikan pesanan ini? (y/n): ");
        			char pilihan;
       	 			scanf(" %c", &pilihan);

        			if (pilihan == 'y' || pilihan == 'Y') {
            			strcpy(temp->status, "Disajikan");
            			Pesanan* disajikan = dequeue(&pesananQueue); // Dequeue pesanan
					if (disajikan) {
						if (pesananDisajikanQueue.rear == NULL) {
                    		pesananDisajikanQueue.front = pesananDisajikanQueue.rear = disajikan;
                		} else {
                    		pesananDisajikanQueue.rear->next = disajikan;
                    		pesananDisajikanQueue.rear = disajikan;
               			}		
                		pesananDisajikanQueue.count++;
                		disajikan->next = NULL; // Pastikan pointer berikutnya NULL
            		}
            			system("cls");
            			printf("Pesanan ID %d telah disajikan.\n", temp->id);
            			getchar();
        			} else {
            			system("cls");
            			printf("Pesanan ID %d tidak disajikan.\n", temp->id);
            			getchar();
        			}
    			} else {
        			system("cls");
        			printf("Antrian kosong. Tidak ada pesanan yang dapat disajikan.\n");
    			}
    			break;
			}

			case 3: {
    			if (pesananDisajikanQueue.front) {
        			Pesanan* temp = pesananDisajikanQueue.front;
        			printf("Daftar Pesanan yang Dapat Diselesaikan:\n");
        			while (temp) {
            			printf("ID: %d, Makanan: %s, Minuman: %s, Pemesan: %s, Tray: %d, Status: %s\n",
                   			temp->id, temp->makanan, temp->minuman, temp->pemesan, temp->trayId, temp->status);
            			temp = temp->next;
        			}
        			printf("Masukkan ID pesanan yang ingin diselesaikan (0 untuk batal): ");
        			int idSelesaikan;
        			scanf("%d", &idSelesaikan);

        			if (idSelesaikan == 0) {
            			system("cls");
            			printf("Penyelesaian dibatalkan.\n");
            			getchar();
        			} else {
            			Pesanan* prev = NULL;
            			temp = pesananDisajikanQueue.front;
            			while (temp) {
                			if (temp->id == idSelesaikan) {
                    			if (prev) {
                        			prev->next = temp->next;
                    			} else {
                        			pesananDisajikanQueue.front = temp->next;
                    			}
                    			if (temp == pesananDisajikanQueue.rear) {
                        			pesananDisajikanQueue.rear = prev;
                    			}
                    			push(&piringStack, temp->trayId); 
                    			pesananDisajikanQueue.count--;
                   		 		system("cls");
                    			printf("Pesanan ID %d selesai dan tray ID %d dikembalikan ke stack.\n", temp->id, temp->trayId);
                    			free(temp);
                    			getchar();
                    			break;
                			}
                			prev = temp;
                			temp = temp->next;
            			}
            			if (!temp) {
                			system("cls");
                			printf("Pesanan dengan ID %d tidak ditemukan.\n", idSelesaikan);
                			getchar();
            			}
            		}
    			} else {
        			printf("Tidak ada pesanan yang siap diselesaikan.\n");
        			getchar();
    			}
    			break;
			}
			
            case 4: {
                printShiftKasir(shiftKasir, kasirAktif);
                getchar();
                break;
            }

            case 5: {
    			if (pesananQueue.front) {
        			Pesanan* temp = pesananQueue.front;
        			printf("Daftar Info Pesanan dalam Antrian (Total Pesanan: %d):\n", pesananQueue.count);
        			while (temp) {
           				printf("ID: %d, Makanan: %s, Minuman: %s, Pemesan: %s, Tray: %d, Status: %s\n",
                   			temp->id, temp->makanan, temp->minuman, temp->pemesan, temp->trayId, temp->status);
            			temp = temp->next;
        			}
    			} else {
        			printf("Tidak ada pesanan dalam antrian.\n");
    			}

    			printf("\n");

    			if (pesananDisajikanQueue.front) {
        			Pesanan* temp = pesananDisajikanQueue.front;
        			printf("Daftar Info Pesanan yang Sudah Disajikan (Total Pesanan: %d):\n", pesananDisajikanQueue.count);
        			while (temp) {
            			printf("ID: %d, Makanan: %s, Minuman: %s, Pemesan: %s, Tray: %d, Status: %s\n",
                    		temp->id, temp->makanan, temp->minuman, temp->pemesan, temp->trayId, temp->status);
            			temp = temp->next;
        			}
    			} else {
        			printf("Tidak ada pesanan yang sudah disajikan.\n");
    			}
    			getchar();
    			break;
			}

            case 6: {
                if (piringStack) {
                    printf("Daftar Tray Tersedia (Total Tray: %d):\n", piringStack->count);
                    Stack* temp = piringStack;
                    while (temp) {
                        printf("Tray ID: %d\n", temp->trayId);
                        temp = temp->next;
                    }
                } else {
                    printf("Tidak ada tray tersedia.\n");
                }
                getchar();
                break;
            }

            case 7:
                printf("Berhasil keluar dari program manajemen pesanan restoran.\n");
                getchar();
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
                fflush(stdin);
                break;
        }
        if (pilihan != 7) {
            printf("\nTekan tombol apa saja untuk melanjutkan...");
            getch();
        }
    } while (pilihan != 7);

    return 0;
}

// Deklarasi Isi Fungsi

//========================================================

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

//========================================================

void printWaktu() {
    printf("Waktu sekarang: %02d:%02d\n", jam, menit);
}

//========================================================

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

//========================================================

Pesanan* dequeue(Queue* queue) {
    if (queue->front == NULL) {
        return NULL;
    }
	
    Pesanan* temp = queue->front;
    queue->front = queue->front->next;
    queue->count--;  

    if (queue->front == NULL)
        queue->rear = NULL;

    return temp;
}

//========================================================

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

//========================================================

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

//========================================================

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

//========================================================

void printShiftKasir(Kasir* head, Kasir* kasirAktif) {
    Kasir* temp = head;
    if (temp == NULL) {
        printf("Tidak ada kasir.\n");
        return;
    }

    printf("Shift Kasir:\n");
    do {
    if (temp == kasirAktif) {
        printf("ID: %d, Nama: %s (Sedang Melayani)\n", temp->id, temp->nama);
    } else {
        printf("ID: %d, Nama: %s\n", temp->id, temp->nama);
    }
    temp = temp->next;
} while (temp != head);
}

//========================================================