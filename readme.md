# generator labiryntów

## opis programu

program służy do generowania labiryntów metodą "Recursive backtracker" oraz do wyświetlania ich za pomocą biblioteki sfml (ele jest też opcja wyświetlania ich w postaci ASCII)

## instalacja

do kompilacji programu wymagany jest program cmake,aby zainstalować make należy wpisać:

```bash
sudo apt  install cmake
```

następnie należy utworzyć folder build:

```bash
mkdir build
```

następnie wchodzimy do pliku build

```bash
cd build
```

teraz za pomocą cmake przygotowujemy konfigurację naszego projektu, cmake powinien znaleźć nasz kompilator i przygotować nam makefile

```bash
cmake ..
```

teraz mamy już wygenerowany naż makefile, wystarczy wpisać make i nasz program zostanie skompilowany, pliki wykonywalne będą znajdować się w folderze build. Jako że sami budujemy bibliotekę sfml nie powinno być konieczności doinstalowywania dodatkowych pakietów

po skompilowaniu w celu uruchomienia main, należy jeszcze skopiować pliki dll do pliku w którym znajdują się pliki wykonywalne

```bash
cp build/SFML-2.5.1/lib/*.dll build 
```

## opis funkcji

`MyTable mazeGenerator(int hight, int width)`  generuje labirynt w obiekcie `MyTable`

`void drawMaze(MyTable table)` rysuje labirynt podany w zmiennej `MyTable` za pomocą biblioteki sfml

`void drawMazeASCII(MyTable table)` rysuje labirynt podany w zmiennej `MyTable` w postaci ASCII na terminalu

## opis obiektów

`MyTable` zawiera w sobie labirynt w takiej postaci że każde pole wie na jakie sąsiednie może wejść (gdzie nie ma ściany)

`Node` jest to opis pojedynczego pola labiryntu, zawiera w sobie na jakie sąsiedzkie pole można wejść

## opis algorytmu

generowanie labiryntu metodą "Recursive backtracker" można uznać za metodę bardzo podobną do znajdowania drzewa rozpinającego grafu.

1. Na stosie kładziemy losowo znaleziony node labiryntu

2. Bierzemy noda z szczytu stosu

3. wkładamy wylosowany noda do zbioru odwiedzonych

4. następnie wybieramy losowego sąsiada wybranego noda i kładziemy go na stos

5. powtarzamy kroki 2 - 4 aż stos się opóźni

## opis interfejsu graficznego

### ustawienie wielkości generowanego okna

w celu zmiany wielkości generowanego okna należy zmienić poniższe stałe (domyślnie są one ustawione na full HD) zmiana wielkość okna jest jeszcze eksperymentalna

```c++
    const int window_w = 1920;
    const int window_h = 1080;
```

### menu

kliknięcie w "wygeneruj nowy labirynt" wygeneruje nowy labirynt  

kliknięcie w "zmien rozmiar labiryntu" pozwoli zmienić wielkość labiryntu

kliknięcie w "najdz najkrotsza droge metoda dijkstry" umożliwi nam rozwiązanie labiryntu, zostaniemy poproszeni o wybranie pola startowego i końcowego (uwaga dla dużych labiryntów trasa nie rysuje się poprawnie)

## przykładowe wygenerowane labirynty

### graficzna reprezentacja

#### labirynt 4x4

![labirynt 4x4](https://github.com/kamkamkil/MazeGenerator/blob/master/pictures/4x4.png )

#### labirynt 5x5

![labirynt 5x5](https://github.com/kamkamkil/MazeGenerator/blob/master/pictures/5x5.png )

#### labirynt 10x15

![labirynt 10x15](https://github.com/kamkamkil/MazeGenerator/blob/master/pictures/10x15.png )

#### labirynt 20x25

![labirynt 20x25](https://github.com/kamkamkil/MazeGenerator/blob/master/pictures/20x25.png )

### reprezentacjia ASCII

#### labirynt  4x4

```bash
xxxxxxxxx
x   x x x
x x x x x
x x x   x
x x xxx x
x x   x x
x xxx x x
x   x   x
xxxxxxxxx
```

#### labirynt  10x10

```bash
xxxxxxxxxxxxxxxxxxxxx
x         x x     x x
x xxxxxxx x x xxx x x
x x     x   x x   x x
x x xxx xxx xxx xxx x
x   x   x x x   x   x
xxxxx xxx x x xxx x x
x   x x     x x   x x
x x x x xxxxx x xxx x
x x x x     x x   x x
x x x x xxxxx xxxxx x
x x   x x   x   x   x
x xxxxxxx x xxx x xxx
x         x   x x   x
x xxxxxxxxxxx x x x x
x   x       x   x x x
xxx x x xxx xxxxxxx x
x   x x x x     x   x
x xxxxx x xxxxx x x x
x       x         x x
xxxxxxxxxxxxxxxxxxxxx
```

## aktualne limitacje

- generowanie w trybie ASCII nie zawsze jest poprawne
- kiedy labirynt jest szery niż wysoki generuje się na menu tekstowy
