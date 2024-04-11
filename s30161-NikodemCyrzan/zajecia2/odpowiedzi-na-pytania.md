# Ćwiczenie 2

## Co się stało? Czy potrafisz wyjaśnić?

```bash
X=tekst
echo $X
bash
echo $X
```

- Utworzono zmienna lokalną X o wartości "tekst".
- Wypisano wartość zmiennej X, rezultat to: tekst
- Uruchomiono podpowłokę
- Próbowano wypisać wartość zmiennej X, ale podpowłoka nie ma do niej dostępu

&ensp;

## Co jest nie tak? jak to naprawić? 

```bash
X=Tekst dłuższy
echo $X
```

Aby użyć w ciągu zawierającego znaki białe, należy otoczyć go czudzysłowami, lub apostrofami. Rozwiązanie:

```bash
X="Tekst dłuższy"
echo $X
```

Lub

```bash
X='Tekst dłuższy'
echo $X
```

&ensp;

# Jaka jest różnica między " a ' ?

```bash
X="Tekst 1"
Y="tekst:$X"
echo "$Y"
Y='tekst:$X'
echo "$Y"
Y=tekst:$X
echo "$Y"
```

Ciąg otoczony apostrofami nie jst ciągiem interpretowalnym. 
Ciąg otoczony cudzysłowiami natomiast jest ciągiem interpretowalnym, czyli nazwy zmiennych będą zamieniane na ich wartości, a znaki specjalne interpretowane.

&ensp;

# Różnica między `$*` a `$@`

Aby przetestować czym różnią się te zmienne, wystarczy przygotować prosty skrypt:

`test.sh`
```bash
for a in "$*";
do
  echo $a
done


for a in "$@";
do
  echo $a
done
```

`terminal`

```terminal
bash test.sh 1 2 3 4
1 2 3 4
1
2
3
4
```

Z rezultatu można wywniosokwać, że `$*` traktuje wszystkie argumenty jako jeden ciąg, natomiast `$@` dzieli je na osobne argumenty.

Ćwiczenie 3

## `PATH`

Zmienna która określa gdzie bash powinien szukać skryptów, których można używać niezależnie od ścieżki roboczej.

## `RANDOM`

Zmienna która za każdym razem przedstawia inną liczbę całkowitą z zakresu 0-32767. Przydatne tam
gdzie jest potrzebna jakaś losowość.

## `PWD`

Zmienna przechowująca aktualną ścieżkę roboczą. Przydatne na przykład do tworzenia ścieżek bezwzględnych.

## `PS1`

Zmienna przechowująca aktualne ustawienia prompta, na przykład zmienienie jej:

```bash
PS1="test|$USER: "
```

Spowoduje, że w terminalu przed miejscem w którym można wprowadzać tekst, będzie pojawiać się takie coś:

```terminal
test|username: 
```

Umożliwia to stworzenie własnego prompta wyświetlającego jakieś przydatne informacje.

## `USER`

Nazwa aktualnego użytkownika. Może być przydatna do sprawdzenia który użytkownik używa skryptu, ale dużo bezpieczniejsze byłoby użycie `$(whoami)`,
ponieważ `$USER` można nadpisać

## `HOSTNAME`

Nazwa urządzenia

## `OSTYPE`

Umożliwia sprawdzenie na jakim systemie operacyjnym został uruchomiony skrypt.

