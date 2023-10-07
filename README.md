# philosophers

### Mon WIP sur le probleme des philosophes.

Le sujet :

[philosubjects.pdf](https://github.com/leitn/philosophers/files/12674668/philosubjects.pdf)

### Current Issues

- Mangent plus que nb_max_meals
- Rien n'est prevu pour gerer la priorite et le fait que les philos affames mangent avant les philosophes rassasies
- Je n'ai pas checke les limites
- J'utilise un simple usleep, mais on me dit que c'est de la merde, donc je partirai en mission pour trouver quelqu'un pour m'expliquer sa fonction ft_usleep. Apres la pause.


### Problemes nuls
- Mon parsing est honteux, pourquoi j'ai mis un malloc ?
- Norme (trop de fonctions par fichier) (commentaires qui trainent) (trop de lignes sur quelques fonctions)
- Fonctions doublons et Fonctions non utilisees
- Organisation : c'est le bazard. Elements inutiles dans mes structures, fichiers quasi vides (coucou free_data.c, think.c et sleep.c) vs fichiers qui ont beaucoup plus que 5 fonctions (coucou get_ingo.c).
- fonction Get Status me creait des segfault, je ne me l'explique pas. Je ne suis pas sure d'avoir encore besoin de l'enum pour les status.
- fonctions die en trop :  is_someone_dead(t_data *data); et death_status(t_philo *philo);sont inutiles maintenant.

### Les bons points
- Mon Makefile range les objets dans un dossier qu'il cree a l'execution. Youpi.
- J'ai des commentaires qui decrivent ce que fait la fonction quand on la survole sur vscode. Je vais devoir les supprimer par contre.

