# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    README.md                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: massah <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/03 16:57:54 by massah            #+#    #+#              #
#    Updated: 2026/04/03 16:57:56 by massah           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

                *This project has been created as part of the 42 curriculum by <massah>.*

# Description:

	So_long est le premier projet videoludique du cursus 42.

	Son objectif est de creer un jeu en 2D avec l'aide de la librairie minilbx-linux fournie.

	Concrètement, les principaux enjeux reposent sur une comprehension des fonctions mises a disposition pour gerer l'interface du jeu (ouverture et fermeture de fenetre selon conditions), l'utilisation de hooks qui permettent de produire un effet a l'ecran et l'utilisation d'algorithmes qui permettent de determiner la validite de la map fournie au programme.

**Fonctionnalités:**

    Dans le cadre de la validation de la partie obligatoire du projet, seules les fonctionnalites de base ont ete implementees :

	- Fermeture du programme en cliquant sur la croix de la fenetre ou en appuyant sur la touche ESC
	- Deplacements du joueur possible grace aux fleches directionnelles du clavier
	- Gestion des collisions avec les murs
	- Sortie accessible uniquement une fois que tous les collectibles de la map ont ete recuperes
	- Compteur de mouvements affiche dans le terminal

# Instructions:

1) Cloner le dépôt
2) Compiler avec make
3) Exécuter le programme so_long en lui fournissant une map:
    ./serveur map.ber
4) Une nouvelle fenetre s'ouvre, vous pouvez jouer !

# Ressources:

- Sujet officiel So_long (42)
- Manuel Linux
- Minilibx

**Utilisation de l’IA:**

    Des outils d’intelligence artificielle ont été utilisés pour :

    1) Comprendre les fonctions de la minilibx
    2) Effectuer une relecture du code

    Toutes les décisions algorithmiques, l’implémentation, les tests et la validation finale ont été réalisés manuellement.
