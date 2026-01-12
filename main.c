#include <stdio.h>

// Faruk TOY
// 2420171018
// https://www.btkakademi.gov.tr/portal/certificate/validate?certificateId=BozfxvKaB1

// kucukten -> buyuge araya eklemeli siralama + ikili arama
// Aciklama: Dizi artan siraya getirilir; girilen deger ikili arama ile bulunur.


// index kisaltmasi olarak literaturde IDX kullanilir
void dizi_yazdir(int dizi[], int basIDX, int sonIDX) {
	int i;
	for (i = basIDX; i <= sonIDX; i++) {
		printf("%2d ", dizi[i]);
	}
	printf("\n");
}

// Araya eklemeli siralama (kucukten -> buyuge)
//   Parametreler:
//     dizi     -> arama yapilacak dizi (ham)
//     BOYUT    -> eleman sayisi
// Not: O(n^2) zamanda calisir.
void arayaeklemeli_siralamaKB(int dizi[], int BOYUT) {
	int i, j;
	int anahtar;

	for (i = 1; i < BOYUT; i++) {
		anahtar = dizi[i];

		for (j = i - 1; (j >= 0) && (anahtar < dizi[j]); j--) {
			dizi[j + 1] = dizi[j];    // saga kaydirma (index shift)
		}

		dizi[j + 1] = anahtar;

		printf("iter. %2d: ", i);
		dizi_yazdir(dizi, 0, BOYUT - 1);
	}
}


//   Ikili arama (binary search)
//   Parametreler:
//     dizi     -> arama yapilacak dizi (sirali)
//     BOYUT    -> eleman sayisi
//     search   -> aranan deger
//     ilk_ind  -> araligin baslangic indisi
//     son_ind  -> araligin bitis indisi
//   Donus: bulunduysa indis, bulunamadiysa -1
//   Not: O(log n) zamanda calisir.
int ikili_arama(int dizi[], int BOYUT, int search, int ilk_ind, int son_ind) {
	int orta_ind = (ilk_ind + son_ind) / 2;

	// aradigimiz eleman dizinin orta indisli elemanina esit ise
	if (search == dizi[orta_ind]) {
		return orta_ind;
	}
	// tek eleman kaldi ve esit degilse: bulunamadi
	else if ((son_ind - ilk_ind) == 0) {
		return -1;
	}
	// aradigimiz eleman dizinin orta indisli elemanindan buyuk ise
	else if (search > dizi[orta_ind] && (son_ind - ilk_ind) > 0) {
		return ikili_arama(dizi, BOYUT, search, orta_ind + 1, son_ind);
	}
	// aradigimiz eleman dizinin orta indisli elemanindan kucuk ise
	else if (search < dizi[orta_ind] && (son_ind - ilk_ind) > 0) {
		return ikili_arama(dizi, BOYUT, search, ilk_ind, orta_ind - 1);
	}
    else {
    	return -1;  // aradigimiz eleman yok
    }
}

int main() {
	int A[] = {55, 12, 17, 4, 90, 21, 34, 63, 18};
	int N = sizeof(A) / sizeof(A[0]);

	int aranan, sonuc;

	printf("Orjinal dizi : ");
	dizi_yazdir(A, 0, N - 1);

	arayaeklemeli_siralamaKB(A, N);

	printf("Siralanmis dizi: ");
	dizi_yazdir(A, 0, N - 1);

	printf("Aramak istenen sayi: ");
	scanf("%d", &aranan);

	// ikili_arama(dizi adi, eleman sayisi, aranan eleman, ilk indis, son indis)
	sonuc = ikili_arama(A, N, aranan, 0, N - 1);

	if (sonuc == -1) {
		printf("Aradiginiz deger %d, dizide bulunamadi!\n", aranan);
	}
	else {
		printf("Aradiginiz deger %d, dizinin %d. indisinde bulundu!\n", aranan, sonuc);
	}

	return 0;
}