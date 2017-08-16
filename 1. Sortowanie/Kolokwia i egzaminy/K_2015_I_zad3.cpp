/* Jak posortowac n-elementowa tablice liczb rzeczywistych, ktore przyjmuja tylko logn roznych wartosci?
Uzasadnic poprawnosc algorytmu i oszacowac zlozonosc. (Nie trzeba implementowac).
*/

Wykorzystamy CountSort oraz wyszukiwanie binarne.
1. Tworzymy dwie nowe tablice - jedna (B) o rozmiarze n i druga (C) o rozmiarze logn. C zerujemy.
2. Przebiegamy po kolei przez wszystkie elementy naszej n-elementowej tablicy, a nastepnie za kazdym razem wyszukujemy binarnie indeksu
   o czesci calkowitej w tablicy C. Wartosc pod tym indeksem inkrementujemy.
3. Typowy CountSort.

Zlozonosc - O(nloglogn + log^2n) = O(nloglogn)

ZLE!!!!!!!!!!!!!!!!
