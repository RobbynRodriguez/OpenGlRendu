# OpenGlRendu : Projet IGAI M1


Projet d'application openGL permettant de tracer et visualiser des courbes et/ou surfaces de Béziers.
Projet réaliser sur l'IDE CLion.

![animatedGIF](https://user-images.githubusercontent.com/82021702/162616665-9205229e-71dc-4933-be03-138a89ad7a7b.gif)

# Réccupération & installation :

Réccupération via commandes git puis build avec Cmake 

dans le dossier OpenGlRendu :

    mkdir build
    
    cd build

    cmake ..

    make

nécéssite Cmake 3.16 ou supérieur (peut être modifier dans le CmakeList.txt
puis lancement de l'exe dans OpenGlRendu/bin/helloWindow

dépendances : GLFW Glad X11

Racourcis : 

-N : On/Off bloom

-B : On/Off Blinn-Phong

déplacement fait avec Z,Q,S,D 
maj gauche pour descendre
espace pour monter

possibilité de zoomer avec la souris (molette)


# Fonctionnalités ajoutées: 

Bloom, HDR, éclairage microfacette (Blinn-Phong).
    
    
# Problèmes rencontrés : 

  Lors de l'implémentation du bloom, je n'arrivais pas à obtenir le bon résultats, soit j'avais un écran noir, soit que quelque traits lumineux.
  Après en avoir discuter avec un ami, mon problème venait du fait que j'avais oublier de crée un deuxième frame buffer.
  
  Côté animation, je m'y suis mis un peu trop tard ( commencé le 9 mars) car je voulais que mon éclairage ainsi que mon bloom fonctionne.
  
  J'ai quelques classes (Bone et skin) de créer mais rien de finit. Problème au niveau des poids que j'initialise mais que lorsque je veux y accéder, n'existe plus.
  
  Temps estimé Hors TP : 15h rendu, 7h animation



TODO:


- Implantation d'un modèle de réflectance à microfacette selon la spécification donnée en annexe B de la spécification GLTF 2.0 (fait)
- Ajout d'une interface graphique ImGui (echec)
- nettoyage code (URGENT)






    
  
