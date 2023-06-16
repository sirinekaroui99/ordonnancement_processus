#include <stdlib.h>
#include <gtk/gtk.h>
#include "/home/linux/Desktop/KarouiSirine-HelaliAmal/Projet_IHM/Politiques/FIFO.c"
#include "/home/linux/Desktop/KarouiSirine-HelaliAmal/Projet_IHM/Politiques/SJF.c"
#include "/home/linux/Desktop/KarouiSirine-HelaliAmal/Projet_IHM/Politiques/RoundRobin.c"
#include "/home/linux/Desktop/KarouiSirine-HelaliAmal/Projet_IHM/Politiques/Priority.c"
#include "/home/linux/Desktop/KarouiSirine-HelaliAmal/Projet_IHM/Politiques/SRT.c"


/* structures */
 typedef struct
{
    const gchar* nom;
    const gchar* TA;
    const gchar* TE;
const gchar* PR;
const gchar* sep;
const gchar* q;
}Process;
  gchar *filename;
void MettreFichier(GtkWidget *widget,gpointer data);
void RR_clicked(GtkWidget *widget,gpointer data);
void sjf_clicked(GtkWidget *widget,gpointer data);

void add_clicked(GtkWidget *widget, gpointer data) {

 // g_print("clickedn add\n");
Process P;
    FILE *fichier;
 
    GtkWidget *pWindow;
    GtkWidget *pVBox;
    GtkWidget *pLabel1;
    GtkWidget *pEntry1;
    GtkWidget *pLabel2;
    GtkWidget *pEntry2;
    GtkWidget *pLabel3;
    GtkWidget *pEntry3;
    GtkWidget *pLabel4;
    GtkWidget *pEntry4;
    GtkWidget *Valider;
 GtkWidget *ANNULER;
 
 
    pWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(pWindow), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(pWindow), 320, 300);
    gtk_window_set_title(GTK_WINDOW(pWindow), "Ajouter un processus ");
    g_signal_connect(G_OBJECT(pWindow), "destroy", G_CALLBACK(gtk_main_quit), NULL);
  
    pVBox = gtk_vbox_new(FALSE,0);
    gtk_container_add(GTK_CONTAINER(pWindow), pVBox);
    pLabel1 = gtk_label_new("Nom du processus (Sous la forme P(i))");
    gtk_box_pack_start(GTK_BOX(pVBox), pLabel1, TRUE, FALSE, 0);
    pEntry1 = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(pVBox), pEntry1, TRUE, FALSE, 0);
     
  
    pLabel2 = gtk_label_new("Temps d'arriver");
    gtk_box_pack_start(GTK_BOX(pVBox), pLabel2, TRUE, FALSE, 0);
    pEntry2 = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(pVBox), pEntry2, TRUE, FALSE, 0);
     
 
  
    pLabel3 = gtk_label_new("Temps d'execution");
    gtk_box_pack_start(GTK_BOX(pVBox), pLabel3, TRUE, FALSE, 0);
    pEntry3 = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(pVBox), pEntry3, TRUE, FALSE, 0);
     
  pLabel4 = gtk_label_new("Priorité");
    gtk_box_pack_start(GTK_BOX(pVBox), pLabel4, TRUE, FALSE, 0);
    pEntry4 = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(pVBox), pEntry4, TRUE, FALSE, 0);
  
    Valider =gtk_button_new_with_label("VALIDER");
    gtk_box_pack_start(GTK_BOX(pVBox), Valider, TRUE, FALSE, 0);

  ANNULER =gtk_button_new_with_label("ANNULER");
    gtk_box_pack_start(GTK_BOX(pVBox), ANNULER, TRUE, FALSE, 0);
  
    g_signal_connect(G_OBJECT(Valider), "clicked" ,G_CALLBACK(gtk_main_quit),NULL);
 g_signal_connect(G_OBJECT(ANNULER), "clicked" ,G_CALLBACK(gtk_main_quit),NULL);
     
    gtk_widget_show_all(pWindow);
    gtk_main();
 
    P.nom = gtk_entry_get_text(GTK_ENTRY(pEntry1));
    P.TA = gtk_entry_get_text(GTK_ENTRY(pEntry2));
    P.TE = gtk_entry_get_text(GTK_ENTRY(pEntry3));
P.PR = gtk_entry_get_text(GTK_ENTRY(pEntry4));
 	P.sep=" ;";
    // décomenter pour voir si tout marche bien...
    //puts(Client.nom);
    //puts(Client.prenom);
    //puts(Client.telephone);
 
    fichier =fopen("configuration.txt","ab+");
    if(fichier!=NULL)
    {
        fwrite(P.nom ,strlen(P.nom),1,fichier);
fwrite(P.sep ,strlen(P.sep),1,fichier);
        fwrite(P.TA ,strlen(P.TA),1,fichier);
fwrite(P.sep ,strlen(P.sep),1,fichier);
        fwrite(P.TE ,strlen(P.TE),1,fichier);
fwrite(P.sep ,strlen(P.sep),1,fichier);
fwrite(P.PR ,strlen(P.PR),1,fichier);
fwrite("\n" ,strlen("\n"),1,fichier);
        fclose(fichier);
    }


//////fermeture methode button_click


}

void algorithme_clicked(GtkWidget *widget, gpointer data) {

GtkWidget *win;

GtkWidget *choix,*fifo,*sjf,*tourniquet,*srt,*priorite, *vbox;

 win = gtk_window_new(GTK_WINDOW_TOPLEVEL);



gtk_window_set_title(GTK_WINDOW(win), "Liste des algorithmes");


gtk_window_set_default_size(GTK_WINDOW(win), 400, 100);
  gtk_container_set_border_width(GTK_CONTAINER(win), 15);
  gtk_window_set_position(GTK_WINDOW(win), GTK_WIN_POS_CENTER);

vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL,0); 



///////////

 //gchar *filename = gtk_file_chooser_get_filename (widget);
  //if (!filename) return;
 // g_print ("Thjjjjjjjjjjjj file selected : %s\n", filename);
 // g_free (filename);

////////////////

 

fifo = gtk_button_new_with_label("FIFO"); 
sjf = gtk_button_new_with_label("SJF"); 
tourniquet = gtk_button_new_with_label("ROUND_ROBIN"); 
srt = gtk_button_new_with_label("SRT"); 
priorite = gtk_button_new_with_label("PRIORITY"); 



//evt click

g_signal_connect(G_OBJECT(fifo), "clicked", G_CALLBACK(FIFO), filename);
g_signal_connect(G_OBJECT(sjf), "clicked", G_CALLBACK(SJF), filename);
g_signal_connect(G_OBJECT(tourniquet), "clicked", G_CALLBACK(RR_clicked), filename);

g_signal_connect(G_OBJECT(srt), "clicked", G_CALLBACK(SRT), filename);
g_signal_connect(G_OBJECT(priorite), "clicked", G_CALLBACK(Priority), filename);

//g_signal_connect (sjf, "clicked", G_CALLBACK (sjf_clicked), NULL); 

//g_signal_connect (fifo, "clicked", G_CALLBACK (choix_clicked), NULL);
//g_signal_connect (sjf, "clicked", G_CALLBACK (choix_clicked), NULL);
//g_signal_connect (tourniquet, "clicked", G_CALLBACK (choix_clicked), NULL);
//g_signal_connect (srt, "clicked", G_CALLBACK (choix_clicked), NULL);
//g_signal_connect (priorite, "clicked", G_CALLBACK (choix_clicked), NULL);





g_signal_connect(win,"delete_event",gtk_main_quit,NULL); 


gtk_box_pack_start(GTK_BOX(vbox),fifo,0,0,0); 
gtk_box_pack_start(GTK_BOX(vbox),sjf,0,0,0); 
gtk_box_pack_start(GTK_BOX(vbox),tourniquet,0,0,0); 
gtk_box_pack_start(GTK_BOX(vbox),srt,0,0,0); 
gtk_box_pack_start(GTK_BOX(vbox),priorite,0,0,0); 





///////////////////

     gtk_container_add(GTK_CONTAINER(win),vbox); 
     gtk_widget_show_all(win); 


///////////////

gtk_widget_show_all(win); 


}

void
file_selected_changed_CB (GtkFileChooser *chooser, gpointer user_data)
{

  filename = gtk_file_chooser_get_filename (chooser);
  if (!filename) return;
 
  g_print ("The currently file selected : %s\n", filename);
  //g_free (filename);


///////
}



void choix_clicked(GtkWidget *widget, gpointer data) {

  GtkWidget *window = NULL;
  GtkWidget *button = NULL;
 GtkWidget *label,*vbox,*btn;
  
 
  /* Création de la fenêtre principale */
  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
gtk_window_set_title(GTK_WINDOW(window), "Selection fichier de configuration");
gtk_window_set_default_size(GTK_WINDOW(window), 400, 90);
 gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  /* Création d'un GtkFileChooserButton */
  button = gtk_file_chooser_button_new ("Choose file...", GTK_FILE_CHOOSER_ACTION_OPEN);



  g_signal_connect (G_OBJECT (button), "selection-changed", G_CALLBACK (file_selected_changed_CB), NULL);



 

 // gtk_container_add (GTK_CONTAINER (window), button);
 label=gtk_label_new("Veuillez sélectionner le fichier de configuration"); 
 btn = gtk_button_new_with_label("Suivant"); 

  /* Signaux */
  g_signal_connect (G_OBJECT(window) , "destroy", G_CALLBACK (gtk_main_quit) , NULL);
 
  /* Affichage de la fenêtre */
 // gtk_widget_show_all (window);

vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL,0); 

gtk_box_pack_start(GTK_BOX(vbox),label,0,0,10); 
 gtk_box_pack_start(GTK_BOX(vbox),button,0,0,10); 
 gtk_box_pack_start(GTK_BOX(vbox),btn,0,0,10); 

 
 g_signal_connect_swapped (btn, "clicked", G_CALLBACK (algorithme_clicked), window);


     gtk_container_add(GTK_CONTAINER(window),vbox); 
     gtk_widget_show_all(window); 


}

void RR_clicked(GtkWidget *widget, gpointer data) {

 // g_print("clickedn fifo\n");
Process P;
GtkWidget *win;
GtkWidget *quantumLabel;
    GtkWidget *quantumVal;
GtkWidget *fifo,*sjf,*tourniquet,*srt,*priorite, *vbox;

GtkWidget *Envoyer;

 win = gtk_window_new(GTK_WINDOW_TOPLEVEL);



gtk_window_set_title(GTK_WINDOW(win), "Execution de l'algorithme Round_Robin");


gtk_window_set_default_size(GTK_WINDOW(win), 400, 100);
  gtk_container_set_border_width(GTK_CONTAINER(win), 15);
  gtk_window_set_position(GTK_WINDOW(win), GTK_WIN_POS_CENTER);

vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL,0); 

////////////////

quantumLabel = gtk_label_new("Entrer le Quantum :");
    gtk_box_pack_start(GTK_BOX(vbox), quantumLabel, FALSE, FALSE, 0);
    quantumVal = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(vbox), quantumVal, FALSE, FALSE, 0);

//////////////////////inserer un champs de texte





 Envoyer =gtk_button_new_with_label("Envoyer");
    gtk_box_pack_start(GTK_BOX(vbox), Envoyer, TRUE, FALSE, 0);

///////////////////
g_signal_connect(G_OBJECT(Envoyer), "clicked" ,G_CALLBACK(gtk_main_quit),NULL);
//





     gtk_container_add(GTK_CONTAINER(win),vbox); 
     gtk_widget_show_all(win); 


///////////////

gtk_widget_show_all(win); 
gtk_main();

P.q = gtk_entry_get_text(GTK_ENTRY(quantumVal));
//puts("gggg");
//puts(P.q);

gchar *quantum;
quantum = P.q;

g_signal_connect(G_OBJECT(Envoyer), "clicked" ,G_CALLBACK(LireQuantum),quantum);

//puts("k222222222222222");

g_signal_connect(G_OBJECT(Envoyer), "clicked" ,G_CALLBACK(RoundRobin),filename);

//////fermeture methode button_click
//g_signal_connect_swapped (Envoyer, "clicked", G_CALLBACK (gtk_widget_destroy), win);
 
}

void sjf_clicked(GtkWidget *widget, gpointer data) {

  g_print("clickedn sjf\n");

GtkWidget *win;

GtkWidget  *vbox,*view;
GtkTextBuffer *buffer;
  GtkTextIter iter;


 win = gtk_window_new(GTK_WINDOW_TOPLEVEL);



gtk_window_set_title(GTK_WINDOW(win), "Execution de l'algorithme SJF");


gtk_window_set_default_size(GTK_WINDOW(win), 400, 100);
  gtk_container_set_border_width(GTK_CONTAINER(win), 15);
  gtk_window_set_position(GTK_WINDOW(win), GTK_WIN_POS_CENTER);

vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL,0); 

view = gtk_text_view_new();
gtk_box_pack_start(GTK_BOX(vbox), view, TRUE, TRUE, 0);
buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(view));
 gtk_text_buffer_get_iter_at_offset(buffer, &iter, 0);

///////////////


gtk_text_buffer_insert(buffer, &iter, "Plain text\n", -1);

////////////////
g_print ("file selected : %s\n", filename);
 // g_free (filename);


///////////////////

     gtk_container_add(GTK_CONTAINER(win),vbox); 
     gtk_widget_show_all(win); 


///////////////

gtk_widget_show_all(win); 

//////fermeture methode button_click


}



///////////////////////////////////////



void button_clicked(GtkWidget *widget, gpointer data) {
    
//////////////////////

////////////////////



  //g_print("clicked\n");
GtkWidget *win;

GtkWidget *Quiter,*add,*choix,*fifo,*sjf,*tourniquet,*srt,*priorite, *vbox;

 win = gtk_window_new(GTK_WINDOW_TOPLEVEL);



gtk_window_set_title(GTK_WINDOW(win), "Menu principale");


gtk_window_set_default_size(GTK_WINDOW(win), 400, 100);
  gtk_container_set_border_width(GTK_CONTAINER(win), 15);
  gtk_window_set_position(GTK_WINDOW(win), GTK_WIN_POS_CENTER);

vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL,0); 

////////////////
add = gtk_button_new_with_label("Ajouter un processus"); 
choix=gtk_button_new_with_label("Choix de l'algorithme"); 
Quiter=gtk_button_new_with_label("Quitter"); 
//fifo = gtk_button_new_with_label("FIFO"); 
//sjf = gtk_button_new_with_label("SJF"); 
//tourniquet = gtk_button_new_with_label("ROUND_ROBIN"); 
//srt = gtk_button_new_with_label("SRT"); 
//priorite = gtk_button_new_with_label("PRIORITY"); 



////evt click
g_signal_connect (add, "clicked", G_CALLBACK (add_clicked), NULL);
 //g_signal_connect (fifo, "clicked", G_CALLBACK (fifo_clicked), NULL);
//g_signal_connect (sjf, "clicked", G_CALLBACK (sjf_clicked), NULL);
g_signal_connect (choix, "clicked", G_CALLBACK (choix_clicked), NULL);
g_signal_connect_swapped (Quiter, "clicked", G_CALLBACK (gtk_widget_destroy), win);
//g_signal_connect(win,"delete_event",gtk_main_quit,NULL); 

gtk_box_pack_start(GTK_BOX(vbox),add,0,0,5);
gtk_box_pack_start(GTK_BOX(vbox),choix,0,0,5);
gtk_box_pack_start(GTK_BOX(vbox),Quiter,0,0,5);
//gtk_box_pack_start(GTK_BOX(vbox),fifo,0,0,0); 
//gtk_box_pack_start(GTK_BOX(vbox),sjf,0,0,0); 
//gtk_box_pack_start(GTK_BOX(vbox),tourniquet,0,0,0); 
//gtk_box_pack_start(GTK_BOX(vbox),srt,0,0,0); 
//gtk_box_pack_start(GTK_BOX(vbox),priorite,0,0,0); 





///////////////////

     gtk_container_add(GTK_CONTAINER(win),vbox); 
     gtk_widget_show_all(win); 


///////////////

gtk_widget_show_all(win); 


//////fermeture methode button_click


}



int main(int argc,char *argv[])
 {

     gtk_init(&argc,&argv);
     GtkWidget *win, *Groupe,*Binome, *btn, *vbox;

     win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
gtk_window_set_title(GTK_WINDOW(win), "Ordonnancement");

gtk_window_set_default_size(GTK_WINDOW(win), 300, 150);
  gtk_container_set_border_width(GTK_CONTAINER(win), 15);
  gtk_window_set_position(GTK_WINDOW(win), GTK_WIN_POS_CENTER);



    // g_signal_connect(win,"delete_event",gtk_main_quit,NULL); 

     Groupe = gtk_label_new("Groupe IDL 2"); 
Binome = gtk_label_new("Karoui Sirine & Helali Amal \n"); 
     btn = gtk_button_new_with_label("Passer au programme"); 

     vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL,0); 

  g_signal_connect (btn, "clicked", G_CALLBACK (button_clicked), NULL);

//pour que lorsque je clique sur le bouton la fenetre se ferme 
  g_signal_connect_swapped (btn, "clicked", G_CALLBACK (gtk_widget_destroy), win);

     gtk_box_pack_start(GTK_BOX(vbox),Groupe,0,0,0); 
gtk_box_pack_start(GTK_BOX(vbox),Binome,0,0,0); 
     gtk_box_pack_start(GTK_BOX(vbox),btn,0,0,0); 

     gtk_container_add(GTK_CONTAINER(win),vbox); 

     gtk_widget_show_all(win); 


     gtk_main(); 
     return 0;
 }
