# Pentago
Pentago in C with GTK3

Zasady:
Ułóż pięć swoich kulek z rzędu w pionie, w poziomie lub na skos, aby pokonać przeciwnika!

Kompilacja:

Windows:
gcc -std=c99 -Wall -o gtk-talk gtk-talk.c win-fifo.c `pkg-config gtk+-3.0 --cflags --libs`

Linux/MacOS:
gcc -std=c99 -Wall -o gtk-talk gtk-talk.c lin-fifo.c `pkg-config gtk+-3.0 --cflags --libs`

Po skompilowaniu należy uruchomić program dwukrotnie, pierwsza kopia z parametrem A, druga z parametrem B.

Windows: 

pentago Ax

pentago Bx

Linux/MacOS:

./pentago Ax

./pentago Bx

Gdzie x to 4 lub 6. Aby zagrać należy uruchomić grę z takim samym x.
