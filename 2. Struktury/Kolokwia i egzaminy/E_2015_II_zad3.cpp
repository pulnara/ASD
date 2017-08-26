 /* Dana jest nastepujaca struktura opisujaca drzewo:
 struct Tree{ Tree *parent;  //rodzic, lub NULL jeœli to korzeñ
 Tree *left, *right; //lewe I prawe dziecko
 Int w_left, w_right //wagi krawêdzi do lewego i do prawego dziecka (dodatnie) }
Prosze opisac (bez implementacji) mozliwie jak najszybszy algorytm, ktory majac na wejœciu drzewo opisane przez strukture Tree znajduje dlugosc
sciezki miedzy dwoma wezlami drzewa (prosta sciezka to taka, ktora nie odwiedza zadnego wezla wiecej ni¿ raz).
(Na potrzeby algorytmu mog¹ panstwo uzupelnic strukture Tree o dalsze pola.)
*/

1. Przebiegamy od pierwszego z podanych wezlow do korzenia, zapisujac na jednej liscie (kolejny wezel przylaczamy na poczatek listy!) adresy mijanych wezlow.
2. Przebiegamy od drugiego z podanych wezlow do korzenia, zapisujac na drugiej liscie (kolejny wezel przylaczamy na poczatek listy!) adresy mijanych wezlow.
3. W jednej petli przebiegamy od poczatku przez nasze nowo utworzone listy i szukamy ostatniego zgodnego adresu.
   Jest on adresem wezla bedacego wspolnym "korzeniem" naszych wezlow.
4. Dlugosc poszukiwanej sciezki jest rowna sumie ilosci 'niezgodnych' elementow w obu listach.

II sposob:

1. Uzupelniamy strukture Tree o pole int which, ktore oznaczac bedzie numer naszego wezla w wedrowce opisanej w punkcie 2 (ponizej).
   Dla wszystkich wezlow w drzewie wartosc tego pola wynosi 0.
2. Startujemy od pierwszego z wezlow i poruszajac sie po parentach, wedrujemy az do roota, w aktualnie badanym wezle zapisujac numer,
   w jakiej kolejnosci odwiedzilismy ten wezel (wezel startowy -> 1, jego parent -> 2, itd.).
3. Startujemy od drugiego z wezlow i poruszajac sie po parentach wedrujemy az do wezla, w ktorym wartosc pola 'which' != 0 lub az do roota.
   Dlugosc szukanej sciezki dla x = wezel, na ktorym sie zatrzymalismy:
       x -> left -> which + x -> right -> which.
