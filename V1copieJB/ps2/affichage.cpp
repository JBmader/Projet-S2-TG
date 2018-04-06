#include <iostream>
#include <allegro.h>
#include "graph.h"

using namespace std;

void menu(struct BITMAP* fond_menu, bool* menu_state, bool* chaine1_ok, bool* chaine2_ok, bool* chaine3_ok, bool* maj, Graph& g1, Graph& g2, Graph& g3)
{
    if (*menu_state==true)
{
    blit(fond_menu,screen,0,0,0,0,1024,768);

        // Pour la chaine 1
        if ((mouse_b&1))
        {
            if((mouse_x>410)&&(mouse_x<900))
            {
                /// On clique sur CHAINE 1
                if((mouse_y>60)&&(mouse_y<150))
                {
                    cout << "Chaine 1" << endl;
                    *menu_state=false;
                    *chaine1_ok=true;
                    *maj=true;
                    g1.charger_inter();
                }
            }
        }

        // Pour la chaine 2
        if ((mouse_b&1))
        {
            if((mouse_x>200)&&(mouse_x<700))
            {
                /// On clique sur CHAINE2
                if((mouse_y>245)&&(mouse_y<335))
                {
                    cout << "Chaine 2" << endl;
                    *menu_state=false;
                    *chaine2_ok=true;
                    g2.charger_inter();
                    *maj=true;
                }
            }
        }

        // Pour la chaine 3
        if ((mouse_b&1))
        {
            if((mouse_x>420)&&(mouse_x<910))
            {
                /// On clique sur CHAINE3
                if((mouse_y>440)&&(mouse_y<530))
                {
                    cout << "Chaine 3" << endl;
                    *menu_state=false;
                    *chaine3_ok=true;
                    g3.charger_inter();
                    *maj=true;
                }
            }
        }

        // Pour les instructions
        if ((mouse_b&1))
        {
            if((mouse_x>40)&&(mouse_x<300))
            {
                /// On clique sur INSTRUCTIONS
                if((mouse_y>640)&&(mouse_y<700))
                {
                    cout << "Instructions" << endl;
                    *menu_state=false;
                }
            }
        }

        // Pour quitter
        if ((mouse_b&1))
        {
            if((mouse_x>840)&&(mouse_x<985))
            {
                /// On clique sur QUITTER
                if((mouse_y>635)&&(mouse_y<700))
                {
                    cout << "Quitter" << endl;
                    *menu_state=false;
                    clear_bitmap(screen);
                    allegro_exit();
                    exit(EXIT_SUCCESS);
                }
            }
        }
    }
}
