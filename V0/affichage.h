#ifndef AFFICHAGE_H_INCLUDED
#define AFFICHAGE_H_INCLUDED

void menu(struct BITMAP* fond_menu, bool* menu_state, struct BITMAP* chaine, struct BITMAP* buffer, bool* chaine1_ok, bool* chaine2_ok, bool* chaine3_ok);
void chaine1(struct BITMAP* fond_menu, struct BITMAP* buffer, bool* menu_state, bool* chaine1_ok);
void chaine2(struct BITMAP* fond_menu, struct BITMAP* buffer, bool* menu_state, bool* chaine2_ok);
void chaine3(struct BITMAP* fond_menu, struct BITMAP* buffer, bool* menu_state, bool* chaine3_ok);

#endif // AFFICHAGE_H_INCLUDED
