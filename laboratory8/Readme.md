## Zadania:

### 1. Zamień sygnał na sumę sygnałów np
```julia
x = sin.(2*pi*t*200) + 2*sin.(2*pi*t*400)
```
- Zaobserwuj wynik transformaty i wyjaśnij go.

### 2. Usuwanie szumów:

- Wypełniamy tablicę wartościami funkcji cosinus ("sygnału") zaburzonej niewielkim "szumem"
np. dodając do każdej wartości wylosowaną liczbę funkcją rand().

- Prosze narysować wykres zaszumionej funkcji.

- Narysować wykres transformaty Fouriera (widmo) tego sygnału (jak poprzednio).

- Po transformacie wyzerowac w widmie wszystkie elementy, których wartość bezwzględna jest mniejsza niz 50. 
W ten sposób usuwamy "szumy" z sygnału.

- Przeprowadzić odwrotną transformatę funkcją ifft(). 

- Narysować wykres otrzymanej funkcji dla częsci rzeczywistej. 

- Porównać z wejściowym wykresem sygnału.

### 3. Proszę nagrać własny glos i zastosować na nim trasformatę Fouriera, narysować wykres widma.

- Następnie poeksperymentować (wyciąć wybrane częstotliwości), dokonać odwrotnej transformaty i odsłuchać efekt.

#### Przydatne materiały:

##### Basic sound processing - http://samcarcagno.altervista.org/blog/basic-sound-processing-julia/
##### Pakiet Wav - https://github.com/dancasimiro/WAV.jl
