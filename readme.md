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

[labirynt 4x4][pictures\5x5.png ]
