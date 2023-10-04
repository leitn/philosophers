/*

MAIN.c :
Check args
Init data
Lancer routine

ROUTINE :
- gettime
while (++i < nb_of_philos)
	{
		if (pthread_create(&data->philo_ths[i], NULL,
				&routine, &data->philos[i]))
			return (1);
	}

- Une fonction qui estime si le philo est mort

- Une fonction eat
	- Une fonction Take Fork
	- Une fonction Drop Fork
	- Compter le nombre de repas manges par philosophe

- Une fonction sleep

- Une fonction think

- Une fonction Ce philosophe est-il mort ? (thread principal, PAS individuels)

- Gestion des erreurs


*/
