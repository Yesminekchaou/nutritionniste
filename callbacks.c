#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include "yes.h"
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void
on_buttongea_clicked                   (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowmenu,*w2;
w2=lookup_widget(objet_graphique,"gestionyes");
gtk_widget_destroy(w2);
windowmenu=create_ajyes();
gtk_widget_show(windowmenu);


}


void
on_buttongem_clicked                   (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowmenu,*w2;
w2=lookup_widget(objet_graphique,"gestionyes");
gtk_widget_destroy(w2);
windowmenu=create_myes();
gtk_widget_show(windowmenu);


}


void
on_buttonges_clicked                   (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowmenu,*w2;
w2=lookup_widget(objet_graphique,"gestionyes");
gtk_widget_destroy(w2);
windowmenu=create_suppyes();
gtk_widget_show(windowmenu);


}


void
on_buttongech_clicked                  (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowmenu,*w2;
w2=lookup_widget(objet_graphique,"gestionyes");
gtk_widget_destroy(w2);
windowmenu=create_cheryes();
gtk_widget_show(windowmenu);


}


void
on_buttongeaff_clicked                 (GtkWidget *objet,
                                        gpointer         user_data)
{
GtkWidget *w2;
GtkWidget *treeview1;
w2=lookup_widget(objet,"gestionyes");
treeview1 = lookup_widget(w2,"treeviewgeaff");
videre(treeview1);
affe(treeview1);
}


void
on_buttongedec_clicked                 (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{

}


void
on_buttongeaok_clicked                 (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *id,*t,*nc,*qd,*d,*cons,*l,*f,*c,*pt,*eqoui,*eqnon,*ajouter,*esucces,*eerreur,*calendargea ;
plat p;
char texte[200];
char t1[200]={'0','/'};
char t2[200]={'0','/'};
char t3[200]={'0','/'};
char t4[200]={'0'};
int an,j,mois;

ajouter = lookup_widget(objet_graphique,"ajyes");
calendargea = lookup_widget(ajouter,"calendargea");
gtk_calendar_get_date(GTK_CALENDAR(calendargea),&an,&mois,&j);
p.d.j=j;
p.d.m=mois+1;
p.d.a=an;
nc = lookup_widget(objet_graphique, "spinbuttongeanc") ;
t = lookup_widget(objet_graphique, "comboboxentrygeat") ;
eqoui = lookup_widget(objet_graphique, "radiobuttongeaoui") ;
eqnon= lookup_widget(objet_graphique, "radiobuttongeanon") ;
l=lookup_widget(objet_graphique, "checkbuttongeal") ;
f= lookup_widget(objet_graphique, "checkbuttongeaf") ;
c= lookup_widget(objet_graphique, "checkbuttongeac") ;
pt = lookup_widget(objet_graphique, "checkbuttongeap") ;
id = lookup_widget(objet_graphique, "entrygeaid") ;
qd= lookup_widget(objet_graphique, "entrygeaqd") ;
strcpy(p.id,gtk_entry_get_text(GTK_ENTRY(id)));
if (control_e(p.id)==0)
{

strcpy(p.qd,gtk_entry_get_text(GTK_ENTRY(qd)));
p.nc=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(nc));
strcpy(p.t,gtk_combo_box_get_active_text(GTK_COMBO_BOX(t)));
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(eqoui)))
{strcpy(p.eq,"oui");}
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(eqnon)))
{strcpy(p.eq,"non");}
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(l)))
{strcpy(t1,"l/");}
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(f)))
{strcpy(t2,"f/");}
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(c)))
{strcpy(t3,"c/");}
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(pt)))
{strcpy(t4,"p");}
strcat(t1,t2);
strcat(t3,t4);
strcat(t1,t3);
strcpy(p.cons,t1);
ajoutyes(p);
sprintf(texte,"✔️ Ajout avec succés 😁!");
esucces = lookup_widget(objet_graphique,"labelgeasuc");
GdkColor color;
gdk_color_parse ("#40e61a", &color);
gtk_widget_modify_fg (esucces, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL(esucces),texte);

sprintf(texte,"");
eerreur=lookup_widget(objet_graphique,"labelgeaidc");
gdk_color_parse ("#ff250d", &color);
gtk_widget_modify_fg (eerreur, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL(eerreur),texte);
}
else
{
sprintf(texte,"❌ Cet id existe dèja 😰!");
eerreur=lookup_widget(objet_graphique,"labelgeaidc");
GdkColor color;
gdk_color_parse ("#ff250d", &color);
gtk_widget_modify_fg (eerreur, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL(eerreur),texte);

sprintf(texte,"");
esucces=lookup_widget(objet_graphique,"labelgeasuc");
gdk_color_parse ("#ff250d", &color);
gtk_widget_modify_fg (esucces, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL(esucces),texte);
}



}


void
on_buttongeac_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowmenu,*w2;
w2=lookup_widget(objet_graphique,"ajyes");
gtk_widget_destroy(w2);
windowmenu=create_gestionyes();
gtk_widget_show(windowmenu);
GtkWidget *treeview1;
treeview1 = lookup_widget(windowmenu,"treeviewgeaff");
affe(treeview1);

}


void
on_buttongemconsulter_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *id,*t,*nc,*qd,*d,*cons,*l,*f,*c,*pt,*eqoui,*eqnon,*esucces,*eerreur,*jr,*mois,*an ;
plat p;
jr = lookup_widget(objet_graphique, "spinbuttongemj") ;
mois = lookup_widget(objet_graphique, "spinbuttongemm") ;
an= lookup_widget(objet_graphique, "spinbuttongema") ;
nc = lookup_widget(objet_graphique, "spinbuttongemnc") ;
t = lookup_widget(objet_graphique, "comboboxentrygemt") ;
eqoui = lookup_widget(objet_graphique, "radiobuttongemoui") ;
eqnon= lookup_widget(objet_graphique, "radiobuttongemnon") ;
l=lookup_widget(objet_graphique, "checkbuttongeml") ;
f= lookup_widget(objet_graphique, "checkbuttongemf") ;
c= lookup_widget(objet_graphique, "checkbuttongemc") ;
pt = lookup_widget(objet_graphique, "checkbuttongemp") ;
id = lookup_widget(objet_graphique, "entrygemid") ;
qd= lookup_widget(objet_graphique, "entrygemqd") ;
strcpy(p.id,gtk_entry_get_text(GTK_ENTRY(id)));
int i=0;
char texte[2000];
char bloc[200][200]={"Petit_Dej","Dejeuner","Diner"};
if (chercheryes(&p,p.id)==1)
{

gtk_entry_set_text(GTK_ENTRY(qd),p.qd);
gtk_spin_button_set_value(jr,p.d.j);
gtk_spin_button_set_value(mois,p.d.m);
gtk_spin_button_set_value(an,p.d.a);
while((i<3)&&(strcmp(bloc[i],p.t)!=0))
{i=i+1;}
gtk_combo_box_set_active(GTK_COMBO_BOX(t),i);
if(p.cons[0]=='l')
{
gtk_toggle_button_set_active(GTK_RADIO_BUTTON(l),TRUE);}
if(p.cons[2]=='f')
{
gtk_toggle_button_set_active(GTK_RADIO_BUTTON(f),TRUE);}
if(p.cons[4]=='c')
{
gtk_toggle_button_set_active(GTK_RADIO_BUTTON(c),TRUE);}
if(p.cons[6]=='p')
{
gtk_toggle_button_set_active(GTK_RADIO_BUTTON(pt),TRUE);}
if(p.cons[0]=='0')
{
gtk_toggle_button_set_active(GTK_RADIO_BUTTON(l),FALSE);}
if(p.cons[2]=='0')
{
gtk_toggle_button_set_active(GTK_RADIO_BUTTON(f),FALSE);}
if(p.cons[4]=='0')
{
gtk_toggle_button_set_active(GTK_RADIO_BUTTON(c),FALSE);}
if(p.cons[6]=='0')
{
gtk_toggle_button_set_active(GTK_RADIO_BUTTON(pt),FALSE);}
if(strcmp(p.eq,"oui")==0)
{gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(eqoui),TRUE);}
if(strcmp(p.eq,"non")==0)
{gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(eqnon),TRUE);}
if(strcmp(p.eq,"oui")!=0)
{gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(eqoui),FALSE);}
if(strcmp(p.eq,"non")!=0)
{gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(eqnon),FALSE);}
sprintf(texte,"");
eerreur=lookup_widget(objet_graphique,"labelgemer");
GdkColor color;
gdk_color_parse ("#ff250d", &color);
gtk_widget_modify_fg (eerreur, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL(eerreur),texte);

sprintf(texte,"");
esucces=lookup_widget(objet_graphique,"labelgemsuc");
gdk_color_parse ("#ff250d", &color);
gtk_widget_modify_fg (esucces, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL(esucces),texte);
}
else
{
sprintf(texte,"❌ Cet id n'existe pas dèja 😰!");
eerreur=lookup_widget(objet_graphique,"labelgemer");
GdkColor color;
gdk_color_parse ("#ff250d", &color);
gtk_widget_modify_fg (eerreur, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL(eerreur),texte);

sprintf(texte,"");
esucces=lookup_widget(objet_graphique,"labelgemsuc");
gdk_color_parse ("#ff250d", &color);
gtk_widget_modify_fg (esucces, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL(esucces),texte);
}
}


void
on_buttongemcancel_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowmenu,*w2;
w2=lookup_widget(objet_graphique,"myes");
gtk_widget_destroy(w2);
windowmenu=create_gestionyes();
gtk_widget_show(windowmenu);
GtkWidget *treeview1;
treeview1 = lookup_widget(windowmenu,"treeviewgeaff");
affe(treeview1);



}


void
on_buttongemok_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *id,*t,*nc,*qd,*d,*cons,*l,*f,*c,*pt,*eqoui,*eqnon,*esucces,*eerreur,*jr,*mois,*an ;
plat p;
char texte[200];
char t1[200]={'0','/'};
char t2[200]={'0','/'};
char t3[200]={'0','/'};
char t4[200]={'0'};
//modifier = lookup_widget(objet_graphique,"myesmine");
jr = lookup_widget(objet_graphique, "spinbuttongemj") ;
mois = lookup_widget(objet_graphique, "spinbuttongemm") ;
an= lookup_widget(objet_graphique, "spinbuttongema") ;
nc = lookup_widget(objet_graphique, "spinbuttongemnc") ;
t = lookup_widget(objet_graphique, "comboboxentrygemt") ;
eqoui = lookup_widget(objet_graphique, "radiobuttongemoui") ;
eqnon= lookup_widget(objet_graphique, "radiobuttongemnon") ;
l=lookup_widget(objet_graphique, "checkbuttongeml") ;
f= lookup_widget(objet_graphique, "checkbuttongemf") ;
c= lookup_widget(objet_graphique, "checkbuttongemc") ;
pt = lookup_widget(objet_graphique, "checkbuttongemp") ;
id = lookup_widget(objet_graphique, "entrygemid") ;
qd= lookup_widget(objet_graphique, "entrygemqd") ;
strcpy(p.id,gtk_entry_get_text(GTK_ENTRY(id)));
if (control_e(p.id)==1)
{
p.d.j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jr));
p.d.m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
p.d.a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(an));
strcpy(p.qd,gtk_entry_get_text(GTK_ENTRY(qd)));
p.nc=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(nc));
strcpy(p.t,gtk_combo_box_get_active_text(GTK_COMBO_BOX(t)));
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(eqoui)))
{strcpy(p.eq,"oui");}
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(eqnon)))
{strcpy(p.eq,"non");}
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(l)))
{strcpy(t1,"l/");}
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(f)))
{strcpy(t2,"f/");}
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(c)))
{strcpy(t3,"c/");}
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(pt)))
{strcpy(t4,"p");}
strcat(t1,t2);
strcat(t3,t4);
strcat(t1,t3);
strcpy(p.cons,t1);
modifieryes(p);
sprintf(texte,"✔️ Modifiee avec succés 😁!");
esucces = lookup_widget(objet_graphique,"labelgemsuc");
GdkColor color;
gdk_color_parse ("#40e61a", &color);
gtk_widget_modify_fg (esucces, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL(esucces),texte);

sprintf(texte,"");
eerreur=lookup_widget(objet_graphique,"labelgemer");
gdk_color_parse ("#ff250d", &color);
gtk_widget_modify_fg (eerreur, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL(eerreur),texte);
}
else
{
sprintf(texte,"❌ Cet id n'existe pas dèja 😰!");
eerreur=lookup_widget(objet_graphique,"labelgemer");
GdkColor color;
gdk_color_parse ("#ff250d", &color);
gtk_widget_modify_fg (eerreur, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL(eerreur),texte);

sprintf(texte,"");
esucces=lookup_widget(objet_graphique,"labelgemsuc");
gdk_color_parse ("#ff250d", &color);
gtk_widget_modify_fg (esucces, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL(esucces),texte);
}


}


void
on_buttongesr_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowmenu,*w2;
w2=lookup_widget(objet_graphique,"suppyes");
gtk_widget_destroy(w2);
windowmenu=create_gestionyes();
gtk_widget_show(windowmenu);
GtkWidget *treeview1;
treeview1 = lookup_widget(windowmenu,"treeviewgeaff");
affe(treeview1);


}


void
on_buttongechch_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *w2;
GtkWidget *treeview2;
GtkWidget *refc,*herreur;
char ref[200];
char texte[200];
plat p;
refc = lookup_widget(objet_graphique, "entrygechid") ;
strcpy(ref,gtk_entry_get_text(GTK_ENTRY(refc)));
if(control_e(ref)==1)
{
w2=lookup_widget(objet_graphique,"cheryes");
treeview2 = lookup_widget(w2,"treeviewgech");
videre(treeview2);
aff_che(treeview2,ref);
sprintf(texte,"");
herreur=lookup_widget(objet_graphique,"labelgecher");
GdkColor color;
gdk_color_parse ("#ff250d", &color);
gtk_widget_modify_fg (herreur, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL(herreur),texte);
}
else
{
sprintf(texte,"❌ Cet id n'existe pas dèja 😰!");
herreur=lookup_widget(objet_graphique,"labelgecher");
GdkColor color;
gdk_color_parse ("#ff250d", &color);
gtk_widget_modify_fg (herreur, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL(herreur),texte);
}
}
void
on_buttongechr_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowmenu,*w2;
w2=lookup_widget(objet_graphique,"cheryes");
gtk_widget_destroy(w2);
windowmenu=create_gestionyes();
gtk_widget_show(windowmenu);
GtkWidget *treeview1;
treeview1 = lookup_widget(windowmenu,"treeviewgeaff");
affe(treeview1);


}


void
on_buttongess_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
plat p;
char ref[200];
char texte[200];
GtkWidget *refs,*eerreur;
refs = lookup_widget(objet_graphique, "entrygesid") ;
strcpy(ref,gtk_entry_get_text(GTK_ENTRY(refs)));
if(control_e(ref)==1)
{
supprimeryes(p,ref);
sprintf(texte,"✔️ Supprimee avec succés 😁!");
eerreur=lookup_widget(objet_graphique,"labelgessuc");
GdkColor color;
gdk_color_parse ("#40e61a", &color);
gtk_widget_modify_fg (eerreur, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL(eerreur),texte);
}
else
{
sprintf(texte,"❌ Cet id n'existe pas dèja 😰!");
eerreur=lookup_widget(objet_graphique,"labelgeser");
GdkColor color;
gdk_color_parse ("#ff250d", &color);
gtk_widget_modify_fg (eerreur, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL(eerreur),texte);
}
}

void
on_treeviewgeaff_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
char ch[200];
plat p;
GtkTreeIter iter;
gchar* ID;
gchar* TYPE;
gchar* Nc;
gchar* Qd;
gchar* D;
gchar* Cons;
gchar* Eq;
GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model,&iter,path))
{
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&ID,1,&TYPE,2,&Nc,3,&Qd,4,&D,5,&Cons,6,&Eq,-1);
strcpy(ch,ID);
supprimeryes(p,ch);

affe(treeview);
}
}


void
on_buttongechct_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *eqoui,*eqnon,*eqh;
char ref[200];
eqh=lookup_widget(objet_graphique, "radiobuttongechctpd") ;
eqoui = lookup_widget(objet_graphique, "radiobuttongechctd") ;
eqnon= lookup_widget(objet_graphique, "radiobuttongechctdn") ;
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(eqoui)))
{strcpy(ref,"Dejeuner");}
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(eqnon)))
{strcpy(ref,"Diner");}
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(eqh)))
{strcpy(ref,"Petit_Dej");}
GtkWidget *w2;
GtkWidget *treeview1;
w2=lookup_widget(objet_graphique,"cheryes");
treeview1 = lookup_widget(w2,"treeviewgechct");
videre(treeview1);
aff_chte(treeview1,ref);
}


void
on_buttongechce_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *eqoui,*eqnon;
char ref[200];
eqoui = lookup_widget(objet_graphique, "radiobuttongechceoui") ;
eqnon= lookup_widget(objet_graphique, "radiobuttongechcenon") ;
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(eqoui)))
{strcpy(ref,"oui");}
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(eqnon)))
{strcpy(ref,"non");}
GtkWidget *w2;
GtkWidget *treeview1;
w2=lookup_widget(objet_graphique,"cheryes");
treeview1 = lookup_widget(w2,"treeviewgechce");
videre(treeview1);
aff_chee(treeview1,ref);
}


void
on_buttongebest_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowmenu,*w2;
w2=lookup_widget(objet_graphique,"gestionyes");
gtk_widget_destroy(w2);
windowmenu=create_bestyes();
gtk_widget_show(windowmenu);
}


void
on_buttongebestr_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowmenu,*w2;
w2=lookup_widget(objet_graphique,"bestyes");
gtk_widget_destroy(w2);
windowmenu=create_gestionyes();
gtk_widget_show(windowmenu);
GtkWidget *treeview1;
treeview1 = lookup_widget(windowmenu,"treeviewgeaff");
affe(treeview1);
}




void
on_buttonbestmenu_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

int i=0,t,j,n1=99999,n2=99999,n3=99999,n4=99999;
GtkWidget *maj,*malabel; char texte[200];
maj=lookup_widget(objet_graphique,"spinbuttonbestmenu");
malabel=lookup_widget(objet_graphique,"labelgebest");
j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(maj));
int a,b,c,b1,a1; float c2;
FILE *f=NULL;
f=fopen("dechets.txt","r");
while(fscanf(f,"%d %d %f",&a,&b,&c2)!=EOF)
{c=(int)(c2);
i=i+1;
if((j==1)&&(i<25))
 {if (n1>c) {n1=c; b1=b; a1=a;}}
else if((j==2)&&(i<50)&&(i>=25))
 {if (n2>c) {n2=c; b1=b; a1=a;}}

else if((j==3)&&(i<75)&&(i>=50))
 {if (n3>c) {n3=c; b1=b; a1=a;}}

else if((j==4)&&(i>=75)&&(i<=100))
 {if (n4>c) { n4=c; b1=b; a1=a;}}
}
fclose(f);
char ch1[200],ch2[200],ch3[200];
/*strcpy(ch1,"le repas num ");
sprintf(ch2,"%d",b1);
strcat(ch1,ch2);
strcat(ch1," du jour ");
sprintf(ch3,"%d",a1);
strcat(ch1,ch3);
strcat(ch1," de la semaine 1 est la meilleur menu");
gtk_label_set_text(GTK_LABEL(malabel),ch1);*/

if (j==1)
{strcpy(ch1,"le repas num ");
sprintf(ch2,"%d",b1);
strcat(ch1,ch2);
strcat(ch1," du jour ");
sprintf(ch3,"%d",a1);
strcat(ch1,ch3);
strcat(ch1," pour la semaine 1 est le meilleur menu");
sprintf(texte,ch1);
GdkColor color;
gdk_color_parse ("#40e61a", &color);
gtk_widget_modify_fg (malabel, GTK_STATE_NORMAL, &color);
    gtk_label_set_text(GTK_LABEL(malabel),texte);
}
else if (j==2)
{strcpy(ch1,"le repas num ");
sprintf(ch2,"%d",b1);
strcat(ch1,ch2);
strcat(ch1," du jour ");
sprintf(ch3,"%d",a1);
strcat(ch1,ch3);
strcat(ch1," pour la semaine 2 est le meilleur menu");
sprintf(texte,ch1); GdkColor color;
gdk_color_parse ("#40e61a", &color);
gtk_widget_modify_fg (malabel, GTK_STATE_NORMAL, &color);
    gtk_label_set_text(GTK_LABEL(malabel),texte);
}
else if (j==3)
{strcpy(ch1,"le repas num ");
sprintf(ch2,"%d",b1);
strcat(ch1,ch2);
strcat(ch1," du jour ");
sprintf(ch3,"%d",a1);
strcat(ch1,ch3);
strcat(ch1," pour la semaine 3 est le meilleur menu");
sprintf(texte,ch1); GdkColor color;
gdk_color_parse ("#40e61a", &color);
gtk_widget_modify_fg (malabel, GTK_STATE_NORMAL, &color);
    gtk_label_set_text(GTK_LABEL(malabel),texte);
}
else if (j==4)
{strcpy(ch1,"le repas num ");
sprintf(ch2,"%d",b1);
strcat(ch1,ch2);
strcat(ch1," du jour ");
sprintf(ch3,"%d",a1);
strcat(ch1,ch3);
strcat(ch1," pour la semaine 4 est le meilleur menu");
sprintf(texte,ch1); GdkColor color;
gdk_color_parse ("#40e61a", &color);
gtk_widget_modify_fg (malabel, GTK_STATE_NORMAL, &color);
    gtk_label_set_text(GTK_LABEL(malabel),texte);
}
}

