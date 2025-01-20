# <p align="center">SOLONG [Projet 42]</p>

<div align="center">
	<table>
		<tr><th>NOTE</th>
		<th>ENGLISH VERSION</th></tr>
		<tr><th><img src="https://github.com/mgayout/mgayout/blob/main/img/note/125.png" height="100"></th>
		<th><a href= "https://github.com/mgayout/so_long/blob/main/eng/README.md"><img src="https://github.com/mgayout/mgayout/blob/main/img/english.png" height="100"></a></th></tr>
	</table>
</div>

Le projet `SO_LONG` est un jeu en 2D, réalisé avec la bibliothèque graphique `Minilibx` (fournit par 42).

Selon le sujet, le but de ce jeu est de collecter des `items` sur la `map` et de prendre la `sortie`.

Voici quelques exemples de fonctionnalité demandées par le sujet de `SO_LONG` :

* Se déplacer dans les 4 directions (Haut, Bas, Gauche et Droite)

* Afficher le compte total de déplacement dans le terminal

* La touche `ECHAP` (ou `ESC`) permet de quitter proprement le jeu

* La carte jouée doit contenir au minim 1 `entrée` (position de départ), 1 `sortie` et un `item`

En plus de l'utilisation d'une bibliothèque graphique, le projet `SO_LONG` nous permet de comprendre l'utilisation d'une structure et de la gestion d'erreurs.

### <p align="center">BONUS_PART</p>

La partie `bonus` de ce projet comprends les 3 choses suivantes :

* Le joueur peut perdre la partie si il est touché par un ennemie

* Le jeu doit contenir des `sprite animations`

* Le compte total de déplacement doit être afficher directement dans la fenètre de jeu

<p align="center"><img width="600" src="clip/game.gif"></p>

## <p align="center">INSTALLATION</p>

`make` permet de télécharger les librairies `LIBFT`, `FT_PRINTF`, `GETNEXTLINE` et `MINILIBX` et d'en compiler le contenue afin de créer l'executable `so_long`.

`make bonus` permet de compiler mes fichiers `bonus` afin de créer l'executable `so_long_bonus`.

`make clean` permet de supprimer tout les fichiers objets.

`make fclean` reprends le principe de `make clean` en supprimant en plus l'executable `so_long`.

`make re` reprends le principe de `make fclean` en compilant de nouveau.

`make rebonus` reprends le principe de `make fclean` en compilant de nouveau mes fichiers `bonus`.

# TEST

Pour tester ce programme il vous suffit de mettre le chemin vers une map (fichier .ber), comme ceci :

`./so_long chemin/vers/la/map.ber`

