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