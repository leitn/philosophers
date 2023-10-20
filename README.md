# philosophers

### Mon WIP sur le probleme des philosophes.

Le sujet :

[philosubjects.pdf](https://github.com/leitn/philosophers/files/12674668/philosubjects.pdf)

### Current Issues
- J'utilise un simple usleep, mais on me dit que c'est de la merde, mais chez moi ca marche.

### Problemes nuls
- Norme (trop de fonctions par fichier) (commentaires qui trainent) (trop de lignes sur quelques fonctions)
- Fonctions doublons et Fonctions non utilisees
- Organisation : c'est le bazard.
- fonctions die.c en trop :  is_someone_dead(t_data *data); et death_status(t_philo *philo);sont inutiles maintenant.

### Les bons points
- Mon Makefile range les objets dans un dossier qu'il cree a l'execution. Youpi.
- check la prio OK
- check les overflows OK
- Mon parsing a une meilleure gueule OK

### Tests OK
- ./philo 5 800 200 200 (doit boucler a l'infini)
- ./philo 1 800 200 200 (doit crever de faim minablement avec une fourchette en main et un bol de spaghettis sur la table )
- ./philo 5 599 200 200 (doit mourir en 600 millisecondes)
- ./philo 200 800 200 200 1 doit afficher "is eating" en dernier.

### Test qui passent pas
- valgrind --tool=helgrind ./philo 4 410 200 200 10
- Helgrind Tests :
- 200 60 60 60
- 199 800 300 100
- 4 410 200 200 10
- 199 610 200 200 10
- 199 610 200 200 10

- 5 800 200 200 7
- 3 800 200 200 7
- 7 800 200 500 7

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

