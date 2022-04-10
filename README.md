# OpenGlRendu : Projet IGAI M1


Projet d'application openGL permettant de tracer et visualiser des courbes et/ou surfaces de Béziers.
Projet réaliser sur l'IDE CLion.

![animatedGIF](https://user-images.githubusercontent.com/82021702/162616665-9205229e-71dc-4933-be03-138a89ad7a7b.gif)

# Réccupération & installation :

Réccupération via commandes git puis build avec Cmake :

cmake --build CLionProjects/OpenGlRendu/cmake-build-debug --target helloWindow

dépendances : GLFW Glad X11


# Fonctionnalités: 

- Courbes de Bézier : 

    Mise en place d'une méthode de discrétisation de l'espace paramétrique pour l'approximation de la courbe par des segments de droite uniforme dans   l'espace paramétrique (à partir du nombre de segment donné par l'utilisateur)
- Visualisation de la courbe et de son polygone de contrôle
- Surface de Béziers :

   Discrétisation de la surface avec définition des attributs suivants sur les sommets (position,normale)
- Visualisation des surfaces selon 2 modes :

    Ombrage diffus (Lambertien) simple en considérant une seule source de lumière

    Visualisation de la normale (interpolée) sur la surface
    
- Rendu temps réel :

    Version demandée avec les paramètres donnés de façon simple (pas de textures)

    Mise en place d'un éclairage 3 points sur un fond uni.
    
    
# Problèmes rencontrés : 

Assez fier de mes résultats, il manque cependant quelques fonctionnalités qui n'ont pas pu être développés à temps et qui seront ajoutés par la suite si mes problèmes trouvent solutions. Projet que je continuerai à mes heures perdues.

TODO:

- Ajout de texture à la courbe.
- Ajout d'une deuxième méthode Uniforme en longueur de segment (tentative faite en faisant une dichotomie)
- Fixation des lumières par rapport à la caméra 
- Implantation d'un modèle de réflectance à microfacette selon la spécification donnée en annexe B de la spécification GLTF 2.0
- Ajout d'une interface graphique ImGui (en cours)






    
  
