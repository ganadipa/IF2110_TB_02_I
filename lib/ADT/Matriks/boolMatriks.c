#include <stdio.h>
#include "boolMatriks.h"

void createMatrix_BoolMatriks(int nRows, int nCols, BoolMatrix *m)
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */
{
    COL_EFF_BoolMatriks(*m) = nCols;
    ROW_EFF_BoolMatriks(*m) = nRows;
}

boolean isMatrixIdxValid_BoolMatriks(int i, int j)
/* Mengirimkan true jika i, j adalah index yang valid untuk matriks apa pun */
{
    return (i >= 0 && i < ROW_CAP_BoolMatriks && j >= 0 && j < COL_CAP_BoolMatriks);
}

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
int getLastIdxRowMatrix_BoolMatriks(BoolMatrix m)
/* Mengirimkan Index baris terbesar m */
{
    return (ROW_EFF_BoolMatriks(m)-1);
}
int getLastIdxColMatrix_BoolMatriks(BoolMatrix m)
/* Mengirimkan Index kolom terbesar m */
{
    return (COL_EFF_BoolMatriks(m)-1);
}
boolean isIdxEffMatrix_BoolMatriks(BoolMatrix m, int i, int j)
/* Mengirimkan true jika i, j adalah Index efektif bagi m */
{
    return (i >= 0 && i < ROW_EFF_BoolMatriks(m) && j >= 0 && j < COL_EFF_BoolMatriks(m));
}
int getElmtDiagonalMatrix_BoolMatriks(BoolMatrix m, int i)
/* Mengirimkan elemen m(i,i) */
{
    return ELMT_BoolMatriks(m, i, i);
}

/* ********** Assignment  Matrix ********** */
void copyMatrix_BoolMatriks(BoolMatrix mIn, BoolMatrix *mOut)
/* Melakukan assignment mOut <- mIn */
{
    createMatrix_BoolMatriks(ROW_EFF_BoolMatriks(mIn), COL_EFF_BoolMatriks(mIn), mOut);
    int i, j;
    for (i = 0; i < ROW_EFF_BoolMatriks(mIn); i++){
        for (j = 0; j < COL_EFF_BoolMatriks(mIn); j++){
            ELMT_BoolMatriks(*mOut, i, j) = ELMT_BoolMatriks(mIn, i, j);
        }
    }
}

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix_BoolMatriks(BoolMatrix *m, int nRow, int nCol)
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
a b c
d e f
g h i
*/
{
    createMatrix_BoolMatriks(nRow, nCol, m);
    int i, j;
    for (i = 0; i < ROW_EFF_BoolMatriks(*m); i++){
        for (j = 0; j < COL_EFF_BoolMatriks(*m); j++){
            scanf("%c", &ELMT_BoolMatriks(*m, i, j));
        }
    }
}

void displayMatrix_BoolMatriks(BoolMatrix m)
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan newline */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
a b c 
d e f
g h i
*/
{
    int i, j;
    for (i = 0; i < ROW_EFF_BoolMatriks(m); i++){
        for (j = 0; j < COL_EFF_BoolMatriks(m); j++){
            printf("%c", ELMT_BoolMatriks(m, i, j));
            if (j!=COL_EFF_BoolMatriks(m)-1)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isMatrixEqual_BoolMatriks(BoolMatrix m1, BoolMatrix m2)
/* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
/* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
/* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */
{
    if (ROW_EFF_BoolMatriks(m1)!=ROW_EFF_BoolMatriks(m2) || COL_EFF_BoolMatriks(m1)!=COL_EFF_BoolMatriks(m2)){
        return false;
    }
    int i, j;
    for (i = 0; i < ROW_EFF_BoolMatriks(m1);i++){
        for (j = 0; j< COL_EFF_BoolMatriks(m1); j++){
            if (ELMT_BoolMatriks(m1, i,j) != ELMT_BoolMatriks(m2, i,j)){
                return false;
            } 
        }
    }
    return true;
}
boolean isMatrixNotEqual_BoolMatriks(BoolMatrix m1, BoolMatrix m2)
/* Mengirimkan true jika m1 tidak sama dengan m2 */
{
    return !isMatrixEqual_BoolMatriks(m1, m2);
}
boolean isMatrixSizeEqual_BoolMatriks(BoolMatrix m1, BoolMatrix m2)
/* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */
/* yaitu RowEff(m1) = RowEff (m2) dan ColEff (m1) = ColEff (m2) */
{
    return (ROW_EFF_BoolMatriks(m1) == ROW_EFF_BoolMatriks(m2) && COL_EFF_BoolMatriks(m1) == COL_EFF_BoolMatriks(m2));
}

/* ********** Operasi lain ********** */
int countElmtMatrix_BoolMatriks(BoolMatrix m)
/* Mengirimkan banyaknya elemen m */
{
    return (ROW_EFF_BoolMatriks(m) * COL_EFF_BoolMatriks(m));
}
