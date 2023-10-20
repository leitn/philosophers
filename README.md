# philosophers

### Mon WIP sur le probleme des philosophes.

Le sujet :

[philosubjects.pdf](https://github.com/leitn/philosophers/files/12674668/philosubjects.pdf)

### Current Issues
- Norme (trop de fonctions par fichier) (commentaires qui trainent) (trop de lignes sur quelques fonctions)

### Les bons points
- Mon Makefile range les objets dans un dossier qu'il cree a l'execution. Youpi.
- check la prio OK
- check les overflows OK
- Mon parsing a une meilleure gueule OK
- Passe tous les tests de Thales sauf 1

### Test qui passent pas
- ./philo 200 410 200 200 - doit tourner 40 secondes au moins


### En correction, attention :
- Ce test
./philo 5 800 200 200 7 | grep -c "is eating"
37

-> c'est normal. C'est AU MOINS 7 fois, pas "7 fois et pas une fois de plus".


