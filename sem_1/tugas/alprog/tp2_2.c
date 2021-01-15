#include <stdio.h>

typedef struct Mahasiswa {
  int nim;
  char *nama[20];
  char *mata_kuliah[20];
} mahasiswa;

typedef struct NilaiMahasiswa {
  int hadir;
  int tugas;
  int quiz;
  int forum;
  int uas;
} nilaiMahasiswa;

void checkGrade (int nilai) {
  switch (nilai) {
  case 50 ... 59:
    printf("[E] Tidak Lulus %d \n", nilai);
    break;
  case 60 ... 69:
    printf("[D] Lulus %d \n", nilai);
    break;
  case 70 ... 79:
    printf("[C] Lulus %d \n", nilai);
    break;
  case 80 ... 89:
    printf("[B] Lulus %d \n", nilai);
    break;
  case 90 ... 100:
    printf("[A] Lulus %d \n", nilai);
  
  default:
    break;
  }
}

void menu1(mahasiswa* pData, int* pTotalData) {
  int total = *pTotalData;
  int nim;
  mahasiswa mhs[10];
  printf("====== INPUT MAHASISWA ======= \n");
  printf("WARNING: Harap menginputkan Nama dan Mata Kuliah dengan CamelCase. Contoh NandaErliana \n");
  printf("Masukkan NIM: "); scanf("%d", &nim);
  if (total == 0) {
    mhs[total].nim = nim;
    printf("Masukkan Nama: "); scanf("%255s", mhs[total].nama);
    printf("Masukkan Mata Kuliah: "); scanf("%255s", mhs[total].mata_kuliah);
    printf("\nSukses Menambahkan Mahasiswa\n");
    *pData = mhs[10];
    total++;
    *pTotalData = total;
  } else {
    for (int i = 0; i < total; i++) {
      if (mhs[i].nim != nim) {
        mhs[total].nim = nim;
        printf("Masukkan Nama: "); scanf("%255s", mhs[total].nama);
        printf("Masukkan Mata Kuliah: "); scanf("%255s", mhs[total].mata_kuliah);
        printf("\nSukses Menambahkan Mahasiswa\n");
        *pData = mhs[10];
        total++;
        *pTotalData = total;
      } else {
        printf("NIM yang anda masukkan sudah ada\n");
      }
    }
  }
}

void menu2(mahasiswa* pData, nilaiMahasiswa* pDataNilai, int* pTotalData) {
  int total = *pTotalData;
  mahasiswa mhs[10];
  nilaiMahasiswa nilai[10];
  mhs[10] = *pData;
  printf("====== INPUT NILAI MAHASISWA ======= \n");
  for (int i = 0; i < total; i++) {
    printf("NIM: %d \n", mhs[i].nim);
    printf("NAMA: %s \n", mhs[i].nama);
    printf("MATA KULIAH: %s \n", mhs[i].mata_kuliah);
    printf("Masukkan Nilai Hadir (0-100): "); scanf("%d", &nilai[i].hadir);
    printf("Masukkan Nilai Tugas (0-100): "); scanf("%d", &nilai[i].tugas);
    printf("Masukkan Nilai Quiz (0-100): "); scanf("%d", &nilai[i].quiz);
    printf("Masukkan Nilai Keaktifan Forum (0-100): "); scanf("%d", &nilai[i].forum);
    printf("Masukkan Nilai UAS (0-100): "); scanf("%d", &nilai[i].uas);
    printf("\n\n");
  }
  *pData = mhs[10];
  *pDataNilai = nilai[10];
  *pTotalData = total;

  printf("\nSukses Menambahkan Nilai\n");
}

void menu3(mahasiswa* pData, nilaiMahasiswa* pDataNilai, int* pTotalData) {
  int nim;
  int total = *pTotalData;
  mahasiswa mhs[10];
  nilaiMahasiswa nilai[10];
  mhs[10] = *pData;
  nilai[10] = *pDataNilai;
  printf("====== NILAI MAHASISWA ======= \n");
  printf("Masukkan NIM: "); scanf("%d", &nim);
  for (int i = 0; i < total; i++) {
    if (mhs[i].nim == nim) {
      printf("NIM: %d \n", mhs[i].nim);
      printf("NAMA: %s \n", mhs[i].nama);
      printf("MATA KULIAH: %s \n", mhs[i].mata_kuliah);
      int nilaiHadir, nilaiTugas, nilaiQuiz, nilaiForum, nilaiUas, kalkulasiNilai;
      nilaiHadir = nilai[i].hadir * 10 / 100;
      nilaiTugas = nilai[i].tugas * 20 / 100;
      nilaiQuiz = nilai[i].quiz * 10 / 100;
      nilaiForum = nilai[i].forum * 10 / 100;
      nilaiUas = nilai[i].uas * 50 / 100;
      kalkulasiNilai = nilaiHadir + nilaiTugas + nilaiQuiz + nilaiForum + nilaiUas;
      // printf("NILAI: %d", kalkulasiNilai);
      checkGrade(kalkulasiNilai);
      printf("\n\n");
    }
  }
  *pData = mhs[10];
  *pDataNilai = nilai[10];
  *pTotalData = total;

  printf("\nNILAI===========\n");
  
}

int main () {
  int menu;
  int totalData = 0;
  mahasiswa data[10];
  nilaiMahasiswa dataNilai[10];

  printf("========== PROGRAM MAHASISWA ABAL-ABAL ======== \n");
  do {
    printf("Menu Program: \n");
    printf("[1] ====> Input data mahasiswa (NIM, Nama, Mata Kuliah) \n");
    printf("[2] ====> Input nilai mahasiswa \n");
    printf("[3] ====> Melihat nilai mahasiswa dan status \n");
    printf("[4] ====> Keluar \n");

    printf("=========================================== \n");
    printf("Masukkan pilihan menu: "); scanf("%d", &menu);
    printf("\n\n");

    switch (menu) {
      case 1:
        menu1(&data[10], &totalData);
        break;
      case 2:
        menu2(&data[10], &dataNilai[10], &totalData);
        break;
      case 3:
        menu3(&data[10], &dataNilai[10], &totalData);
        break;
      
      default:
        break;
    }
  } while (menu != 4);

  return 0;
}
