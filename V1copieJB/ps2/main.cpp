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



    /// Le nom du r�pertoire o� se trouvent les images � charger
    //grman::set_pictures_path("chaine1");
    grman::set_pictures_path("images");


    /// Un exemple de graphe
    Graph g1, g2, g3;

     bool maj=false;
    /// Vous gardez la main sur la "boucle de jeu"
    /// ( contrairement � des frameworks plus avanc�s )
    while ( !key[KEY_ESC] )
    {

        menu(fond_menu, &menu_state, &chaine1_ok, &chaine2_ok, &chaine3_ok, &maj, g1, g2, g3);
        /// Il faut appeler les m�thodes d'update des objets qui comportent des widgets
        if (chaine1_ok==true)
        {
            g1.update(menu_state, maj, chaine1_ok, chaine2_ok, chaine3_ok);
        }

        if (chaine2_ok==true)
        {
            g2.update(menu_state, maj, chaine1_ok, chaine2_ok, chaine3_ok);
        }


        if (chaine3_ok==true)
        {
            g3.update(menu_state, maj, chaine1_ok, chaine2_ok, chaine3_ok);
        }


        /// Mise � jour g�n�rale (clavier/souris/buffer etc...)
        grman::mettre_a_jour(&maj);
    }

    grman::fermer_allegro();

    return 0;
}
END_OF_MAIN();


