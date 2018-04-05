#include "grman/grman.h"
#include <iostream>

#include "graph.h"
#include "affichage.h"


int main()
{
    /// A appeler en 1er avant d'instancier des objets graphiques etc...
    grman::init();

    ///Initialisation des variables pour le menu
    bool menu_state=true;
    bool chaine1_ok=false;
    bool chaine2_ok=false;
    bool chaine3_ok=false;

    ///Initialisation graphique pour le menu
    BITMAP* fond_menu;
    fond_menu=load_bitmap("images/menu.bmp", NULL);
    if (!fond_menu)
    {
        allegro_message("ERREUR DE CHARGEMENT DE L'IMAGE menu");
        allegro_exit();
        exit(EXIT_FAILURE);
    }



    /// Le nom du répertoire où se trouvent les images à charger
    //grman::set_pictures_path("chaine1");
    grman::set_pictures_path("images");


    /// Un exemple de graphe
    Graph g;
    g.chaine1();

     bool maj=false;
    /// Vous gardez la main sur la "boucle de jeu"
    /// ( contrairement à des frameworks plus avancés )
    while ( !key[KEY_ESC] )
    {

        menu(fond_menu, &menu_state, &chaine1_ok, &chaine2_ok, &chaine3_ok, &maj);
        /// Il faut appeler les méthodes d'update des objets qui comportent des widgets
        if (chaine1_ok==true)
        {
            g.update(menu_state, maj);
        }

        /// Mise à jour générale (clavier/souris/buffer etc...)
        grman::mettre_a_jour(&maj);
    }

    grman::fermer_allegro();

    return 0;
}
END_OF_MAIN();


