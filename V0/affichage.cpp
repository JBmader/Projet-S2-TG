#include <iostream>
#include <allegro.h>

using namespace std;

void chaine1(struct BITMAP* fond_menu, struct BITMAP* buffer, bool* menu_state, bool* chaine1_ok)
{
    if ((mouse_b&1))
        {
            if((mouse_x>10)&&(mouse_x<60))
            {
                /// On clique sur CHAINE 1
                if((mouse_y>15)&&(mouse_y<60))
                {
                    cout << "Retourn menu" << endl;
                    *menu_state=true;
                    *chaine1_ok=false;
                    clear_bitmap(screen);
                    blit(fond_menu,buffer,0,0,0,0,900,640);
                }

            }
        }
}

void chaine2(struct BITMAP* fond_menu, struct BITMAP* buffer, bool* menu_state, bool* chaine2_ok)
{
    if ((mouse_b&1))
        {
            if((mouse_x>10)&&(mouse_x<60))
            {
                /// On clique sur CHAINE 1
                if((mouse_y>15)&&(mouse_y<60))
                {
                    cout << "Retourn menu" << endl;
                    *menu_state=true;
                    *chaine2_ok=false;
                    clear_bitmap(screen);
                    blit(fond_menu,buffer,0,0,0,0,900,640);
                }

            }
        }
}

void chaine3(struct BITMAP* fond_menu, struct BITMAP* buffer, bool* menu_state, bool* chaine3_ok)
{
    if ((mouse_b&1))
        {
            if((mouse_x>10)&&(mouse_x<60))
            {
                /// On clique sur CHAINE 1
                if((mouse_y>15)&&(mouse_y<60))
                {
                    cout << "Retourn menu" << endl;
                    *menu_state=true;
                    *chaine3_ok=false;
                    clear_bitmap(screen);
                    blit(fond_menu,buffer,0,0,0,0,900,640);
                }

            }
        }
}



void menu(struct BITMAP* fond_menu, bool* menu_state, struct BITMAP* chaine, struct BITMAP* buffer, bool* chaine1_ok, bool* chaine2_ok, bool* chaine3_ok)
{
    if (*menu_state==true)
{
    blit(fond_menu,buffer,0,0,0,0,900,640);

        // Pour la chaine 1
        if ((mouse_b&1))
        {
            if((mouse_x>360)&&(mouse_x<800))
            {
                /// On clique sur CHAINE 1
                if((mouse_y>50)&&(mouse_y<140))
                {
                    blit(chaine,buffer,0,0,0,0,900,640);
                    cout << "Chaine 1" << endl;
                    *menu_state=false;
                    *chaine1_ok=true;
                }
            }
        }

        // Pour la chaine 2
        if ((mouse_b&1))
        {
            if((mouse_x>175)&&(mouse_x<620))
            {
                /// On clique sur CHAINE2
                if((mouse_y>215)&&(mouse_y<300))
                {
                    blit(chaine,buffer,0,0,0,0,900,640);
                    cout << "Chaine 2" << endl;
                    *menu_state=false;
                    *chaine2_ok=true;
                }
            }
        }

        // Pour la chaine 3
        if ((mouse_b&1))
        {
            if((mouse_x>370)&&(mouse_x<800))
            {
                /// On clique sur CHAINE3
                if((mouse_y>380)&&(mouse_y<460))
                {
                    blit(chaine,buffer,0,0,0,0,900,640);
                    cout << "Chaine 3" << endl;
                    *menu_state=false;
                    *chaine3_ok=true;
                }
            }
        }

        // Pour les instructions
        if ((mouse_b&1))
        {
            if((mouse_x>40)&&(mouse_x<260))
            {
                /// On clique sur INSTRUCTIONS
                if((mouse_y>565)&&(mouse_y<600))
                {
                    cout << "Instructions" << endl;
                    *menu_state=false;
                }
            }
        }

        // Pour quitter
        if ((mouse_b&1))
        {
            if((mouse_x>740)&&(mouse_x<860))
            {
                /// On clique sur QUITTER
                if((mouse_y>560)&&(mouse_y<610))
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
