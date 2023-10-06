# philosophers

### Mon WIP sur le probleme des philosophes.

Le sujet :

[philosubjects.pdf](https://github.com/leitn/philosophers/files/12674668/philosubjects.pdf)

### Current Issues

- Parfois le programme ne s'interrompt pas quand un philo est mort (mais il ne print plus)
- Parfois, un philosophe meurt immediatement.
- Parfois, le programme laisse un philosophe prendre une fourchette apres la mort d'un autre. ( lock stdout ?)

![Screenshot from 2023-10-06 16-18-48](https://github.com/leitn/philosophers/assets/104629160/d55728a5-2a44-4cf1-a0d4-6a44227c8aa0)

- Aucune routine implementee dans le cas ou il n'y a qu'un philosophe
- (cinquieme argument) Je n'ai pas encore de fonction pour interrompre le programme une fois nb_of_meals atteint par tous les philos
- Rien n'est prevu pour gerer la priorite et que les philos affames mangent avant les philosophes rassasies
- Je n'ai pas checke les limites


### Problemes nuls
- Mon parsing est honteux, pourquoi j'ai mis un malloc ?
- Norme (trop de fonctions par fichier) (commentaires qui trainent) (trop de lignes sur quelques fonctions)
- Fonctions doublons et Fonctions non utilisees
- Organisation : certains fichiers sont quasiment vides

### Les bons points
- Mon Makefile range les objets dans un dossier qu'il cree a l'execution. Youpi.

