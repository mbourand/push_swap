# push_swap

_Ce programme cherche le minimum d'opérations nécessaires pour trier par ordre croissant une pile d'éléments._

<br/>

## Qu'est-ce qu'une pile
Une pile est une façon de socker des éléments dans laquelle on ne peut accéder qu'au haut de la pile : lorsqu'on ajoute un élément, il est placé en haut de la pile, et on ne peut retirer que l'élément en haut de la pile. Ce type de stockage est souvent appelé [stockage Last In First Out (LIFO)](https://fr.wikipedia.org/wiki/Last_in,_first_out)

<br/>

## Règles
Lorsque le programme se lance, on lui donne une liste de nombres en arguments, pour trier cette liste, il utilise deux piles : **a** et **b**. Les nombres sont initialisés dans **a** au lancement du programme.

Les opérations autorisées pour trier la liste sont :
| Opération   | Description                                        |
|:-----------:|:--------------------------------------------------:|
| sa/sb/ss    | Echange les deux premiers éléments de a/b/les deux |
| pa/pb       | Place le premier élément de a/b en haut de b/a     |
| ra/rb/rr    | Monte tous les éléments de a/b/les deux d'un cran  |
| rra/rrb/rrr | Descend tous les éléments de a/b/les deux d'un cran|

<br/>

## Les deux exécutables
Les tâches de ce projet sont réparties en deux exécutables : **checker** et **push_swap** :

**push_swap** est l'exécutable qui se charge de la recherche des opérations à effectuer.
**checker** est celui qui vérifie si, après les opérations de push_swap, la liste est bien triée, il propose aussi des informations avec l'option **-v**

<br/>

## Utilisation
1. Clonez le dépôt [ ```git clone https://www.github.com/mbourand/push_swap``` ]
2. Compilez le projet [ ```make``` ]
3. Lancez le programme
   - [ ```./push_swap -52 5 87 69 15 28 ...``` ]
   - Pour connaître le nombre d'opérations [ ```./push_swap -52 5 87 69 | wc -l``` ]
   - Pour vérifier si la liste est triée [ ```ARG="-52 5 87 69 ..."; ./push_swap $ARG | ./checker [-v] $ARG``` ]
