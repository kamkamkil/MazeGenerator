# generator labiryntów

## opis programu

program służy do generowania labiryntów metodą "Recursive backtracker" oraz do wyświetlania ich za pomocą biblioteki sfml (ele jest też opcja wyświetlania ich w postaci ASCII)

## instalacja

UWAGA KOMPILATOR MSVC NIE JEST WSPIERANY

do kompilacji programu wymagany jest program cmake, niestety nie wiem jak przygotować odpowiedniego makefile. W celu kompilacji programu należy wejść do pliku build, następnie dzięki komendzie cmake .. wygeneruje nam się plik konfiguracyjny naszego kompilatora (na przykład make). Na linuxsie możliwe że trzeba doinstalować dodatkowe pakiety ([więcej](https://www.sfml-dev.org/tutorials/2.5/compile-with-cmake.php)).

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

![labirynt 5x5](pictures\5x5.png )

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

- aktualnie za każdym razem generuje się ten sam labirynt

- generowanie w trybie ASCII nie zawsze jest poprawne
