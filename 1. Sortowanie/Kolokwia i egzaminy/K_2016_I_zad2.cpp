/* Dana jest n elementowa tablica A zawierajaca liczby naturalne (potencjalnie bardzo duze).
Wiadomo, ze tablica A powstala w dwoch krokach. Najpierw wygenerowano losowo (z nieznanym rozkladem)
n roznych liczb nieparzystych i posortowano je rosnaco. Nastepnie wybrano losowo sufit z logn elementow powsta³ej tablicy
i zamieniono je na losowo wybrane liczby parzyste. Prosze zaproponowac (bez implementacji!) algorytm sortowania tak powstalych danych.
Algorytm powinien byc mozliwie jak najszybszy. Prosze oszacowac i podac jego zlozonosc czasowa.
*/

k = sufit z log n
1. Tworzymy 2 nowe tablice - jedna na k elementow (dla ulatwienia opisu nazwijmy ja B), druga na n-k elementow (nazwijmy ja C). - O(1)
2. Przebiegamy przez tablice A i po kolei parzyste liczby przepisujemy do tablicy B, a nieparzyste do C. - O(n)
3. Tablica C jest juz posortowana, sortujemy wiec (np. QuickSortem) tablicê B - O(klogk)
4. Mergujemy tablice B i C do tablicy A - O(n)

A wiec ostatecznie zlozonosc - O(n), bo n > (logn)*log(logn)
