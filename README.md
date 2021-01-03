# BernardRoxane_LouppeErin

Groupe : BERNARD Roxane et LOUPPE Erin
Lien github : https://github.com/Platypussss/BernardRoxane_LouppeErin.git

Nous avons fait un jeu de plateau en 2D. Le but est de survivre jusqu'à ce que les ennemis soient tous morts. Il faut donc éviter les murs et attaquer les ennemis grâce à des missiles.

Pour se déplacer, il faut utiliser les flèches et la barre d'espace: flèche droite pour aller à droite, flèche gauche pour aller à gauche, flèche du bas pour se baisser (utile pour passer sous les murs), flèche du haut pour se relever, et barre d'espace pour sauter.

En tout, un joueur possède 5 vies. Il en perd une chaque fois qu'il entre en collision avec une ennemi. 
Les ennemis ont été fait de telle sorte qu'ils suivent le joueur dès que celui-ci se trouve à une certaine distance d'un ennemi. 
Pour tuer un ennemi, il faut envoyer des missiles en faisant un clic gauche avec la souris.

Des messages s'affichent en début et en fin de partie pour annoncer que la partie commence et si le joueur a oui ou non gagné. Il y a également un compteur de vies qui est affiché en haut à gauche de l'écran.

Nous avons également mis le makefile à jour.
Pour compiler, il suffit donc d'entrer make dans le terminal, puis de taper ./main. Le jeu se lance automatiquement juste après.
