## Zadanie
Za pomocą języka R przeanalizować dowolne dane z poprzednich laboratoriów. Elementy obowiązkowe:
- W jednej tabeli języka R należy umieścić wyniki dwóch różnych eksperymentów (t.j. 
czas działania dwóch różnych funkcji) dla różnych parametrów (t.j. rozmiarów wektora(macierzy)).
- Tabela powinna zawierać dane z 10-krotnego uruchomienia tego samego eksperymentu dla tych samych parametrów (dla każdego takiego zestawu)
- Należy przedstawić wykresy średnich czasów obliczenia wybranych funkcji w zależności od rozmiaru wektora (macierzy)
- Wykresy powinny zawierać informację o odchyleniu standardowym dla uzyskanych wyników. 
- Słupki błędów można narysować korzystając z funkcji geom_errorbar pakietu ggplot2 . 
- Uwaga, potrzebna może być instalacja biblioteki ggplot2. W RStudio wystarczy dodać odpowiedni pakiet w zakładce "Packages" w prawym dolnym rogu oraz oznaczyć ten pakiet jako "user library".

Przy korzystaniu z konsoli:
  - install.packages("ggplot2")
  - library("ggplot2")

- Uzyc aproksymacji wielomianowej dostepnej w jezyku R do znalezienia odpowiednich wielomianow, 
ktore najlepiej pasuja do wynikow kazdego z algorytmow. 
- Dodac wykresy uzyskanych wielomianow do wykresu. 
