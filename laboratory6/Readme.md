## Rendering problem

In case there is a problem while rendering jupyter notebook - look at this site: 
https://nbviewer.jupyter.org/github/jakubowiczish/mownit/blob/master/laboratory6/laboratory6.ipynb


## Zadania
- Napisać własną implementację interpolacji wielomianowej stosując wprost wzór na wielomian interpolacyjny Lagrange'a. 
  - Język implementacji do wyboru (Julia, C). 
  - Przetestować swoją implementację na wylosowanych węzłach interpolacji w wybranym przedziale. 
  - Narysować wykres wielomianu interpolacyjnego w tym przedziale wraz z wezlami interpolacji.

- Zrobic to samo dla metody Newtona (metoda ilorazów róznicowych). 
  - Zadbac o to, żeby ilorazy wyliczać tylko raz dla danego zbioru wezłow interpolacji. 
  - Jezyk implementacji wybrac taki sam, jak w poprzednim punkcie. 
  - Narysować wykres wielomianu interpolacyjnego dla tych samych danych, co w poprzednim punkcie.

- Zastosowac interpolację wielomianową z pakietu Polynomials (jesli wybralismy Julie) albo z funkcji gsl_interp_polynomial z pakietu GSL (jesli wybraliśmy C) do tych samych danych, co w poprzednich punktach. 
  - Porównać wszystkie 3 wyniki interpolacji wielomianowej na jednym wykresie. Co zauważamy? Dlaczego?

- Porownać metody poprzez pomiar czasu wykonania dla zmiennej ilości węzłow interpolacji. 
  - Dokonac pomiaru 10 razy i policzyc wartość średnią oraz oszacować bład pomiaru za pomoca odchylenia standardowego.  - -       - Narzedzie do analizy danych do wyboru (Julia, R)

- Poeksperymentowac z interpolacją funkcjami sklejanymi (minimum dwie rozne funkcje sklejane), narysowac wykresy i porownac z wykresami interpolacji wielomianowej.

- Zademonstrowac efekt Rungego.

- Zbadać i zademonstrować podczas zajęc rózne algorytmy interpolacji stosowane w grafice komputerowej (np. do zmiany wielkości obrazu). 
  - Można korzystac z gotowych rozwiazań, ale trzeba wiedzieć, jak te algorytmy dzialaja. 
  - Do zaliczenia tego zadania potrzebne jest demonstracja i porownanie działania conajmniej dwóch metod.
