#include <stdlib.h>
#include <glib.h>
#include <gtk/gtk.h>
#include <stdio.h>
//declaration de builer
GtkBuilder *builder;
GtkBuilder *builder_f;
GtkBuilder *builder_m;
GtkBuilder *builder_d;
//structure info pour stocker les informations de chacune des cartes
typedef struct {
    int valeur;
    int ligne;
    int colonne;
}info;
// structure facille avec deffiernt champs pour eviter la perdre de l'information 
typedef struct{
        GtkWidget **image;
        GtkWidget *label_statue;
           GtkWidget *score;
             GtkWidget *chrono;
         GtkWidget **btn;
         int n;
        int m;
         int taille ;
                 info btn_info[2];
                  int **grille;
        int **retourne;
        int s;
        int gagne;
        int * val;
       GTimer *timer;
int retour;

}facile;
//meme chose que facile
typedef struct{
        GtkWidget **image;
        GtkWidget *label_statue;
                   GtkWidget *score;
                     GtkWidget *chrono;
         GtkWidget **btn;
         int n;
        int m;
         int taille ;
                 info btn_info[2];
                  int **grille;
        int **retourne;
        int s;
        int gagne;
        int * val;
         int retour;
          GTimer *timer;


}moyenne;
//meme chose que facile
typedef struct{
        GtkWidget **image;
        GtkWidget *label_statue;
                   GtkWidget *score;
                     GtkWidget *chrono;
         GtkWidget **btn;
         int n;
        int m;
         int taille ;
                 info btn_info[2];
                  int **grille;
        int **retourne;
        int s;
        int gagne;
        int * val;
         GTimer *timer;

int retour;

}difficille;
//structure general qui assemble different mode de jeu 
  typedef struct {

        facile *f;
        difficille *d;
        moyenne *m;

    }app_widget;

//pour remplir le tableau d'indexation 
int* initvaleur (int *val,int n);
//pour gener des valeurs aleatoires et les stocker dans une matrice represente le plateau de jeu 
int** generateur(int *val, int **grille,int n, int m);
//fonction retourne la valeur de la carte  temporairement‏ retourner 
int jeu_statue(int **retourne,int **grille,int n,int m);
//les focntions qui recoivent‏ les signals pour afficher les fenteres de jeu 
void afficher_f(GtkWidget *pWidget, gpointer pData);
void afficher_m(GtkWidget *pWidget, gpointer pData);
void afficher_d(GtkWidget *pWidget, gpointer pData);
 void afficher_win2(GtkWidget *pWidget, gpointer pData);
 void afficher_rejouer(GtkWidget *pWidget, gpointer pData);
 //les focntions qui recoivent‏ les signals des cartes de plateau de jeu 
 void help(GtkWidget* button,gpointer data);
 void nouveau(GtkWidget* button,gpointer data);
 void help_m(GtkWidget* button,gpointer data);
 void nouveau_m(GtkWidget* button,gpointer data);
 void help_d(GtkWidget* button,gpointer data);
 void nouveau_d(GtkWidget* button,gpointer data);
