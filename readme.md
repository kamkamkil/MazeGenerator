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
