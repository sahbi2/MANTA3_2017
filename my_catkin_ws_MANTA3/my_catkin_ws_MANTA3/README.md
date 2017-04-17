MANTA3 Git Repository
======

Le projet MANTA
---------------------


MANTA est un projet dont l’un des aspects vise à développer un drone de surface autonome, ou USV, pouvant cartographier les fonds subaquatiques de profondeur réduite.
Le drone doit être capable de se repérer grâce à la fusion de ses données GPS et IMU mais aussi d’éviter les obstacles l’entourant en les détectant via un télémètre laser. 
Son échosondeur renvoie la profondeur sous le drone, permettant ainsi de dresser des cartes des fonds.

Technologie et implémentation
-----------------------------
Les moteurs sont contrôlés par un Arduino Due et 2 ESC ( Electronic Speed Controller ) qui sont les drivers des moteurs.

L’implémentation logicielle est faite sur une Rapsberry Pi 2 et utilise le framework ROS pour réunir les données des différents capteurs et contrôler les actionneurs. 


Perspectives de développement
-----------------------------

La direction que nous recommandons de suivre pour développer le drone est la suivante :

Commencer par installer proprement un nouvel environnement ROS. 
Le code de base intégrant les capteurs et permettant la navigation devrait être fonctionnel.
Seule la fusion des données de localisation ne fonctionne pas car elle ne reçoit pas les bons formats de données sur les topics gps et imu.
Demandez de l’aide à François Pessaux pour tout ce qui est configuration de la RPi.
Particulièrement pour les aspects réseau et connection aux proxi qui nous ont posés problème.

Ensuite il faut faire fonctionner la fusion des données afin d’avoir une localisation plus précise.
Cela permettra d’implémenter les premières fonctions de base de la navigation autonome.
Pour commencer à développer le comportement autonome du drone nous recommandons de réaliser les étapes suivantes dans l’ordre proposé :

-réaliser une fonction qui permette au drone de rejoindre une coordonnée GPS en particulier.
Il s’agit réaliser une fonction qui calcule les commandes moteurs nécessaires à rejoindre la destination demandée. 
Le noeud ROS de commande des moteurs devra, à une fréquence donnée, corriger l’orientation du drone en fonction des nouvelles positions et orientation actuelle.
Il devra s’assurer que le drone pointe vers la destination puis avancer tout droit sans se soucier d’éventuels obstacles.

-optimiser l’utilisation du télémètre laser ( il faudra aller le demander à David Filliat ) afin de développer des algorithmes de contournement d’objet.
Cette étape est primordiale pour le développement d’un drone dont le comportement sera autonome ou semi-autonome.
Nous vous recommandons de référer à David Filliat pour qu’il vous guide sur la marche à suivre.

-Enfin il s’agira de développer les algorithmes de navigation permettant au drone de cartographier de manière autonome un périmètre.
Ce périmètre peut être définit à la manière de votre choix ( par des coordonnées GPS ou un rayon autour du drone par exemple ).
De nouveau, David Filliat est la référence en la matière à l’U2IS, n’hésitez pas à aller lui demander conseil.

WARNING : 
Il ne faut pas tester les moteurs hors de l’eau ! En effet ils se servent de l’eau comme lubrifiant.

