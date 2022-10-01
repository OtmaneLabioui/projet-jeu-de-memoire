#include "fonction.c"
#include "fonction_f.c"
#include "fonction_m.c"
#include "fonction_d.c"

static void load_css(){//decalarer un css pour faire background de notre windows
GtkCssProvider *cssprovider;
GdkScreen *screen;
GdkDisplay * display;


GFile *css_file=g_file_new_for_path("style.css");


cssprovider=gtk_css_provider_new();
display=gdk_display_get_default();
screen=gdk_display_get_default_screen(display);
gtk_style_context_add_provider_for_screen(screen,GTK_STYLE_PROVIDER(cssprovider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
gtk_css_provider_load_from_file(cssprovider,css_file,NULL);
}



int main (int argc, char *argv[])


{



 /* Initialize GTK+ */
  gtk_init (&argc, &argv);

  load_css();
  app_widget *callback_data=g_slice_new(app_widget);//l'allocation de memoire  pour la variable structure callback_data
  callback_data->f = g_slice_new(facile);//'allocation de memoire  pour la variable structure facile
  callback_data->m = g_slice_new(moyenne);//'allocation de memoire  pour la variable structure moyenne
  callback_data->d = g_slice_new(difficille);//'allocation de memoire  pour la variable structure difficle
//declaration des deffierents widgets utiliser
GtkWidget *jouer;
GtkWidget *win ;
GtkWidget *quitter;
GtkWidget *rejouer_f;
GtkWidget *win2;
GtkWidget *facile;
GtkWidget *moyenne;
GtkWidget *difficile;
int i,j;
gchar str_img[] = "img_0";
char bt[]="bt_0";
//declaration des builders utiliser
   builder=gtk_builder_new_from_file("glade/win_principale.glade");
   builder_f=gtk_builder_new_from_file("glade/nv_facile.glade");
   builder_m=gtk_builder_new_from_file("glade/nv_moyenne.glade");
   builder_d=gtk_builder_new_from_file("glade/nv_difficile.glade");

//pointer different pointeur widget sur widget dans glade

        facile=GTK_WIDGET(gtk_builder_get_object(builder,"facile"));
        moyenne=GTK_WIDGET(gtk_builder_get_object(builder,"moyenne"));
        difficile=GTK_WIDGET(gtk_builder_get_object(builder,"difficile"));
        win2=GTK_WIDGET(gtk_builder_get_object(builder,"wd2"));

        win=GTK_WIDGET(gtk_builder_get_object(builder,"wd1"));
        gtk_window_set_default_size(GTK_WINDOW(win),600,500);
        gtk_window_set_default_size(GTK_WINDOW(win2),600,500);


        rejouer_f=GTK_WIDGET(gtk_builder_get_object(builder_f,"rejouer"));
        jouer=GTK_WIDGET(gtk_builder_get_object(builder,"jouer"));
        quitter=GTK_WIDGET(gtk_builder_get_object(builder,"quitter"));
//Cette fonction  pour utiliser les widgets dans css pour changer arriere plan
gtk_widget_set_name(jouer,"jouer1");
gtk_widget_set_name(quitter,"quitter1");

//pour connecter tous les signals
gtk_builder_connect_signals(builder,callback_data);

callback_data->f->timer=g_timer_new ();//declarer un chronometre
callback_data->m->timer=g_timer_new ();
callback_data->d->timer=g_timer_new ();


//connecter les signals des differents widgets
    g_signal_connect(quitter, "clicked" , G_CALLBACK(gtk_main_quit) , NULL);
    g_signal_connect(jouer, "clicked" , G_CALLBACK(afficher_win2) , NULL);
    g_signal_connect(facile, "clicked" , G_CALLBACK(afficher_f) , NULL);
//depart de chrono pour facile
g_timer_start (callback_data->f->timer );
//Affecter la taille correspond a facile
    callback_data->f->n=gtk_widget_get_name(GTK_WIDGET(facile))[0] - '0';
    callback_data->f->m=gtk_widget_get_name(GTK_WIDGET(facile))[1] - '0';


callback_data->f->taille=callback_data->f->n*callback_data->f->m;
//l'allocation memoire et intialisation de tabeau retourner 
callback_data->f->retourne=(int **)malloc(callback_data->f->n*sizeof(int*));
for(i=0;i<callback_data->f->n;i++){

callback_data->f->retourne[i]=(int *)malloc(callback_data->f->m*sizeof(int));
}
for(i=0;i<callback_data->f->n;i++){
    for(j=0; j<callback_data->f->m;j++){
    callback_data->f->retourne[i][j]=0;
    }
    }
//connecter les widgets utiliser par facile
    callback_data->f->label_statue= GTK_WIDGET(gtk_builder_get_object(builder_f, "label_statue"));
        callback_data->f->score= GTK_WIDGET(gtk_builder_get_object(builder_f, "score"));
        callback_data->f->chrono= GTK_WIDGET(gtk_builder_get_object(builder_f, "chrono"));


    callback_data->f->gagne=0;
    callback_data->f->s=0;
  callback_data->f->val=initvaleur (callback_data->f->val,callback_data->f->taille);
    srand(time(NULL));
callback_data->f->grille=generateur(callback_data->f->val, callback_data->f->grille,callback_data->f->n,callback_data->f->m);
//l'allocation memoire de image et btn 
 callback_data->f->image=(GtkWidget**) g_slice_alloc (callback_data->f->taille*sizeof (GtkWidget*));
 callback_data->f->btn=(GtkWidget**) g_slice_alloc (callback_data->f->taille*sizeof (GtkWidget*));



//pointer sur les widgets dans glad 
   for(i= 0;i<6;i++) {
     str_img[4] = i + '0';
    callback_data->f->image[i]=GTK_WIDGET(gtk_builder_get_object(builder_f, str_img));}

    for(i= 0;i<6;i++) {
    bt[3] = i + '0';
    callback_data->f->btn[i]=GTK_WIDGET(gtk_builder_get_object(builder_f, bt));

    }


//connecter les signals

    for(i= 0;i<6;i++){
    g_signal_connect(callback_data->f->btn[i], "clicked" , G_CALLBACK(nouveau_f),callback_data->f);
    }//le signal emet par une click
    for(i= 0;i<6;i++){
    g_signal_connect(callback_data->f->btn[i], "leave" , G_CALLBACK(help_f),callback_data->f);
    }//le signal emet par la sortie du curseur du zone  boutton




// le mode de jeu facile est le meme que moyenne et difficle alors on a les memes instruction sauf difference de la taille utiliser.

  g_signal_connect(moyenne, "clicked" , G_CALLBACK(afficher_m) , NULL);

g_timer_start (callback_data->m->timer );



    callback_data->m->n=gtk_widget_get_name(GTK_WIDGET(moyenne))[0] - '0';
    callback_data->m->m=gtk_widget_get_name(GTK_WIDGET(moyenne))[1] - '0';


callback_data->m->taille=callback_data->m->n*callback_data->m->m;
callback_data->m->retourne=(int **)malloc(callback_data->m->n*sizeof(int*));
for(i=0;i<callback_data->m->n;i++){

callback_data->m->retourne[i]=(int *)malloc(callback_data->m->m*sizeof(int));
}
for(i=0;i<callback_data->m->n;i++){
    for(j=0; j<callback_data->m->m;j++){
    callback_data->m->retourne[i][j]=0;
    }
    }

    callback_data->m->label_statue= GTK_WIDGET(gtk_builder_get_object(builder_m, "label_statue"));
    callback_data->m->score= GTK_WIDGET(gtk_builder_get_object(builder_m, "score"));
    callback_data->m->chrono= GTK_WIDGET(gtk_builder_get_object(builder_m, "chrono"));

    callback_data->m->gagne=0;
    callback_data->m->s=0;
  callback_data->m->val=initvaleur (callback_data->m->val,callback_data->m->taille);
    srand(time(NULL));
callback_data->m->grille=generateur(callback_data->m->val, callback_data->m->grille,callback_data->m->n,callback_data->m->m);
 callback_data->m->image=(GtkWidget**) g_slice_alloc (callback_data->m->taille*sizeof (GtkWidget*));
 callback_data->m->btn=(GtkWidget**) g_slice_alloc (callback_data->m->taille*sizeof (GtkWidget*));




   for(i= 0;i<10;i++) {
     str_img[4] = i + '0';
    callback_data->m->image[i]=GTK_WIDGET(gtk_builder_get_object(builder_m, str_img));}

    callback_data->m->image[10]=GTK_WIDGET(gtk_builder_get_object(builder_m, "img_10"));
    callback_data->m->image[11]=GTK_WIDGET(gtk_builder_get_object(builder_m, "img_11"));

    for(i= 0;i<10;i++) {
    bt[3] = i + '0';
    callback_data->m->btn[i]=GTK_WIDGET(gtk_builder_get_object(builder_m, bt));
    }
    callback_data->m->btn[10]=GTK_WIDGET(gtk_builder_get_object(builder_m, "bt_10"));
    callback_data->m->btn[11]=GTK_WIDGET(gtk_builder_get_object(builder_m, "bt_11"));






    for(i= 0;i<12;i++){
    g_signal_connect(callback_data->m->btn[i], "clicked" , G_CALLBACK(nouveau_m),callback_data->m);
    }
    for(i= 0;i<12;i++){
    g_signal_connect(callback_data->m->btn[i], "leave" , G_CALLBACK(help_m),callback_data->m);
    }














 g_signal_connect(difficile, "clicked" , G_CALLBACK(afficher_d) , NULL);

g_timer_start (callback_data->d->timer );

   callback_data->d->n=gtk_widget_get_name(GTK_WIDGET(difficile))[0] - '0';
   callback_data->d->m=gtk_widget_get_name(GTK_WIDGET(difficile))[1] - '0';
callback_data->d->taille = callback_data->d->n * callback_data->d->m;
callback_data->d->retourne=(int **)malloc(callback_data->d->n*sizeof(int*));
for(i=0;i<callback_data->d->n;i++){

callback_data->d->retourne[i]=(int *)malloc(callback_data->d->m*sizeof(int));
}
for(i=0;i<4;i++){
    for(j=0; j<4;j++){
    callback_data->d->retourne[i][j]=0;
    }
    }

    callback_data->d->label_statue= GTK_WIDGET(gtk_builder_get_object(builder_d, "label_statue"));
      callback_data->d->score= GTK_WIDGET(gtk_builder_get_object(builder_d, "score"));
              callback_data->d->chrono= GTK_WIDGET(gtk_builder_get_object(builder_d, "chrono"));

    callback_data->d->gagne=0;
    callback_data->d->s=0;
  callback_data->d->val=initvaleur (callback_data->d->val,callback_data->d->taille);
    srand(time(NULL));
callback_data->d->grille=generateur(callback_data->d->val, callback_data->d->grille,callback_data->d->n,callback_data->d->m);
 callback_data->d->image=(GtkWidget**) g_slice_alloc (callback_data->d->taille*sizeof (GtkWidget*));
 callback_data->d->btn=(GtkWidget**) g_slice_alloc (callback_data->d->taille*sizeof (GtkWidget*));




   for(i= 0;i<10;i++) {
     str_img[4] = i + '0';
    callback_data->d->image[i]=GTK_WIDGET(gtk_builder_get_object(builder_d, str_img));}

    callback_data->d->image[10]=GTK_WIDGET(gtk_builder_get_object(builder_d, "img_10"));
    callback_data->d->image[11]=GTK_WIDGET(gtk_builder_get_object(builder_d, "img_11"));
    callback_data->d->image[12]=GTK_WIDGET(gtk_builder_get_object(builder_d, "img_12"));
    callback_data->d->image[13]=GTK_WIDGET(gtk_builder_get_object(builder_d, "img_13"));
    callback_data->d->image[14]=GTK_WIDGET(gtk_builder_get_object(builder_d, "img_14"));
    callback_data->d->image[15]=GTK_WIDGET(gtk_builder_get_object(builder_d, "img_15"));

    for(i= 0;i<10;i++) {
    bt[3] = i + '0';
    callback_data->d->btn[i]=GTK_WIDGET(gtk_builder_get_object(builder_d, bt));
    }
    callback_data->d->btn[10]=GTK_WIDGET(gtk_builder_get_object(builder_d, "bt_10"));
    callback_data->d->btn[11]=GTK_WIDGET(gtk_builder_get_object(builder_d, "bt_11"));
    callback_data->d->btn[12]=GTK_WIDGET(gtk_builder_get_object(builder_d, "bt_12"));
    callback_data->d->btn[13]=GTK_WIDGET(gtk_builder_get_object(builder_d, "bt_13"));
    callback_data->d->btn[14]=GTK_WIDGET(gtk_builder_get_object(builder_d, "bt_14"));
    callback_data->d->btn[15]=GTK_WIDGET(gtk_builder_get_object(builder_d, "bt_15"));






    for(i= 0;i<16;i++){
    g_signal_connect(callback_data->d->btn[i], "clicked" , G_CALLBACK(nouveau_d),callback_data->d);
    }
    for(i= 0;i<16;i++){
    g_signal_connect(callback_data->d->btn[i], "leave" , G_CALLBACK(help_d),callback_data->d);
    }




  gtk_widget_show_all(win);
  gtk_main ();
  g_slice_free(app_widget, callback_data);
  return 0;
}
