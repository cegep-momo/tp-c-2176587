Interface et Expérience Utilisateur:
- Confirmation avant suppression de livres.

Gestion des Données:
- Import/Export CSV pour faciliter la gestion en lot (en plus du format actuel).
    - Ajout d'un boutton pour exporter en CSV.
    - Ajout d'un boutton pour switch le mode d'import.

Bonus:
- Logs d’activité avec sauvegarde dans un fichier.

# Question 1 : C++

Nous n’avons pas vu l’écriture de fichiers en classe. Pour écrire des fichiers, il est nécessaire d’utiliser la library `fstream` en déclarant `#include <fstream>` en haut de notre fichier cpp. La library `fstream` est une library du genre *stream* (comme `iostream` et `sstream`) dédiée à la modification de fichiers contenant plusieurs classes très utiles telles que `filebuf`, `fstream`, `ifstream` et `ofstream`.

Pour lire le contenu d’un fichier avec `fstream`, on va faire usage de la classe `ifstream` (dont le nom est une contraction de la phrase *input file stream*) qu’on va déclarer en tant qu’objet:
```
ifstream nomDuInputFileStream(nomDuFichierALire);
```

Par la suite, nous pouvons, avec la méthode `getline()`, récolter la première ligne de ce fichier texte à l’aide de notre objet `ifstream` et stocker le contenu de cette ligne dans une variable:
```
// va lire la première ligne et la stocker dans la variable stringLigne
getline(nomDuInputFileStream, stringLigne); 
```

Réexécuter cette méthode nous permettra de lire les lignes suivantes:
```
// va lire la deuxième ligne et la stocker dans la variable stringLigne
getline(nomDuInputFileStream, stringLigne);
// va lire la troisième ligne et la stocker dans la variable stringLigne
getline(nomDuInputFileStream, stringLigne);
```

À l’aide de la classe `ios`, il est également possible de changer la déclaration de notre `ifstream` pour commencer la lecture par la dernière ligne du fichier:
```
ifstream nomDuInputFileStream(nomDuFichierALire, ios::ate);
getline(nomDuInputFileStream, stringLigne); // dernière ligne
getline(nomDuInputFileStream, stringLigne); // avant-dernière ligne
getline(nomDuInputFileStream, stringLigne); // avant-avant-dernière ligne
```

Pour écrire dans un fichier avec `fstream`, on va faire usage de la classe `ofstream` (dont le nom est une contraction de la phrase *output file stream*) qu’on va déclarer en tant qu’objet:
```
ofstream nomDuOutputFileStream(nomDuFichierOuEcrire);
```

Par la suite, nous pouvons, avec la méthode et l’opérateur d’insertion `<<`, écrire sur la première ligne de ce fichier texte à l’aide de notre objet `ofstream`:
```
nomDuOutputFileStream << "bonjour" ;
// le fichier contiendra maintenant le texte "bonjour" dans sa première ligne
```

Réexécuter cette ligne réécrira par-dessus la première ligne et supprimera ce qu’elle contenait avant:
```
nomDuOutputFileStream << "salut" ;
// le fichier contiendra maintenant le texte "salut" dans sa première ligne
```

À l’aide de la classe `ios`, il est également possible de changer la déclaration de notre `ofstream` pour empiler les lignes une en dessous de l’autre:
```
ofstream nomDuOutputFileStream(nomDuFichierALire, ios::app);
nomDuOutputFileStream << "salut" ; // ligne 1
nomDuOutputFileStream << "bonjour" ; // ligne 2
nomDuOutputFileStream << "hello" ; // ligne 3
```

>Il existe aussi d’autres membres de la classe `ios` tels que `ios::trunc` pour supprimer le contenu complet du fichier et `ios::binary` pour écrire des binaires.

Pour s’assurer de ne pas avoir de crash lors de notre lecture ou écriture, il est recommandé d’utiliser la méthode `.is_open()` de `ifstream` et `ofstream`:
```
if (!fstream.is_open()) {
    cout << "message d’erreur";
    return false;
}
// exécution du reste du code
```

Et finalement, lorsqu’on a fini avec notre `ifstream`/`ofstream`, on peut le fermer avec la méthode `close()` qui va nous permettre de garantir que toutes nos données sont bien écrites et de libérer de l’espace en mémoire:
```
fstream.close();
```

# Question 2 : Options de développement possible

En présupposant que la bibliothèque va à tout jamais préserver la même structure de données stable, je recommanderais de migrer les données des livres et des utilisateurs vers une base de données qui soit relationnelle et plus fiable que de simples fichiers texte. Je serais incliné à choisir **PostgreSQL** en raison de sa réputation pour sa fiabilité, son intégrité des données et son excellent système de récupération de données après une panne. Cela permettra à la bibliothèque d’augmenter sa user base en toute sécurité et permettra de préserver le système de recherche de livres, qui serait trop lent s’il était implémenté sur une base de données TXT contenant plus de livres. Il serait également possible d’implémenter une **interface web** pour que les clients puissent voir quels livres sont disponibles, réserver des livres ou simplement rechercher des informations sur des livres telles que les auteurs et la date de publication. Ce front-end serait programmé en **ReactJS** et utiliserait une version **RESTful** de notre programme **C++**. Finalement, je recommanderais une interface **CLI** écrite en **Python** pour les administrateurs. Je crois que Python est un bon langage pour cette tâche en raison de sa facilité à s’intégrer avec d’autres systèmes, de sa constante flexibilité (la possibilité de modifier le script en cas de besoin d’une nouvelle fonctionnalité) et de sa capacité exceptionnelle à automatiser via ses libraries.