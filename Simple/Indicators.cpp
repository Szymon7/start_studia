#include "Indicators.h"
#include <cstdlib>
#include <iostream>
#include <limits>
using namespace std;
const int MAX_LEN = 128;

/*
  int str_len(char * s)

  Wlasna implementacja funkcji wyznaczajacej dlugosc
  napisu liczona w znakach

  Parametry:
    char * s -- tablica zawierajaca napis, ktorego
    dlugosc jest wyznaczana

  Rezultat:
    Dlugosc napisu liczona w znakach
*/
int Indicators::str_len(char * s)
{
  int length = 0;
  while (*s++) {
    length++;
  }
  return length;
}

/*
  int lwr_str_cnt(char * s)

  Wyznacza liczbe malych liter w napisie s

  Parametry:
    char s[] -- tablica zawierajaca napis

  Rezultat:
    Liczba malych liter w napisie s
*/
int Indicators::lwr_str_cnt(char * s)
{
  int count = 0;
  while (*s) {
    if (islower(*s)) {
      count++;
    }
    s++;
  }
  return count;
}

/*
  int upr_str_cnt(char * s)

  Wyznacza liczbe duzych liter w napisie s

  Parametry:
    char * s -- tablica zawierajaca napis

  Rezultat:
    Liczba duzych liter w napisie s
*/
int Indicators::upr_str_cnt(char * s)
{
  int count = 0;
  while (*s) {
    if (isupper(*s)) {
      count++;
    }
    s++;
  }
  return count;
}

/*
  int dgt_str_cnt(char * s)

  Wyznacza liczbe cyfr w napisie s

  Parametry:
    char * s -- tablica zawierajaca napis

  Rezultat:
    Liczba cyfr w napisie s
*/
int Indicators::dgt_str_cnt(char * s)
{
  int count = 0;
  while (*s) {
    if (isdigit(*s)) {
      count++;
    }
    s++;
  }
  return count;
}

/*
  int nalpha_str_cnt(const char * s)

  Wyznacza liczbe liter i cyfr w napisie s

  Parametry:
    char * s -- tablica zawierajaca napis

  Rezultat:
    Liczba liter i cyfr w napisie s
*/
int Indicators::nalpha_str_cnt(char * s)
{
  int count = 0;
  while (*s) {
    if (isalnum(*s)) {
      count++;
    }
    s++;
  }
  return count;
}

/*
  int chr_str_cnt(char c, char * s)

  Wyznacza liczbe wystapien znaku c w s

  Parametry:
    char c   -- znak poszukiwany w napisie
    char * s -- tablica zawierajaca napis

  Rezultat:
    Liczba wystapien znaku c w napisie s
*/
int Indicators::chr_str_cnt(char c, char * s)
{
  int count = 0;
  while (*s) {
    if (*s == c) {
      count++;
    }
    s++;
  }
  return count;
}

/*
  char * chr_str_pos(char c, char * s)

  Wyznacza wskazanie na pierwsze wystapienie znaku c w s

  Parametry:
    char c   -- znak poszukiwany w napisie
    char * s -- tablica zawierajaca napis

  Rezultat:
    Wskazanie na pierwsze wystapienie znaku c w s lub 0 gdy znak
    nie zostal znaleziony
*/
char * Indicators::chr_str_pos(char c, char * s)
{
  while (*s) {
    if (*s == c) {
      return s;
    }
    s++;
  }
  return nullptr;
}

/*
  char * chr_str_rpos(char c, char * s)

  Wyznacza wskazanie na ostatnie wystapienie znaku c w s

  Parametry:
    char c   -- znak poszukiwany w napisie
    char * s -- tablica zawierajaca napis

  Rezultat:
    Wskazanie na ostatnie wystapienie znaku c w s lub NULL gdy znak
    nie zostal znaleziony
*/
char * Indicators::chr_str_rpos(char c, char * s)
{
  char *last_pos = nullptr;
  while (*s) {
    if (*s == c) {
      last_pos = s;
    }
    s++;
  }
  return last_pos;
}

/*
  char * str_rev( char * s )

  Odwraca kolejnosc znakow w tablicy s

  Parametry:
    char * s -- tablica zawierajaca napis

  Rezultat:
    Wskazanie na tablice s
*/
char * Indicators::str_rev(char * s)
{
  char *start = s;
  char *end = s + str_len(s) - 1;
  while (start < end) {
    char temp = *start;
    *start = *end;
    *end = temp;
    start++;
    end--;
  }
  return s;
}

/*
  int str_word_count(char * s)

  Funkcja wyznacza liczbe slow w tablicy s. Jako slowo
  rozumiemy ciag liter cyfr i znakow podkreslenia. Slowa
  moga być rozdzielane jednym lub wieloma znakami spacji, tabulacji,
  podzialu wiersza.

  Przyklad:
  Napis: "Ala _ma_    kot_ta i    dwa psy"
  Liczba slow: 6

  Parametry:
    char * s -- tablica zawierajaca napis

  Rezultat:
    Liczba slow w napisie s
*/
int Indicators::str_word_count(char * s)
{
  int count = 0;
  bool in_word = false;
  while (*s) {
    if (isalnum(*s) || *s == '_') {
      if (!in_word) {
        in_word = true;
        count++;
      }
    } else {
      in_word = false;
    }
    s++;
  }
  return count;
}

int Indicators::run()
{
  char line[MAX_LEN];
  char c;
  char * pos;

  cout << "\n\nWpisz linie tekstu: ";
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cin.getline(line, MAX_LEN-1);

  cout << "\nLiczba znakow         : " << str_len(line);
  cout << "\nLiczba malych liter   : " << lwr_str_cnt(line);
  cout << "\nLiczba duzych liter   : " << upr_str_cnt(line);
  cout << "\nLiczba cyfr           : " << dgt_str_cnt(line);
  cout << "\nLiczba znakw alphanum : " << nalpha_str_cnt(line);

  cout << "\n\nPodaj pojedynczy znak: ";
  cin >> c;

  cout << "\nLiczba wystapien znaku " << c << ": " << chr_str_cnt(c, line);

  if((pos = chr_str_pos(c, line)) != 0)
    cout << "\nPierwsze wystapienie znaku " << *pos << " na pozycji: " << pos - line;
  else
    cout << "\nZnak " << c << " nie zostal znaleziony";

  if((pos = chr_str_rpos(c, line)) != 0)
    cout << "\nOstatnie wystapienie znaku " << *pos  << " na pozycji: " << pos - line;
  else
    cout << "\nZnak " << c << " nie zostal znaleziony";

  cout << "\n\nNapis oryginalny : " << line;
  cout << "\nNapis odwrocony  : " << str_rev(line);
  cout << "\nLiczba slow w napisie: " << str_word_count(line);

  cout << "\n\nNacisnij enter, aby kontynuowac";

  cin.ignore();
  cin.get();

  std::cout << "\n=============================\n\n";

  return EXIT_SUCCESS;
}
