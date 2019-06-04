## Zadanie
- Napisać program w języku C używającego interfejsu GSL do BLAS: 
funkcji gsl_blas_ddot (mnożenie dwóch wektorów) i gsl_blas_dgemv (mnożenie macierzy przez wektor).
- Uruchomić i zmierzyć czasy działania obydwu funkcji - każdej dla różnych rozmiarów wektorów. 
Dokonać 10 pomiarów dla każdego rozmiaru wektora.
- Czasy działania powinny być zapisywane do jednego pliku CSV. 
- Należy zaplanować odpowiednią strukturę kolumn takiego pliku.
- Wczytać dane z w/w pliku do jednego DataFrame w języku Julia.
- Korzystająć z mechanizmów DataFrame w języku Julia obliczyć średnią i odchylenie standardowe, w taki sposób, 
aby narysować wykresy średnich czasów obliczenia operacji BLAS w zależności od rozmiaru wektora (macierzy) osobno dla poziomu 1 i poziomu 2. Dodać słupki błędów do obydwu wykresów uzyskanych z obliczenia odchylenia standardowego. Prosze poukladac wykresy w tabalke za pomoca opcji layout
- Należy zadbać o staranne podpisanie osi i wykresów.
