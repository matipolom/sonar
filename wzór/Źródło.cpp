//POP 2019-1-21 projekt 2 Po³om Mateusz ACIR 3 180565 œrodowisko: Dev-C++ 5.11; kompilator: TDM-GCC 4.9.2 64-bit Release
#include <iostream>
#include <fstream>

using namespace std;

int funkcja_Rminus(int n) {
	if (n == 0) return 255;
	else return (funkcja_Rminus(n - 1) - 5);
}

int funkcja_Rplus(int n) {
	if (n == 153) return 0;
	else return (funkcja_Rplus(n - 1) + 5);
}

int funkcja_Gplus(int n) {
	if (n == 51) return 0;
	else return (funkcja_Gplus(n - 1) + 5);
}

int funkcja_Gminus(int n) {
	if (n == 204) return 255;
	else return (funkcja_Gplus(n - 1) - 5);
}

int funkcja_Bminus(int n) {
	if (n == 102) return 255;
	else return (funkcja_Bminus(n - 1) - 5);
}

struct BITMAPFILEHEADER {
	int bfType;
	int bfSize;
	int bfReserved1;
	int bfReserved2;
	int bfOffBits;
};

struct BITMAPINFOHEADER {
	int biSize;
	int biWidth;
	int biHeight;
	int biPlanes;
	int biBitCount;
	int biCompression;
	int biSizeImage;
	int biXpelsPerMeter;
	int biYpelsPerMeter;
	int biCrlUses;
	int biCrlImportant;
};

void czytaj_BITMAPFILEHEADER(ifstream& plik_wejsciowy, BITMAPFILEHEADER& bfh) {
	plik_wejsciowy.read(reinterpret_cast<char*>(&bfh.bfType), 2);
	plik_wejsciowy.read(reinterpret_cast<char*>(&bfh.bfSize), 4);
	plik_wejsciowy.read(reinterpret_cast<char*>(&bfh.bfReserved1), 2);
	plik_wejsciowy.read(reinterpret_cast<char*>(&bfh.bfReserved2), 2);
	plik_wejsciowy.read(reinterpret_cast<char*>(&bfh.bfOffBits), 4);
}
void czytaj_BITMAPINFOHEADER(ifstream& plik_wejsciowy, BITMAPINFOHEADER& bih) {
	plik_wejsciowy.read(reinterpret_cast<char*>(&bih.biSize), 4);
	plik_wejsciowy.read(reinterpret_cast<char*>(&bih.biWidth), 4);
	plik_wejsciowy.read(reinterpret_cast<char*>(&bih.biHeight), 4);
	plik_wejsciowy.read(reinterpret_cast<char*>(&bih.biPlanes), 2);
	plik_wejsciowy.read(reinterpret_cast<char*>(&bih.biBitCount), 2);
	plik_wejsciowy.read(reinterpret_cast<char*>(&bih.biCompression), 4);
	plik_wejsciowy.read(reinterpret_cast<char*>(&bih.biSizeImage), 4);
	plik_wejsciowy.read(reinterpret_cast<char*>(&bih.biXpelsPerMeter), 4);
	plik_wejsciowy.read(reinterpret_cast<char*>(&bih.biYpelsPerMeter), 4);
	plik_wejsciowy.read(reinterpret_cast<char*>(&bih.biCrlUses), 4);
	plik_wejsciowy.read(reinterpret_cast<char*>(&bih.biCrlImportant), 4);
}

void zapisuj_BITMAPFILEHEADER(ofstream& plik_wyjsciowy, BITMAPFILEHEADER& bfh) {
	plik_wyjsciowy.write(reinterpret_cast<char*>(&bfh.bfType), 2);
	plik_wyjsciowy.write(reinterpret_cast<char*>(&bfh.bfSize), 4);
	plik_wyjsciowy.write(reinterpret_cast<char*>(&bfh.bfReserved1), 2);
	plik_wyjsciowy.write(reinterpret_cast<char*>(&bfh.bfReserved2), 2);
	plik_wyjsciowy.write(reinterpret_cast<char*>(&bfh.bfOffBits), 4);
}

void zapisuj_BITMAPINFOHEADER(ofstream& plik_wyjsciowy, BITMAPINFOHEADER& bih) {
	plik_wyjsciowy.write(reinterpret_cast<char*>(&bih.biSize), 4);
	plik_wyjsciowy.write(reinterpret_cast<char*>(&bih.biWidth), 4);
	plik_wyjsciowy.write(reinterpret_cast<char*>(&bih.biHeight), 4);
	plik_wyjsciowy.write(reinterpret_cast<char*>(&bih.biPlanes), 2);
	plik_wyjsciowy.write(reinterpret_cast<char*>(&bih.biBitCount), 2);
	plik_wyjsciowy.write(reinterpret_cast<char*>(&bih.biCompression), 4);
	plik_wyjsciowy.write(reinterpret_cast<char*>(&bih.biSizeImage), 4);
	plik_wyjsciowy.write(reinterpret_cast<char*>(&bih.biXpelsPerMeter), 4);
	plik_wyjsciowy.write(reinterpret_cast<char*>(&bih.biYpelsPerMeter), 4);
	plik_wyjsciowy.write(reinterpret_cast<char*>(&bih.biCrlUses), 4);
	plik_wyjsciowy.write(reinterpret_cast<char*>(&bih.biCrlImportant), 4);
}

void kolorowanie(int p, ofstream& plik_wyjsciowy) {
	int r = 0;
	int g = 0;
	int b = 0;

	if (p == 0) {
		r = 255;
		g = 0;
		b = 255;
		plik_wyjsciowy.write(reinterpret_cast<char*>(&b), 1);
		plik_wyjsciowy.write(reinterpret_cast<char*>(&g), 1);
		plik_wyjsciowy.write(reinterpret_cast<char*>(&r), 1);
	}
	else if (1 <= p and p <= 50) {
		r = funkcja_Rminus(p) * (-1);
		g = 0;
		b = 255;
		plik_wyjsciowy.write(reinterpret_cast<char*>(&b), 1);
		plik_wyjsciowy.write(reinterpret_cast<char*>(&g), 1);
		plik_wyjsciowy.write(reinterpret_cast<char*>(&r), 1);
	}
	else if (p == 51) {
		r = 0;
		g = 0;
		b = 255;
		plik_wyjsciowy.write(reinterpret_cast<char*>(&b), 1);
		plik_wyjsciowy.write(reinterpret_cast<char*>(&g), 1);
		plik_wyjsciowy.write(reinterpret_cast<char*>(&r), 1);
	}
	else if (52 <= p and p <= 101) {
		r = 0;
		g = funkcja_Gplus(p) * (-1);
		b = 255;
		plik_wyjsciowy.write(reinterpret_cast<char*>(&b), 1);
		plik_wyjsciowy.write(reinterpret_cast<char*>(&g), 1);
		plik_wyjsciowy.write(reinterpret_cast<char*>(&r), 1);
	}
	else if (p == 102) {
		r = 0;
		g = 255;
		b = 255;
		plik_wyjsciowy.write(reinterpret_cast<char*>(&b), 1);
		plik_wyjsciowy.write(reinterpret_cast<char*>(&g), 1);
		plik_wyjsciowy.write(reinterpret_cast<char*>(&r), 1);
	}
	else if (103 <= p and p <= 152) {
		r = 0;
		g = 255;
		b = funkcja_Bminus(p) * (-1);
		plik_wyjsciowy.write(reinterpret_cast<char*>(&b), 1);
		plik_wyjsciowy.write(reinterpret_cast<char*>(&g), 1);
		plik_wyjsciowy.write(reinterpret_cast<char*>(&r), 1);
	}
	else if (p == 153) {
		r = 0;
		g = 255;
		b = 0;
		plik_wyjsciowy.write(reinterpret_cast<char*>(&b), 1);
		plik_wyjsciowy.write(reinterpret_cast<char*>(&g), 1);
		plik_wyjsciowy.write(reinterpret_cast<char*>(&r), 1);
	}
	else if (154 <= p and p <= 203) {
		r = funkcja_Rplus(p) * (-1);
		g = 255;
		b = 0;
		plik_wyjsciowy.write(reinterpret_cast<char*>(&b), 1);
		plik_wyjsciowy.write(reinterpret_cast<char*>(&g), 1);
		plik_wyjsciowy.write(reinterpret_cast<char*>(&r), 1);
	}
	else if (p == 204) {
		r = 255;
		g = 255;
		b = 0;
		plik_wyjsciowy.write(reinterpret_cast<char*>(&b), 1);
		plik_wyjsciowy.write(reinterpret_cast<char*>(&g), 1);
		plik_wyjsciowy.write(reinterpret_cast<char*>(&r), 1);
	}
	else if (205 <= p and p <= 255) {
		r = 255;
		g = funkcja_Gminus(p) * (-1);
		b = 0;
		plik_wyjsciowy.write(reinterpret_cast<char*>(&b), 1);
		plik_wyjsciowy.write(reinterpret_cast<char*>(&g), 1);
		plik_wyjsciowy.write(reinterpret_cast<char*>(&r), 1);
	}
}

void dodanie_zer(BITMAPINFOHEADER bih, ofstream& plik_wyjsciowy) {
	int ilezer;
	ilezer = bih.biWidth % 4;
	while (ilezer) {
		int zero = 0;
		plik_wyjsciowy.write(reinterpret_cast<char*>(&zero), 1);
		ilezer--;
	}
}

int main() {

	ifstream plik_wejsciowy;
	ofstream plik_wyjsciowy;

	plik_wejsciowy.open("sonar_aktywny2_szary.bmp", ios::binary);
	if (!plik_wejsciowy) {
		cout << "Plik wejsciowy nie zosta³ otwarty.";
		return 0;
	}

	plik_wyjsciowy.open("sonar_aktywny2_pokolorowany2.bmp", ios::binary);
	if (!plik_wyjsciowy) {
		cout << "Plik wyjsciowy nie zosta³ otwarty.";
		return 0;
	}
	BITMAPFILEHEADER bfh;
	BITMAPINFOHEADER bih;

	czytaj_BITMAPFILEHEADER(plik_wejsciowy, bfh);
	czytaj_BITMAPINFOHEADER(plik_wejsciowy, bih);
	zapisuj_BITMAPFILEHEADER(plik_wyjsciowy, bfh);
	zapisuj_BITMAPINFOHEADER(plik_wyjsciowy, bih);

	int p = 0;

	for (int i = 0; i < bih.biHeight; i++) {
		for (int i = 0; i < bih.biWidth; i++) {
			plik_wejsciowy.read(reinterpret_cast<char*>(&p), 1);
			plik_wejsciowy.seekg(2, ios::cur);

			kolorowanie(p, plik_wyjsciowy);
		}
		dodanie_zer(bih, plik_wyjsciowy);
		plik_wejsciowy.seekg(1, ios::cur);
	}
	plik_wejsciowy.close();
	plik_wyjsciowy.close();
	return 0;
}
