#include <iostream>
#include "Test.h"
using namespace std;

bool testGangster(Gangster& p)
{

  // On teste que la fonction emprisonne marche correctement
  p.setTemps(0);
  if (p.getTemps() != 0)
    {
      error("setTemps() ou getTemps()");
      return false;
    }

  p.setEnPrison(false);
  if( p.getEnPrison() )
    {
      error("setEnPrison() ou getEnPrison");
      return false;
    }

  p.emprisonne();
  if( p.getEnPrison() )
    {
      error(" emprisonne() ou getEnPrison()");
      return false;
    }

  long recompense = 300; 
  p.setRecompense(recompense);
  if (p.getRecompense() != recompense)
    {
      error(" setRecompense() ou getRecompense() ");
      return false;
    }
  
  p.augmenteRecompense();
  if (p.getRecompense() <= recompense)
    {
      error(" augmenteRecompense() ");
      return false;
    }
  p.setGang(KONOHA);
  if (p.getGang() != KONOHA )
    {
      error(" setGang() ou getGang() ");
      return false;
    }

  if (p.gangToString() != "Konoha")
    {
      error(" gangToString() ");
      return false;
    }

  p.effaceRecompense();

  if ( p.getRecompense() != 0)
    {
      error(" effaceRecompense ");
      return false;
    }
  return true;
}


bool testPersonnage(Personnage& p)
{

  p.setNom("test");
  if (p.getNom() != "test")
    {
      error(" setNom() ou getNom() ");
      return false;
    }

  p.setType(PIGEON);
  if (p.getType() != PIGEON)
    {
      error(" setType() ou getType() ");
      return false;
    }


  Lieu** itineraire = p.getItineraire();
  p.setItineraire(itineraire);
  

  if ( p.getItineraire() != itineraire || itineraire == NULL)
    {
      error("getItineraire() ou setItineraire");
      return false;
    }

  int taille = p.getTailleItineraire();

  p.setLieu(itineraire[0]);
  p.setPosition(0);

  // On teste si son itineraire ne contient aucun pointeur NULL sur Lieu et que la fonction deplace marche bien comme il se doit
  for (int i = p.getPosition() ; i < taille; i++)
    {
      if (itineraire[i] == NULL || p.getLieu() == NULL ||  p.getLieu() != itineraire[p.getPosition()])
	error("getLieu() ou deplace() ou getPosition()");
      return false;
      p.deplace();
    }


  return true;
}

bool testCarte(Carte& c)
{
  Lieu* m = c.addLieu("Marseille");
  Lieu* p = c.addLieu("Paris");

  if (c.getNbVilles() != 2)
    {
      error("addLieu() ou getNbVilles()");
      return false;
    }

  if (m != c.getLieu("Marseille"))
    {
      error("getLieu ou addLieu");
      return false;
    }

  Lieu** v = c.getVilles();
  long n = c.getNbVilles();
  for (int i = 0 ; i < n ; i++)
    {
      if ( !(v[i] == m || v[i] == p) )
	{
	  error("getVilles()");
	  return false;
	}
    }

  c.setVilles(v);
  if (c.getVilles() != v)
    {
      error("setVilles()");
      return false;
    }

  return true;
}

bool testPolicier(Policier& p)
{
  long exReputation  = p.getRep();
  p.setRep(exReputation);
  if (p.getRep() != exReputation)
    {
      error("setRep()");
      return false;
    }
  p.incrementePopularite();

  if ( p.getRep() <= exReputation )
    {
      error("incrementePopularite");
      return false;
    }

  exReputation = p.getRep();
  p.decrementePopularite();
  if ( p.getRep() >= exReputation)
    {
      error("decrementePopularite()");
      return false;
    }
  return true;
}

bool testPigeon(Pigeon& p)
{
  long argent,vcount,volcount;
  long setArgent(2);
  if (argent = p.getArgent() != 2)
    {
      error("setArgent() ou getArgent()");
      return false;
    }
  p.setVisitCount(3);
  if (vcount = p.getVisitCount() != 3)
    {
      error("setVisitCount() ou getVisitCount()");
      return false;
    }

  p.setVolCount(3);
  if (volcount = p.getVisitCount() != 3)
    {
      error("setVolCount() ou getVolCount()");
      return false;
    }
    
  return true;
}

bool testLieu(Lieu& l)
{
  l.setNom("Paris");
  Lieu * tmp = new Lieu("Marseille");
  l.addConnexion(TRAIN,tmp);
  if (!l.estAccessible(TRAIN,const_cast<Lieu&>(*tmp)))
    {
      error("estAccessible() ou addConnexion()");
      return false;
    }
  if (l.distance(TRAIN,const_cast<Lieu&>(*tmp)) != 1)
    {
      error("distance()");
      return false;
    }
  l.removeConnexion(TRAIN,tmp);
  if (l.estAccessible(TRAIN,const_cast<Lieu&>(*tmp)))
    {
      error("estAccessible() ou removeConnexion()");
      return false;
    }

  if ( l.getNom() != "Paris")
    {
      error("setNom() ou getNom()");
      return false;
    }

  long nombreB = 0; 
  long nombreT = 0;
  Lieu** bateau = l.getBateau();
  Lieu** train = l.getTrain();

  for (int i = 0 ; i < l.getNbBateau() ; i++)
    {
      if (bateau[i] == NULL)
        {
	  error("getBateau()");
        }
    }
  for (int i = 0 ; i < l.getNbTrain() ; i++)
    {
      if (train[i] == NULL)
        {
	  error("getTrain()");
        }
    }
  return true;
}

bool testScenario(Scenario& s)
{
    
  s.initCarte();
  Lieu*** itineraires = s.getItineraires(); 
  int * taille = s.getTaille();
  Lieu** itineraire = itineraires[0];

  if (itineraires == NULL || itineraire == NULL )
    {
      error("getItineraires()");
      return false;
    }

  Personnage* g = new Gangster("gangster",itineraire[0],itineraire,taille[0],GANGSTER,SHINOBI);
  Personnage* po = new Policier("policier",itineraire[0],itineraire,taille[0],POLICIER);
  Personnage* pi = new Pigeon("pigeon",itineraire[0],itineraire,taille[0],PIGEON);

    
  g->interagit(*(pi));
  po->interagit(*g);
    
  g->deplace();
  if (g->getLieu() != itineraire[1])
    {
      error("Personnage::deplace()");
      return false;
    }

  return true;
}

void error(string s)
{
  cout << " [-] La/Les fonctions " << s << " ne fonctionne(nt) pas correctemet" << endl;
}
