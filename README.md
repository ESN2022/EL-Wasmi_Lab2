# EL-Wasmi_Lab2
# **Lab2: “Let’s count stuff”**

Dans ce laboratoire, **"Lab 2 : Let's count stuff"**, nous allons commencer par implémenter un compteur décimal à 1 chiffre et l'afficher sur un écran à 7 segments. Nous nous baserons sur cela pour implémenter un compteur décimal à 3 chiffres et l'afficher sur toirs afficheurs 7 segments en utilisant la méthode de pooling au début, et nous améliorerons le code en utilisant un timer en interrupteur. Les étapes que nous suivrons pour réaliser ce projet comprennent la conception de l'architecture, la création d'un système Nios II de base, l'implémentation d'un compteur décimal à 1 et 3 chiffres à l'aide d'un programme C, l'amélioration du code en ajoutant un timer pour contrôler la vitesse d'affichage des chiffres sur l'affichage à 7 segments à une seconde, et l'utilisation de composants matériels ou logiciels pour convertir les nombres en BCD.

# Architecture du système ,

Pour la réalisation de ce lab, j'ai dessiné d'abord l'architecture du système . L'architecture ,end un processeur Nios II, une mémoire RAM, un bloc JTAG pour la communication UART,et un PIO de 12 bits (4 bits pour chaque afficheur à 7 segments) configuré en sortie. J'ai ajouté un composant bin_to_7seg pour convertir les données binaires en données décimales pour les trois afficheur à 7 segments. Enfin, j'ai ajouté un timer qui fonctionne en interruption pour gérer la vitesse de comptage du compteur.

voici image de l'architecture conçue pour ce projet :

![design_lab2](https://user-images.githubusercontent.com/75042681/213027388-d12efb0c-3d03-4d96-9a34-3b3d2c20f1b6.PNG)


# Progression et résultat :

> 1 comit : Mise en place du système de base et création d'un compteur simple :

- Création de l'architecture de base comprenant un processeur Nios II, une mémoire RAM, un bloc JTAG pour la communication UART, ainsi qu'un PIO de 4 bits configuré en sortie pour un seul afficheur .
- Ajout d'un composant bin_to_7seg pour convertir les données binaires en données décimales pour l'afficheur à 7 segments.
--Affectation des broches pour relier les composants entre eux et création d'un fichier VHDL d'initialisation.
- Création de la partie logicielle en utilisant le langage C, pour envoyer des données de test à l'afficheur à 7 segments.
- Validation de la compilation et du bon fonctionnement du système en envoyant une séquence de nombres à l'afficheur à 7 segments et en vérifiant que les bons nombres sont affichés sur l'afficheur à 7 segments.

Exemple d'affichage du nombre 3 :

![test](https://user-images.githubusercontent.com/75042681/213034123-61da35e8-44f4-47d3-8578-e38db07a93ab.jpg)


Passage à l'implémentation d'un compteur à 3 chiffres.

> 2 comit : Implémentation d'un compteur à 3 chiffres avec polling :

- Changement du nombre de bits pour le PIO de sortie à 12 bits dans le système pour contrôler les 3 afficheurs (4 bits par afficheur), modification du fichier d'entête pour affecter à chaque afficheur un composant bin_to_7seg.
- Utilisation d'une fonction en software pour convertir les données en BCD (binary-coded decimal) pour l'affichage sur les afficheurs à 7 segments.
- Création de la partie logicielle pour gérer le comptage en utilisant la méthode de polling.
- Validation de la fonctionnalité du compteur en affichant les résultats sur les afficheurs à 7 segments.

> 3 comit : Amélioration et validation de la partie compteur avec polling :

- Optimisation du code pour améliorer le compteur.
- Tests pour s'assurer que le système fonctionne correctement avec la méthode de polling.
> 4 comit : Implémentation d'un compteur à 3 chiffres avec interruption :

- Ajout de l'interruption de 1 seconde pour le périphérique timer dans l'architecture Qsys.
- Mise en place d'un nouveau code prenant en compte l'interruption pour contrôler la poursuite du compteur, en utilisant les registres appropriés pour configurer le timer Nios II.
- Tests pour s'assurer que le système fonctionne correctement avec l'interruption timer.
- Finalisation de toutes les tâches liées à Lab2 et validation du projet en comparant les résultats avec la méthode de polling et l'interruption.
