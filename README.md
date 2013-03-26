# Algorytmy sortowania na AiSD

Przegląd podstawowych algorytmów sortowania jakie były do wykonania
na Algorytmy i Strunktury Danych razem z generatorem wykresów.

## Wymagania

- sh lub inna powłoka zgodna z POSIX (bash, zsh, etc.)
- GNU Make
- GCC 4.6+

Jeśli chcesz mieć od razu wygenerowany raport to będzie potrzebne również:

- R 2.15+
- pdfTeX 3.1415926+

## Sposób użycia

Skompilowanie wszystkich programów odbywa się poprzez polecenie:

    $ make all

By wygenerować pliki testowe należy odpalić polecenie:

    $ make data

Przy odpaleniu polecenia

    $ make test

Zostaną skompilowane wszystkie pliki, zostaną utworzone dane testowe oraz
zostanie odpalony skrypt testujący, który jednocześnie liczy czas w nanosekundach
i umieszcza wynik w odpowiednich plikach w folderze `out/`. Nazwy plików są
konstruowane następująco `<typ danych>_<nazwa programu>`.

By przetestować pojedynczy algorytm należy wykonać polecenie:

    $ ./test.sh <nazwa programu>

### Jak odpalić by nie upiec kompa?

Polecam zalogować się przez SSH na serwerze PP, do którego jesteśmy przypisani, np.:

    $ ssh inf109706@polluks.cs.put.poznan.pl

Sklonować to repozytorium:

    $ git clone https://github.com/put-poznan/sorts.git

Odpalić GNU Screen

    $ screen

Przejść do odpowiedniego katalogu i odpalić:

    $ make test | mail -s Zakończono twój@adres.email.pl

Wcisnąć kombinację klawiszy Control-a d co spowoduje odłączenie się danej konsoli
i można spokojnie opuścić sesję SSH. Gdy się skończy praca naszego skryptu otrzymamy
maila zawierającego wyjście naszego generatora.

## Dodanie nowego algorytmu

Wpierw należy utworzyć nowy plik z kodem o nazwie `<nazwa algorytmu>.c` i umieścić go
w głównym folderze. Funkcja `main` powinna wyglądać następująco:

    int main(int argc, char* argv[]) {
      if (argc < 2) return 1;

      int size = atoi(argv[1]);
      int *arr = (int*)malloc(sizeof(int) * size);

      for (int i = 0; i < size; i++)
        scanf("%d", arr + i);

      sort(arr, size);

      free(arr);

      return 0;
    }

Gdzie `sort` to funkcja sortująca przyjmująca 2 argumenty: tablicę oraz jej rozmiar.

Po napisaniu kodu należy dodać dany kod do pliku `Makefile` na końcu linijki:

    SOURCES=heap.c insertion.c selection.c shell.c quick_left.c quick_rand.c

### Styl

Używamy stylu K&R z podwójną spacją zamiast tablulacji. Zmienne i funkcje nazywać
przy pomocy `small_caps_snake_case`, makra i stałe przy pomocy `BIG_CASE_SNAKE_CASE`.
Nie używać notacji węgierskiej czy innego badziewia.

## Generowanie raportu

Po odpaleniu polecenia

    $ make report

Zostanie wywołane polecenie `$ make test` a następnie zostanie zbudowany raport
zawierający wykresy czasu od ilości danych. Zostanie zapisany on jako plik
`plots.pdf`.
