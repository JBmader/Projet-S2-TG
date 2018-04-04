#include <iostream>
#include <allegro.h>
#include "affichage.h"

using namespace std;

int main()
{
    ///Initialisation d'Allegro
    allegro_init();
    install_keyboard();
    install_mouse();
    bool menu_state=true;
    bool chaine1_ok=false;
    bool chaine2_ok=false;
    bool chaine3_ok=false;
    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,900,640,0,0))
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    srand(time(NULL)); // Alétatoire
    show_mouse(screen);

    ///Initialisation de nos BITMAPs ici
    BITMAP* fond_menu, *chaine, *buffer;

    fond_menu=load_bitmap("images/menu.bmp", NULL);
    chaine=load_bitmap("images/chaine.bmp", NULL);
    buffer=create_bitmap(900,640);

    ///Test des images.

    if (!fond_menu)
    {
        allegro_message("ERREUR DE CHARGEMENT DE L'IMAGE menu");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    if (!chaine)
    {
        allegro_message("ERREUR DE CHARGEMENT DE L'IMAGE chaine");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    ///Boucle de "jeu"
    while (!key[KEY_ESC])
    {
        menu(fond_menu, &menu_state, chaine, buffer, &chaine1_ok, &chaine2_ok, &chaine3_ok);
        if (chaine1_ok==true){chaine1(fond_menu, buffer, &menu_state, &chaine1_ok);}
        if (chaine2_ok==true){chaine2(fond_menu, buffer, &menu_state, &chaine2_ok);}
        if (chaine3_ok==true){chaine3(fond_menu, buffer, &menu_state, &chaine3_ok);}

        blit(buffer,screen, 0, 0, 0, 0, 900, 640);
    }
    cout << "Bye bye" << endl;
    return 0;
}
END_OF_MAIN();
