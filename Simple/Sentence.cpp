#include "Sentence.h"

#include <iostream>
#include <cstdlib>
#include <limits>
using namespace std;

#define MAX_LEN 128

/*----------------------------------------------------------------------------
  int str_len( char s[] )

  Funkcja:
  Wlasna implementacja funkcji wyznaczajacej dlugosc napisu liczona w znakach

  Parametry:
    char s[] -- tablica zawierajaca napis ktorego dlugosc jest wyznaczana

  Rezultat:
    dlugosc napisu liczona w znakach
----------------------------------------------------------------------------*/
int Sentence::str_len(char s[])
{
  int length = 0;
  while (s[length] != '\0') {
    length++;
  }
  return length;
}

/*----------------------------------------------------------------------------
  int lwr_str_cnt( char s[] )

  Funkcja:
    Wyznacza liczbe malych liter w napisie s

  Parametry:
    char s[] -- tablica zawierajaca napis

  Rezultat:
    Liczba malych liter w napisie s
----------------------------------------------------------------------------*/
int Sentence::lwr_str_cnt( char s[] )
{
  int count = 0;
  for (int i = 0; s[i] != '\0'; ++i) {
    if (s[i] >= 'a' && s[i] <= 'z') {
      count++;
    }
  }
  return count;
}

/*----------------------------------------------------------------------------
  int upr_str_cnt( char s[] )

  Funkcja:
    Wyznacza liczbe duzych liter w napisie s

  Parametry:
    char s[] -- tablica zawierajaca napis

  Rezultat:
    Liczba duzych liter w napisie s
----------------------------------------------------------------------------*/
int Sentence::upr_str_cnt( char s[] )
{
  int count = 0;
  for (int i = 0; s[i] != '\0'; ++i) {
    if (s[i] >= 'A' && s[i] <= 'Z') {
      count++;
    }
  }
  return count;
}


/*----------------------------------------------------------------------------
  int dgt_str_cnt( char s[] )

  Funkcja:
    Wyznacza liczbe cyfr w napisie s

  Parametry:
    char s[] -- tablica zawierajaca napis

  Rezultat:
    Liczba cyfr w napisie s
----------------------------------------------------------------------------*/
int Sentence::dgt_str_cnt( char s[] )
{
  int count = 0;
  for (int i = 0; s[i] != '\0'; ++i) {
    if (s[i] >= '0' && s[i] <= '9') {
      count++;
    }
  }
  return count;
}

/*----------------------------------------------------------------------------
  int nalpha_str_cnt( char s[] )

  Funkcja:
    Wyznacza liczbe liter i cyfr w napisie s

  Parametry:
    char s[] -- tablica zawierajaca napis

  Rezultat:
    Liczba liter i cyfr w napisie s
----------------------------------------------------------------------------*/
int Sentence::nalpha_str_cnt( char s[] )
{
  int count = 0;
  for (int i = 0; s[i] != '\0'; ++i) {
    if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
      count++;
    }
  }
  return count;
}

/*----------------------------------------------------------------------------
  int chr_str_cnt( char c, char s[] )

  Funkcja:
    Wyznacza liczbe wystapien znaku c w s

  Parametry:
    char c   -- znak poszukiwany w napisie
    char s[] -- tablica zawierajaca napis


  Rezultat:
    Liczba wystapien znaku c w napisie s
----------------------------------------------------------------------------*/
int Sentence::chr_str_cnt( char c, char s[] )
{
  int count = 0;
  for (int i = 0; s[i] != '\0'; ++i) {
    if (s[i] == c) {
      count++;
    }
  }
  return count;
}

/*----------------------------------------------------------------------------
int chr_str_pos( char c, char s[] )

  Funkcja:
    Wyznacza indeks (pozycje w napisie) pierwszego wystapienia znaku c w s

  Parametry:
    char c   -- znak poszukiwany w napisie
    char s[] -- tablica zawierajaca napis


  Rezultat:
    Pozycja znaku w tablicy liczona od 0 lub -1 gdy znak nie znaleziony
----------------------------------------------------------------------------*/
int Sentence::chr_str_pos( char c, char s[] )
{
  int i = 0;
  while (s[i] != '\0') {
    if (s[i] == c) {
      return i;
    }
    i++;
  }
  return -1;
}

/*----------------------------------------------------------------------------
int chr_str_rpos( char c, char s[] )

  Funkcja:
    Wyznacza indeks (pozycje w napisie) ostatniego wystapienia znaku c w s

  Parametry:
    char c   -- znak poszukiwany w napisie
    char s[] -- tablica zawierajaca napis


  Rezultat:
    Pozycja znaku w tablicy liczona od 0 lub -1 gdy znak nie znaleziony
----------------------------------------------------------------------------*/
int Sentence::chr_str_rpos( char c, char s[] )
{
  int i = 0;
  int last_pos = -1;
  while (s[i] != '\0') {
    if (s[i] == c) {
      last_pos = i;
    }
    i++;
  }
  return last_pos;
}

/*----------------------------------------------------------------------------
  void str_rev( char s[] )

  Funkcja:
    Odwraca kolejnosc znakow w tablicy s

  Parametry:
    char s[] -- tablica zawierajaca napis

  Rezultat:
    Brak
----------------------------------------------------------------------------*/
void Sentence::str_rev( char s[] )
{
  int len = str_len(s);
  for (int i = 0; i < len / 2; ++i) {
    std::swap(s[i], s[len - i - 1]);
  }
}

int Sentence::run()
{
  char line[ MAX_LEN ];
  char c;
  int pos;

  cout << "\n\nWpisz linie tekstu: ";
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cin.getline( line, MAX_LEN );

  cout << "\nLiczba znakow           : " << str_len( line );
  cout << "\nLiczba malych liter     : " << lwr_str_cnt( line );
  cout << "\nLiczba duzych liter     : " << upr_str_cnt( line );
  cout << "\nLiczba cyfr             : " << dgt_str_cnt( line );
  cout << "\nLiczba alfanumerycznych : " << nalpha_str_cnt( line );

  cout << "\n\nPodaj pojedynczy znak: ";
  cin.get( c );

  cout << "\nLiczba wystapien znaku  " << c << " : " << chr_str_cnt( c, line );

  if( ( pos = chr_str_pos( c, line ) ) != -1 )
    cout << "\nPierwsze wystapienie znaku " << c << " od poczatku : " << pos + 1;
  else
    cout << "\nZnak " << c << " nie zostal znaleziony";

  if( ( pos = chr_str_rpos( c, line ) ) != -1 )
    cout << "\nPierwsze wystapienie znaku " << c << " od konca : " << pos + 1;
  else
    cout << "\nZnak " << c << " nie zostal znaleziony";

  cout << "\n\nNapis oryginalny : " << line;
  str_rev( line );
  cout << "\nNapis odwrocony  : " << line;

  cin.ignore();
  cin.get();
  return EXIT_SUCCESS;
}
