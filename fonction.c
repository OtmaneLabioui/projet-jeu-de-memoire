#include "fonction.h"


	void afficher_win2(GtkWidget *pWidget, gpointer data){


		GtkWidget *win2 ;
		GtkWidget *win ;

		win=GTK_WIDGET(gtk_builder_get_object(builder,"wd1"));
		win2=GTK_WIDGET(gtk_builder_get_object(builder,"wd2"));

		gtk_widget_show_all(win2);
		gtk_widget_destroy(win);

		}

		void afficher_f(GtkWidget *pWidget, gpointer pData){


               GtkWidget *wd_f ;
		GtkWidget *win2 ;
		wd_f=GTK_WIDGET(gtk_builder_get_object(builder_f,"wd_f"));
		win2=GTK_WIDGET(gtk_builder_get_object(builder,"wd2"));
                gtk_window_set_default_size(GTK_WINDOW(wd_f),600,500);


		gtk_widget_show_all(wd_f);
		gtk_widget_destroy(win2);

		}
		void afficher_m(GtkWidget *pWidget, gpointer pData){



		GtkWidget *wd_m ;
		GtkWidget *win2 ;
		wd_m=GTK_WIDGET(gtk_builder_get_object(builder_m,"wd_m"));
		win2=GTK_WIDGET(gtk_builder_get_object(builder,"wd2"));
		        gtk_window_set_default_size(GTK_WINDOW(wd_m),600,500);

		gtk_widget_show_all(wd_m);
		gtk_widget_destroy(win2);
		}
		void afficher_d(GtkWidget *pWidget, gpointer pData){

	    GtkWidget *wd_d ;
		GtkWidget *win2 ;


		wd_d=GTK_WIDGET(gtk_builder_get_object(builder_d,"wd_d"));
		win2=GTK_WIDGET(gtk_builder_get_object(builder,"wd2"));
				        gtk_window_set_default_size(GTK_WINDOW(wd_d),600,500);
		gtk_widget_show_all(wd_d);
		gtk_widget_destroy(win2);
		}


//cette focntion , normalement est deja definit dans la bibliotheque stdlib.h mais dans codeblocks ne fonctionne pas il faut declarer 
char * itoa (int value, char *result, int base)
{
    // check that the base if valid
    if (base < 2 || base > 36) { *result = '"151900920"'; return result; }

    char* ptr = result, *ptr1 = result, tmp_char;
    int tmp_value;

    do {
        tmp_value = value;
        value /= base;
        *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
    } while ( value );

    // Apply negative sign
    if (tmp_value < 0) *ptr++ = '-';
    *ptr-- = '"151900920"';
    while (ptr1 < ptr) {
        tmp_char = *ptr;
        *ptr--= *ptr1;
        *ptr1++ = tmp_char;
    }
    return result;
}







int * initvaleur (int *val,int n)
{val=(int *)malloc(n*sizeof(int));
  int i,j;
  for (i=0; i<(n/2); i++) *(val+i)=i+1;
  for (i=(n/2); i<n; i++)  *(val+i)=i-(n/2)+1;
return val ;
}

int** generateur(int *val, int **grille,int n, int m){
 int i, j, k, l;
grille=(int **)malloc(n*sizeof(int*));
for(i=0;i<n;i++){

grille[i]=(int *)malloc(m*sizeof(int));
}
  for(i=0;i<n;i++){
    for(j=0; j<m;j++){
    grille[i][j]=0;
    }
    }
 int repet, nombre;
 for(i=0;i<n;i++){
     for(j=0; j<m; j++){
       repet = 0;
      nombre =rand() % (n*m);
        for(k=0;k<n;k++){
           for(l=0; l<m; l++){
              if (grille[k][l]== val[nombre])
                repet++; }

        }
        if (repet < 2)
        grille[i][j]=val[nombre];
        else
            j--;
    }
  }
return grille;
}



int jeu_statue(int **retourne,int **grille,int n,int m){


int i,j,valeur;

for(i=0;i<n;i++){

    for(j=0; j<m; j++){

            if (retourne[i][j]==1) valeur = grille[i][j];

        }

     }

 return valeur;

}



















