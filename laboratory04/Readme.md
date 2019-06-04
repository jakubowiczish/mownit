
# Zadania
# Zadanie 1
- ustal losowe (referencyjne) x rozmiaru 1000 oraz losowe A rozmiaru 1000x1000 
- policz b=A*x,nastepnie rozwiąz rownanie Ax=b trzema metodami:
  - inv()
  - \
  - factorize()

- Porównaj jakość wyniku (zmierzoną jako długość różnicy wektorów wyniku oraz referencyjnego x) oraz czas wykonania (@time). 
- UWAGA: pierwsze wykonanie fukcji w Julii zawiera czas kompilacji tej funkcji, dlatego czas mierzymy od drugiego wywołania !

## Zadanie 2
- Policz wspołczynniki wielomianu aproksymującego dowolne dane z poprzednich laboratoriów 
tworząc wprost układ równań i rozwiązujac go (metoda zaprezentowana na tym laboratorium).
- Porównaj wyniki z tymi otrzymanymi poprzednio.

## Zadanie 3
- Znajdź i zaprezentuj działanie innego zastosowania wybranej faktoryzacji.
Przykładowe (ale nie jedyne!) tematy:

- tworzenie pseudoinversji macierzy(http://buzzard.ups.edu/courses/2014spring/420projects/math420-UPS-spring-2014-macausland-pseudo-inverse-present.pdf).

- uzycie faktoryzacji QR do znajdowania wartości własnych(https://en.wikipedia.org/wiki/QR_algorithm)

- zastosowanie faktoryzacji SVD - przykład zastosowania w uczeniu maszynowym https://blog.statsbot.co/singular-value-decomposition-tutorial-52c695315254
