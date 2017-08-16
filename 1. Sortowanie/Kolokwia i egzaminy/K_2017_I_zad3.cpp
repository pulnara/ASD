/*
Prosze opisac (bez implementacji!) jak najszybszy algorytm, ktory otrzymuje na wejsciu pewien ciag n liter oraz liczbe k
i wypisuje najczesciej powtarzajacy siê podciag d³ugosci k (jesli ciagow mogacych stanowic rozwiazanie jest kilka, algorytm zwraca dowolny z nich).
Mozna zalozyc, ze ciag sklada sie wylacznie z liter a i b. Na przyklad dla ciagu ababaaaabb oraz k = 3 rozwiazaniem jest zarowno ciag aba,
ktory powtarza sie dwa razy (to, ze te wystapienia na siebie nachodza nie jest istotne).
Zaproponowany algorytm opisac, uzasadnic jego poprawnosc oraz oszacowac jego z³ozonosc.
*/

1. Tworzymy nowa tablice T o wielkosci n - (k - 1) elementow. - O(1)
2. Jednokrotnie przechodzac przez tablice wejsciowa (o dlugosci n) zapisujemy w kolejnych indeksach tablicy T kolejne wystepujace podciagi znakow o dlugosci k. - O(n)
3. Wykonujemy radix sort na tablicy T. - O(n*k)
4. Tworzymy 2 zmienne - jedna na maksymalna liczbe wystapien dotychczas najczesciej powtarzajacego sie podciagu, druga przechowujaca aktualnie najczesciej wystepujacy podciag.
   Ustawiamy im pierwotne wartosci dla pierwszego podciagu w posortowanej tablicy T. - O(1)
5. Jednokrotnie przechodzimy przez posortowana tablice T i zliczamy wystapienia poszczegolnych ciagow. Jesli liczba wystapien wlasnie zbadanego ciagu jest wieksza od liczby wystapien
   ciagu, ktory byl dotychczasowym najczesciej powtarzajacym sie podciagiem, odpowiednio aktualizujemy zmienne utworzone w punkcie 4. - O(n-k+1)

Zlozonosc: O(n*k)
