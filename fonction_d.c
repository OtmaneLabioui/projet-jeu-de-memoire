//meme chose que fonction_f.c
void help_d(GtkWidget* button,gpointer data){
     difficille* callback_data = (difficille*)data;
 int k, t;
  int but_ligne=gtk_widget_get_name(GTK_WIDGET(button))[0] - '0';

    int but_col=gtk_widget_get_name(GTK_WIDGET(button))[1] - '0';

 if((callback_data->retourne[but_ligne][but_col]==1) && (callback_data->s==1)){

                        callback_data->s=0;
 callback_data->btn_info[1].valeur=jeu_statue(callback_data->retourne,callback_data->grille,callback_data->n,callback_data->m);
                   callback_data->btn_info[1].ligne=but_ligne;
                    callback_data->btn_info[1].colonne=but_col;

                       //Si les cartes sont les mêmes

                       if ( callback_data->btn_info[0].valeur== callback_data->btn_info[1].valeur){



                        callback_data->retourne[callback_data->btn_info[0].ligne][callback_data->btn_info[0].colonne]=2;

                        callback_data->retourne[callback_data->btn_info[1].ligne][callback_data->btn_info[1].colonne]=2;
            
                                        callback_data->retour = 0;int i,j;
                                        for(i=0; i<callback_data->n; i++)
                                        {

                                        for(j=0; j<callback_data->m; j++)

                                        {
                                        if (callback_data->retourne[i][j]==2) callback_data->retour++;

                                        }

                                        }


                                        if (callback_data->retour== (callback_data->n*callback_data->m)-2)  callback_data->gagne=1;
                                        else callback_data->gagne=0;



                  gchar score[]="score:0";
            score[6]=callback_data->retour/2+'0';

                            gtk_label_set_text(GTK_LABEL(callback_data->score),score);




            

                        }

                        else

                        { int i,j;

                                 callback_data->retourne[callback_data->btn_info[0].ligne][callback_data->btn_info[0].colonne]=0;

                                callback_data->retourne[callback_data->btn_info[1].ligne][callback_data->btn_info[1].colonne]=0;

                                for(i=0;i<callback_data->n;i++){
                                for(j=0;j<callback_data->m;j++){
                                if(callback_data->btn_info[0].ligne==i) k=callback_data->btn_info[0].colonne+(i*(callback_data->m));
}}


                                gtk_image_set_from_file(GTK_IMAGE(callback_data->image[k]), "res/arriere.png");




                   for(i=0;i<callback_data->n;i++){
                                for(j=0;j<callback_data->m;j++){
                                if(callback_data->btn_info[1].ligne==i) t=callback_data->btn_info[1].colonne+(i*(callback_data->m));
}}




                                gtk_image_set_from_file(GTK_IMAGE(callback_data->image[t]),"res/arriere.png");



                        }

}





               



}









void nouveau_d(GtkWidget* button,gpointer data){

     difficille* callback_data = (difficille*)data;


    int but_ligne=gtk_widget_get_name(GTK_WIDGET(button))[0] - '0';

    int but_col=gtk_widget_get_name(GTK_WIDGET(button))[1] - '0';

    int k,i,j;

     for(i=0;i<callback_data->n;i++){
     for(j=0;j<callback_data->m;j++){
      if(but_ligne==i) k=but_col+(i*(callback_data->m));
}}

         gchar nv[]= "res/img_0.png";

          if(callback_data->retourne[but_ligne][but_col]== 0 && callback_data->s==0 ){

            int d=callback_data->grille[but_ligne][but_col];
        
                    nv[8]=d+'0';
                             gtk_image_set_from_file(GTK_IMAGE(callback_data->image[k]),nv);


            callback_data->retourne[but_ligne][but_col]=1;




             callback_data->btn_info[0].valeur=jeu_statue(callback_data->retourne,callback_data->grille,callback_data->n,callback_data->m);

             callback_data->btn_info[0].ligne=but_ligne;

             callback_data->btn_info[0].colonne=but_col;

            callback_data->s++;



          callback_data->retourne[but_ligne][but_col]=2;}



                  if((callback_data->retourne[but_ligne][but_col]==0) && (callback_data->s==1)){


                         int d=callback_data->grille[but_ligne][but_col];
                           
                    nv[8]=d+'0';
                             gtk_image_set_from_file(GTK_IMAGE(callback_data->image[k]),nv);




                  //on retourne la carte temporairement "=1" en attendant la comparaison

                  callback_data->retourne[but_ligne][but_col]=1;


                  if(callback_data->gagne==1) {

                  gchar score[]="score:0";
            score[6]=callback_data->retour-6+'0';
                            gtk_label_set_text(GTK_LABEL(callback_data->score),score);
                  gtk_label_set_text(GTK_LABEL(callback_data->label_statue), "Jeu est Terminer");
                  g_timer_stop(callback_data->timer);
int f =(int)g_timer_elapsed (callback_data->timer, NULL);
char var[]="10000000 s";
itoa(f,var,10);

gtk_label_set_text(GTK_LABEL(callback_data->chrono), var);
                  
                  }
}


                  }



