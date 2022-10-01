#include <stdlib.h>

void help_f(GtkWidget* button,gpointer data){
facile* callback_data = (facile*)data;
 int k, t;
  int but_ligne=gtk_widget_get_name(GTK_WIDGET(button))[0] - '0';//nombre de ligne et de collone des bouttons qui emient le signal

    int but_col=gtk_widget_get_name(GTK_WIDGET(button))[1] - '0';

 if((callback_data->retourne[but_ligne][but_col]==1) && (callback_data->s==1)){//seulemet la deuxieme carte choisi par l'utilisateur qui verifie cette cindition

                        callback_data->s=0;//intialisation de cette variable qui structure la comparaison et le jeu 
 callback_data->btn_info[1].valeur=jeu_statue(callback_data->retourne,callback_data->grille,callback_data->n,callback_data->m);//recoit la valeur de la carte clique par l'utlisateur
                   callback_data->btn_info[1].ligne=but_ligne;//stocker les  valeurs de ligne et de collonne
                    callback_data->btn_info[1].colonne=but_col;

                       //Si les cartes sont les mêmes

                       if ( callback_data->btn_info[0].valeur== callback_data->btn_info[1].valeur){



                        callback_data->retourne[callback_data->btn_info[0].ligne][callback_data->btn_info[0].colonne]=2;

                        callback_data->retourne[callback_data->btn_info[1].ligne][callback_data->btn_info[1].colonne]=2;
                        //alors les cartes sont diffentivement retourner


                                       callback_data->retour = 0;int i,j;
                                        for(i=0; i<callback_data->n; i++)
                                        {

                                        for(j=0; j<callback_data->m; j++)

                                        {
                                        if (callback_data->retourne[i][j]==2) callback_data->retour++;

                                        }

                                        }
   //calculer le nombre des cartes retourner

                                        if (callback_data->retour == (callback_data->n*callback_data->m)-2)  callback_data->gagne=1;
                                        else callback_data->gagne=0;


 gchar score[]="score:0";//changer le score 
            score[6]=callback_data->retour/2+'0';

          gtk_label_set_text(GTK_LABEL(callback_data->score),score);







                        }

                        else

                        { int i,j;
//retouner les cartes en face cachee et donne la valeur zero dans le tableau retouner
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








//cette fonction active par clique
void nouveau_f(GtkWidget* button,gpointer data){

     facile* callback_data = (facile*)data;


    int but_ligne=gtk_widget_get_name(GTK_WIDGET(button))[0] - '0';

    int but_col=gtk_widget_get_name(GTK_WIDGET(button))[1] - '0';

    int k,i,j;

     for(i=0;i<callback_data->n;i++){
     for(j=0;j<callback_data->m;j++){
      if(but_ligne==i) k=but_col+(i*(callback_data->m));
}}

         gchar nv[]= "res/img_0.png";
//pointer sur les images de mannieres aleatoires 
          if(callback_data->retourne[but_ligne][but_col]== 0 && callback_data->s==0 ){//cette condition est vrai seulemet pour la premiere carte

            int d=callback_data->grille[but_ligne][but_col];

                    nv[8]=d+'0';
                             gtk_image_set_from_file(GTK_IMAGE(callback_data->image[k]),nv);//afficher les images aleatoires dans le plateau


            callback_data->retourne[but_ligne][but_col]=1;



//stocker les donner depend du premiere carte
             callback_data->btn_info[0].valeur=jeu_statue(callback_data->retourne,callback_data->grille,callback_data->n,callback_data->m);

             callback_data->btn_info[0].ligne=but_ligne;

             callback_data->btn_info[0].colonne=but_col;

            callback_data->s++;


//donne la valeur 2 temporairment dans le tableau retourne et pour connaitre la deuxieme carte choisi dans la focntion help
          callback_data->retourne[but_ligne][but_col]=2;}



                  if((callback_data->retourne[but_ligne][but_col]==0) && (callback_data->s==1)){
//cette condition est vrai seulemet pour la deuxieme carte

                         int d=callback_data->grille[but_ligne][but_col];

                    nv[8]=d+'0';
                             gtk_image_set_from_file(GTK_IMAGE(callback_data->image[k]),nv);




                  //on retourne la carte temporairement "=1" en attendant la comparaison

                  callback_data->retourne[but_ligne][but_col]=1;

                  if(callback_data->gagne==1) {gtk_label_set_text(GTK_LABEL(callback_data->label_statue), "Jeu est Terminer");
                  gchar score[]="score:0";
            score[6]=callback_data->retour-1+'0';

          gtk_label_set_text(GTK_LABEL(callback_data->score),score);
          //donne le temps lorsque le jeu est terminer
g_timer_stop(callback_data->timer);
int f =(int)g_timer_elapsed (callback_data->timer, NULL);
char var[]="10000000 s";
itoa(f,var,10);

gtk_label_set_text(GTK_LABEL(callback_data->chrono), var);

               
                  }}



                  }






