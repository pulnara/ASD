/* Dana formula logiczna w postaci 2-CNF. // CNF = alternatywy polaczone koniukcjami, 2 oznacza ze maksymalnie dwa wyrazy

(x or y) and (~x or z) and (~z or ~y)

Czy istnieje wartosciowanie takie ze formula jest spelniona?
(tu istnieje: x = 1, y = 0, z = 1)
*/

Kazda z alternatyw mozna zapisac jako:
x or y == (x => ~y) and (~x => y)
~x or z == (~x => ~z) and (x => z)
~z or ~y == (~z => y) and (z => ~y)

Po rozpisaniu kazda implikacja '=>' oznaczac bedzie krawedz miedzy poprzednikiem a nastepnikiem.

1. Tworzymy graf o wierzcholkach x, ~x, y, ~y, z, ~z, itd. (w zaleznosci od liczby roznych wyrazow w alternatywach)
2. Kazda z alternatyw w danej formule logicznej w postaci 2-CNF traktujemy jako koniunkcje 2 implikacji (wg wzoru powyzej).
   Dla ka¿dej koniunkcji powstalej z kazdej z wprowadzonych alternatyw w naszym grafie tworzymy krawedz miedzy poprzednikiem a nastepnikiem implikacji.
3. Szukamy silnie spojnych skladowych. Dla i = x, y, z... :
   Jesli dla ktoregokolwiek i (i) oraz (~i) naleza do jednej spojnej skladowej, to nie istnieje odpowiednie wartosciowanie (bo i => ~i /\ ~i => i, co jest sprzeczne).
