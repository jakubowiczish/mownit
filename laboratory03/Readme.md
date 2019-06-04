# Zadania
## Zadanie 1.
Uruchomić

- naive_multiplication(A,B),
- better_multiplication(A,B)
- mnożenie BLAS w Julii (A*B)
dla coraz większych macierzy i zmierzyć czasy. 
- Narysować wykres zależyności czasu od rozmiaru macierzy wraz z słupkami błędów, 
tak jak na poprzednim laboratorium. Wszystkie trzy metody powinny być na jednym wykresie.

## Zadanie 2.
Napisać w języku C:

- naiwną metodę mnożenia macierzy (wersja 1) 
- ulepszoną za pomocą zamiany pętli metodę mnożenia macierzy (wersja 2), 
pamiętając, że w C macierz przechowywana jest wierszami 
(row major order tzn A11,A12, ..., A1m, A21, A22,...,A2m, ..Anm), inaczej niż w Julii ! 
- skorzystać z  możliwości BLAS dostępnego w GSL(wersja 3). 

- Należy porównywać działanie tych trzech algorytmow bez włączonej opcji optymalizacji kompilatora. 
Przedstawić wyniki na jednym wykresie tak jak w p.1.(osobno niż p.1). 
- (Dla chętnych) sprawdzić, co się dzieje, jak włączymy optymalizację kompilatora i dodać do wykresu.

## Zadanie 3.
- Użyć funkcji polyfit z pakietu Polynomials do znalezienia odpowiednich wielomianow, 
ktore najlepiej pasują do zależności czasowych kazdego z algorytmow. 
Stopień wielomianu powinien zgadzać się z teoretyczną złożonoscią. 
- Dodać wykresy uzyskanych wielomianow do wczesniejszych wykresów.
