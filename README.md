# philosophers

### Mon WIP sur le probleme des philosophes.

Le sujet :

[philosubjects.pdf](https://github.com/leitn/philosophers/files/12674668/philosubjects.pdf)

### Current Issues
- J'utilise un simple usleep, mais on me dit que c'est de la merde, mais chez moi ca marche.

### Problemes nuls
- Norme (trop de fonctions par fichier) (commentaires qui trainent) (trop de lignes sur quelques fonctions)
- Organisation : c'est le bazard.
- fonctions die.c en trop :  is_someone_dead(t_data *data);  inutile maintenant.

### Les bons points
- Mon Makefile range les objets dans un dossier qu'il cree a l'execution. Youpi.
- check la prio OK
- check les overflows OK
- Mon parsing a une meilleure gueule OK

### Test qui passent pas
- ./philo 200 410 200 200 - doit tourner 40 secondes au moins
- ./philo 200 410 200 80 - idem

### Tests a faire apres chaque changement
- 5 800 200 150 : doivent vivre au moins 40 secondes
- 5 800 200 200  : doivent vivre au moins40 secondes
- 3 610 200 80 : doivent vivre au moins 40 secondes
- 3 610 200 200 : doivent vivre au moins 40 secondes
- 199 610 200 80 : idem
- 200 410 200 80 : idem
- 200 410 200 200 : idem

### En correction, attention :
- Ce test
./philo 5 800 200 200 7 | grep -c "is eating"
37

-> c'est normal. C'est AU MOINS 7 fois, pas "7 fois et pas une fois de plus".

### Parsing
- ./philo 0 800 200 200. Attendu: (invalid arguments) : OK
- ./philo 5 "   200    " 200 200. Attendu : ???? . Chez moi : Invalid Argument.
- Toutes variations d'espaces : Invalid Argumnment.
- ./philo 5. Attendu : ?. Chez moi : Invalid Argument.

