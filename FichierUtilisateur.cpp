#include "FichierUtilisateur.h"
#include <fcntl.h>
#include <unistd.h>
#include <cstring>

int estPresent(const char* nom)
{
  // TO DO
  return 0;
}

////////////////////////////////////////////////////////////////////////////////////
int hash(const char* motDePasse)
{
  int somme = 0;
  for (int i = 0; motDePasse[i] != '\0'; i++)
  {
    somme += (i + 1) * motDePasse[i];
  }
  return somme % 97;
}

////////////////////////////////////////////////////////////////////////////////////
void ajouteUtilisateur(const char* nom, const char* motDePasse)
{
  // TO DO
}

////////////////////////////////////////////////////////////////////////////////////
int verifieMotDePasse(int pos, const char* motDePasse)
{
  // TO DO
  return 0;
}

////////////////////////////////////////////////////////////////////////////////////
int listeUtilisateurs(UTILISATEUR *vecteur) // le vecteur doit etre suffisamment grand
{
  // TO DO
  return 0;
}
