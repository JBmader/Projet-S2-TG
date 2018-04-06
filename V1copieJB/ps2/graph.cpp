#include "graph.h"
#include "grman/grman.h"
#include "grman/widget.h"
#include <fstream>

/***************************************************
                    VERTEX
****************************************************/

/// Le constructeur met en place les �l�ments de l'interface
VertexInterface::VertexInterface(int idx, int x, int y, std::string pic_name, int pic_idx)
{
    // La boite englobante
    m_top_box.set_pos(x, y);
    m_top_box.set_dim(130, 100);
    m_top_box.set_moveable();

    // Le slider de r�glage de valeur
    m_top_box.add_child( m_slider_value );
    m_slider_value.set_range(0.0 , 100.0); // Valeurs arbitraires, � adapter...
    m_slider_value.set_dim(20,80);
    m_slider_value.set_gravity_xy(grman::GravityX::Left, grman::GravityY::Up);

    // Label de visualisation de valeur
    m_top_box.add_child( m_label_value );
    m_label_value.set_gravity_xy(grman::GravityX::Left, grman::GravityY::Down);

    // Une illustration...
    if (pic_name!="")
    {
        m_top_box.add_child( m_img );
        m_img.set_pic_name(pic_name);
        m_img.set_pic_idx(pic_idx);
        m_img.set_gravity_x(grman::GravityX::Right);
    }

    // Label de visualisation d'index du sommet dans une boite
    m_top_box.add_child( m_box_label_idx );
    m_box_label_idx.set_gravity_xy(grman::GravityX::Right, grman::GravityY::Down);
    m_box_label_idx.set_dim(20,12);
    m_box_label_idx.set_bg_color(BLANC);

    m_box_label_idx.add_child( m_label_idx );
    m_label_idx.set_message( std::to_string(idx) );
}


/// Gestion du Vertex avant l'appel � l'interface
void Vertex::pre_update()
{
    if (!m_interface)
        return;

    /// Copier la valeur locale de la donn�e m_value vers le slider associ�
    m_interface->m_slider_value.set_value(m_value);

    /// Copier la valeur locale de la donn�e m_value vers le label sous le slider
    m_interface->m_label_value.set_message( std::to_string( (int)m_value) );
}


/// Gestion du Vertex apr�s l'appel � l'interface
void Vertex::post_update()
{
    if (!m_interface)
        return;

    /// Reprendre la valeur du slider dans la donn�e m_value locale
    m_value = m_interface->m_slider_value.get_value();
}



/***************************************************
                    EDGE
****************************************************/

/// Le constructeur met en place les �l�ments de l'interface
EdgeInterface::EdgeInterface(Vertex& from, Vertex& to)
{
    // Le WidgetEdge de l'interface de l'arc
    if ( !(from.m_interface && to.m_interface) )
    {
        std::cerr << "Error creating EdgeInterface between vertices having no interface" << std::endl;
        throw "Bad EdgeInterface instanciation";
    }
    m_top_edge.attach_from(from.m_interface->m_top_box);
    m_top_edge.attach_to(to.m_interface->m_top_box);
    m_top_edge.reset_arrow_with_bullet();

    // Une boite pour englober les widgets de r�glage associ�s
    m_top_edge.add_child(m_box_edge);
    m_box_edge.set_dim(24,60);
    m_box_edge.set_bg_color(BLANCBLEU);

    // Le slider de r�glage de valeur
    m_box_edge.add_child( m_slider_weight );
    m_slider_weight.set_range(0.0 , 100.0); // Valeurs arbitraires, � adapter...
    m_slider_weight.set_dim(16,40);
    m_slider_weight.set_gravity_y(grman::GravityY::Up);

    // Label de visualisation de valeur
    m_box_edge.add_child( m_label_weight );
    m_label_weight.set_gravity_y(grman::GravityY::Down);

}


/// Gestion du Edge avant l'appel � l'interface
void Edge::pre_update()
{
    if (!m_interface)
        return;

    /// Copier la valeur locale de la donn�e m_weight vers le slider associ�
    m_interface->m_slider_weight.set_value(m_weight);

    /// Copier la valeur locale de la donn�e m_weight vers le label sous le slider
    m_interface->m_label_weight.set_message( std::to_string( (int)m_weight ) );
}

/// Gestion du Edge apr�s l'appel � l'interface
void Edge::post_update()
{
    if (!m_interface)
        return;

    /// Reprendre la valeur du slider dans la donn�e m_weight locale
    m_weight = m_interface->m_slider_weight.get_value();
}



/***************************************************
                    GRAPH
****************************************************/

/// Ici le constructeur se contente de pr�parer un cadre d'accueil des
/// �l�ments qui seront ensuite ajout�s lors de la mise ne place du Graphe
GraphInterface::GraphInterface(int x, int y, int w, int h)
{
    m_top_box.set_dim(1024,768);
    m_top_box.set_gravity_xy(grman::GravityX::Right, grman::GravityY::Down);

    m_top_box.add_child(m_main_box);
    m_main_box.set_dim(1024,718);
    m_main_box.set_gravity_xy(grman::GravityX::Right, grman::GravityY::Down);
    m_main_box.set_bg_color(VERT_FOND);

    m_top_box.add_child(m_tool_box);
    m_tool_box.set_dim(150,50);
    m_tool_box.set_gravity_xy(grman::GravityX::Left, grman::GravityY::Up);
    m_tool_box.set_bg_color(VERT_FOND);

    m_tool_box.add_child(m_bouton_retour); ///Bouton retour
    m_bouton_retour.set_dim(50,50);
    m_bouton_retour.set_gravity_xy(grman::GravityX::Left, grman::GravityY::Center);
    m_bouton_retour.add_child(m_bouton_retour_image);
    m_bouton_retour_image.set_pic_name("bouton_retour.png");

    ///Bouton Charger
    m_tool_box.add_child(m_bouton_charger); ///Bouton retour
    m_bouton_charger.set_dim(50,50);
    m_bouton_charger.set_gravity_xy(grman::GravityX::Center, grman::GravityY::Center);
    m_bouton_charger.add_child(m_bouton_charger_image);
    m_bouton_charger_image.set_pic_name("bouton_chargement.png");


    ///Bouton sauvegarder
    m_tool_box.add_child(m_bouton_sauver); ///Bouton retour
    m_bouton_sauver.set_dim(50,50);
    m_bouton_sauver.set_gravity_xy(grman::GravityX::Right, grman::GravityY::Center);
    m_bouton_sauver.add_child(m_bouton_sauver_image);
    m_bouton_sauver_image.set_pic_name("bouton_save.png");

}


/// M�thode sp�ciale qui construit un graphe arbitraire (d�mo)
/// Cette m�thode est � enlever et remplacer par un syst�me
/// de chargement de fichiers par exemple.
/// Bien s�r on ne veut pas que vos graphes soient construits
/// "� la main" dans le code comme �a.
void Graph::charger(std::string fichier_name)
{

    std::fstream fic(fichier_name, std::ios_base::in);
    int ordre;
    int nb_aretes;
    fic >> ordre;

        for (int i = 0; i < ordre; i++) {
                int a, c, d;
                double b;
                std::string e;
                fic >> a >> b >> c >> d >> e;
                add_interfaced_vertex(a, b, c, d, e);

        }
    fic >> nb_aretes;

    for (int i = 0; i < nb_aretes; i++) {
                int a, b, c;
                double d;
                fic >> a >> b >> c >> d;
                add_interfaced_edge(a, b, c, d);
    }
        fic.close();
}

void Graph::charger_inter()
{
     m_interface = std::make_shared<GraphInterface>(50, 0, 750, 600);
}

void Graph::sauver(std::string fichier_name)
{
    int ordre=m_vertices.size();
    int nb_arretes=m_edges.size();
    std::ofstream fic(fichier_name, std::ios_base::out |std::ios_base::trunc);

    fic<<ordre<<std::endl;

    for (int i = 0; i < ordre; i++)
    {
        int a, c, d;
        double b;
        std::string e;
        a=i;
        b=m_vertices[i].m_value;
        c=m_vertices[i].m_interface->m_top_box.get_posx();
        d=m_vertices[i].m_interface->m_top_box.get_posy();
        e=m_vertices[i].m_interface->m_img.getm_pic_name();
        fic<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<std::endl;
    }
    fic<<nb_arretes<<std::endl;
    for(int i=0; i < nb_arretes; i++)
    {
            int a,b,c;
            double d;
            a=i;
            b=m_edges[i].m_from;
            c=m_edges[i].m_to;
            d=m_edges[i].m_weight;
            fic<<a<<" "<<b<<" "<<c<<" "<<d<<std::endl;
    }
    fic.close();
}

/// La m�thode update � appeler dans la boucle de jeu pour les graphes avec interface
void Graph::update(bool& menu_state, bool &maj, bool& chaine1_ok, bool& chaine2_ok, bool& chaine3_ok)
{
    if (!m_interface)
        return;

    for (auto &elt : m_vertices)
        elt.second.pre_update();

    for (auto &elt : m_edges)
        elt.second.pre_update();

    m_interface->m_top_box.update();

    for (auto &elt : m_vertices)
        elt.second.post_update();

    for (auto &elt : m_edges)
        elt.second.post_update();

    if ( m_interface->m_bouton_retour.clicked())
    {
        menu_state=true;
        maj=false;
        chaine1_ok=false;
        chaine2_ok=false;
        chaine3_ok=false;
    }
    if(m_interface->m_bouton_charger.clicked())
    {
        std::string fic;
        std::cout<<"Quel fichier voulez-vous charger? N'oubliez pas le '.txt' !"<<std::endl;
        std::cin>> fic;
        this->charger(fic);

    }
    if(m_interface->m_bouton_sauver.clicked())
    {
        std::string fic;
        std::cout<<"Dans quelle fichier voulez-vous sauver le graphe? N'oubliez pas le '.txt'!"<<std::endl;
        std::cin>> fic;
        this->sauver(fic);
    }

}

/// Aide � l'ajout de sommets interfac�s
void Graph::add_interfaced_vertex(int idx, double value, int x, int y, std::string pic_name, int pic_idx )
{
    if ( m_vertices.find(idx)!=m_vertices.end() )
    {
        std::cerr << "Error adding vertex at idx=" << idx << " already used..." << std::endl;
        throw "Error adding vertex";
    }
    // Cr�ation d'une interface de sommet
    VertexInterface *vi = new VertexInterface(idx, x, y, pic_name, pic_idx);
    // Ajout de la top box de l'interface de sommet
    m_interface->m_main_box.add_child(vi->m_top_box);
    // On peut ajouter directement des vertices dans la map avec la notation crochet :
    m_vertices[idx] = Vertex(value, vi);
}

/// Aide � l'ajout d'arcs interfac�s
void Graph::add_interfaced_edge(int idx, int id_vert1, int id_vert2, double weight)
{
    if ( m_edges.find(idx)!=m_edges.end() )
    {
        std::cerr << "Error adding edge at idx=" << idx << " already used..." << std::endl;
        throw "Error adding edge";
    }

    if ( m_vertices.find(id_vert1)==m_vertices.end() || m_vertices.find(id_vert2)==m_vertices.end() )
    {
        std::cerr << "Error adding edge idx=" << idx << " between vertices " << id_vert1 << " and " << id_vert2 << " not in m_vertices" << std::endl;
        throw "Error adding edge";
    }

    EdgeInterface *ei = new EdgeInterface(m_vertices[id_vert1], m_vertices[id_vert2]);
    m_interface->m_main_box.add_child(ei->m_top_edge);
    m_edges[idx] = Edge(weight, ei);
     m_edges[idx].m_from = id_vert1;

    m_edges[idx].m_to = id_vert2;



    m_vertices[id_vert1].m_out.push_back(idx);

    m_vertices[id_vert2].m_in.push_back(idx);
}
